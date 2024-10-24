#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

// 视角控制变量
float angle = 0.0f;
float angleX = 0.7f, angleY = 0.4f; // 相机位置
int choise = 0;
std::string str = {" <<---"};

void drawText(float x, float y, float z, const std::string &text)
{
    glPushMatrix();
    glRasterPos3d(x, y, z); // 移动到指定位置
    for (char c : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
    }
    glPopMatrix();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, 0.001, 6);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClearColor(1, 1, 1, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float x1 = 1.0;
    // 设置相机视角
    gluLookAt(x1 * cos(angleY) * cos(angleX),
              x1 * sin(angleY) * cos(angleX),
              x1 * sin(angleX),
              0.0, 0.0, 0.0,
              0.0, 0.0, 1.0);
    // 绘制坐标轴
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1, 0, 0);
    glVertex3f(1, 0, 0); // X轴
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, -1, 0);
    glVertex3f(0, 1, 0); // Y轴
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, -1);
    glVertex3f(0, 0, 1); // Z轴
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    for (int i = -9; i <= 9; i ++)
    {
        if (i == 0){
            drawText(0, 0, 0, "0");
            continue;
        }
        glBegin(GL_LINES);
        glVertex3f(i*0.1, 0, 0);
        glVertex3f(i*0.1, 0.03, 0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(0, i*0.1, 0);
        glVertex3f(0, i*0.1, 0.03);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(0, 0, i*0.1);
        glVertex3d(0, 0.03, i*0.1);
        glEnd();
        std::string text = std::to_string(i);
        // std::cout << "text : " << text << " i = " << i*0.1 << std::endl;
        drawText(i*0.1, 0, -0.2, text);
        drawText(0, i*0.1, 0.1, text);
        drawText(0.2, 0, i*0.1, text);
    }

    // 绘制箭头
    glPushMatrix();
    // 旋转90度使锥体尖端朝向Y轴正方向
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, 1.0);
    glutSolidCone(0.03, 0.09, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 1.0);
    glutSolidCone(0.03, 0.09, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, 1.0);
    glutSolidCone(0.03, 0.09, 10, 10);
    glPopMatrix();

    drawText(0.0, 1.15, 0.0, "Y");
    drawText(0.0, 0.0, 1.15, "Z");
    drawText(1.15, 0.0, 0.0, "X");


    if(choise == 1){
        drawText(0.0, 0.6, 0.8, "1.Cube" + str);
        drawText(0.0, 0.6, 0.7, "2.Torus");
        drawText(0.0, 0.6, 0.6, "3.Sphere");
        drawText(0.0, 0.6, 0.5, "4.Dodecahedron");
        drawText(0.0, 0.6, 0.4, "5.EXIT");
    }
    else if(choise == 2){
        drawText(0.0, 0.6, 0.8, "1.Cube");
        drawText(0.0, 0.6, 0.7, "2.Torus" + str);
        drawText(0.0, 0.6, 0.6, "3.Sphere");
        drawText(0.0, 0.6, 0.5, "4.Dodecahedron");
        drawText(0.0, 0.6, 0.4, "5.EXIT");
        }
    else if (choise == 3){
        drawText(0.0, 0.61, 0.8, "1.Cube");
        drawText(0.0, 0.6, 0.7, "2.Torus");
        drawText(0.0, 0.6, 0.6, "3.Sphere" + str);
        drawText(0.0, 0.6, 0.5, "4.Dodecahedron");
        drawText(0.0, 0.6, 0.4, "5.EXIT");
        }
    else if(choise == 4){
        drawText(0.0, 0.6, 0.8, "1.Cube");
        drawText(0.0, 0.6, 0.7, "2.Torus");
        drawText(0.0, 0.6, 0.6, "3.Sphere");
        drawText(0.0, 0.6, 0.5, "4.Dodecahedron" + str);
        drawText(0.0, 0.6, 0.4, "5.EXIT");
        }
    else if(choise == 5){
        exit(0);
    }
    else{
        drawText(0.0, 0.6, 0.8, "1.Cube");
        drawText(0.0, 0.6, 0.7, "2.Torus");
        drawText(0.0, 0.6, 0.6, "3.Sphere");
        drawText(0.0, 0.6, 0.5, "4.Dodecahedron");
        drawText(0.0, 0.6, 0.4, "5.EXIT");
    }

    switch (choise)
    {
        case 1: // 绘制立方体
            glPushMatrix(); // 保存当前矩阵
            glTranslatef(0.3, 0.3, 0.3);
            glColor3f(0.5, 0.5, 1);
            glutSolidCube(0.2);
            glColor3f(0.3, 0.4, 0.0);
            glutWireCube(0.2); // 绘制线框立方体
            break;

        case 2: // 绘制环形体
            glPushMatrix();
            glColor3f(0.1, 0.2, 1.0);
            glTranslatef(-0.6, -0.5, -0.2);
            glutSolidTorus(0.1, 0.2, 10, 10);
            glColor3f(0.0, 0.2, 0.3);
            glutWireTorus(0.1, 0.2, 10, 10); // 绘制线框环形体
            break;

        case 3: // 绘制球体
            glPushMatrix();
            glTranslatef(0.5, 0.3, -0.7);
            glColor3f(1.0, 0.5, 0.5);
            glutSolidSphere(0.2, 10, 10);
            glColor3f(0.0, 0.0, 0.5);
            glutWireSphere(0.2, 10, 10); // 绘制线框球体
            break;

        case 4: // 绘制十二面体
            glPushMatrix();
            glTranslatef(0.5, -0.5, 0.5);
            glColor3f(0.5, 1.0, 0.5);
            glScalef(0.1, 0.1, 0.1);
            glutSolidDodecahedron();
            glColor3f(0.0, 0.4, 0.0);
            glutWireDodecahedron(); // 绘制线框十二面体
            break;

        default: // 无效按键 
            drawText(0.0, 0.6, 0.9, "Invalid key!");
            break;
    }


    glPopMatrix(); // 恢复矩阵
    


    glFlush();
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
    int num = key - '0';
    if(num >= 1 && num <= 5)
        choise = num;
    std::cout << "angleX: " << angleX << " angleY: " << angleY << " choise: " << choise << std::endl;
    glutPostRedisplay(); // 重新绘制场景
}

void auto_rotate()
{
    angle += 5.0;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Axder and 3D objects --- [left : A |right : D |up : W | down : S]");

    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    // glutIdleFunc(auto_rotate);
    glutMainLoop();

    return 0;
}