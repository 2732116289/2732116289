// #define GLUT_DISABLE_ATEXIT_HACK
// #include <GL/glut.h>

// void reshape(int w, int h);
// void init();
// void display();

// int main(int argc, char **argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//     glutInitWindowSize(500, 500);
//     glutInitWindowPosition(1920 / 2 - 250, 1080 / 2 - 250);
//     glutCreateWindow("3D Basic");
//     glutReshapeFunc(reshape);
//     init();
//     glutDisplayFunc(display);
//     glutMainLoop();

//     return 0;
// }

// void reshape(int w, int h)
// {
//     glViewport(0, 0, w, h);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     // glOrtho(-1.0, 1.0, -1.0, 1.0, 0.1, 2.5);
//     gluPerspective(45.0, (double)w / (double)h, 0.1, 20.0);
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
// }
// void init()
// {
//     glClearColor(0.0, 0.0, 0.0, 0.0);
//     glShadeModel(GL_MODELVIEW);
//     // glColor3f(1.0, 1.0, 1.0);
// }

// void display()
// {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
//     gluLookAt(1.4, 1.0,0.8, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//     // gluLookAt(1, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//     glColor3f(1.0, 0.0, 0.0);
//     // glutWireCube(0.5);

//     glutSolidCube(0.5);
//     glColor3f(0, 0, 1);
//     glutWireCube(0.5);
//     glutSwapBuffers();
// }



#include <GL/glut.h>

float angle = 0.0; // 立方体旋转的角度

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 0.1, 2.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(1.4, 1.0, 0.8, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix(); // 保存当前矩阵
    glRotatef(angle, 0.0, 1.0, 0.0); // 旋转立方佄1�7
    glColor3f(0.0, 1.0, 0.0);
    glutSolidCube(0.5);
    glPopMatrix(); // 恢复矩阵
 
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'a') {
        angle += 5.0; // 向左旋转
    } else if (key == 'd') {
        angle -= 5.0; // 向右旋转
    }
    glutPostRedisplay(); // 请求重新绘制
}

void auto_rotate() {
    angle += 5.0;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Interactive 3D Cube");
    glutReshapeFunc(reshape); 
    glutDisplayFunc(display);
    // glutKeyboardFunc(keyboard); // 注册键盘输入处理
    glutIdleFunc(auto_rotate); // 注册自动旋转处理
    glutMainLoop();
    return 0;
}

