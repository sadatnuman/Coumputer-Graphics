#include <windows.h>
#include <GL/glut.h>
#include <cmath>

float angle = 0.0f;  // For leaf swaying animation

void drawTree(float x, float y) {
    // Draw trunk (static)
    glColor3f(0.55f, 0.27f, 0.07f);  // Brown
    glBegin(GL_QUADS);
        glVertex2f(x - 0.03f, y);
        glVertex2f(x + 0.03f, y);
        glVertex2f(x + 0.03f, y + 0.3f);
        glVertex2f(x - 0.03f, y + 0.3f);
    glEnd();

    // Swaying leaves (rotated around top of trunk)
    glPushMatrix();
    glTranslatef(x, y + 0.3f, 0);
    glRotatef(10 * sin(angle), 0, 0, 1);  // Animate sway
    glTranslatef(-x, -(y + 0.3f), 0);

    glColor3f(0.0f, 0.6f, 0.0f);  // Green leaves
    for (float i = 0; i < 3; ++i) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y + 0.3f + i * 0.05f);
        for (int j = 0; j <= 20; ++j) {
            float theta = 2.0f * 3.1416f * float(j) / 20.0f;
            float dx = 0.12f * cosf(theta);
            float dy = 0.12f * sinf(theta);
            glVertex2f(x + dx, y + 0.3f + i * 0.05f + dy);
        }
        glEnd();
    }

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawTree(0.0f, -0.6f);  // Draw single tree

    glutSwapBuffers();
}

void update(int value) {
    angle += 0.1f;
    if (angle > 2 * 3.1416f)
        angle -= 2 * 3.1416f;

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Single Tree with Swaying Leaves");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
