#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define MAX_DROPS 100
#define MAX_BUBBLES 100

const float groundY = -0.8f;

// Raindrop data
float dropX[MAX_DROPS];
float dropY[MAX_DROPS];
float dropSpeed[MAX_DROPS];
int dropCount = 0;

// Bubble data
float bubbleX[MAX_BUBBLES];
float bubbleY[MAX_BUBBLES];
float bubbleRadius[MAX_BUBBLES];
float bubbleAlpha[MAX_BUBBLES];
int bubbleActive[MAX_BUBBLES];
int bubbleCount = 0;

// Draw a circle for bubbles
void drawCircle(float x, float y, float radius, float alpha) {
    int segments = 32;
    glColor4f(0.5f, 0.7f, 1.0f, alpha);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * 3.14159f * i / segments;
        glVertex2f(x + cosf(angle) * radius, y + sinf(angle) * radius);
    }
    glEnd();
}

void drawGround() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(-1, groundY);
    glVertex2f(1, groundY);
    glVertex2f(1, -1);
    glVertex2f(-1, -1);
    glEnd();
}

void drawDrops() {
    glColor3f(0.2f, 0.4f, 1.0f);
    for (int i = 0; i < dropCount; ++i) {
        glBegin(GL_LINES);
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 0.05f);
        glEnd();
    }
}

void drawBubbles() {
    for (int i = 0; i < bubbleCount; ++i) {
        if (bubbleActive[i]) {
            drawCircle(bubbleX[i], bubbleY[i], bubbleRadius[i], bubbleAlpha[i]);
        }
    }
}

void update(int value) {
    // Add new drop randomly (limit MAX_DROPS)
    if (dropCount < MAX_DROPS && (rand() % 5) == 0) {
        dropX[dropCount] = (rand() % 2000 / 1000.0f) - 1.0f;  // -1 to 1
        dropY[dropCount] = 1.0f;
        dropSpeed[dropCount] = 0.01f + (rand() % 100 / 10000.0f);
        dropCount++;
    }

    // Update drops
    for (int i = 0; i < dropCount; ) {
        dropY[i] -= dropSpeed[i];
        if (dropY[i] <= groundY + 0.01f) {
            // Create bubble if there's space
            if (bubbleCount < MAX_BUBBLES) {
                bubbleX[bubbleCount] = dropX[i];
                bubbleY[bubbleCount] = groundY + 0.01f;
                bubbleRadius[bubbleCount] = 0.01f;
                bubbleAlpha[bubbleCount] = 1.0f;
                bubbleActive[bubbleCount] = 1;
                bubbleCount++;
            }

            // Remove this drop by swapping with last and decreasing count
            dropX[i] = dropX[dropCount - 1];
            dropY[i] = dropY[dropCount - 1];
            dropSpeed[i] = dropSpeed[dropCount - 1];
            dropCount--;
        } else {
            i++;
        }
    }

    // Update bubbles
    for (int i = 0; i < bubbleCount; ++i) {
        if (bubbleActive[i]) {
            bubbleRadius[i] += 0.005f;
            bubbleAlpha[i] -= 0.02f;
            if (bubbleAlpha[i] <= 0.0f) {
                bubbleActive[i] = 0;

                // Optional: compact bubble arrays by swapping with last active bubble
                // but not required here for simplicity
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // approx 60 FPS
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawGround();
    drawDrops();
    drawBubbles();

    glutSwapBuffers();
}

void init() {
    srand((unsigned int)time(0));
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0f, 0.0f, 0.05f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Rain Bubble Effect - C Style GLUT");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
