#include <windows.h>
#include <GL/glut.h>

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    glColor3ub(255, 0, 0); // Red
    glVertex2f(0, 0);
    glVertex2f(14, 0);
    glVertex2f(14, 1);
    glVertex2f(0, 1);

    glColor3ub(255, 165, 0); // Orange
    glVertex2f(0, 1);
    glVertex2f(14, 1);
    glVertex2f(14, 2);
    glVertex2f(0, 2);

    glColor3ub(255, 255, 0); // Yellow
    glVertex2f(0, 2);
    glVertex2f(14, 2);
    glVertex2f(14, 3);
    glVertex2f(0, 3);

    glColor3ub(0, 128, 0); // Green
    glVertex2f(0, 3);
    glVertex2f(14, 3);
    glVertex2f(14, 4);
    glVertex2f(0, 4);

    glColor3ub(0, 0, 255); // Blue
    glVertex2f(0, 4);
    glVertex2f(14, 4);
    glVertex2f(14, 5);
    glVertex2f(0, 5);

    glColor3ub(75, 0, 130); // Indigo
    glVertex2f(0, 5);
    glVertex2f(14, 5);
    glVertex2f(14, 6);
    glVertex2f(0, 6);

    glColor3ub(238, 130, 238); // Violet
    glVertex2f(0, 6);
    glVertex2f(14, 6);
    glVertex2f(14, 7);
    glVertex2f(0, 7);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Rainbow Flag");
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    gluOrtho2D(-20, 20, -20, 20);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}
