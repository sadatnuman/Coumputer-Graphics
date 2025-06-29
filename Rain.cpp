#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

#define MAX_DROPS 1000

float dropX[MAX_DROPS];
float dropY[MAX_DROPS];
int totalDrops = 0;

void addDrop() {
    if (totalDrops < MAX_DROPS) {
        dropX[totalDrops] = -1.0f + static_cast<float>(rand()) / (RAND_MAX / 2.0f); // from -1 to 1
        dropY[totalDrops] = 1.0f;
        totalDrops++;
    }
}

void update(int value) {
    for (int i = 0; i < totalDrops; i++) {
        dropY[i] -= 0.03f;

        // If raindrop reaches the bottom, remove it
        if (dropY[i] < -1.0f) {
            for (int j = i; j < totalDrops - 1; j++) {
                dropX[j] = dropX[j + 1];
                dropY[j] = dropY[j + 1];
            }
            totalDrops--;
            i--;
        }
    }

    // Add a few new drops
    for (int i = 0; i < 5; i++) {
        addDrop();
    }

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void drawRaindrops() {
    glColor3f(0.2f, 0.4f, 1.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < totalDrops; i++) {
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 0.05f);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawRaindrops();
    glFlush();
}

void init() {
    glClearColor(0.85f, 0.95f, 1.0f, 1.0f); // Light sky blue background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple Raindrop Effect");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
