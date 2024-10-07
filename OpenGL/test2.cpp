#include <GL/glut.h>

void display(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);

    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1024/2-250, 768/2-250);
    glutCreateWindow("Hello World");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

