#include "../include/AntTweakBar/AntTweakBar.h"
#include "../include/Common.h"
#include "../include/ViewManager.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/STB/stb_image_write.h"
#include <fstream>

using namespace glm;
using namespace std;

#if (_MSC_VER == 1600)
#include <string>
#include <type_traits>
namespace std
{
  template <typename T>
  typename enable_if<is_convertible<T, _Longlong>::value, string>::type to_string(T rhs) { return to_string(static_cast<_Longlong>(rhs)); }
}
#endif

struct
{
  GLint model_matrix;
  GLint view_matrix;
  GLint proj_matrix;
} uniforms;

GLuint program;
mat4 proj_matrix;
float aspect;

Shape m_shape;
ViewManager m_camera;
TwBar *bar;
vec2 m_screenSize;
vector<Shape> m_shapes;
int m_currentShape;
float m_zoom = 3.0f;
float m_fps = 0;
unsigned int m_frames = 0;
unsigned int m_currentTime = 0;
unsigned int m_timebase = 0;
bool m_autoRotate;
bool m_isOthogonol;
vec3 m_backgroundColor = vec3(0.486, 0.721, 0.918);

typedef enum
{
  SHAPE_BOX = 0,
  SHAPE_FISH,
  SHAPE_TEAPOT,
  NUM_SHAPES
} ModelShape;

void TW_CALL SetAutoRotateCB(const void *value, void *clientData)
{
  m_autoRotate = *(const int *)value;
}
void TW_CALL GetAutoRotateCB(void *value, void *clientData)
{
  *(int *)value = m_autoRotate;
}
void TW_CALL SetIsOthoCB(const void *value, void *clientData)
{
  m_isOthogonol = *(const int *)value;
  m_camera.ToggleOrtho();
}
void TW_CALL GetIsOthoCB(void *value, void *clientData)
{
  *(int *)value = m_isOthogonol;
}
void TW_CALL ResetRotationCB(void *clientData)
{
  m_camera.SetRotation(0, 0);
  for (int i = 0; i < m_shapes.size(); ++i)
  {
    m_shapes[i].rotation = vec3(0);
  }
  glutPostRedisplay();
}

