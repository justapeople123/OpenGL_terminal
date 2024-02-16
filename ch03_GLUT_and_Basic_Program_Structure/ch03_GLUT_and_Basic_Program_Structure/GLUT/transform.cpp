//#include <GL/freeglut.h>
// #include <string>
//
// std::string myColor = "Blue";
// float teapot_posX = 0.0f;
// float teapot_posY = 0.0f;
// float teapot_size = 1.0f;
//
// const int timer_interval = 100;
// float rotateAngle = 0.0f;
// float rotateSpeed = 30.0f;
//
// const int SIZE_1 = 1;
// const int SIZE_2 = 2;
// const int MENU_EXIT = 3;
//
// void My_Display()
// {
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
//     gluLookAt(0.0, 2.0, 5.0,
//               0.0, 0.0, 0.0,
//               0.0, 1.0, 0.0);
//
//     glTranslatef(teapot_posX, teapot_posY, 0.0f);
//     glRotatef(rotateAngle, 0.0f, 1.0f, 0.0f);
//     glScalef(teapot_size, teapot_size, teapot_size);
//     if (myColor == "Red")
//     {
//         glColor3b(125, 0, 00);
//     }
//     else if (myColor == "Green")
//     {
//         glColor3b(0, 125, 0);
//     }
//     else if (myColor == "Blue")
//     {
//         glColor3b(0, 0, 125);
//     }
//
//     glutWireTeapot(1);
//
//     glutSwapBuffers();
// }
//
// void My_Reshape(int width, int height)
// {
//     float aspect = static_cast<float>(width) / static_cast<float>(height);
//
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glViewport(0, 0, width, height);
//     gluPerspective(60.0f, aspect, 0.1f, 10.0f);
// }
//
// void My_Keyboard(unsigned char key, int x, int y)
// {
//     if (key == 'W' || key == 'w')
//     {
//         teapot_posY += 0.05f;
//     }
//     else if (key == 'S' || key == 's')
//     {
//         teapot_posY -= 0.05f;
//     }
//     else if (key == 'A' || key == 'a')
//     {
//         teapot_posX -= 0.05f;
//     }
//     else if (key == 'D' || key == 'd')
//     {
//         teapot_posX += 0.05f;
//     }
// }
//
// void My_SpecialKeys(int key, int x, int y)
// {
//     if (key == GLUT_KEY_F1)
//     {
//         myColor = "Red";
//     }
//     else if (key == GLUT_KEY_F2)
//     {
//         myColor = "Green";
//     }
//     if (key == GLUT_KEY_F3)
//     {
//         myColor = "Blue";
//     }
// }
//
// void My_Timer(int val)
// {
//     glutPostRedisplay();
//     glutTimerFunc(timer_interval, My_Timer, val);
//     rotateAngle += rotateSpeed * timer_interval * 0.001;
// }
//
// void My_Menu(int id)
// {
//     if (id == SIZE_1)
//     {
//         teapot_size = 1.0f;
//     }
//     else if (id == SIZE_2)
//     {
//         teapot_size = 2.0f;
//     }
//     else if (id == MENU_EXIT)
//     {
//         exit(0);
//     }
// }
//
// int main(int argc, char *argv[])
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//     glutInitWindowPosition(100, 100);
//     glutInitWindowSize(600, 600);
//     glutCreateWindow("glut");
//     glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
//
//     glutDisplayFunc(My_Display);
//     glutReshapeFunc(My_Reshape);
//     glutKeyboardFunc(My_Keyboard);
//     glutSpecialFunc(My_SpecialKeys);
//     glutTimerFunc(timer_interval, My_Timer, 0);
//
//     int menu_main = glutCreateMenu(My_Menu);
//     int menu_entry = glutCreateMenu(My_Menu);
//     glutSetMenu(menu_main);
//     glutAddSubMenu("Teapot Size", menu_entry);
//     glutAddMenuEntry("Exit", MENU_EXIT);
//     glutSetMenu(menu_entry);
//     glutAddMenuEntry("1.0", SIZE_1);
//     glutAddMenuEntry("2.0", SIZE_2);
//     glutSetMenu(menu_main);
//     glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//     glutMainLoop();
// }
