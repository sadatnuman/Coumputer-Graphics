#include <GL/glut.h>
float angle = 00.0f;

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    glRotatef(-angle, 0.0f, 0.0f, 1.0f); // Clockwise rotation
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 0.4f);
        glVertex2f(0.4f, 0.4f);
        glVertex2f(0.4f, 0.0f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void update(int value) {
    angle += 2.0f;
    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Clockwise Rotation");
    gluOrtho2D(-2, 2, -2, 2);
    glutDisplayFunc(draw);
    glutTimerFunc(20, update, 0);
    glutMainLoop();
    return 0;
}
