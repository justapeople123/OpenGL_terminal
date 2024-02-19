#include <GL/freeglut.h>
 #include <string>

 void My_Display()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0.0, 2.0, 5.0,
             0.0, 0.0, 0.0,
             0.0, 1.0, 0.0);
   glColor3b(125, 0, 0);

   glutWireTeapot(1);

   glutSwapBuffers();
 }

 void My_Reshape(int width, int height)
{
   float aspect = static_cast<float>(width) / static_cast<float>(height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0, 0, width, height);
   gluPerspective(60.0f, aspect, 0.1f, 10.0f);
 }

 int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowPosition(100, 100);
   glutInitWindowSize(600, 600);
   glutCreateWindow("glut");
   glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

   glutDisplayFunc(My_Display);
   glutReshapeFunc(My_Reshape);

   glutMainLoop();
 }