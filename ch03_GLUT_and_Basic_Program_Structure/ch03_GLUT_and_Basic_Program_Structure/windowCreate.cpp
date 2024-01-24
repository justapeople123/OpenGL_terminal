#include <GL/glut.h>
#include <cmath>

void My_Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glutSwapBuffers();
}

// Main
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(600, 600);
//	glutCreateWindow("glut");
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//
//	glutDisplayFunc(My_Display);
//	glutMainLoop();
//}
