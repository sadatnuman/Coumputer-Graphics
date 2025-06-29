#include <windows.h>     // Only needed on Windows for GLUT
#include <GL/gl.h>       // Core OpenGL functions
#include <GL/glu.h>      // OpenGL Utility Library
#include <GL/glut.h>     // GLUT (OpenGL Utility Toolkit)

void Draw(float x, float y, float z) {
    glPushMatrix();
    glScalef(x, y, z);         // Apply scaling
    glColor3f(0, 1, 0);        // Green color

    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 0.4f);
        glVertex2f(0.4f, 0.4f);
        glVertex2f(0.4f, 0.0f);
    glEnd();

    glPopMatrix();
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-0.8f, -0.3f, 0.0f);  // Move the shape inside the view
    Draw(4.0f, 4.0f, 1.0f);           // Draw scaled rectangle

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scaling Example");

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background to white

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);  // Set the coordinate system

    glMatrixMode(GL_MODELVIEW);       // Switch to model view
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}
