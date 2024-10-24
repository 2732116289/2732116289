#include <GL/glut.h>
#include <cmath>
#include <iostream>

// 定义金字塔的基本参数
float angleX = 0.0f, angleY = 0.0f;
const float baseLength = 2.0f;  // 底边长度
const float height = 2.0f;      // 高度

// 计算底面顶点坐标
void calculateBaseVertices(float baseLength, float &x1, float &y1, float &z1,
                           float &x2, float &y2, float &z2,
                           float &x3, float &y3, float &z3,
                           float &x4, float &y4, float &z4) {
    x1 = -baseLength / 2.0f;
    y1 = -baseLength / 2.0f;
    z1 = 0.0f;

    x2 = baseLength / 2.0f;
    y2 = -baseLength / 2.0f;
    z2 = 0.0f;

    x3 = baseLength / 2.0f;
    y3 = baseLength / 2.0f;
    z3 = 0.0f;

    x4 = -baseLength / 2.0f;
    y4 = baseLength / 2.0f;
    z4 = 0.0f;
}

// 计算金字塔顶部顶点坐标
void calculateTopVertex(float baseLength, float height, float &x, float &y, float &z) {
    x = 0.0f;
    y = 0.0f;
    z = height;
}

// 绘制金字塔
void drawPyramid() {
    float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
    float xt, yt, zt;

    calculateBaseVertices(baseLength, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
    calculateTopVertex(baseLength, height, xt, yt, zt);

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    // 绘制底面
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);

    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);
    glVertex3f(x1, y1, z1);

    // 绘制侧面
    glVertex3f(xt, yt, zt);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);

    glVertex3f(xt, yt, zt);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);

    glVertex3f(xt, yt, zt);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);

    glVertex3f(xt, yt, zt);
    glVertex3f(x4, y4, z4);
    glVertex3f(x1, y1, z1);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);    
    glLoadIdentity();

    float x1 = 1.0;

    // 设置相机视角
    gluLookAt(x1 * cos(angleY) * cos(angleX),
              x1 * sin(angleY) * cos(angleX),
              x1 * sin(angleX),
              0.0, 0.0, 0.0,
              0.0, 0.0, 1.0);

    // 绘制金字塔
    glScalef(0.1,0.1,0.1);
    drawPyramid();
    glutPostRedisplay();
    glFinish();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        angleY += 0.1;
        break; // 向左移动
    case 'd':
        angleY -= 0.1;
        break; // 向右移动
    case 'w':
        angleX -= 0.1;
        break; // 向上移动
    case 's':
        angleX += 0.1;
        break; // 向下移动
    default:
        break;
    }
    // int num = key - '0';
    // if(num >= 1 && num <= 5)
    //     choise = num;
    // std::cout << "angleX: " << angleX << " angleY: " << angleY << " choise: " << choise << std::endl;
    glutPostRedisplay(); // 重新绘制场景
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("High Precision Pyramid");

    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}