#include <windows.h> // For MS Windows
#include <GL/glut.h> // GLUT, includes glu.h and gl.h

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glLineWidth(10);

    // ITALY
    glBegin(GL_POLYGON);
    glColor3ub(0, 146, 70); // Green
    glVertex2f(0.5, 0.5);
    glVertex2f(1.5, 0.5);
    glVertex2f(1.5, 2);
    glVertex2f(0.5, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // White
    glVertex2f(1.5, 0.5);
    glVertex2f(2.5, 0.5);
    glVertex2f(2.5, 2);
    glVertex2f(1.5, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(206, 43, 55); // Red
    glVertex2f(2.5, 0.5);
    glVertex2f(3.5, 0.5);
    glVertex2f(3.5, 2);
    glVertex2f(2.5, 2);
    glEnd();

    // POLAND
    glBegin(GL_POLYGON);
    glColor3ub(220, 20, 60); // Red
    glVertex2f(2, 3);
    glVertex2f(6, 3);
    glVertex2f(6, 4);
    glVertex2f(2, 4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // White
    glVertex2f(2, 4);
    glVertex2f(6, 4);
    glVertex2f(6, 5);
    glVertex2f(2, 5);
    glEnd();

    // GERMANY
    glBegin(GL_POLYGON);
    glColor3ub(255, 206, 0); // Yellow
    glVertex2f(-7, 1);
    glVertex2f(-1, 1);
    glVertex2f(-1, 2);
    glVertex2f(-7, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(221, 0, 0); // Red
    glVertex2f(-7, 2);
    glVertex2f(-1, 2);
    glVertex2f(-1, 3);
    glVertex2f(-7, 3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0); // Black
    glVertex2f(-7, 3);
    glVertex2f(-1, 3);
    glVertex2f(-1, 4);
    glVertex2f(-7, 4);
    glEnd();

    // RUSSIA
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // White
    glVertex2f(-7, -1);
    glVertex2f(-1, -1);
    glVertex2f(-1, -2);
    glVertex2f(-7, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 57, 166); // Blue
    glVertex2f(-7, -2);
    glVertex2f(-1, -2);
    glVertex2f(-1, -3);
    glVertex2f(-7, -3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(213, 43, 30); // Red
    glVertex2f(-7, -3);
    glVertex2f(-1, -3);
    glVertex2f(-1, -4);
    glVertex2f(-7, -4);
    glEnd();

    // AUSTRIA
    glBegin(GL_POLYGON);
    glColor3ub(237, 41, 57); // Red
    glVertex2f(1, -1);
    glVertex2f(7, -1);
    glVertex2f(7, -2);
    glVertex2f(1, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // White
    glVertex2f(1, -2);
    glVertex2f(7, -2);
    glVertex2f(7, -3);
    glVertex2f(1, -3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237, 41, 57); // Red
    glVertex2f(1, -3);
    glVertex2f(7, -3);
    glVertex2f(7, -4);
    glVertex2f(1, -4);
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutCreateWindow("OpenGL Flags"); // Create a window
    glutInitWindowSize(500, 500); // Set window size
    gluOrtho2D(-10, 10, -10, 10); // Set 2D coordinate system
    glutDisplayFunc(display); // Register display function
    glutMainLoop(); // Enter event-processing loop
    return 0;
}
