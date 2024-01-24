#include <GL/glut.h>

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(600, 600);
  glutCreateWindow("glut");
  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

  glutDisplayFunc();
  glutReshapeFunc();
  glutKeyboardFunc();
  glutSpecialFunc();
  glutTimerFunc();

  glutMainLoop();
}