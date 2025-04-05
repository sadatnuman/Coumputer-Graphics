#include <windows.h> // For MS Windows
#include <GL/glut.h> // GLUT, includes glu.h and gl.h

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Manually draw each square
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, 1);
    glVertex2f(0, 1);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_QUADS);
    glVertex2f(1, 0);
    glVertex2f(2, 0);
    glVertex2f(2, 1);
    glVertex2f(1, 1);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_QUADS);
    glVertex2f(2, 0);
    glVertex2f(3, 0);
    glVertex2f(3, 1);
    glVertex2f(2, 1);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_QUADS);
    glVertex2f(3, 0);
    glVertex2f(4, 0);
    glVertex2f(4, 1);
    glVertex2f(3, 1);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_QUADS);
    glVertex2f(0, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 2);
    glVertex2f(0, 2);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_QUADS);
    glVertex2f(1, 1);
    glVertex2f(2, 1);
    glVertex2f(2, 2);
    glVertex2f(1, 2);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_QUADS);
    glVertex2f(2, 1);
    glVertex2f(3, 1);
    glVertex2f(3, 2);
    glVertex2f(2, 2);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_QUADS);
    glVertex2f(3, 1);
    glVertex2f(4, 1);
    glVertex2f(4, 2);
    glVertex2f(3, 2);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_QUADS);
    glVertex2f(0, 2);
    glVertex2f(1, 2);
    glVertex2f(1, 3);
    glVertex2f(0, 3);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_QUADS);
    glVertex2f(1, 2);
    glVertex2f(2, 2);
    glVertex2f(2, 3);
    glVertex2f(1, 3);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_QUADS);
    glVertex2f(2, 2);
    glVertex2f(3, 2);
    glVertex2f(3, 3);
    glVertex2f(2, 3);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_QUADS);
    glVertex2f(3, 2);
    glVertex2f(4, 2);
    glVertex2f(4, 3);
    glVertex2f(3, 3);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_QUADS);
    glVertex2f(0, 3);
    glVertex2f(1, 3);
    glVertex2f(1, 4);
    glVertex2f(0, 4);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_QUADS);
    glVertex2f(1, 3);
    glVertex2f(2, 3);
    glVertex2f(2, 4);
    glVertex2f(1, 4);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_QUADS);
    glVertex2f(2, 3);
    glVertex2f(3, 3);
    glVertex2f(3, 4);
    glVertex2f(2, 4);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_QUADS);
    glVertex2f(3, 3);
    glVertex2f(4, 3);
    glVertex2f(4, 4);
    glVertex2f(3, 4);
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("4x4 Chess Board");
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(80, 80);
    gluOrtho2D(0, 4, 0, 4); // Define the coordinate system
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}
