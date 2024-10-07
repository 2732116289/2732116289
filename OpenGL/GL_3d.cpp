#include <GL/glut.h>
#include <cmath>
#include <iostream>

float angleX = 0.0; // x轴旋转角度
float angleY = 0.0; // y轴旋转角度

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.1, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(1.4 * cos(angleY) * cos(angleX), 
              1.4 * sin(angleX), 
              1.4 * sin(angleY) * cos(angleX), 
              0.0, 0.0, 0.0, 
              0.0, 1.0, 0.0);

    // 设置光照
    GLfloat lightPos[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat lightAmbient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat lightDiffuse[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glPushMatrix();
    glRotatef(angleY * 180.0 / M_PI, 0.0, 1.0, 0.0); // Y轴旋转
    glRotatef(angleX * 180.0 / M_PI, 1.0, 0.0, 0.0); // X轴旋转
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glutSolidCube(1.5);
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': angleY += 0.05; break; // 向左旋转
        case 'd': angleY -= 0.05; break; // 向右旋转
        case 'w': angleX += 0.05; break; // 向上旋转
        case 's': angleX -= 0.05; break; // 向下旋转
    }
    std::cout << "angleX: " << angleX << ", angleY: " << angleY << std::endl;
    glutPostRedisplay(); // 请求重新绘制
}

void autoRotate() {
    angleX += 0.01;
    angleY += 0.02;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Interactive 3D Cube with Sketch Effect");
    glEnable(GL_DEPTH_TEST); // 启用深度测试
    glutReshapeFunc(reshape); 
    glutDisplayFunc(display);
    // glutKeyboardFunc(keyboard); // 注册键盘输入处理
    glutIdleFunc(autoRotate);
    glutMainLoop();
    return 0;
}