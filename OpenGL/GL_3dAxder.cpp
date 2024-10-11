#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

// 视角控制变量
float angle = 0.0f;
float angleX = -2.6f, angleY = -5.9f; // 相机位置
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
              x1 * sin(angleX),
              x1 * sin(angleY) * cos(angleX),
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
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

    drawText(0.0, 1.15, 0.0, "Z");
    drawText(0.0, 0.0, 1.15, "Y");
    drawText(1.15, 0.0, 0.0, "X");

    glColor3b(1.0, 0.0, 0);

    if(choise == 1){
        drawText(1, 1.8, 1, "1.Cube" + str);
        drawText(1, 1.7, 1, "2.Torus");
        drawText(1, 1.6, 1, "3.Sphere");
        drawText(1, 1.5, 1, "4.Dodecahedron");
        drawText(1, 1.4, 1, "5.EXIT");
    }
    else if(choise == 2){
        drawText(1, 1.8, 1, "1.Cube");
        drawText(1, 1.7, 1, "2.Torus" + str);
        drawText(1, 1.6, 1, "3.Sphere");
        drawText(1, 1.5, 1, "4.Dodecahedron");
        drawText(1, 1.4, 1, "5.EXIT");
        }
    else if (choise == 3){
        drawText(1, 1.8, 1, "1.Cube");
        drawText(1, 1.7, 1, "2.Torus");
        drawText(1, 1.6, 1, "3.Sphere" + str);
        drawText(1, 1.5, 1, "4.Dodecahedron");  
        drawText(1, 1.4, 1, "5.EXIT");  
        }
    else if(choise == 4){
        drawText(1, 1.8, 1, "1.Cube");
        drawText(1, 1.7, 1, "2.Torus");
        drawText(1, 1.6, 1, "3.Sphere");
        drawText(1, 1.5, 1, "4.Dodecahedron" + str);
        drawText(1, 1.4, 1, "5.EXIT");
        }
    else if(choise == 5){
        exit(0);
    }
    else{
        drawText(1, 1.8, 1, "1.Cube");
        drawText(1, 1.7, 1, "2.Torus");
        drawText(1, 1.6, 1, "3.Sphere");
        drawText(1, 1.5, 1, "4.Dodecahedron");
        drawText(1, 1.4, 1, "5.EXIT");
    }

    switch (choise)
    {
        case 1:
            glPushMatrix(); // 保存当前矩阵
            glTranslatef(0.3, 0.3, 0.3);
            glColor3f(0.5, 0.5, 1);
            glutSolidCube(0.2);
            glColor3f(0.3, 0.4, 0.0);
            glutWireCube(0.2);
            break;

        case 2:
            glPushMatrix();
            glColor3f(0.1, 0.2, 1.0);
            glTranslatef(-0.6, -0.5, -0.2);
            glutSolidTorus(0.1, 0.2, 10, 10);
            glColor3f(0.0, 0.2, 0.3);
            glutWireTorus(0.1, 0.2, 10, 10);
            break;

        case 3:
            glPushMatrix();
            glTranslatef(0.5, 0.3, -0.7);
            glColor3f(1.0, 0.5, 0.5);
            glutSolidSphere(0.2, 10, 10);
            glColor3f(0.0, 0.0, 0.5);
            glutWireSphere(0.2, 10, 10);
            break;

        case 4:
            glPushMatrix();
            glTranslatef(0.5, -0.5, 0.5);
            glColor3f(0.5, 1.0, 0.5);
            glScalef(0.1, 0.1, 0.1);
            glutSolidDodecahedron();
            glColor3f(0.0, 0.4, 0.0);
            glutWireDodecahedron();
            break;

        default:
            drawText(1.0, 1.0, 1.0, "Invalid key!");
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
        angleY -= 0.1;
        break; // 向左移动
    case 'd':
        angleY += 0.1;
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

    glEnable(GL_DEPTH_TEST || GL_LIGHTING || GL_LIGHT0 || GL_COLOR_MATERIAL || GL_NORMALIZE || GL_CULL_FACE || GL_TEXTURE_2D);
    glutReshapeFunc(reshape);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    // glutIdleFunc(auto_rotate);
    glutMainLoop();

    return 0;
}