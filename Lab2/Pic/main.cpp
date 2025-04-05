#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

// Function to display graphics
void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);     // Clear the color buffer
    glLineWidth(3);

    // Define positions for four circles
    float positions[4][2] = {
        {-0.3699, 0.3504}, {0.3436, 0.3677},
        {0.3436, -0.3401}, {-0.3526, -0.3516}
    };
    float r = 0.5;

    // Draw four circles
    for (int j = 0; j < 4; j++) {
        glBegin(GL_POLYGON);
        glColor3f(223.0 / 255, 243.0 / 255, 252.0 / 255);
        for (int i = 0; i < 200; i++) {
            float A = (i * 2 * M_PI) / 200;
            glVertex2f(r * cos(A) + positions[j][0], r * sin(A) + positions[j][1]);
        }
        glEnd();
    }

    //arrow
    glBegin(GL_QUADS);
    glColor3ub(246,146,148);
    glVertex2f(-0.1,0.2);
    glVertex2f(-0.1,0.4);
    glVertex2f(0.1,0.4);
    glVertex2f(0.1,0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(246,146,148);
    glVertex2f(-0.2,0.4);
    glVertex2f(0,0.6);
    glVertex2f(0.2,0.4);
    glEnd();



    // Draw center circles
    float center[2] = {0.0, 0.1};
    float R = 0.1;

    for (int j = 0; j < 2; j++) {
        glBegin(GL_POLYGON);
        glColor3f(166.0 / 255, 223.0 / 255, 250.0 / 255);
        for (int i = 0; i < 200; i++) {
            float A = (i * 2 * M_PI) / 200;
            glVertex2f(R * cos(A) + center[0], R * sin(A) + center[1]);
        }
        R += 0.05;
        glEnd();
    }

    // Draw triangle
    glBegin(GL_TRIANGLES);
    glColor3ub(250, 208, 132);
    glVertex2f(-0.8, 0.6);
    glVertex2f(-0.7, 0.55);
    glVertex2f(-0.8, 0.5);
    glEnd();

    // Draw plus sign (+)
    glBegin(GL_LINES);
    glColor3ub(247, 146, 146);
    glVertex2f(-0.25, 0.75);
    glVertex2f(-0.15, 0.75);
    glVertex2f(-0.2, 0.8);
    glVertex2f(-0.2, 0.7);
    glEnd();

    // Draw another triangle
    glBegin(GL_TRIANGLES);
    glColor3ub(241, 146, 144);
    glVertex2f(0.1, -0.75);
    glVertex2f(0.2, -0.7);
    glVertex2f(0.2, -0.8);
    glEnd();

    // Draw cross sign (X)
    glBegin(GL_LINES);
    glColor3ub(255, 152, 153);
    glVertex2f(-0.6, -0.6);
    glVertex2f(-0.5, -0.7);
    glVertex2f(-0.6, -0.7);
    glVertex2f(-0.5, -0.6);
    glEnd();

    // Define square positions
    float squares[3][4][2] = {
        {{-0.4, -0.5}, {-0.4, -0.3}, {-0.2, -0.3}, {-0.2, -0.5}},
        {{-0.1, -0.5}, {-0.1, -0.3}, {0.1, -0.3}, {0.1, -0.5}},
        {{0.2, -0.5}, {0.2, -0.3}, {0.4, -0.3}, {0.4, -0.5}}
    };

    // Draw squares
    glColor3ub(254, 211, 133);
    for (int i = 0; i < 3; i++) {
        glBegin(GL_QUADS);
        for (int j = 0; j < 4; j++) {
            glVertex2f(squares[i][j][0], squares[i][j][1]);
        }
        glEnd();
    }


    glBegin(GL_QUADS);
    glColor3ub(254, 211, 133);
    glVertex2f(-0.32,-0.3);
    glVertex2f(-0.32,0.12);
    glVertex2f(-0.28,0.12);
    glVertex2f(-0.28,-0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 211, 133);
    glVertex2f(-0.28,0.08);
    glVertex2f(-0.28,0.12);
    glVertex2f(-0.1485776339369, 0.1206079279332);
    glVertex2f(-0.1486862465207, 0.0801909087643);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(254, 211, 133);
    glVertex2f(-0.02,-0.3);
    glVertex2f(-0.0200669441337,-0.0482869536007);
    glVertex2f(0.0199211307485,-0.0482869536007);
    glVertex2f(0.02,-0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 211, 133);
    glVertex2f(0.28,-0.3);
    glVertex2f(0.28,0.1);
    glVertex2f(0.32,0.1);
    glVertex2f(0.32,-0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 211, 133);
    glVertex2f(0.1452852045516,0.0598556045804);
    glVertex2f(0.1493268540589,0.0998230274851);
    glVertex2f(0.28,0.1);
    glVertex2f(0.28,0.06);
    glEnd();


    glFlush();

}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Shapes");
    glutInitWindowSize(501, 495);
    gluOrtho2D(-1, 1, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