void setupGUI()
{
  // Initialize AntTweakBar
  // TwDefine(" GLOBAL fontscaling=2 ");
#ifdef _MSC_VER
  TwInit(TW_OPENGL, NULL);
#else
  TwInit(TW_OPENGL_CORE, NULL);
#endif
  TwGLUTModifiersFunc(glutGetModifiers);
  bar = TwNewBar("Properties");
  TwDefine(" Properties size='300 220' ");
  TwDefine(" Properties fontsize='3' color='0 0 0' alpha=180 "); // http://anttweakbar.sourceforge.net/doc/tools:anttweakbar:twbarparamsyntax

  TwAddVarRO(bar, "time", TW_TYPE_FLOAT, &m_fps, " label='FPS' help='Frame Per Second(FPS)' ");
  {
    TwEnumVal shapeEV[NUM_SHAPES] = {{SHAPE_BOX, "Box"}, {SHAPE_FISH, "Fish"}, {SHAPE_TEAPOT, "Teapot"}};
    TwType shapeType = TwDefineEnum("ShapeType", shapeEV, NUM_SHAPES);
    TwAddVarRW(bar, "Shape", shapeType, &m_currentShape, " keyIncr='<' keyDecr='>' help='Change object shape.' ");
  }

  TwAddVarRW(bar, "Zoom", TW_TYPE_FLOAT, &m_zoom, " min=0.01 max=3.0 step=0.01 help='Camera zoom in/out' ");
  TwAddVarRW(bar, "BackgroundColor", TW_TYPE_COLOR3F, value_ptr(m_backgroundColor), " label='Background Color' opened=true help='Used in glClearColor' ");
  TwAddVarCB(bar, "AutoRotate", TW_TYPE_BOOL32, SetAutoRotateCB, GetAutoRotateCB, NULL, " label='Auto-rotate' key=space help='Toggle auto-rotate mode.' ");
  TwAddVarCB(bar, "OthoToggle", TW_TYPE_BOOL32, SetIsOthoCB, GetIsOthoCB, NULL, " label='Is Orthographic' key=space help='Toggle orthogonal camera' ");
  TwAddButton(bar, "ResetRotation", ResetRotationCB, NULL, " label='Reset Rotation' ");
}
void setupModel()
{
  int numModels = 3;
  string model_names[] =
      {
          "box_realistic.obj",
          "clownfish.obj",
          "teapot.obj"};

  int numTextures = 3;
  string texture_names[] =
      {
          "box_texture_color.png",
          "clownfish4.png",
          "teapot.png",
          "teapot.png"};

  map<string, vector<tinyobj::shape_t>> model_cache;
  map<string, TextureData> texture_cache;

  for (int i = 0; i < numModels; i++)
  {
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    map<string, vector<tinyobj::shape_t>>::iterator found = model_cache.find(model_names[i]);
    if (found != model_cache.end())
    {
      shapes = found->second;
    }
    else
    {
      std::string err;

      bool ret = tinyobj::LoadObj(shapes, materials, err, model_names[i].c_str());
      if (err.size() > 0)
      {
        printf("Load Models Fail: %s\n", err.c_str());
        continue;
      }
      model_cache.insert(pair<string, vector<tinyobj::shape_t>>(model_names[i], shapes));
      printf("Load Models Success ! Shapes size %d Material size %d\n", shapes.size(), materials.size());
    }

    for (int j = 0; j < shapes.size(); ++j)
    {
      Shape m_shape;

      glGenVertexArrays(1, &m_shape.vao);
      glBindVertexArray(m_shape.vao);

      glGenBuffers(3, &m_shape.vbo);
      glGenBuffers(1, &m_shape.p_normal);
      glBindBuffer(GL_ARRAY_BUFFER, m_shape.vbo);
      glBufferData(GL_ARRAY_BUFFER, shapes[j].mesh.positions.size() * sizeof(float) + shapes[j].mesh.normals.size() * sizeof(float), NULL, GL_STATIC_DRAW);

      glBufferSubData(GL_ARRAY_BUFFER, 0, shapes[j].mesh.positions.size() * sizeof(float), &shapes[j].mesh.positions[0]);
      glBufferSubData(GL_ARRAY_BUFFER, shapes[j].mesh.positions.size() * sizeof(float), shapes[j].mesh.normals.size() * sizeof(float), &shapes[j].mesh.normals[0]);

      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
      glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void *)(shapes[j].mesh.positions.size() * sizeof(float)));

      glBindBuffer(GL_ARRAY_BUFFER, m_shape.p_normal);
      glBufferData(GL_ARRAY_BUFFER, shapes[j].mesh.normals.size() * sizeof(float), shapes[j].mesh.normals.data(), GL_STATIC_DRAW);
      glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

      glBindBuffer(GL_ARRAY_BUFFER, m_shape.vboTex);
      glBufferData(GL_ARRAY_BUFFER, shapes[j].mesh.texcoords.size() * sizeof(float), shapes[j].mesh.texcoords.data(), GL_STATIC_DRAW);
      glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_shape.ebo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, shapes[j].mesh.indices.size() * sizeof(unsigned int), shapes[j].mesh.indices.data(), GL_STATIC_DRAW);
      m_shape.materialId = shapes[j].mesh.material_ids[0];
      m_shape.indexCount = shapes[j].mesh.indices.size();

      glEnableVertexAttribArray(0);
      glEnableVertexAttribArray(1);
      glEnableVertexAttribArray(2);
#if 1
      printf("Add object %s\n", shapes[j].name.c_str());
#else
      printf("Add object %s", shapes[j].name.c_str());
      if (shapes[j].mesh.material_ids.size() > 0)
        printf("\t- %s", materials[shapes[j].mesh.material_ids[0]].diffuse_texname.c_str());
      printf("\n");
