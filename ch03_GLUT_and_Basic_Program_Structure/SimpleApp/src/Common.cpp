#define _CRT_SECURE_NO_WARNINGS

#include "../include/Common.h"


#define STB_IMAGE_IMPLEMENTATION
#include "../include/STB/stb_image.h"

#undef _CRT_SECURE_NO_WARNINGS

// Print OpenGL context related information.
void Common::DumpInfo(void)
{
  printf("Vendor: %s\n", glGetString(GL_VENDOR));
  printf("Renderer: %s\n", glGetString(GL_RENDERER));
  printf("Version: %s\n", glGetString(GL_VERSION));
  printf("GLSL: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void Common::ShaderLog(GLuint shader)
{
  GLint isCompiled = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
  if (isCompiled == GL_FALSE)
  {
    GLint maxLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

    // The maxLength includes the NULL character
    GLchar *errorLog = new GLchar[maxLength];
    glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);

    printf("%s\n", errorLog);
    delete[] errorLog;
  }
}

void Common::PrintGLError()
{
  GLenum code = glGetError();
  switch (code)
  {
  case GL_NO_ERROR:
    std::cout << "GL_NO_ERROR" << std::endl;
    break;
  case GL_INVALID_ENUM:
    std::cout << "GL_INVALID_ENUM" << std::endl;
    break;
  case GL_INVALID_VALUE:
    std::cout << "GL_INVALID_VALUE" << std::endl;
    break;
  case GL_INVALID_OPERATION:
    std::cout << "GL_INVALID_OPERATION" << std::endl;
    break;
  case GL_INVALID_FRAMEBUFFER_OPERATION:
    std::cout << "GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl;
    break;
  case GL_OUT_OF_MEMORY:
    std::cout << "GL_OUT_OF_MEMORY" << std::endl;
    break;
  case GL_STACK_UNDERFLOW:
    std::cout << "GL_STACK_UNDERFLOW" << std::endl;
    break;
  case GL_STACK_OVERFLOW:
    std::cout << "GL_STACK_OVERFLOW" << std::endl;
    break;
  default:
    std::cout << "GL_ERROR" << std::endl;
  }
}

TextureData Common::Load_png(const char *path)
{
  TextureData texture;
  int n;
  stbi_uc *data = stbi_load(path, &texture.width, &texture.height, &n, 4);
  if (data != NULL)
  {
    texture.data = new unsigned char[texture.width * texture.height * 4 * sizeof(unsigned char)];
    memcpy(texture.data, data, texture.width * texture.height * 4 * sizeof(unsigned char));
    // vertical-mirror image data
    for (size_t i = 0; i < texture.width; i++)
    {
      for (size_t j = 0; j < texture.height / 2; j++)
      {
        for (size_t k = 0; k < 4; k++)
        {
          std::swap(texture.data[(j * texture.width + i) * 4 + k], texture.data[((texture.height - j - 1) * texture.width + i) * 4 + k]);
        }
      }
    }
    stbi_image_free(data);
  }
  return texture;
}

// Read shader file
char **Common::LoadShaderSource(const char *file)
{
  FILE *fp = fopen(file, "rb");
  fseek(fp, 0, SEEK_END);
  long sz = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *src = new char[sz + 1];
  fread(src, sizeof(char), sz, fp);
  src[sz] = '\0';
  char **srcp = new char *[1];
  srcp[0] = src;
  return srcp;
}

// Release 2-dimension array
void Common::FreeShaderSource(char **srcp)
{
  delete srcp[0];
  delete srcp;
}
