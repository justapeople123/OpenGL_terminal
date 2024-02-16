//#include <GL/freeglut.h>
// #include <string>

// float oldbackGray = 0.2f;    // Assuming initial background color is gray
// float backgroundGray = 0.2f; // Initial background color
// int clickPt_x = 0;

// void My_Display()
// {
//   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//   glMatrixMode(GL_MODELVIEW);
//   glLoadIdentity();
//   gluLookAt(0.0, 2.0, 5.0,
//             0.0, 0.0, 0.0,
//             0.0, 1.0, 0.0);

//   glColor3b(0, 0, 125);

//   glutWireTeapot(1);

//   glutSwapBuffers();
// }

// void My_Reshape(int width, int height)
// {
//   float aspect = static_cast<float>(width) / static_cast<float>(height);

//   glMatrixMode(GL_PROJECTION);
//   glLoadIdentity();
//   glViewport(0, 0, width, height);
//   gluPerspective(60.0f, aspect, 0.1f, 10.0f);
// }

// void My_Mouse(int button, int state, int x, int y)
// {
//   if (button == GLUT_LEFT_BUTTON)
//   {
//     if (state == GLUT_DOWN)
//     {
//       oldbackGray = backgroundGray;
//       clickPt_x = x;
//     }
//   }
// }

// void Mouse_Moving(int x, int y)
// {
//   backgroundGray = (x - clickPt_x) * 0.005f + oldbackGray;
//   backgroundGray = std::min(std::max(backgroundGray, 0.0f), 1.0f);

//   glClearColor(backgroundGray, backgroundGray, backgroundGray, 1.0f);
//   glutPostRedisplay();
// }

// int main(int argc, char *argv[])
// {
//   glutInit(&argc, argv);
//   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//   glutInitWindowPosition(100, 100);
//   glutInitWindowSize(600, 600);
//   glutCreateWindow("glut");
//   glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

//   glutDisplayFunc(My_Display);
//   glutReshapeFunc(My_Reshape);
//   glutMouseFunc(My_Mouse);
//   glutMotionFunc(Mouse_Moving);

//   glutMainLoop();
// }