#endif
      m_shapes.push_back(m_shape);
    }
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < numTextures; ++i)
  {
    TextureData textureData;
    map<string, TextureData>::iterator found = texture_cache.find(texture_names[i]);
    if (found != texture_cache.end())
    {
      textureData = found->second;
    }
    else
    {
      textureData = Common::Load_png(texture_names[i].c_str());
      texture_cache.insert(pair<string, TextureData>(texture_names[i], textureData));
    }

    glGenTextures(1, &m_shapes[i].m_texture);
    glBindTexture(GL_TEXTURE_2D, m_shapes[i].m_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, textureData.width, textureData.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData.data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  }
  glBindTexture(GL_TEXTURE_2D, 0);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  m_shapes[0].scale = vec3(2.0, 2.0, 2.0);
  m_shapes[1].scale = vec3(0.25, 0.25, 0.25);
  m_shapes[2].scale = vec3(0.5, 0.5, 0.5);
}
void setupShader()
{
  program = glCreateProgram();

  GLuint vs = glCreateShader(GL_VERTEX_SHADER);
  GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
  char **vsSource = Common::LoadShaderSource("../Assets/vertex.vs.glsl");
  char **fsSource = Common::LoadShaderSource("../Assets/fragment.fs.glsl");
  glShaderSource(vs, 1, vsSource, NULL);
  glShaderSource(fs, 1, fsSource, NULL);
  Common::FreeShaderSource(vsSource);
  Common::FreeShaderSource(fsSource);
  glCompileShader(vs);
  glCompileShader(fs);
  Common::ShaderLog(vs);
  Common::ShaderLog(fs);

  // Attach Shader to program
  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);

  // Cache uniform variable id
  uniforms.model_matrix = glGetUniformLocation(program, "model");
  uniforms.view_matrix = glGetUniformLocation(program, "view");
  uniforms.proj_matrix = glGetUniformLocation(program, "projection");

  glUseProgram(program);
}
void takeScreenshotPNG()
{
  const unsigned int Width = m_screenSize.x;
  const unsigned int Height = m_screenSize.y;
  int size = Width * Height * 4;
  unsigned char *pixels = new unsigned char[size];
  unsigned char *rotatedPixels = new unsigned char[size];
  glReadBuffer(GL_FRONT);
  glReadPixels(0, 0, Width, Height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
  // invert Y axis
  for (int h = 0; h < Height; ++h)
  {
    for (int w = 0; w < Width; ++w)
    {
      rotatedPixels[((Height - h - 1) * Width + w) * 4] = pixels[(h * Width + w) * 4];
      rotatedPixels[((Height - h - 1) * Width + w) * 4 + 1] = pixels[(h * Width + w) * 4 + 1];
      rotatedPixels[((Height - h - 1) * Width + w) * 4 + 2] = pixels[(h * Width + w) * 4 + 2];
      rotatedPixels[((Height - h - 1) * Width + w) * 4 + 3] = pixels[(h * Width + w) * 4 + 3];
    }
  }

  int fileIndex = 0;
  while (1)
  {
    string fileName = string("./" + to_string(fileIndex) + ".png").c_str();
    std::ifstream infile(fileName);
    if (!infile.good())
      break;
    fileIndex++;
  }
  stbi_write_png(string("./" + to_string(fileIndex) + ".png").c_str(), Width, Height, 4, rotatedPixels, 0);
  delete pixels, rotatedPixels;
  printf("Take screenshot\n");
}

void My_Init()
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glEnable(GL_DEPTH_TEST);
  glEnable(GLUT_MULTISAMPLE);
  glDepthFunc(GL_LEQUAL);

  setupShader();
  setupModel();
}
void My_Display()
{
  m_currentTime = glutGet(GLUT_ELAPSED_TIME);
  if (m_currentTime - m_timebase > 1000)
  {
    m_fps = (m_frames * 1000) / (m_currentTime - m_timebase);
    m_frames = 0;
    m_timebase = m_currentTime;
  }
  m_frames++;

  // glClearColor(0, 0, 0, 0);
  glClearColor(m_backgroundColor.r, m_backgroundColor.g, m_backgroundColor.b, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  m_camera.SetZoom(m_zoom);

#if 1
  glUseProgram(program);
  {
    glBindVertexArray(m_shape.vao);

    glUniformMatrix4fv(uniforms.view_matrix, 1, GL_FALSE, value_ptr(m_camera.GetViewMatrix() * m_camera.GetModelMatrix()));
    glUniformMatrix4fv(uniforms.proj_matrix, 1, GL_FALSE, value_ptr(m_camera.GetProjectionMatrix(aspect)));

    for (int i = 0; i < m_shapes.size(); ++i)
    {
      if (i != m_currentShape)
        continue;

      Shape m_shape = m_shapes[i];

      glUniformMatrix4fv(uniforms.model_matrix, 1, GL_FALSE, value_ptr(m_shapes[i].getTransformationMatrix()));

      glBindVertexArray(m_shape.vao);
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, m_shape.m_texture);
      glDrawElements(GL_TRIANGLES, m_shape.indexCount, GL_UNSIGNED_INT, 0);
      glBindVertexArray(0);
    }
  }
  glUseProgram(0);
#endif

  TwDraw();
  glutSwapBuffers();
}
void My_Reshape(int width, int height)
{
  m_screenSize = vec2(width, height);
  aspect = width * 1.0f / height;
  m_camera.SetWindowSize(width, height);
  glViewport(0, 0, width, height);
  TwWindowSize(width, height);
}
void My_Timer(int val)
{
  if (m_autoRotate)
  {
    for (int i = 0; i < m_shapes.size(); ++i)
    {
      m_shapes[i].rotation.y += 1;
    }
  }

  glutPostRedisplay();
  glutTimerFunc(16, My_Timer, val);
}
void My_Mouse(int button, int state, int x, int y)
{
  if (!TwEventMouseButtonGLUT(button, state, x, y))
  {
    m_camera.mouseEvents(button, state, x, y);
    m_zoom = m_camera.GetZoom();
    TwRefreshBar(bar);
  }
}
void My_Keyboard(unsigned char key, int x, int y)
{
  if (key == 27) // Escape key
  {
    exit(0);
  }

  if (!TwEventKeyboardGLUT(key, x, y))
  {
    m_camera.keyEvents(key);

    if (key == 't' || key == 'T')
    {
      takeScreenshotPNG();
    }
  }
}
void My_SpecialKeys(int key, int x, int y)
{
  if (!TwEventSpecialGLUT(key, x, y))
  {
    switch (key)
    {
    case GLUT_KEY_F1:
      printf("F1 is pressed at (%d, %d)\n", x, y);
      break;
    case GLUT_KEY_PAGE_UP:
      printf("Page up is pressed at (%d, %d)\n", x, y);
      break;
    case GLUT_KEY_LEFT:
      printf("Left arrow is pressed at (%d, %d)\n", x, y);
      break;
    default:
      printf("Other special key is pressed at (%d, %d)\n", x, y);
      break;
    }
  }
}
void My_Mouse_Moving(int x, int y)
{
  if (!TwEventMouseMotionGLUT(x, y))
  {
    m_camera.mouseMoveEvent(x, y);
  }
}

int main(int argc, char *argv[])
{
#ifdef __APPLE__
  // Change working directory to source code path
  chdir(__FILEPATH__("/../Assets/"));
#endif
  // Initialize GLUT and GLEW, then create a window.
  ////////////////////
  glutInit(&argc, argv);
#ifdef _MSC_VER
  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
#else
  glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
#endif

  glutInitWindowPosition(200, 200);
  glutInitWindowSize(800, 800);
  glutCreateWindow("3.5 AntTweakBar"); // You cannot use OpenGL functions before this line; The OpenGL context must be created first by glutCreateWindow()!
#ifdef _MSC_VER
  glewInit();
#endif

  // Print debug information
  Common::DumpInfo();
  ////////////////////

  // Call custom initialize function
  My_Init();
  setupGUI();
  ////////////////////

  // Register GLUT callback functions
  ////////////////////
  glutDisplayFunc(My_Display);
  glutReshapeFunc(My_Reshape);
  glutMouseFunc(My_Mouse);
  glutKeyboardFunc(My_Keyboard);
  glutSpecialFunc(My_SpecialKeys);
  glutTimerFunc(16, My_Timer, 0);
  glutPassiveMotionFunc(My_Mouse_Moving);
  glutMotionFunc(My_Mouse_Moving);
  ////////////////////

  // Enter main event loop.
  glutMainLoop();

  return 0;
}
