#include <iostream>
#include<GL/gl.h>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include<time.h>
#include <stdlib.h>
using namespace std;

bool day = true;
bool screenOne=true;
bool screenTwo=false;

const float PI = 3.14159265f;

void Line(float x1, float y1, float x2, float y2)
{
    glColor3ub(60,60,60);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void Circle(float radius, float xc, float yc,float r,float g, float b)
{
    glColor3ub(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

#define MAX_DROPS 1000

float dropX[MAX_DROPS];
float dropY[MAX_DROPS];
int totalDrops = 0;

const float X_MIN = -10.0f;
const float X_MAX = 10.0f;
const float Y_MIN = -8.0f;
const float Y_MAX = 8.0f;

bool raindrop = false;

void addDrop() {
    if (totalDrops < MAX_DROPS) {
        dropX[totalDrops] = X_MIN + static_cast<float>(rand()) / RAND_MAX * (X_MAX - X_MIN);
        dropY[totalDrops] = Y_MAX;
        totalDrops++;
    }
}

void RainUpdate(int value)//URAIN01
{
    if (raindrop) {
        for (int i = 0; i < totalDrops; i++) {
            dropY[i] -= 0.3f;

            if (dropY[i] < Y_MIN) {
                for (int j = i; j < totalDrops - 1; j++) {
                    dropX[j] = dropX[j + 1];
                    dropY[j] = dropY[j + 1];
                }
                totalDrops--;
                i--;
            }
        }

        for (int i = 0; i < 5; i++) {
            addDrop();
        }

        glutPostRedisplay();
    }
    glutTimerFunc(10, RainUpdate, 0);
}
bool rain = false;
void drawRaindrops()
{
    if(rain){
    glColor3f(0.2f, 0.4f, 1.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < totalDrops; i++) {
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 0.5f);
    }
    glEnd();
    }
}

void Sky()//SKY01
{

    if(day){
        glBegin(GL_POLYGON);
        glColor3ub(135,206,235);
        glVertex2f(-10,2);
        glVertex2f(-10,8);
        glVertex2f(10,8);
        glVertex2f(10,2);
        glEnd();
    }
    else{
        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2f(-10,2);
	    glVertex2f(-10,8);
	    glVertex2f(10,8);
	    glVertex2f(10,2);
	    glEnd();
	}
}

void Sun(float cx, float cy, float r, int num_segments)//SUN02
{

    if(day){
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(234,90,62);
    glVertex2f(cx, cy);

    for (int i = 0; i <= num_segments; ++i) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
    }

    else{
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(190,190,190);
    glVertex2f(cx, cy);

    for (int i = 0; i <= num_segments; ++i) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
    }
}

float movecloud1 = 0.0f;
float movecloud2 = 0.0f;
float movecloud3 = 0.0f;

void Cloud()//CLD03
{

    if(day){

        //cloud 1
        glPushMatrix();
        glTranslatef(movecloud1,0,0);
        Circle(0.5,-6,7,230,230,230);
        Circle(0.4,-5.2,7.2,230,230,230);
        Circle(0.4,-5.3,6.6,230,230,230);
        Circle(0.4,-4.6,6.8,230,230,230);
        glPopMatrix();

        //cloud 2
        glPushMatrix();
        glTranslatef(movecloud2,0,0);
        Circle(0.5,-1.5,7,230,230,230);
        Circle(0.4,-0.8,7.4,230,230,230);
        Circle(0.5,-0.8,6.6,230,230,230);
        Circle(0.5,-0.1,7.1,230,230,230);
        glPopMatrix();

        //cloud 3
        glPushMatrix();
        glTranslatef(movecloud3,0,0);
        Circle(0.6,7.8,7,230,230,230);
        Circle(0.5,8.8,7.4,230,230,230);
        Circle(0.5,8.6,6.7,230,230,230);
        Circle(0.4,9.4,6.8,230,230,230);
        glPopMatrix();
    }
    else{

        //cloud 1
        glPushMatrix();
        glTranslatef(movecloud1,0,0);
        Circle(0.5,-6,7,204,204,204);
        Circle(0.4,-5.2,7.2,204,204,204);
        Circle(0.4,-5.3,6.6,204,204,204);
        Circle(0.4,-4.6,6.8,204,204,204);
        glPopMatrix();

        //cloud 2
        glPushMatrix();
        glTranslatef(movecloud2,0,0);
        Circle(0.5,-1.5,7,204,204,204);
        Circle(0.4,-0.8,7.4,204,204,204);
        Circle(0.5,-0.8,6.6,204,204,204);
        Circle(0.5,-0.1,7.1,204,204,204);
        glPopMatrix();

        //cloud 3
        glPushMatrix();
        glTranslatef(movecloud3,0,0);
        Circle(0.6,7.8,7,204,204,204);
        Circle(0.5,8.8,7.4,204,204,204);
        Circle(0.5,8.6,6.7,204,204,204);
        Circle(0.4,9.4,6.8,204,204,204);
        glPopMatrix();
    }
}

void Updatecloud(int value)//UCLD02
{

    float speed = 0.01f;
    float resetThreshold = 10.0f;
    float resetX = -10.0f;

    movecloud1 += speed; if (movecloud1 > resetThreshold) movecloud1 = resetX;
    movecloud2 += speed; if (movecloud2 > resetThreshold) movecloud2 = resetX;
    movecloud3 += speed; if (movecloud3 > resetThreshold) movecloud3 = resetX;

    glutPostRedisplay();
    glutTimerFunc(20,Updatecloud,0);
}



float balloonAngle = 0.0f;
void Man_in_Hot_Air_Balloon(float x, float y, float z, float r, float g, float b) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);

    Circle(0.03, 5.56, 4.7, r, g, b);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(5.53, 4.6);
    glVertex2f(5.52, 4.67);
    glVertex2f(5.6, 4.67);
    glVertex2f(5.59, 4.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(5.5, 4.6);
    glVertex2f(5.52, 4.67);
    glVertex2f(5.51, 4.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(5.61, 4.6);
    glVertex2f(5.6, 4.67);
    glVertex2f(5.62, 4.6);
    glEnd();

    glPopMatrix();
}

void Hot_Air_Balloon()//HAB04
{
    glPushMatrix();

    glTranslatef(5.7f, 4.2f, 0.0f);
    glRotatef(5 * sin(balloonAngle), 0.0f, 0.0f, 1.0f);
    glTranslatef(-5.7f, -4.2f, 0.0f);

    if(day){
        glBegin(GL_POLYGON);
        glColor3ub(209, 6, 25);
        glVertex2f(5.45, 5.15);
        glVertex2f(4.9847427952107, 5.6232830012037);
        glVertex2f(4.7303946539271, 6.0103345205485);
        glVertex2f(4.675101579735, 6.3863274250548);
        glVertex2f(4.7801584207, 6.7623203295612);
        glVertex2f(5, 7);
        glVertex2f(5.4989683851973, 7.2599579972902);
        glVertex2f(5.9966060529262, 7.2488993824518);
        glVertex2f(6.5, 7);
        glVertex2f(6.7320039396811, 6.6351462589193);
        glVertex2f(6.781767706454, 6.2978585063474);
        glVertex2f(6.7098867100042, 6.0158638279677);
        glVertex2f(6.5108316429127, 5.6785760753958);
        glVertex2f(6.2951886535635, 5.4518744712081);
        glVertex2f(5.95, 5.15);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(209, 6, 25);
        glVertex2f(5.45, 4.95);
        glVertex2f(5.45, 5.15);
        glVertex2f(5.95, 5.15);
        glVertex2f(5.95, 4.95);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(187, 137, 94);
        glVertex2f(5.5, 4.2);
        glVertex2f(5.4, 4.6);
        glVertex2f(6, 4.6);
        glVertex2f(5.9, 4.2);
        glEnd();

        Line(5.4, 4.6, 6, 4.6);
        Line(5.5, 4.6, 5.5, 4.95);
        Line(5.625, 4.6, 5.625, 4.95);
        Line(5.77, 4.6, 5.77, 4.95);
        Line(5.9, 4.6, 5.9, 4.95);

        Man_in_Hot_Air_Balloon(0,0,0,0,0,0);
        Man_in_Hot_Air_Balloon(0.1,0,0,0,0,0);
        Man_in_Hot_Air_Balloon(0.2,0,0,0,0,0);
        Man_in_Hot_Air_Balloon(0.3,0,0,0,0,0);

    }
    else {

        glBegin(GL_POLYGON);
        glColor3ub(185, 25, 25);
        glVertex2f(5.45, 5.15);
        glVertex2f(4.9847427952107, 5.6232830012037);
        glVertex2f(4.7303946539271, 6.0103345205485);
        glVertex2f(4.675101579735, 6.3863274250548);
        glVertex2f(4.7801584207, 6.7623203295612);
        glVertex2f(5, 7);
        glVertex2f(5.4989683851973, 7.2599579972902);
        glVertex2f(5.9966060529262, 7.2488993824518);
        glVertex2f(6.5, 7);
        glVertex2f(6.7320039396811, 6.6351462589193);
        glVertex2f(6.781767706454, 6.2978585063474);
        glVertex2f(6.7098867100042, 6.0158638279677);
        glVertex2f(6.5108316429127, 5.6785760753958);
        glVertex2f(6.2951886535635, 5.4518744712081);
        glVertex2f(5.95, 5.15);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(185, 25, 25);
        glVertex2f(5.45, 4.95);
        glVertex2f(5.45, 5.15);
        glVertex2f(5.95, 5.15);
        glVertex2f(5.95, 4.95);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(160, 116, 78);
        glVertex2f(5.5, 4.2);
        glVertex2f(5.4, 4.6);
        glVertex2f(6, 4.6);
        glVertex2f(5.9, 4.2);
        glEnd();

        Line(5.4, 4.6, 6, 4.6);
        Line(5.5, 4.6, 5.5, 4.95);
        Line(5.625, 4.6, 5.625, 4.95);
        Line(5.77, 4.6, 5.77, 4.95);
        Line(5.9, 4.6, 5.9, 4.95);

        Man_in_Hot_Air_Balloon(0,0,0,200,200,200);
        Man_in_Hot_Air_Balloon(0.1,0,0,200,200,200);
        Man_in_Hot_Air_Balloon(0.2,0,0,200,200,200);
        Man_in_Hot_Air_Balloon(0.3,0,0,200,200,200);
    }

    glPopMatrix();
}

void drawAirplane(float x, float y, float z)//pln
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    // Main Body
    if (day) glColor3ub(251, 251, 251);
    else glColor3ub(180, 180, 180);
    glBegin(GL_POLYGON);
        glVertex2f(1.66, 5.88); glVertex2f(4.57, 5.37); glVertex2f(4.97, 5.29);
        glVertex2f(5.13, 5.24); glVertex2f(5.19, 5.22); glVertex2f(5.2, 5.2);
        glVertex2f(5.06, 5.14); glVertex2f(4.74, 5.11); glVertex2f(4.34, 5.09);
        glVertex2f(3.79, 5.09); glVertex2f(3.30, 5.13); glVertex2f(3.02, 5.15);
        glVertex2f(2.46, 5.30); glVertex2f(2.16, 5.33); glVertex2f(1.87, 5.38);
        glVertex2f(1.65, 5.43); glVertex2f(1.51, 5.48); glVertex2f(1.39, 5.54);
        glVertex2f(1.32, 5.59); glVertex2f(1.28, 5.63); glVertex2f(1.27, 5.66);
        glVertex2f(1.26, 5.69); glVertex2f(1.27, 5.71); glVertex2f(1.29, 5.73);
        glVertex2f(1.30, 5.75); glVertex2f(1.36, 5.76); glVertex2f(1.40, 5.77);
        glVertex2f(1.41, 5.78); glVertex2f(1.47, 5.83); glVertex2f(1.50, 5.84);
        glVertex2f(1.55, 5.87); glVertex2f(1.60, 5.88); glVertex2f(1.66, 5.88);
    glEnd();

    // Vertical Tail Fin
    if (day) glColor3ub(237, 104, 233); else glColor3ub(100, 80, 150);
    glBegin(GL_POLYGON);
        glVertex2f(2.51, 5.38); glVertex2f(2.53, 5.38); glVertex2f(2.53, 5.35);
        glVertex2f(2.52, 5.33); glVertex2f(2.51, 5.31); glVertex2f(2.50, 5.28);
        glVertex2f(2.50, 5.22); glVertex2f(2.50, 5.17); glVertex2f(2.48, 5.18);
        glVertex2f(2.46, 5.20); glVertex2f(2.46, 5.30); glVertex2f(2.49, 5.36);
        glVertex2f(2.51, 5.38);
    glEnd();

    // Rear Fin (Inner Color Fill)
    glColor3ub(245, 245, 245);
    glBegin(GL_POLYGON);
        glVertex2f(2.97, 5.30); glVertex2f(3.02, 5.28); glVertex2f(3.02, 5.18);
        glVertex2f(3.00, 5.11); glVertex2f(2.58, 5.14); glVertex2f(2.50, 5.22);
        glVertex2f(2.51, 5.31); glVertex2f(2.54, 5.37); glVertex2f(2.60, 5.4);
        glVertex2f(2.90, 5.32); glVertex2f(2.97, 5.30);
    glEnd();

    // Left Wing
    if (day) glColor3ub(237, 104, 233); else glColor3ub(100, 80, 150);
    glBegin(GL_POLYGON);
        glVertex2f(2.6, 5.4); glVertex2f(3.75, 5.52); glVertex2f(3.90615, 5.65);
        glVertex2f(3.82426, 5.45); glVertex2f(3.02531, 5.28); glVertex2f(2.6, 5.4);
    glEnd();

    // Wing Shadow Detail
    glColor3ub(241, 241, 241);
    glBegin(GL_POLYGON);
        glVertex2f(3.28, 5.31); glVertex2f(3.50238, 5.26); glVertex2f(3.6898, 5.23);
        glVertex2f(3.92053, 5.20); glVertex2f(4.16875, 5.18); glVertex2f(4.37074, 5.18);
        glVertex2f(4.58759, 5.17); glVertex2f(4.89, 5.18); glVertex2f(5.02798, 5.17);
        glVertex2f(5.15, 5.24); glVertex2f(5.17924, 5.15); glVertex2f(5.06489, 5.14);
        glVertex2f(4.74918, 5.11); glVertex2f(4.34352, 5.09); glVertex2f(3.79875, 5.09);
        glVertex2f(3.30356, 5.13); glVertex2f(3.02269, 5.15); glVertex2f(3.02519, 5.18);
        glVertex2f(3.02791, 5.21); glVertex2f(3.02791, 5.25); glVertex2f(3.06082, 5.25);
        glVertex2f(3.28, 5.31);
    glEnd();

    // Right Wing
    if (day) glColor3ub(237, 104, 233); else glColor3ub(100, 80, 150);
    glBegin(GL_POLYGON);
        glVertex2f(4.621, 5.38); glVertex2f(4.678, 5.38); glVertex2f(4.742, 5.40);
        glVertex2f(5.1799, 5.85); glVertex2f(5.4413, 5.81); glVertex2f(5.165, 5.31);
        glVertex2f(5.13, 5.24); glVertex2f(4.9725, 5.29); glVertex2f(4.622, 5.38);
    glEnd();

    // Rear Tail Fin Right Side
    if (day) glColor3ub(237, 104, 233); else glColor3ub(100, 80, 150);
    glBegin(GL_POLYGON);
        glVertex2f(5.206, 5.37); glVertex2f(5.3847, 5.37); glVertex2f(5.0279, 5.17);
        glVertex2f(4.8272, 5.18); glVertex2f(4.7211, 5.20); glVertex2f(4.6917, 5.23);
        glVertex2f(5.206, 5.37);
    glEnd();

    // Window Series (Black)
    for (int i = 0; i < 42; i++) {
        if (i >= 16 && i <= 31) continue;  // Skip some to maintain spacing
        float dx = cos(-10 * M_PI / 180) * 0.06 * i;
        float dy = sin(-10 * M_PI / 180) * 0.06 * i;
        glColor3ub(0, 0, 0);
        glBegin(GL_POLYGON);
            glVertex2f(1.91106 + dx, 5.67 + dy);
            glVertex2f(1.91607 + dx, 5.71 + dy);
            glVertex2f(1.95433 + dx, 5.71 + dy);
            glVertex2f(1.94986 + dx, 5.67 + dy);
        glEnd();
    }

    // Headlight / Nose Detail
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(1.4769, 5.83); glVertex2f(1.4953, 5.83); glVertex2f(1.5176, 5.83);
        glVertex2f(1.5417, 5.82); glVertex2f(1.5658, 5.81); glVertex2f(1.5899, 5.81);
        glVertex2f(1.6052, 5.79); glVertex2f(1.6056, 5.78); glVertex2f(1.5970, 5.76);
        glVertex2f(1.5873, 5.74); glVertex2f(1.5750, 5.74); glVertex2f(1.5552, 5.74);
        glVertex2f(1.5246, 5.74); glVertex2f(1.4891, 5.749); glVertex2f(1.4573, 5.75);
        glVertex2f(1.4307, 5.76); glVertex2f(1.4047, 5.77);
    glEnd();

    glPopMatrix();

}

float Plane_Position = 0.0f;
void Plane() //PLN27
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(Plane_Position, 0, 0);

    drawAirplane(Plane_Position, 1.5f, 0);

    glPopMatrix();
}

bool planeRunning = true;
float planeSpeed = 0.03f;
void update_Plane(int value) //UPLN15
{
    if (planeRunning) {
        Plane_Position -= planeSpeed;
        if (Plane_Position < -10.0f) {
            Plane_Position = 10.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, update_Plane, 0);
}

void Hot_Air_Ballon_update(int value)//UHAB03
{
    balloonAngle += 0.02f;
    if (balloonAngle > 2 * 3.1416f)
        balloonAngle -= 2 * 3.1416f;

    glutPostRedisplay();
    glutTimerFunc(16, Hot_Air_Ballon_update, 0);  // ~60 FPS
}

void Watch_Tower()//WTWR06
{

    if(day){

     //watch tower 01
     glBegin(GL_TRIANGLES);
     glColor3ub(128,27,43);
     glVertex2f(-4.3,5.2);
     glVertex2f(-3.7,5.7);
     glVertex2f(-3.1,5.2);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(249,241,241);
     glVertex2f(-4,3.6);
     glVertex2f(-4,5.2);
     glVertex2f(-3.4,5.2);
     glVertex2f(-3.4,3.6);
     glEnd();

     glBegin(GL_QUADS); //window1
     glColor3ub(75,75,75);
     glVertex2f(-3.8,4);
     glVertex2f(-3.8,4.2);
     glVertex2f(-3.6,4.2);
     glVertex2f(-3.6,4);
     glEnd();

     glBegin(GL_QUADS); //window2
     glColor3ub(75,75,75);
     glVertex2f(-3.8,4.4);
     glVertex2f(-3.8,4.6);
     glVertex2f(-3.6,4.6);
     glVertex2f(-3.6,4.4);
     glEnd();

     glBegin(GL_QUADS); //window3
     glColor3ub(75,75,75);
     glVertex2f(-3.8,4.8);
     glVertex2f(-3.8,5);
     glVertex2f(-3.6,5);
     glVertex2f(-3.6,4.8);
     glEnd();

     //watch tower 02
     glBegin(GL_TRIANGLES);
     glColor3ub(128,27,43);
     glVertex2f(8.1,5);
     glVertex2f(8.7,5.4);
     glVertex2f(9.3,5);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(249,241,241);
     glVertex2f(8.4,3.4);
     glVertex2f(8.4,5);
     glVertex2f(9,5);
     glVertex2f(9,3.4);
     glEnd();

     glBegin(GL_QUADS); //window1
     glColor3ub(75,75,75);
     glVertex2f(8.6,3.8);
     glVertex2f(8.6,4);
     glVertex2f(8.8,4);
     glVertex2f(8.8,3.8);
     glEnd();

     glBegin(GL_QUADS); //window2
     glColor3ub(75,75,75);
     glVertex2f(8.6,4.2);
     glVertex2f(8.6,4.4);
     glVertex2f(8.8,4.4);
     glVertex2f(8.8,4.2);
     glEnd();

     glBegin(GL_QUADS); //window3
     glColor3ub(75,75,75);
     glVertex2f(8.6,4.6);
     glVertex2f(8.6,4.8);
     glVertex2f(8.8,4.8);
     glVertex2f(8.8,4.6);
     glEnd();
    }
    else{

     //watch tower 01
     glBegin(GL_TRIANGLES);
     glColor3ub(128,27,43);
     glVertex2f(-4.3,5.2);
     glVertex2f(-3.7,5.7);
     glVertex2f(-3.1,5.2);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(186,186,186);
     glVertex2f(-4,3.6);
     glVertex2f(-4,5.2);
     glVertex2f(-3.4,5.2);
     glVertex2f(-3.4,3.6);
     glEnd();

     glBegin(GL_QUADS); //window1
     glColor3ub(75,75,75);
     glVertex2f(-3.8,4);
     glVertex2f(-3.8,4.2);
     glVertex2f(-3.6,4.2);
     glVertex2f(-3.6,4);
     glEnd();

     glBegin(GL_QUADS); //window2
     glColor3ub(75,75,75);
     glVertex2f(-3.8,4.4);
     glVertex2f(-3.8,4.6);
     glVertex2f(-3.6,4.6);
     glVertex2f(-3.6,4.4);
     glEnd();

     glBegin(GL_QUADS); //window3
     glColor3ub(75,75,75);
     glVertex2f(-3.8,4.8);
     glVertex2f(-3.8,5);
     glVertex2f(-3.6,5);
     glVertex2f(-3.6,4.8);
     glEnd();

     //watch tower 02
     glBegin(GL_TRIANGLES);
     glColor3ub(128,27,43);
     glVertex2f(8.1,5);
     glVertex2f(8.7,5.4);
     glVertex2f(9.3,5);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(186,186,186);
     glVertex2f(8.4,3.4);
     glVertex2f(8.4,5);
     glVertex2f(9,5);
     glVertex2f(9,3.4);
     glEnd();

     glBegin(GL_QUADS); //window1
     glColor3ub(75,75,75);
     glVertex2f(8.6,3.8);
     glVertex2f(8.6,4);
     glVertex2f(8.8,4);
     glVertex2f(8.8,3.8);
     glEnd();

     glBegin(GL_QUADS); //window2
     glColor3ub(75,75,75);
     glVertex2f(8.6,4.2);
     glVertex2f(8.6,4.4);
     glVertex2f(8.8,4.4);
     glVertex2f(8.8,4.2);
     glEnd();

     glBegin(GL_QUADS); //window3
     glColor3ub(75,75,75);
     glVertex2f(8.6,4.6);
     glVertex2f(8.6,4.8);
     glVertex2f(8.8,4.8);
     glVertex2f(8.8,4.6);
     glEnd();
    }
}

void Mountain()//MUN05
{

    if(day){

     glBegin(GL_TRIANGLES); //mountain 1
     glColor3ub(82,199,46);
     glVertex2f(-9.99999,2);
     glVertex2f(-6,6);
     glVertex2f(-4,2);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(49,165,13);
     glVertex2f(-4,2);
     glVertex2f(-6,6);
     glVertex2f(-2,2);
     glEnd();

     glBegin(GL_TRIANGLES); //mountain 2
     glColor3ub(82,199,46);
     glVertex2f(-6,2);
     glVertex2f(-2,5);
     glVertex2f(2,2);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(49,165,13);
     glVertex2f(2,2);
     glVertex2f(-2,5);
     glVertex2f(5,2);
     glEnd();

     glBegin(GL_TRIANGLES); //mountain 3
     glColor3ub(82,199,46);
     glVertex2f(-1,2);
     glVertex2f(2,7);
     glVertex2f(5,2);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(49,165,13);
     glVertex2f(5,2);
     glVertex2f(2,7);
     glVertex2f(7,2);
     glEnd();

     glBegin(GL_TRIANGLES); //mountain 4
     glColor3ub(82,199,46);
     glVertex2f(4,2);
     glVertex2f(7.8,5);
     glVertex2f(9,2);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(49,165,13);
     glVertex2f(9,2);
     glVertex2f(7.8,5);
     glVertex2f(9.99999,2);
     glEnd();
    }

    else{
     glBegin(GL_TRIANGLES); //mountain 1
     glColor3ub(45,129,19);
     glVertex2f(-9.99999,2);
     glVertex2f(-6,6);
     glVertex2f(-4,2);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(17,75,56);
     glVertex2f(-4,2);
     glVertex2f(-6,6);
     glVertex2f(-2,2);
     glEnd();

     glBegin(GL_TRIANGLES); //mountain 2
     glColor3ub(45,129,19);
     glVertex2f(-6,2);
     glVertex2f(-2,5);
     glVertex2f(2,2);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(17,75,56);
     glVertex2f(2,2);
     glVertex2f(-2,5);
     glVertex2f(5,2);
     glEnd();

     glBegin(GL_TRIANGLES); //mountain 3
     glColor3ub(45,129,19);
     glVertex2f(-1,2);
     glVertex2f(2,7);
     glVertex2f(5,2);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(17,75,56);
     glVertex2f(5,2);
     glVertex2f(2,7);
     glVertex2f(7,2);
     glEnd();

     glBegin(GL_TRIANGLES); //mountain 4
     glColor3ub(45,129,19);
     glVertex2f(4,2);
     glVertex2f(7.8,5);
     glVertex2f(9,2);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(17,75,56);
     glVertex2f(9,2);
     glVertex2f(7.8,5);
     glVertex2f(9.99999,2);
     glEnd();
    }
}

void Land()//LND07
{

    if(day){
        glBegin(GL_QUADS);
        glColor3ub(124,252,0);
        glVertex2f(-10,0);
        glVertex2f(-10,2);
        glVertex2f(10,2);
        glVertex2f(10,0);
        glEnd();
    }
    else{
        glBegin(GL_QUADS);
        glColor3ub(102,154,27);
        glVertex2f(-10,0);
        glVertex2f(-10,2);
        glVertex2f(10,2);
        glVertex2f(10,0);
        glEnd();
    }
}

float _angle1 = 0.0f;
void wind_turbine(float a, float b, float c, float x, float y, float z)//WINDT08
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(a, b, c);
    glTranslatef(x,y,z);

    glBegin(GL_POLYGON);
    glColor3ub(55,55,57);
    glVertex2f(8.8, 0.55);
    glVertex2f(8.8, 0.6);
    glVertex2f(9.1, 0.6);
    glVertex2f(9.1, 0.55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(200, 200, 200);
    glVertex2f(8.88, 0.6);
    glVertex2f(8.88, 2.18);
    glVertex2f(9.02, 2.18);
    glVertex2f(9.02, 0.6);
    glEnd();

    glPushMatrix();
    glTranslatef(8.945f, 2.175f, 0.0f);  // Move to center of blade
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f); // Rotate around Z
    glTranslatef(-8.945f, -2.175f, 0.0f); // Move back

    glBegin(GL_POLYGON);
    glColor3ub(230, 230, 230);
    glVertex2f(8.38, 1.68);
    glVertex2f(8.32, 1.7);
    glVertex2f(8.712, 2.147);
    glVertex2f(8.945, 2.175);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 230, 230);
    glVertex2f(8.945, 2.175);
    glVertex2f(8.817, 2.914);
    glVertex2f(8.857, 2.967);
    glVertex2f(9.045, 2.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 230, 230);
    glVertex2f(8.945, 2.175);
    glVertex2f(9.65, 1.92);
    glVertex2f(9.68, 1.86);
    glVertex2f(9.084, 1.994);
    glEnd();

    Circle(0.105, 8.945, 2.175, 255, 255, 255);

    //red
    glBegin(GL_POLYGON);
    glColor3ub(185, 25, 25);
    glVertex2f(8.38, 1.68);
    glVertex2f(8.32, 1.7);
    glVertex2f(8.3920473519525, 1.7825779468883);
    glVertex2f(8.4630120614104, 1.752256661938);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(185, 25, 25);
    glVertex2f(8.8362040688834, 2.8040848505408);
    glVertex2f(8.817, 2.914);
    glVertex2f(8.857, 2.967);
    glVertex2f(8.8924561211847, 2.8598390970698);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(185, 25, 25);
    glVertex2f(9.5464102700322, 1.9570956561623);
    glVertex2f(9.65, 1.92);
    glVertex2f(9.68, 1.86);
    glVertex2f(9.5712720301, 1.8839728324333);
    glEnd();

    glPopMatrix();

    glPopMatrix();
}

void Wind_Turbine_update(int value)//UWINDT04
{

    _angle1 += 2.0f;
	glutPostRedisplay();

	glutTimerFunc(20, Wind_Turbine_update, 0);
}

void TOWER(float x, float y, float z , float a, float b, float c)//TWR09
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(x, y, z);
    glTranslatef(a, b, c);

    if(day){

     glBegin(GL_QUADS);
     glColor3ub(60,60,60);
     glVertex2f(-1, 0.35);
     glVertex2f(-1, 0.4);
     glVertex2f(1, 0.4);
     glVertex2f(1, 0.35);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(160,160,160);
     glVertex2f(-0.9, 0.4);
     glVertex2f(-0.9, 1);
     glVertex2f(-0.7, 1);
     glVertex2f(-0.7, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(160,160,160);
     glVertex2f(0.7, 0.4);
     glVertex2f(0.7, 1);
     glVertex2f(0.9, 1);
     glVertex2f(0.9, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(190,190,190);
     glVertex2f(-0.7, 0.4);
     glVertex2f(-0.7, 1.2);
     glVertex2f(-0.5, 1.2);
     glVertex2f(-0.5, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(190,190,190);
     glVertex2f(0.5, 0.4);
     glVertex2f(0.5, 1.2);
     glVertex2f(0.7, 1.2);
     glVertex2f(0.7, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(210,210,210);
     glVertex2f(-0.5, 0.4);
     glVertex2f(-0.5, 2);
     glVertex2f(0.5, 2);
     glVertex2f(0.5, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(69,118,247);
     glVertex2f(-0.5, 0.4);
     glVertex2f(-0.5, 4);
     glVertex2f(-0.2, 4);
     glVertex2f(-0.2, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(69,118,247);
     glVertex2f(0.2, 0.4);
     glVertex2f(0.2, 4);
     glVertex2f(0.5, 4);
     glVertex2f(0.5, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(160,160,160);
     glVertex2f(-0.4, 4);
     glVertex2f(-0.4, 4.2);
     glVertex2f(-0.3, 4.2);
     glVertex2f(-0.3, 4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(160,160,160);
     glVertex2f(0.3, 4);
     glVertex2f(0.3, 4.2);
     glVertex2f(0.4, 4.2);
     glVertex2f(0.4, 4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(180,180,180);
     glVertex2f(-0.5, 4.2);
     glVertex2f(-0.5, 4.4);
     glVertex2f(0.5, 4.4);
     glVertex2f(0.5, 4.2);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(190,190,190);
     glVertex2f(-0.3, 4.4);
     glVertex2f(-0.3, 4.6);
     glVertex2f(0.3, 4.6);
     glVertex2f(0.3, 4.4);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(69,118,247);
     glVertex2f(-0.3, 4.6);
     glVertex2f(0,4.9);
     glVertex2f(0.3, 4.6);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(69,118,247);
     glVertex2f(-0.2, 3);
     glVertex2f(-0.2, 3.2);
     glVertex2f(0.2, 3.2);
     glVertex2f(0.2, 3);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(90,90,90);
     glVertex2f(-0.2, 2.8);
     glVertex2f(-0.2, 2.9);
     glVertex2f(-0.1, 3);
     glVertex2f(0, 3);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(90,90,90);
     glVertex2f(0, 3);
     glVertex2f(0.1, 3);
     glVertex2f(0.2, 2.9);
     glVertex2f(0.2, 2.8);
     glEnd();

     Line(0,4.9,0,5.2);

     glBegin(GL_POLYGON);
     glColor3ub(69,118,247);
     glVertex2f(-0.15, 0.4);
     glVertex2f(-0.15, 1);
     glVertex2f(0.15, 1);
     glVertex2f(0.15, 0.4);
     glEnd();

     Line(-0.15, 0.4, -0.15, 1);
     Line(-0.15, 0.4, 0.15, 0.4);
     Line(-0.15, 1, 0.15, 1);
     Line(0.15, 0.4, 0.15, 1);
     Line(0, 0.4, 0, 1);

    }
    else{

     glBegin(GL_QUADS);
     glColor3ub(30,30,30);
     glVertex2f(-1, 0.35);
     glVertex2f(-1, 0.4);
     glVertex2f(1, 0.4);
     glVertex2f(1, 0.35);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(79,79,79);
     glVertex2f(-0.9, 0.4);
     glVertex2f(-0.9, 1);
     glVertex2f(-0.7, 1);
     glVertex2f(-0.7, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(79,79,79);
     glVertex2f(0.7, 0.4);
     glVertex2f(0.7, 1);
     glVertex2f(0.9, 1);
     glVertex2f(0.9, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(100,100,100);
     glVertex2f(-0.7, 0.4);
     glVertex2f(-0.7, 1.2);
     glVertex2f(-0.5, 1.2);
     glVertex2f(-0.5, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(100,100,100);
     glVertex2f(0.5, 0.4);
     glVertex2f(0.5, 1.2);
     glVertex2f(0.7, 1.2);
     glVertex2f(0.7, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(135,135,135);
     glVertex2f(-0.5, 0.4);
     glVertex2f(-0.5, 2);
     glVertex2f(0.5, 2);
     glVertex2f(0.5, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(37,89,136);
     glVertex2f(-0.5, 0.4);
     glVertex2f(-0.5, 4);
     glVertex2f(-0.2, 4);
     glVertex2f(-0.2, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(37,89,136);
     glVertex2f(0.2, 0.4);
     glVertex2f(0.2, 4);
     glVertex2f(0.5, 4);
     glVertex2f(0.5, 0.4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(79,79,79);
     glVertex2f(-0.4, 4);
     glVertex2f(-0.4, 4.2);
     glVertex2f(-0.3, 4.2);
     glVertex2f(-0.3, 4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(79,79,79);
     glVertex2f(0.3, 4);
     glVertex2f(0.3, 4.2);
     glVertex2f(0.4, 4.2);
     glVertex2f(0.4, 4);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(100,100,100);
     glVertex2f(-0.5, 4.2);
     glVertex2f(-0.5, 4.4);
     glVertex2f(0.5, 4.4);
     glVertex2f(0.5, 4.2);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(120,120,120);
     glVertex2f(-0.3, 4.4);
     glVertex2f(-0.3, 4.6);
     glVertex2f(0.3, 4.6);
     glVertex2f(0.3, 4.4);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(37,89,136);
     glVertex2f(-0.3, 4.6);
     glVertex2f(0,4.9);
     glVertex2f(0.3, 4.6);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(37,89,136);
     glVertex2f(-0.2, 3);
     glVertex2f(-0.2, 3.2);
     glVertex2f(0.2, 3.2);
     glVertex2f(0.2, 3);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(90,90,90);
     glVertex2f(-0.2, 2.8);
     glVertex2f(-0.2, 2.9);
     glVertex2f(-0.1, 3);
     glVertex2f(0, 3);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(90,90,90);
     glVertex2f(0, 3);
     glVertex2f(0.1, 3);
     glVertex2f(0.2, 2.9);
     glVertex2f(0.2, 2.8);
     glEnd();

     Line(0,4.9,0,5.2);

     glBegin(GL_POLYGON);
     glColor3ub(69,118,247);
     glVertex2f(-0.15, 0.4);
     glVertex2f(-0.15, 1);
     glVertex2f(0.15, 1);
     glVertex2f(0.15, 0.4);
     glEnd();

     Line(-0.15, 0.4, -0.15, 1);
     Line(-0.15, 0.4, 0.15, 0.4);
     Line(-0.15, 1, 0.15, 1);
     Line(0.15, 0.4, 0.15, 1);
     Line(0, 0.4, 0, 1);

    }
    glPopMatrix();
}

void Window_House1(float x, float y, float z){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(1.78, 0.58);
    glVertex2f(1.78, 0.82);
    glVertex2f(2.02, 0.82);
    glVertex2f(2.02, 0.58);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(69,118,247);
    glVertex2f(1.8, 0.6);
    glVertex2f(1.8,0.8);
    glVertex2f(2, 0.6);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(181,190,247);
    glVertex2f(1.8,0.8);
    glVertex2f(2, 0.8);
    glVertex2f(2, 0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(1.9, 0.58);
    glVertex2f(1.9, 0.82);
    glVertex2f(1.91, 0.82);
    glVertex2f(1.91, 0.58);
    glEnd();

    glPopMatrix();
}

void HOUSE1(float x, float y, float z , float a, float b, float c)//HUS10
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(x, y, z);
    glTranslatef(a, b, c);
    if(day){

    glBegin(GL_QUADS);
    glColor3ub(55,55,57);
    glVertex2f(1.6, 0.35);
    glVertex2f(1.6, 0.4);
    glVertex2f(2.6, 0.4);
    glVertex2f(2.6, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(130,130,250);
    glVertex2f(1.7, 0.4);
    glVertex2f(1.7, 2.35);
    glVertex2f(2.5, 2.35);
    glVertex2f(2.5, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(91,91,177);
    glVertex2f(1.65, 1.2);
    glVertex2f(1.65, 1.25);
    glVertex2f(2.55, 1.25);
    glVertex2f(2.55, 1.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(91,91,177);
    glVertex2f(1.65, 2.3);
    glVertex2f(1.65, 2.35);
    glVertex2f(2.55, 2.35);
    glVertex2f(2.55, 2.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80,80,80);
    glVertex2f(2.2, 0.4);
    glVertex2f(2.2, 0.85);
    glVertex2f(2.4, 0.85);
    glVertex2f(2.4, 0.4);
    glEnd();

    Circle(0.02,2.24, 0.64,233,233,233);

    Window_House1(0,0,0);
    Window_House1(0,0.35,0);
    Window_House1(0.4,0.35,0);
    Window_House1(0,0.7,0);
    Window_House1(0,1.05,0);
    Window_House1(0,1.4,0);
    Window_House1(0.4,0.7,0);
    Window_House1(0.4,1.05,0);
    Window_House1(0.4,1.4,0);

    }
    else{

    glBegin(GL_QUADS);
    glColor3ub(55,55,57);
    glVertex2f(1.6, 0.35);
    glVertex2f(1.6, 0.4);
    glVertex2f(2.6, 0.4);
    glVertex2f(2.6, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97,97,187);
    glVertex2f(1.7, 0.4);
    glVertex2f(1.7, 2.35);
    glVertex2f(2.5, 2.35);
    glVertex2f(2.5, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(18,18,50);
    glVertex2f(1.65, 1.2);
    glVertex2f(1.65, 1.25);
    glVertex2f(2.55, 1.25);
    glVertex2f(2.55, 1.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(18,18,50);
    glVertex2f(1.65, 2.3);
    glVertex2f(1.65, 2.35);
    glVertex2f(2.55, 2.35);
    glVertex2f(2.55, 2.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80,80,80);
    glVertex2f(2.2, 0.4);
    glVertex2f(2.2, 0.85);
    glVertex2f(2.4, 0.85);
    glVertex2f(2.4, 0.4);
    glEnd();

    Circle(0.02,2.24, 0.64,210,210,210);

    Window_House1(0,0,0);
    Window_House1(0,0.35,0);
    Window_House1(0.4,0.35,0);
    Window_House1(0,0.7,0);
    Window_House1(0,1.05,0);
    Window_House1(0,1.4,0);
    Window_House1(0.4,0.7,0);
    Window_House1(0.4,1.05,0);
    Window_House1(0.4,1.4,0);

    }
    glPopMatrix();
}

void Window_House2(float x, float y, float z){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(4.78, 0.58);
    glVertex2f(4.78, 0.82);
    glVertex2f(5.02, 0.82);
    glVertex2f(5.02, 0.58);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(69,118,247);
    glVertex2f(4.8, 0.6);
    glVertex2f(4.8, 0.8);
    glVertex2f(5, 0.8);
    glVertex2f(5, 0.6);
    glEnd();

    Line(4.9, 0.58,4.9, 0.82);



    glPopMatrix();

}

void HOUSE2(float x, float y, float z , float a, float b, float c)//HUS11
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(x, y, z);
    glTranslatef(a, b, c);

    if(day){

    glBegin(GL_QUADS);
    glColor3ub(55,55,57);
    glVertex2f(3.8, 0.35);
    glVertex2f(3.8, 0.4);
    glVertex2f(6, 0.4);
    glVertex2f(6, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 198, 39);
    glVertex2f(4, 0.4);
    glVertex2f(4, 1.5);
    glVertex2f(4.6, 1.5);
    glVertex2f(4.6, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 198, 39);
    glVertex2f(4.6, 0.4);
    glVertex2f(4.6, 1.8);
    glVertex2f(5.2, 1.8);
    glVertex2f(5.2, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 198, 39);
    glVertex2f(5.2, 0.4);
    glVertex2f(5.2, 2.4);
    glVertex2f(5.8, 2.4);
    glVertex2f(5.8, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 198, 39);
    glVertex2f(5, 1.8);
    glVertex2f(5, 3);
    glVertex2f(5.2, 3);
    glVertex2f(5.2, 1.8);
    glEnd();

    Line(4.6, 0.4, 4.6, 1.81);
    Line(4, 0.4, 4, 1.5);

    Line(5, 1.82, 5, 3);
    Line(5.2, 0.4, 5.2, 3);
    Line(5.8, 0.4, 5.8, 2.4);

    glBegin(GL_TRIANGLES);
    glColor3ub(240, 150, 30);
    glVertex2f(5.2, 2.4);
    glVertex2f(5.5, 2.7);
    glVertex2f(5.8, 2.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(240, 150, 30);
    glVertex2f(4.6, 1.8);
    glVertex2f(4.9, 2.1);
    glVertex2f(5.2, 1.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(176, 99, 27);
    glVertex2f(3.9, 1.5);
    glVertex2f(3.9, 1.55);
    glVertex2f(4.6, 1.55);
    glVertex2f(4.6, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(176, 99, 27);
    glVertex2f(4.9, 3);
    glVertex2f(4.9, 3.05);
    glVertex2f(5.3, 3.05);
    glVertex2f(5.3, 3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(144, 50, 48);
    glVertex2f(4.5, 1.7);
    glVertex2f(4.45, 1.75);
    glVertex2f(4.9, 2.2);
    glVertex2f(4.9, 2.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(144, 50, 48);
    glVertex2f(4.9, 2.1);
    glVertex2f(4.9, 2.2);
    glVertex2f(5.35, 1.75);
    glVertex2f(5.3, 1.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(144, 50, 48);
    glVertex2f(5.1, 2.3);
    glVertex2f(5.05, 2.35);
    glVertex2f(5.5, 2.8);
    glVertex2f(5.5, 2.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(144, 50, 48);
    glVertex2f(5.5, 2.7);
    glVertex2f(5.5, 2.8);
    glVertex2f(5.95, 2.35);
    glVertex2f(5.9, 2.3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(144, 50, 48);
    glVertex2f(5, 3.05);
    glVertex2f(5.1, 3.2);
    glVertex2f(5.2, 3.05);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(4.08, 1.18);
    glVertex2f(4.08, 1.32);
    glVertex2f(4.52, 1.32);
    glVertex2f(4.52, 1.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(69,118,247);
    glVertex2f(4.1, 1.2);
    glVertex2f(4.1, 1.3);
    glVertex2f(4.5, 1.3);
    glVertex2f(4.5, 1.2);
    glEnd();

    Line(4.23, 1.2, 4.23, 1.3);
    Line(4.37, 1.2, 4.37, 1.3);


    Line(4,0.9,4.6,0.9);
    Line(4.1, 0.85,4.5, 0.85);

    glBegin(GL_QUADS);
    glColor3ub(84, 85, 90);
    glVertex2f(4.2, 0.4);
    glVertex2f(4.2, 0.8);
    glVertex2f(4.4, 0.8);
    glVertex2f(4.4, 0.4);
    glEnd();

    Circle(0.01, 4.24, 0.56, 220,220,220);

    glBegin(GL_QUADS);
    glColor3ub(84, 85, 90);
    glVertex2f(5.4, 0.4);
    glVertex2f(5.4, 0.8);
    glVertex2f(5.6, 0.8);
    glVertex2f(5.6, 0.4);
    glEnd();

    Circle(0.01, 5.43, 0.57, 220,220,220);

    glBegin(GL_QUADS);
    glColor3ub(50, 50, 50);
    glVertex2f(5.4, 0.9);
    glVertex2f(5.4, 1.3);
    glVertex2f(5.6, 1.3);
    glVertex2f(5.6, 0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 150, 30);
    glVertex2f(5.3, 0.90);
    glVertex2f(5.3, 1.05);
    glVertex2f(5.7, 1.05);
    glVertex2f(5.7, 0.90);
    glEnd();

    Line(5.2,0.9,5.8,0.9);

    Line(5.2,1.5,5.8,1.5);

    Window_House2(0,0,0);
    Window_House2(0,0.3,0);
    Window_House2(0,0.5,0);
    Window_House2(0,0.8,0);

    Window_House2(0.6,1.1,0);
    Window_House2(0.6,1.4,0);

    }
    else{

    glBegin(GL_QUADS);
    glColor3ub(55,55,57);
    glVertex2f(3.8, 0.35);
    glVertex2f(3.8, 0.4);
    glVertex2f(6, 0.4);
    glVertex2f(6, 0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 150, 30);
    glVertex2f(4, 0.4);
    glVertex2f(4, 1.5);
    glVertex2f(4.6, 1.5);
    glVertex2f(4.6, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 150, 30);
    glVertex2f(4.6, 0.4);
    glVertex2f(4.6, 1.8);
    glVertex2f(5.2, 1.8);
    glVertex2f(5.2, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 150, 30);
    glVertex2f(5.2, 0.4);
    glVertex2f(5.2, 2.4);
    glVertex2f(5.8, 2.4);
    glVertex2f(5.8, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 150, 30);
    glVertex2f(5, 1.8);
    glVertex2f(5, 3);
    glVertex2f(5.2, 3);
    glVertex2f(5.2, 1.8);
    glEnd();

    Line(4.6, 0.4, 4.6, 1.81);
    Line(4, 0.4, 4, 1.5);

    Line(5, 1.82, 5, 3);
    Line(5.2, 0.4, 5.2, 3);
    Line(5.8, 0.4, 5.8, 2.4);

    glBegin(GL_TRIANGLES);
    glColor3ub(227, 116, 26);
    glVertex2f(5.2, 2.4);
    glVertex2f(5.5, 2.7);
    glVertex2f(5.8, 2.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(227, 116, 26);
    glVertex2f(4.6, 1.8);
    glVertex2f(4.9, 2.1);
    glVertex2f(5.2, 1.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(176, 99, 27);
    glVertex2f(3.9, 1.5);
    glVertex2f(3.9, 1.55);
    glVertex2f(4.6, 1.55);
    glVertex2f(4.6, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(176, 99, 27);
    glVertex2f(4.9, 3);
    glVertex2f(4.9, 3.05);
    glVertex2f(5.3, 3.05);
    glVertex2f(5.3, 3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(144, 50, 48);
    glVertex2f(4.5, 1.7);
    glVertex2f(4.45, 1.75);
    glVertex2f(4.9, 2.2);
    glVertex2f(4.9, 2.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(144, 50, 48);
    glVertex2f(4.9, 2.1);
    glVertex2f(4.9, 2.2);
    glVertex2f(5.35, 1.75);
    glVertex2f(5.3, 1.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(144, 50, 48);
    glVertex2f(5.1, 2.3);
    glVertex2f(5.05, 2.35);
    glVertex2f(5.5, 2.8);
    glVertex2f(5.5, 2.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(144, 50, 48);
    glVertex2f(5.5, 2.7);
    glVertex2f(5.5, 2.8);
    glVertex2f(5.95, 2.35);
    glVertex2f(5.9, 2.3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(144, 50, 48);
    glVertex2f(5, 3.05);
    glVertex2f(5.1, 3.2);
    glVertex2f(5.2, 3.05);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(4.08, 1.18);
    glVertex2f(4.08, 1.32);
    glVertex2f(4.52, 1.32);
    glVertex2f(4.52, 1.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(69,118,247);
    glVertex2f(4.1, 1.2);
    glVertex2f(4.1, 1.3);
    glVertex2f(4.5, 1.3);
    glVertex2f(4.5, 1.2);
    glEnd();

    Line(4.23, 1.2, 4.23, 1.3);
    Line(4.37, 1.2, 4.37, 1.3);


    Line(4,0.9,4.6,0.9);
    Line(4.1, 0.85,4.5, 0.85);

    glBegin(GL_QUADS);
    glColor3ub(84, 85, 90);
    glVertex2f(4.2, 0.4);
    glVertex2f(4.2, 0.8);
    glVertex2f(4.4, 0.8);
    glVertex2f(4.4, 0.4);
    glEnd();

    Circle(0.01, 4.24, 0.56, 220,220,220);

    glBegin(GL_QUADS);
    glColor3ub(84, 85, 90);
    glVertex2f(5.4, 0.4);
    glVertex2f(5.4, 0.8);
    glVertex2f(5.6, 0.8);
    glVertex2f(5.6, 0.4);
    glEnd();

    Circle(0.01, 5.43, 0.57, 220,220,220);

    glBegin(GL_QUADS);
    glColor3ub(50, 50, 50);
    glVertex2f(5.4, 0.9);
    glVertex2f(5.4, 1.3);
    glVertex2f(5.6, 1.3);
    glVertex2f(5.6, 0.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 116, 26);
    glVertex2f(5.3, 0.90);
    glVertex2f(5.3, 1.05);
    glVertex2f(5.7, 1.05);
    glVertex2f(5.7, 0.90);
    glEnd();

    Line(5.2,0.9,5.8,0.9);

    Line(5.2,1.5,5.8,1.5);

    Window_House2(0,0,0);
    Window_House2(0,0.3,0);
    Window_House2(0,0.5,0);
    Window_House2(0,0.8,0);

    Window_House2(0.6,1.1,0);
    Window_House2(0.6,1.4,0);

    }
    glPopMatrix();

}

void House3Window1(float x, float y, float z){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);

    glBegin(GL_POLYGON);
    glColor3ub(247, 214, 135);
    glVertex2f(-6.35, 1.15);
    glVertex2f(-6.35, 1.2);
    glVertex2f(-5.85, 1.2);
    glVertex2f(-5.85, 1.15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(247, 214, 135);
    glVertex2f(-6.3, 1.15);
    glVertex2f(-6.3, 1.85);
    glVertex2f(-5.9, 1.85);
    glVertex2f(-5.9, 1.15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(69,118,247);
    glVertex2f(-6.25, 1.2);
    glVertex2f(-6.25, 1.8);
    glVertex2f(-5.95, 1.8);
    glVertex2f(-5.95, 1.2);
    glEnd();

    Line(-6.25, 1.2, -6.25, 1.8);
    Line(-6.25, 1.2, -5.95, 1.2);
    Line(-6.25, 1.8, -5.95, 1.8);
    Line(-5.95, 1.8, -5.95, 1.2);
    Line(-6.1, 1.2, -6.1, 1.8);
    Line(-6.25, 1.4, -5.95, 1.4);
    Line(-6.25, 1.6, -5.95, 1.6);

    glPopMatrix();
}

void House3Window2(float x, float y, float z){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);

    glBegin(GL_POLYGON);
    glColor3ub(240, 240, 240);
    glVertex2f(-8.04, 2.86);
    glVertex2f(-8.04, 2.9);
    glVertex2f(-7.71, 2.9);
    glVertex2f(-7.71, 2.86);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(240, 240, 240);
    glVertex2f(-8.04, 2.88);
    glVertex2f(-8.04, 3.54);
    glVertex2f(-7.71, 3.54);
    glVertex2f(-7.71, 2.88);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(69,118,247);
    glVertex2f(-8, 2.9);
    glVertex2f(-8, 3.5);
    glVertex2f(-7.75, 3.5);
    glVertex2f(-7.75, 2.9);
    glEnd();

    Line(-8, 2.9, -8, 3.5);
    Line(-8, 2.9, -7.75, 2.9);
    Line(-8, 3.5, -7.75, 3.5);
    Line(-7.75, 3.5,-7.75, 2.9);
    Line(-8, 3.1, -7.75, 3.1);
    Line(-8, 3.3, -7.75, 3.3);

    glPopMatrix();
}

void House3Pillar(float x, float y, float z, float r, float g, float b){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(-6.8, 0.6);
    glVertex2f(-6.8, 0.75);
    glVertex2f(-6.5, 0.75);
    glVertex2f(-6.5, 0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 0, 0);
    glVertex2f(-6.8, 0.75);
    glVertex2f(-6.8, 0.85);
    glVertex2f(-6.5, 0.85);
    glVertex2f(-6.5, 0.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(-6.8, 0.85);
    glVertex2f(-6.75, 0.95);
    glVertex2f(-6.55, 0.95);
    glVertex2f(-6.5, 0.85);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(-6.75, 0.95);
    glVertex2f(-6.75, 2);
    glVertex2f(-6.55, 2);
    glVertex2f(-6.55, 0.95);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 0, 0);
    glVertex2f(-6.78, 2);
    glVertex2f(-6.78, 2.1);
    glVertex2f(-6.52, 2.1);
    glVertex2f(-6.52, 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(-6.8, 2.1);
    glVertex2f(-6.8, 2.2);
    glVertex2f(-6.5, 2.2);
    glVertex2f(-6.5, 2.1);
    glEnd();

    glPopMatrix();
}

void HOUSE3(float x, float y, float z , float a, float b, float c)//HUS12
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(x, y, z);
    glTranslatef(a, b, c);
    if(day){

        glBegin(GL_POLYGON);
        glColor3ub(173, 87, 54);
        glVertex2f(-9.1, 0.3);
        glVertex2f(-9.1, 0.6);
        glVertex2f(-5.5, 0.6);
        glVertex2f(-5.5, 0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(188, 188, 188);
        glVertex2f(-7.9, 0.3);
        glVertex2f(-7.9, 0.4);
        glVertex2f(-6.7, 0.4);
        glVertex2f(-6.7, 0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(217, 217, 217);
        glVertex2f(-7.8, 0.4);
        glVertex2f(-7.8, 0.5);
        glVertex2f(-6.8, 0.5);
        glVertex2f(-6.8, 0.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.7, 0.5);
        glVertex2f(-7.7, 0.6);
        glVertex2f(-6.9, 0.6);
        glVertex2f(-6.9, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(218, 111, 69);
        glVertex2f(-8.9, 0.6);
        glVertex2f(-8.9, 3.8);
        glVertex2f(-5.7, 3.8);
        glVertex2f(-5.7, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-9, 2.1);
        glVertex2f(-9, 2.2);
        glVertex2f(-8.1, 2.2);
        glVertex2f(-8.1, 2.1);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-6.5, 2.1);
        glVertex2f(-6.5, 2.2);
        glVertex2f(-5.6, 2.2);
        glVertex2f(-5.6, 2.1);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-9, 3.8);
        glVertex2f(-9, 3.9);
        glVertex2f(-5.6, 3.9);
        glVertex2f(-5.6, 3.8);
        glEnd();

        House3Pillar(0, 0, 0, 247, 214, 135);
        House3Pillar(-1.3, 0, 0, 247, 214, 135);

        House3Window1(0, 0, 0);
        House3Window1(-2.4, 0, 0);
        House3Window1(0, 1.6, 0);
        House3Window1(-2.4, 1.6, 0);

        glBegin(GL_POLYGON);
        glColor3ub(247, 214, 135);
        glVertex2f(-8.1, 2.2);
        glVertex2f(-8.1, 3.8);
        glVertex2f(-7.3, 4.4);
        glVertex2f(-6.5, 3.8);
        glVertex2f(-6.5, 2.2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-8.08, 2.2);
        glVertex2f(-8.08, 2.3);
        glVertex2f(-6.55, 2.3);
        glVertex2f(-6.55, 2.2);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(45, 12, 81);
        glVertex2f(-8.3, 2.04);
        glVertex2f(-8.34, 2.1);
        glVertex2f(-7.3, 2.9);
        glVertex2f(-7.3, 2.8);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(45, 12, 81);
        glVertex2f(-7.3, 2.8);
        glVertex2f(-7.3, 2.9);
        glVertex2f(-6.26, 2.1);
        glVertex2f(-6.32, 2.04);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-8.28, 2.01);
        glVertex2f(-8.3, 2.04);
        glVertex2f(-7.3, 2.8);
        glVertex2f(-7.3, 2.765);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.3, 2.765);
        glVertex2f(-7.3, 2.8);
        glVertex2f(-6.32, 2.04);
        glVertex2f(-6.345, 2.015);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(114, 75, 122);
        glVertex2f(-9, 3.9);
        glVertex2f(-8.6, 4.4);
        glVertex2f(-6, 4.4);
        glVertex2f(-5.6, 3.9);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(247, 214, 135);
        glVertex2f(-8.1, 3.9);
        glVertex2f(-7.3, 4.4);
        glVertex2f(-6.5, 3.9);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(45, 16, 74);
        glVertex2f(-8.2, 3.6);
        glVertex2f(-8.3, 3.7);
        glVertex2f(-7.3, 4.6);
        glVertex2f(-7.3, 4.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(45, 16, 74);
        glVertex2f(-7.3, 4.4);
        glVertex2f(-7.3, 4.6);
        glVertex2f(-6.3, 3.7);
        glVertex2f(-6.4, 3.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-8.2, 3.6);
        glVertex2f(-8.25, 3.65);
        glVertex2f(-7.3, 4.48);
        glVertex2f(-7.3, 4.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.3, 4.4);
        glVertex2f(-7.3, 4.48);
        glVertex2f(-6.35, 3.65);
        glVertex2f(-6.4, 3.6);
        glEnd();

        House3Window2(0, 0, 0);
        House3Window2(1.14, 0, 0);

        Circle(0.24 ,-7.3, 3.4,255,0,0);
        Circle(0.23 ,-7.3, 3.4,240, 240, 240);
        Circle(0.2 ,-7.3, 3.4,69,118,247);

        Line(-7.5, 3.4, -7.1, 3.4);
        Line(-7.3, 3.2, -7.3, 3.6);

        glBegin(GL_POLYGON);
        glColor3ub(228, 116, 78);
        glVertex2f(-6.6, 4.2);
        glVertex2f(-6.6, 4.9);
        glVertex2f(-6.4, 5.1);
        glVertex2f(-6.2, 4.9);
        glVertex2f(-6.2, 4.2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(247, 214, 135);
        glVertex2f(-6.7, 4.7);
        glVertex2f(-6.7, 4.9);
        glVertex2f(-6.1, 4.9);
        glVertex2f(-6.1, 4.7);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(247, 214, 135);
        glVertex2f(-7.65, 0.6);
        glVertex2f(-7.65, 1.9);
        glVertex2f(-6.95, 1.9);
        glVertex2f(-6.95, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(117, 43, 56);
        glVertex2f(-7.6, 0.6);
        glVertex2f(-7.6, 1.85);
        glVertex2f(-7, 1.85);
        glVertex2f(-7, 0.6);
        glEnd();

        Circle(0.05, -7.45, 1.4, 240, 240, 240);
    }
    else{

        glBegin(GL_POLYGON);
        glColor3ub(173, 87, 54);
        glVertex2f(-9.1, 0.3);
        glVertex2f(-9.1, 0.6);
        glVertex2f(-5.5, 0.6);
        glVertex2f(-5.5, 0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(188, 188, 188);
        glVertex2f(-7.9, 0.3);
        glVertex2f(-7.9, 0.4);
        glVertex2f(-6.7, 0.4);
        glVertex2f(-6.7, 0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(217, 217, 217);
        glVertex2f(-7.8, 0.4);
        glVertex2f(-7.8, 0.5);
        glVertex2f(-6.8, 0.5);
        glVertex2f(-6.8, 0.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.7, 0.5);
        glVertex2f(-7.7, 0.6);
        glVertex2f(-6.9, 0.6);
        glVertex2f(-6.9, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(218, 111, 69);
        glVertex2f(-8.9, 0.6);
        glVertex2f(-8.9, 3.8);
        glVertex2f(-5.7, 3.8);
        glVertex2f(-5.7, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-9, 2.1);
        glVertex2f(-9, 2.2);
        glVertex2f(-8.1, 2.2);
        glVertex2f(-8.1, 2.1);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-6.5, 2.1);
        glVertex2f(-6.5, 2.2);
        glVertex2f(-5.6, 2.2);
        glVertex2f(-5.6, 2.1);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-9, 3.8);
        glVertex2f(-9, 3.9);
        glVertex2f(-5.6, 3.9);
        glVertex2f(-5.6, 3.8);
        glEnd();

        House3Pillar(0, 0, 0, 247, 214, 135);
        House3Pillar(-1.3, 0, 0, 247, 214, 135);

        House3Window1(0, 0, 0);
        House3Window1(-2.4, 0, 0);
        House3Window1(0, 1.6, 0);
        House3Window1(-2.4, 1.6, 0);

        glBegin(GL_POLYGON);
        glColor3ub(230, 165, 107);
        glVertex2f(-8.1, 2.2);
        glVertex2f(-8.1, 3.8);
        glVertex2f(-7.3, 4.4);
        glVertex2f(-6.5, 3.8);
        glVertex2f(-6.5, 2.2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-8.08, 2.2);
        glVertex2f(-8.08, 2.3);
        glVertex2f(-6.55, 2.3);
        glVertex2f(-6.55, 2.2);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(45, 12, 81);
        glVertex2f(-8.3, 2.04);
        glVertex2f(-8.34, 2.1);
        glVertex2f(-7.3, 2.9);
        glVertex2f(-7.3, 2.8);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(45, 12, 81);
        glVertex2f(-7.3, 2.8);
        glVertex2f(-7.3, 2.9);
        glVertex2f(-6.26, 2.1);
        glVertex2f(-6.32, 2.04);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-8.28, 2.01);
        glVertex2f(-8.3, 2.04);
        glVertex2f(-7.3, 2.8);
        glVertex2f(-7.3, 2.765);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.3, 2.765);
        glVertex2f(-7.3, 2.8);
        glVertex2f(-6.32, 2.04);
        glVertex2f(-6.345, 2.015);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(114, 75, 122);
        glVertex2f(-9, 3.9);
        glVertex2f(-8.6, 4.4);
        glVertex2f(-6, 4.4);
        glVertex2f(-5.6, 3.9);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(230, 165, 107);
        glVertex2f(-8.1, 3.9);
        glVertex2f(-7.3, 4.4);
        glVertex2f(-6.5, 3.9);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(45, 16, 74);
        glVertex2f(-8.2, 3.6);
        glVertex2f(-8.3, 3.7);
        glVertex2f(-7.3, 4.6);
        glVertex2f(-7.3, 4.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(45, 16, 74);
        glVertex2f(-7.3, 4.4);
        glVertex2f(-7.3, 4.6);
        glVertex2f(-6.3, 3.7);
        glVertex2f(-6.4, 3.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-8.2, 3.6);
        glVertex2f(-8.25, 3.65);
        glVertex2f(-7.3, 4.48);
        glVertex2f(-7.3, 4.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.3, 4.4);
        glVertex2f(-7.3, 4.48);
        glVertex2f(-6.35, 3.65);
        glVertex2f(-6.4, 3.6);
        glEnd();

        House3Window2(0, 0, 0);
        House3Window2(1.14, 0, 0);

        Circle(0.24 ,-7.3, 3.4,255,0,0);
        Circle(0.23 ,-7.3, 3.4,240, 240, 240);
        Circle(0.2 ,-7.3, 3.4,69,118,247);

        Line(-7.5, 3.4, -7.1, 3.4);
        Line(-7.3, 3.2, -7.3, 3.6);

        glBegin(GL_POLYGON);
        glColor3ub(228, 116, 78);
        glVertex2f(-6.6, 4.2);
        glVertex2f(-6.6, 4.9);
        glVertex2f(-6.4, 5.1);
        glVertex2f(-6.2, 4.9);
        glVertex2f(-6.2, 4.2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(247, 214, 135);
        glVertex2f(-6.7, 4.7);
        glVertex2f(-6.7, 4.9);
        glVertex2f(-6.1, 4.9);
        glVertex2f(-6.1, 4.7);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(247, 214, 135);
        glVertex2f(-7.65, 0.6);
        glVertex2f(-7.65, 1.9);
        glVertex2f(-6.95, 1.9);
        glVertex2f(-6.95, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(117, 43, 56);
        glVertex2f(-7.6, 0.6);
        glVertex2f(-7.6, 1.85);
        glVertex2f(-7, 1.85);
        glVertex2f(-7, 0.6);
        glEnd();

        Circle(0.05, -7.45, 1.4, 240, 240, 240);

    }
    glPopMatrix();
    glPopMatrix();
}

void School_Window(float x, float y, float z){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_POLYGON);
    glColor3ub(0, 0 ,0);
    glVertex2f(-4.42, 1.88);
    glVertex2f(-4.42, 2.32);
    glVertex2f(-3.98, 2.32);
    glVertex2f(-3.98, 1.88);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(69,118,247);
    glVertex2f(-4.4, 1.9);
    glVertex2f(-4.4, 2.3);
    glVertex2f(-4, 2.3);
    glVertex2f(-4, 1.9);
    glEnd();

    Line(-4.2, 1.9, -4.2, 2.3);

    glPopMatrix();

}

void School_Line(float x1, float y1, float x2, float y2, float r, float g, float b)
{
    glColor3ub(r, g, b);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

float _secondAngle = 0.0f;
float _minuteAngle = 0.0f;
float _hourAngle = 0.0f;

void School_Clock(float x, float y, float z){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);

    Circle(0.22, -3.4, 3.1, 0, 0, 0);
    Circle(0.2, -3.4, 3.1, 255, 255, 255);

    // HOUR HAND
    glPushMatrix();
    glTranslatef(-3.4, 3.1, 0);        // Move to clock center
    glRotatef(_hourAngle, 0, 0, 1);    // Rotate around center
    glTranslatef(3.4, -3.1, 0);        // Move back

    School_Line(-3.4, 3.1, -3.4, 3.26, 0, 0, 0);
    School_Line(-3.39, 3.1, -3.39, 3.26, 0, 0, 0);
    glPopMatrix();

    // MINUTE HAND
    glPushMatrix();
    glTranslatef(-3.4, 3.1, 0);
    glRotatef(_minuteAngle, 0, 0, 1);
    glTranslatef(3.4, -3.1, 0);
    School_Line(-3.4, 3.11, -3.22, 3.11, 0, 0, 0);
    School_Line(-3.4, 3.10, -3.22, 3.10, 0, 0, 0);
    glPopMatrix();

    // SECOND HAND
    glPushMatrix();
    glTranslatef(-3.4, 3.1, 0);
    glRotatef(_secondAngle, 0, 0, 1);
    glTranslatef(3.4, -3.1, 0);
    School_Line(-3.4, 2.91, -3.4, 3.1, 255, 0, 0);
    School_Line(-3.39, 2.91, -3.39, 3.1, 255, 0, 0);
    glPopMatrix();

    // Center Dot
    Circle(0.03, -3.4, 3.1, 0, 0, 0);

    glPopMatrix();
}

void School_Clock_update(int value)//USCLC05
{
    _secondAngle -= 6.0f;    // Clockwise
    _minuteAngle -= 3.0f;    // Clockwise
    _hourAngle   -= 1.0f;    // Clockwise

    if (_secondAngle <= -360.0f) _secondAngle += 360.0f;
    if (_minuteAngle <= -360.0f) _minuteAngle += 360.0f;
    if (_hourAngle   <= -360.0f) _hourAngle += 360.0f;

    glutPostRedisplay();
    glutTimerFunc(1000, School_Clock_update, 0);
}

void SCHOOL(float x, float y, float z , float a, float b, float c)//SCL13
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(x, y, z);
    glTranslatef(a, b, c);

    if(day){

        glBegin(GL_POLYGON);
        glColor3ub(173, 87, 54);
        glVertex2f(-4.9, 0.3);
        glVertex2f(-4.9, 0.6);
        glVertex2f(-1.9, 0.6);
        glVertex2f(-1.9, 0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(199, 41, 38);
        glVertex2f(-4.7, 0.6);
        glVertex2f(-4.7, 0.7);
        glVertex2f(-2.1, 0.7);
        glVertex2f(-2.1, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(250, 171, 26);
        glVertex2f(-4.6, 0.7);
        glVertex2f(-4.6, 2.5);
        glVertex2f(-2.2, 2.5);
        glVertex2f(-2.2, 0.7);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(199, 41, 38);
        glVertex2f(-4.7, 1.6);
        glVertex2f(-4.7, 1.7);
        glVertex2f(-2.1, 1.7);
        glVertex2f(-2.1, 1.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(199, 41, 38);
        glVertex2f(-4.7, 2.5);
        glVertex2f(-4.7, 2.6);
        glVertex2f(-2.1, 2.6);
        glVertex2f(-2.1, 2.5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(199, 41, 38);
        glVertex2f(-3.9, 3.4);
        glVertex2f(-3.9, 3.5);
        glVertex2f(-2.9, 3.5);
        glVertex2f(-2.9, 3.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 192, 56);
        glVertex2f(-3.8, 0.6);
        glVertex2f(-3.8, 3.4);
        glVertex2f(-3, 3.4);
        glVertex2f(-3, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(189, 189, 189);
        glVertex2f(-3.9, 0.3);
        glVertex2f(-3.9, 0.4);
        glVertex2f(-2.9, 0.4);
        glVertex2f(-2.9, 0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(217, 217, 217);
        glVertex2f(-3.8, 0.4);
        glVertex2f(-3.8, 0.5);
        glVertex2f(-3, 0.5);
        glVertex2f(-3, 0.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(245, 245, 245);
        glVertex2f(-3.7, 0.5);
        glVertex2f(-3.7, 0.6);
        glVertex2f(-3.1, 0.6);
        glVertex2f(-3.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(206, 122, 86);
        glVertex2f(-3.6, 0.6);
        glVertex2f(-3.6, 1.4);
        glVertex2f(-3.2, 1.4);
        glVertex2f(-3.2, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(69,118,247);
        glVertex2f(-3.55, 0.65);
        glVertex2f(-3.55, 1.35);
        glVertex2f(-3.45, 1.35);
        glVertex2f(-3.45, 0.65);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(69,118,247);
        glVertex2f(-3.35, 0.65);
        glVertex2f(-3.35, 1.35);
        glVertex2f(-3.25, 1.35);
        glVertex2f(-3.25, 0.65);
        glEnd();

        Line(-3.4, 0.6, -3.4, 1.4);
        Line(-3.6, 1.4, -3.2, 1.4);
        Line(-3.6, 0.6, -3.2, 0.6);
        Line(-3.6, 0.6, -3.6, 1.4);
        Line(-3.2, 0.6, -3.2, 1.4);

        Circle(0.015, -3.425, 1.025, 255, 255, 255);
        Circle(0.015, -3.375, 1.025, 255, 255, 255);

        glBegin(GL_POLYGON);
        glColor3ub(69,118,247);
        glVertex2f(-3.6, 1.6);
        glVertex2f(-3.6, 2.8);
        glVertex2f(-3.2, 2.8);
        glVertex2f(-3.2, 1.6);
        glEnd();

        Line(-3.6, 1.6, -3.6, 2.8);
        Line(-3.6, 1.6, -3.2, 1.6);
        Line(-3.6, 2.8, -3.2, 2.8);
        Line(-3.2, 1.6, -3.2, 2.8);
        Line(-3.4, 1.6, -3.4, 2.8);
        Line(-3.6, 1.8, -3.2, 1.8);
        Line(-3.6, 2, -3.2, 2);
        Line(-3.6, 2.2, -3.2, 2.2);
        Line(-3.6, 2.4, -3.2, 2.4);
        Line(-3.6, 2.6, -3.2, 2.6);

        School_Window(0, 0, 0);
        School_Window(0, -0.9, 0);
        School_Window(1.6, 0, 0);
        School_Window(1.6, -0.9, 0);

        School_Clock(0, 0, 0);
    }
    else{

        glBegin(GL_POLYGON);
        glColor3ub(173, 87, 54);
        glVertex2f(-4.9, 0.3);
        glVertex2f(-4.9, 0.6);
        glVertex2f(-1.9, 0.6);
        glVertex2f(-1.9, 0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(199, 41, 38);
        glVertex2f(-4.7, 0.6);
        glVertex2f(-4.7, 0.7);
        glVertex2f(-2.1, 0.7);
        glVertex2f(-2.1, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(250, 171, 26);
        glVertex2f(-4.6, 0.7);
        glVertex2f(-4.6, 2.5);
        glVertex2f(-2.2, 2.5);
        glVertex2f(-2.2, 0.7);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(199, 41, 38);
        glVertex2f(-4.7, 1.6);
        glVertex2f(-4.7, 1.7);
        glVertex2f(-2.1, 1.7);
        glVertex2f(-2.1, 1.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(199, 41, 38);
        glVertex2f(-4.7, 2.5);
        glVertex2f(-4.7, 2.6);
        glVertex2f(-2.1, 2.6);
        glVertex2f(-2.1, 2.5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(199, 41, 38);
        glVertex2f(-3.9, 3.4);
        glVertex2f(-3.9, 3.5);
        glVertex2f(-2.9, 3.5);
        glVertex2f(-2.9, 3.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(235, 142, 46);
        glVertex2f(-3.8, 0.6);
        glVertex2f(-3.8, 3.4);
        glVertex2f(-3, 3.4);
        glVertex2f(-3, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(189, 189, 189);
        glVertex2f(-3.9, 0.3);
        glVertex2f(-3.9, 0.4);
        glVertex2f(-2.9, 0.4);
        glVertex2f(-2.9, 0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(217, 217, 217);
        glVertex2f(-3.8, 0.4);
        glVertex2f(-3.8, 0.5);
        glVertex2f(-3, 0.5);
        glVertex2f(-3, 0.4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(245, 245, 245);
        glVertex2f(-3.7, 0.5);
        glVertex2f(-3.7, 0.6);
        glVertex2f(-3.1, 0.6);
        glVertex2f(-3.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(206, 122, 86);
        glVertex2f(-3.6, 0.6);
        glVertex2f(-3.6, 1.4);
        glVertex2f(-3.2, 1.4);
        glVertex2f(-3.2, 0.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(69,118,247);
        glVertex2f(-3.55, 0.65);
        glVertex2f(-3.55, 1.35);
        glVertex2f(-3.45, 1.35);
        glVertex2f(-3.45, 0.65);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(69,118,247);
        glVertex2f(-3.35, 0.65);
        glVertex2f(-3.35, 1.35);
        glVertex2f(-3.25, 1.35);
        glVertex2f(-3.25, 0.65);
        glEnd();

        Line(-3.4, 0.6, -3.4, 1.4);
        Line(-3.6, 1.4, -3.2, 1.4);
        Line(-3.6, 0.6, -3.2, 0.6);
        Line(-3.6, 0.6, -3.6, 1.4);
        Line(-3.2, 0.6, -3.2, 1.4);

        Circle(0.015, -3.425, 1.025, 255, 255, 255);
        Circle(0.015, -3.375, 1.025, 255, 255, 255);

        glBegin(GL_POLYGON);
        glColor3ub(69,118,247);
        glVertex2f(-3.6, 1.6);
        glVertex2f(-3.6, 2.8);
        glVertex2f(-3.2, 2.8);
        glVertex2f(-3.2, 1.6);
        glEnd();

        Line(-3.6, 1.6, -3.6, 2.8);
        Line(-3.6, 1.6, -3.2, 1.6);
        Line(-3.6, 2.8, -3.2, 2.8);
        Line(-3.2, 1.6, -3.2, 2.8);
        Line(-3.4, 1.6, -3.4, 2.8);
        Line(-3.6, 1.8, -3.2, 1.8);
        Line(-3.6, 2, -3.2, 2);
        Line(-3.6, 2.2, -3.2, 2.2);
        Line(-3.6, 2.4, -3.2, 2.4);
        Line(-3.6, 2.6, -3.2, 2.6);

        School_Window(0, 0, 0);
        School_Window(0, -0.9, 0);
        School_Window(1.6, 0, 0);
        School_Window(1.6, -0.9, 0);

        School_Clock(0, 0, 0);
    }
    glPopMatrix();
}

//All House, School, Tower & Turbine
void Wind_Turbine()
{
    wind_turbine(1, 1.2, 1, -0.5, 0.5, 0);
    wind_turbine(1, 1.2, 1, -2.1, 0.5, 0);

    wind_turbine(1, 1.2, 1, 0.3, 0, 0);
    wind_turbine(1, 1.2, 1, -1.3, 0, 0);

    wind_turbine(1, 1.2, 1, -16.8, 0.5, 0);
    wind_turbine(1, 1.2, 1, -18.3, 0.5, 0);

    wind_turbine(1, 1.2, 1, -16, 0, 0);
    wind_turbine(1, 1.2, 1, -17.6, 0, 0);
}

void House2()
{
    HOUSE2(1, 1, 1, 0, 0, 0);
}

void House1()
{
    HOUSE1(1.15, 1.15, 1, 0, 0, 0);
}

void Tower()
{
    TOWER(1, 1, 1, 0.2, 0, 0);
}

void School()
{
    SCHOOL(0.8, 0.8, 1, 0.5, 0.18, 0);
}

void House3()
{
    HOUSE3(0.6, 0.6, 0.6, -1.5, 0.38, 0);
}

void Road()//ROD14
{

    glBegin(GL_QUADS); //road
    glColor3ub(71,72,76);
    glVertex2f(-10,-2.5);
    glVertex2f(-10,-0.5);
    glVertex2f(10,-0.5);
    glVertex2f(10,-2.5);
    glEnd();

    glBegin(GL_QUADS); //road side walk way 1
    glColor3ub(204,204,188);
    glVertex2f(-10,-3);
    glVertex2f(-10,-2.5);
    glVertex2f(10,-2.5);
    glVertex2f(10,-3);
    glEnd();

    glBegin(GL_QUADS); //road side walk way 2
    glColor3ub(204,204,188);
    glVertex2f(-10,-0.5);
    glVertex2f(-10,0);
    glVertex2f(10,0);
    glVertex2f(10,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(235,232,226);
    glVertex2f(-9.8,-1.6);
    glVertex2f(-9.8,-1.4);
    glVertex2f(-8.2,-1.4);
    glVertex2f(-8.2,-1.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(235,232,226);
    glVertex2f(-7,-1.6);
    glVertex2f(-7,-1.4);
    glVertex2f(-5.4,-1.4);
    glVertex2f(-5.4,-1.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(235,232,226);
    glVertex2f(-4.2,-1.6);
    glVertex2f(-4.2,-1.4);
    glVertex2f(-2.8,-1.4);
    glVertex2f(-2.8,-1.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(235,232,226);
    glVertex2f(-0.4,-1.6);
    glVertex2f(-0.4,-1.4);
    glVertex2f(1.2,-1.4);
    glVertex2f(1.2,-1.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(235,232,226);
    glVertex2f(2.2,-1.6);
    glVertex2f(2.2,-1.4);
    glVertex2f(3.8,-1.4);
    glVertex2f(3.8,-1.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(235,232,226);
    glVertex2f(5,-1.6);
    glVertex2f(5,-1.4);
    glVertex2f(6.6,-1.4);
    glVertex2f(6.6,-1.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(235,232,226);
    glVertex2f(7.8,-1.6);
    glVertex2f(7.8,-1.4);
    glVertex2f(9.4,-1.4);
    glVertex2f(9.4,-1.6);
    glEnd();

    //zebra crossing
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-2,-2.5);
    glVertex2f(-2,-0.5);
    glVertex2f(-1.95,-0.5);
    glVertex2f(-1.95,-2.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-1.05,-2.5);
    glVertex2f(-1.05,-0.5);
    glVertex2f(-1,-0.5);
    glVertex2f(-1,-2.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-2,-2.4);
    glVertex2f(-2,-2.2);
    glVertex2f(-1,-2.2);
    glVertex2f(-1,-2.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-2,-2);
    glVertex2f(-2,-1.8);
    glVertex2f(-1,-1.8);
    glVertex2f(-1,-2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-2,-1.6);
    glVertex2f(-2,-1.4);
    glVertex2f(-1,-1.4);
    glVertex2f(-1,-1.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-2,-1.2);
    glVertex2f(-2,-1);
    glVertex2f(-1,-1);
    glVertex2f(-1,-1.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-2,-0.8);
    glVertex2f(-2,-0.6);
    glVertex2f(-1,-0.6);
    glVertex2f(-1,-0.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(120, 120, 120);
    glVertex2f(-10, -3.2);
    glVertex2f(-10, -3);
    glVertex2f(10, -3);
    glVertex2f(10, -3.2);
    glEnd();

}

void TRAFFIC_LIGHT(float x, float y, float z , float a, float b, float c)//TL16
{
       glMatrixMode(GL_MODELVIEW);
       glPushMatrix();
       glScalef(x, y, z);
       glTranslatef(a, b, c);

       glBegin(GL_QUADS);
       glColor3ub(50,50,50);
       glVertex2f(-0.86, -0.5);
       glVertex2f(-0.86, -0.48);
       glVertex2f(-0.79, -0.48);
       glVertex2f(-0.79, -0.5);
       glEnd();

       glBegin(GL_QUADS);
       glColor3ub(80,80,80);
       glVertex2f(-0.85, -0.5);
       glVertex2f(-0.85, 0.25);
       glVertex2f(-0.8, 0.25);
       glVertex2f(-0.8, -0.5);
       glEnd();

       glBegin(GL_QUADS);
       glColor3ub(45,45,45);
       glVertex2f(-0.9, -0.1);
       glVertex2f(-0.9, 0.25);
       glVertex2f(-0.75, 0.25);
       glVertex2f(-0.75, -0.1);
       glEnd();

       glBegin(GL_TRIANGLES);
       glColor3ub(50,50,50);
       glVertex2f(-0.9, 0.15);
       glVertex2f(-0.95, 0.2);
       glVertex2f(-0.9, 0.2);
       glEnd();

       glBegin(GL_TRIANGLES);
       glColor3ub(50,50,50);
       glVertex2f(-0.9, 0.05);
       glVertex2f(-0.95, 0.1);
       glVertex2f(-0.9, 0.1);
       glEnd();

       glBegin(GL_TRIANGLES);
       glColor3ub(50,50,50);
       glVertex2f(-0.9, -0.05);
       glVertex2f(-0.95, 0);
       glVertex2f(-0.9, 0);
       glEnd();

       glBegin(GL_TRIANGLES);
       glColor3ub(50,50,50);
       glVertex2f(-0.75, 0.15);
       glVertex2f(-0.75, 0.2);
       glVertex2f(-0.7, 0.2);
       glEnd();

       glBegin(GL_TRIANGLES);
       glColor3ub(50,50,50);
       glVertex2f(-0.75, 0.05);
       glVertex2f(-0.75, 0.1);
       glVertex2f(-0.7, 0.1);
       glEnd();

       glBegin(GL_TRIANGLES);
       glColor3ub(50,50,50);
       glVertex2f(-0.75, -0.05);
       glVertex2f(-0.75, 0);
       glVertex2f(-0.7, 0);
       glEnd();

       Circle(0.035, -0.825, 0.175, 255, 0, 0);
       Circle(0.035, -0.825, 0.075, 250, 167, 0);
       Circle(0.035, -0.825, -0.025, 0, 132, 80);

       glPopMatrix();

}

void Traffic_Light(){

    TRAFFIC_LIGHT(1, 1.5, 1, 0, 0, 0);

}

void Tree(float r, float g, float b, float x, float y, float z)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_POLYGON);
    glColor3ub(140,25,0);
    glVertex2f(-9,-0.2);
    glVertex2f(-9,0.2);
    glVertex2f(-8.9,0.2);
    glVertex2f(-8.9, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(r,g,b);
    glVertex2f(-9.2, 0.2);
    glVertex2f(-8.95, 0.4);
    glVertex2f(-8.7, 0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(r,g,b);
    glVertex2f(-9.2, 0.3);
    glVertex2f(-8.95, 0.5);
    glVertex2f(-8.7, 0.3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(r,g,b);
    glVertex2f(-9.2, 0.4);
    glVertex2f(-8.95, 0.6);
    glVertex2f(-8.7, 0.4);
    glEnd();

    glPopMatrix();
}

void Road_Side_Tree()//RST15
{

    if(day){
        Tree(23,178,79,0,0.2,0);
        Tree(23,178,79,3,0.2,0);
        Tree(23,178,79,6,0.2,0);
        Tree(23,178,79,10,0.2,0);
        Tree(23,178,79,12.5,0.2,0);
        Tree(23,178,79,15,0.2,0);
        Tree(23,178,79,17.5,0.2,0);
    }
    else{
        Tree(2,100,37,0,0.2,0);
        Tree(2,100,37,3,0.2,0);
        Tree(2,100,37,6,0.2,0);
        Tree(2,100,37,10,0.2,0);
        Tree(2,100,37,12.5,0.2,0);
        Tree(2,100,37,15,0.2,0);
        Tree(2,100,37,17.5,0.2,0);
    }
}

void Lamppost(float x, float y, float z, float r, float g, float b)//LMPL17
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);

    Circle(0.1 ,-7.9, -1.96, 144, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(-7.94, -2.12);
    glVertex2f(-7.985, -1.99);
    glVertex2f(-7.815, -1.99);
    glVertex2f(-7.86, -2.12);
    glEnd();

    Line(-7.95, -2.13, -7.85, -2.13);
    Line(-7.95, -2.1, -8, -1.98);
    Line(-8, -1.98, -7.8, -1.98);
    Line(-7.8, -1.98, -7.85, -2.13);
    Line(-7.9, -2.13, -7.9, -1.98);

    glBegin(GL_POLYGON);
    glColor3ub(144, 0, 0);
    glVertex2f(-7.95, -3);
    glVertex2f(-7.95, -2.65);
    glVertex2f(-7.85, -2.65);
    glVertex2f(-7.85, -3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(144, 0, 0);
    glVertex2f(-7.93, -2.63);
    glVertex2f(-7.93, -2.13);
    glVertex2f(-7.87, -2.13);
    glVertex2f(-7.87, -2.63);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(109, 2, 2);
    glVertex2f(-8, -3);
    glVertex2f(-8, -2.98);
    glVertex2f(-7.8, -2.98);
    glVertex2f(-7.8, -3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(109, 2, 2);
    glVertex2f(-7.98, -2.65);
    glVertex2f(-7.98, -2.63);
    glVertex2f(-7.82, -2.63);
    glVertex2f(-7.82, -2.65);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(109, 2, 2);
    glVertex2f(-7.96, -2.22);
    glVertex2f(-7.96, -2.18);
    glVertex2f(-7.84, -2.18);
    glVertex2f(-7.84, -2.22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(109, 2, 2);
    glVertex2f(-8.02, -1.98);
    glVertex2f(-8.02, -1.96);
    glVertex2f(-7.78, -1.96);
    glVertex2f(-7.78, -1.98);
    glEnd();

    Line(-7.9, -1.86, -7.9, -1.78);

    glPopMatrix();
}
void Lamppost_Light(){

    if(day){

        Lamppost(-0.4, 0, 0, 167, 199, 203);
        Lamppost(3.3,0 , 0, 167, 199, 203);
        Lamppost(7.3, 0, 0, 167, 199, 203);
        Lamppost(11.1, 0, 0, 167, 199, 203);
        Lamppost(15.5, 0, 0, 167, 199, 203);

        Lamppost(-0.4, 2.5, 0, 167, 199, 203);
        Lamppost(3.3, 2.5, 0, 167, 199, 203);
        Lamppost(7.3, 2.5, 0, 167, 199, 203);
        Lamppost(11.1, 2.5, 0, 167, 199, 203);
        Lamppost(15.5, 2.5, 0, 167, 199, 203);

    }
    else{

        Lamppost(-0.4, 0, 0, 247, 230, 204);
        Lamppost(3.3,0 , 0, 247, 230, 204);
        Lamppost(7.3, 0, 0, 247, 230, 204);
        Lamppost(11.1, 0, 0, 247, 230, 204);
        Lamppost(15.5, 0, 0, 247, 230, 204);

        Lamppost(-0.4, 2.5, 0, 247, 230, 204);
        Lamppost(3.3, 2.5, 0, 247, 230, 204);
        Lamppost(7.3, 2.5, 0, 247, 230, 204);
        Lamppost(11.1, 2.5, 0, 247, 230, 204);
        Lamppost(15.5, 2.5, 0, 247, 230, 204);
    }
}

float movecar1 = 0.0f;
void Car1()//CAR18
{

    if(day){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(movecar1,0,0);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(211,0,0);
    glVertex2f(2, -2.2);
    glVertex2f(2, -2.05);
    glVertex2f(2.1, -2);
    glVertex2f(2.3, -2);
    glVertex2f(2.6, -1.75);
    glVertex2f(3.15, -1.75);
    glVertex2f(3.4, -2);
    glVertex2f(3.6, -2);
    glVertex2f(3.6, -2.2);
    glEnd();

    Line(2.55, -2.05,3.1, -2.05);

    //glass1
    glBegin(GL_POLYGON);
    glColor3ub(25,55,110);
    glVertex2f(2.4, -2);
    glVertex2f(2.65, -1.85);
    glVertex2f(2.85, -1.85);
    glVertex2f(2.85, -2);
    glEnd();

    //glass2
    glBegin(GL_POLYGON);
    glColor3ub(25,55,110);
    glVertex2f(2.9, -2);
    glVertex2f(2.9, -1.85);
    glVertex2f(3.15, -1.85);
    glVertex2f(3.3, -2);
    glEnd();

    //tyre1
    Circle(0.12,2.35,-2.2,0,0,0);
    Circle(0.09,2.35,-2.2,117,117,117);

    //tyre2
    Circle(0.12,3.24,-2.2,0,0,0);
    Circle(0.09,3.24,-2.2,117,117,117);

    glPopMatrix();
    }

    else{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(movecar1,0,0);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(155,0,0);
    glVertex2f(2, -2.2);
    glVertex2f(2, -2.05);
    glVertex2f(2.1, -2);
    glVertex2f(2.3, -2);
    glVertex2f(2.6, -1.75);
    glVertex2f(3.15, -1.75);
    glVertex2f(3.4, -2);
    glVertex2f(3.6, -2);
    glVertex2f(3.6, -2.2);
    glEnd();

    Line(2.55, -2.05,3.1, -2.05);

    //glass1
    glBegin(GL_POLYGON);
    glColor3ub(25,55,110);
    glVertex2f(2.4, -2.);
    glVertex2f(2.65, -1.85);
    glVertex2f(2.85, -1.85);
    glVertex2f(2.85, -2);
    glEnd();

    //glass2
    glBegin(GL_POLYGON);
    glColor3ub(25,55,110);
    glVertex2f(2.9, -2);
    glVertex2f(2.9, -1.85);
    glVertex2f(3.15, -1.85);
    glVertex2f(3.3, -2);
    glEnd();

    //tyre1
    Circle(0.12,2.35,-2.2,0,0,0);
    Circle(0.09,2.35,-2.2,113,112,110);

    //tyre2
    Circle(0.12,3.24,-2.2,0,0,0);
    Circle(0.09,3.24,-2.2,113,112,110);

    glPopMatrix();
    }
}

bool Car1KeyMove = true;
void UpdateCar1(int value)//UCAR06
{

    float speed = 0.05f;
    float resetThreshold = -16.0f;
    float resetX = 16.0f;

    if(Car1KeyMove){
        movecar1 -= speed;
    }
    if (movecar1 < resetThreshold){
            movecar1 = resetX;
    }

    glutPostRedisplay();
    glutTimerFunc(20,UpdateCar1,0);
}

float movecar2 = 0.0f;
void Car2()//CAR19
{

    if(day){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(movecar2,0,0);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(227, 231, 234);
    glVertex2f(-6.14, -1);
    glVertex2f(-6.14, -0.8);
    glVertex2f(-5.9, -0.8);
    glVertex2f(-5.7, -0.6);
    glVertex2f(-5.3, -0.6);
    glVertex2f(-5.1, -0.8);
    glVertex2f(-4.9, -0.8);
    glVertex2f(-4.8, -0.85);
    glVertex2f(-4.8, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 107, 242);
    glVertex2f(-5.8, -0.95);
    glVertex2f(-5.8, -0.9);
    glVertex2f(-5.15, -0.9);
    glVertex2f(-5.15, -0.95);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(42, 55, 61);
    glVertex2f(-5.1, -0.8);
    glVertex2f(-4.9, -0.8);
    glVertex2f(-4.8, -0.85);
    glVertex2f(-4.8, -1);
    glVertex2f(-5.28, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(42, 55, 61);
    glVertex2f(-6.14, -1);
    glVertex2f(-6.14, -0.8);
    glVertex2f(-5.9, -0.8);
    glVertex2f(-5.7, -1);
    glEnd();

    //glass1
    glBegin(GL_POLYGON);
    glColor3ub(25,55,110);
    glVertex2f(-5.8, -0.8);
    glVertex2f(-5.65, -0.65);
    glVertex2f(-5.52, -0.65);
    glVertex2f(-5.52, -0.8);
    glEnd();

    //glass2
    glBegin(GL_POLYGON);
    glColor3ub(25,55,110);
    glVertex2f(-5.48, -0.8);
    glVertex2f(-5.48, -0.65);
    glVertex2f(-5.3, -0.65);
    glVertex2f(-5.16, -0.8);
    glEnd();

    //tyre1
    Circle(0.12,-5.86,-1,0,0,0);
    Circle(0.09,-5.86,-1,117,117,117);

    //tyre2
    Circle(0.12,-5.12,-1,0,0,0);
    Circle(0.09,-5.12,-1,117,117,117);

    glBegin(GL_POLYGON);
    glColor3ub(247, 77, 44);
    glVertex2f(-5.5, -0.6);
    glVertex2f(-5.5, -0.5);
    glVertex2f(-5.35, -0.5);
    glVertex2f(-5.35, -0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5, 147, 209);
    glVertex2f(-5.65, -0.6);
    glVertex2f(-5.65, -0.5);
    glVertex2f(-5.5, -0.5);
    glVertex2f(-5.5, -0.6);
    glEnd();

    glPopMatrix();
    }
    else{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(movecar2,0,0);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(200,200,200);
    glVertex2f(-6.14, -1);
    glVertex2f(-6.14, -0.8);
    glVertex2f(-5.9, -0.8);
    glVertex2f(-5.7, -0.6);
    glVertex2f(-5.3, -0.6);
    glVertex2f(-5.1, -0.8);
    glVertex2f(-4.9, -0.8);
    glVertex2f(-4.8, -0.85);
    glVertex2f(-4.8, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 9, 242);
    glVertex2f(-5.8, -0.95);
    glVertex2f(-5.8, -0.9);
    glVertex2f(-5.15, -0.9);
    glVertex2f(-5.15, -0.95);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(40, 40, 40);
    glVertex2f(-5.1, -0.8);
    glVertex2f(-4.9, -0.8);
    glVertex2f(-4.8, -0.85);
    glVertex2f(-4.8, -1);
    glVertex2f(-5.28, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(40,40,40);
    glVertex2f(-6.14, -1);
    glVertex2f(-6.14, -0.8);
    glVertex2f(-5.9, -0.8);
    glVertex2f(-5.7, -1);
    glEnd();

    //glass1
    glBegin(GL_POLYGON);
    glColor3ub(25,55,110);
    glVertex2f(-5.8, -0.8);
    glVertex2f(-5.65, -0.65);
    glVertex2f(-5.52, -0.65);
    glVertex2f(-5.52, -0.8);
    glEnd();

    //glass2
    glBegin(GL_POLYGON);
    glColor3ub(25,55,110);
    glVertex2f(-5.48, -0.8);
    glVertex2f(-5.48, -0.65);
    glVertex2f(-5.3, -0.65);
    glVertex2f(-5.16, -0.8);
    glEnd();

    //tyre1
    Circle(0.12,-5.86,-1,0,0,0);
    Circle(0.09,-5.86,-1,113,112,110);

    //tyre2
    Circle(0.12,-5.12,-1,0,0,0);
    Circle(0.09,-5.12,-1,113,112,110);

    glBegin(GL_POLYGON);
    glColor3ub(247, 77, 44);
    glVertex2f(-5.5, -0.6);
    glVertex2f(-5.5, -0.5);
    glVertex2f(-5.35, -0.5);
    glVertex2f(-5.35, -0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5, 147, 209);
    glVertex2f(-5.65, -0.6);
    glVertex2f(-5.65, -0.5);
    glVertex2f(-5.5, -0.5);
    glVertex2f(-5.5, -0.6);
    glEnd();

    glPopMatrix();
    }
}

bool Car2KeyMove = true;
void UpdateCar2(int value)//UCAR07
{

    float speed = 0.05f;
    float resetThreshold = 16.0f;
    float resetX = -16.0f;

    if(Car2KeyMove){
        movecar2 += speed;
    }
    if (movecar2 > resetThreshold){
            movecar2 = resetX;
    }

    glutPostRedisplay();
    glutTimerFunc(20,UpdateCar2,0);
}

void Bus1_Window(float x, float y, float z, float R, float G, float B){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(R, G, B);
    glVertex2f(2.95, -0.85);
    glVertex2f(2.95, -0.65);
    glVertex2f(3.1, -0.65);
    glVertex2f(3.1, -0.85);
    glEnd();

    Line(2.95, -0.85, 3.1, -0.85);
    Line(2.95, -0.85, 2.95, -0.65);
    Line(2.95, -0.65, 3.1, -0.65);
    Line(3.1, -0.65, 3.1, -0.85);

    glPopMatrix();

}

float movebus1 = 0.0f;
void Bus1()//BUS20
{
    if(day){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(movebus1,0,0);

    glBegin(GL_POLYGON);
    glColor3ub(252, 200, 48);
    glVertex2f(1.84, -1.2);
    glVertex2f(1.8, -1.16);
    glVertex2f(1.8, -0.64);
    glVertex2f(1.84, -0.6);
    glVertex2f(3.56, -0.6);
    glVertex2f(3.6, -0.64);
    glVertex2f(3.6, -0.86);
    glVertex2f(3.64, -0.9);
    glVertex2f(3.86, -0.9);
    glVertex2f(3.9, -0.94);
    glVertex2f(3.9, -1.16);
    glVertex2f(3.86, -1.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(21,102,86);
    glVertex2f(3.16, -1.2);
    glVertex2f(3.16, -0.66);
    glVertex2f(3.38, -0.66);
    glVertex2f(3.38, -1.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,202,204);
    glVertex2f(3.18, -0.84);
    glVertex2f(3.18, -0.7);
    glVertex2f(3.26, -0.7);
    glVertex2f(3.26, -0.84);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,202,204);
    glVertex2f(3.28, -0.84);
    glVertex2f(3.28, -0.7);
    glVertex2f(3.36, -0.7);
    glVertex2f(3.36, -0.84);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(46, 132, 102);
    glVertex2f(3.18, -1.12);
    glVertex2f(3.18, -0.88);
    glVertex2f(3.26, -0.88);
    glVertex2f(3.26, -1.12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(46, 132, 102);
    glVertex2f(3.28, -1.12);
    glVertex2f(3.28, -0.88);
    glVertex2f(3.36, -0.88);
    glVertex2f(3.36, -1.12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105, 202, 204);
    glVertex2f(3.52, -0.84);
    glVertex2f(3.52, -0.66);
    glVertex2f(3.6, -0.66);
    glVertex2f(3.6, -0.84);
    glEnd();

    Line(3.52, -0.84, 3.6, -0.84);
    Line(3.52, -0.84, 3.52, -0.66);
    Line(3.52, -0.66, 3.6, -0.66);

    Bus1_Window(0, 0, 0, 105, 202, 204);
    Bus1_Window(-0.20, 0, 0, 105, 202, 204);
    Bus1_Window(-0.40, 0, 0, 105, 202, 204);
    Bus1_Window(-0.60, 0, 0, 105, 202, 204);
    Bus1_Window(-0.80, 0, 0, 105, 202, 204);
    Bus1_Window(-1.00, 0, 0, 105, 202, 204);

    Line(3.45, -0.95, 3.8, -0.95);

    glBegin(GL_QUADS);
    glColor3ub(136, 96, 25);
    glVertex2f(1.85, -1.1);
    glVertex2f(1.85, -1.05);
    glVertex2f(3.1, -1.05);
    glVertex2f(3.1, -1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(136, 96, 25);
    glVertex2f(1.85, -0.95);
    glVertex2f(1.85, -0.9);
    glVertex2f(3.1, -0.9);
    glVertex2f(3.1, -0.95);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52, 47, 48);
    glVertex2f(1.84, -1.2);
    glVertex2f(1.8, -1.16);
    glVertex2f(3.9, -1.16);
    glVertex2f(3.86, -1.2);
    glEnd();

    Circle(0.18, 3.6, -1.2, 0, 0, 0);
    Circle(0.10, 3.6, -1.2, 114, 107, 104);
    Circle(0.18, 2.16, -1.2, 0, 0, 0);
    Circle(0.10, 2.16, -1.2, 114, 107, 104);

    glPopMatrix();
    }
    else{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(movebus1,0,0);

    glBegin(GL_POLYGON);
    glColor3ub(246, 169, 25);
    glVertex2f(1.84, -1.2);
    glVertex2f(1.8, -1.16);
    glVertex2f(1.8, -0.64);
    glVertex2f(1.84, -0.6);
    glVertex2f(3.56, -0.6);
    glVertex2f(3.6, -0.64);
    glVertex2f(3.6, -0.86);
    glVertex2f(3.64, -0.9);
    glVertex2f(3.86, -0.9);
    glVertex2f(3.9, -0.94);
    glVertex2f(3.9, -1.16);
    glVertex2f(3.86, -1.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(21,102,86);
    glVertex2f(3.16, -1.2);
    glVertex2f(3.16, -0.66);
    glVertex2f(3.38, -0.66);
    glVertex2f(3.38, -1.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73,185,191);
    glVertex2f(3.18, -0.84);
    glVertex2f(3.18, -0.7);
    glVertex2f(3.26, -0.7);
    glVertex2f(3.26, -0.84);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73,185,191);
    glVertex2f(3.28, -0.84);
    glVertex2f(3.28, -0.7);
    glVertex2f(3.36, -0.7);
    glVertex2f(3.36, -0.84);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(46, 132, 102);
    glVertex2f(3.18, -1.12);
    glVertex2f(3.18, -0.88);
    glVertex2f(3.26, -0.88);
    glVertex2f(3.26, -1.12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(46, 132, 102);
    glVertex2f(3.28, -1.12);
    glVertex2f(3.28, -0.88);
    glVertex2f(3.36, -0.88);
    glVertex2f(3.36, -1.12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(40, 167, 178);
    glVertex2f(3.52, -0.84);
    glVertex2f(3.52, -0.66);
    glVertex2f(3.6, -0.66);
    glVertex2f(3.6, -0.84);
    glEnd();

    Line(3.52, -0.84, 3.6, -0.84);
    Line(3.52, -0.84, 3.52, -0.66);
    Line(3.52, -0.66, 3.6, -0.66);

    Bus1_Window(0, 0, 0, 44, 169, 179);
    Bus1_Window(-0.20, 0, 0, 44, 169, 179);
    Bus1_Window(-0.40, 0, 0, 44, 169, 179);
    Bus1_Window(-0.60, 0, 0, 44, 169, 179);
    Bus1_Window(-0.80, 0, 0, 44, 169, 179);
    Bus1_Window(-1.00, 0, 0, 44, 169, 179);

    Line(3.45, -0.95, 3.8, -0.95);

    glBegin(GL_QUADS);
    glColor3ub(136, 96, 25);
    glVertex2f(1.85, -1.1);
    glVertex2f(1.85, -1.05);
    glVertex2f(3.1, -1.05);
    glVertex2f(3.1, -1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(136, 96, 25);
    glVertex2f(1.85, -0.95);
    glVertex2f(1.85, -0.9);
    glVertex2f(3.1, -0.9);
    glVertex2f(3.1, -0.95);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52, 47, 48);
    glVertex2f(1.84, -1.2);
    glVertex2f(1.8, -1.16);
    glVertex2f(3.9, -1.16);
    glVertex2f(3.86, -1.2);
    glEnd();

    Circle(0.18, 3.6, -1.2, 0, 0, 0);
    Circle(0.10, 3.6, -1.2, 114, 107, 104);
    Circle(0.18, 2.16, -1.2, 0, 0, 0);
    Circle(0.10, 2.16, -1.2, 114, 107, 104);

    glPopMatrix();
    }
}

bool Bus1KeyMove = true;
void UpdateBus1(int value)//UBUS08
{

    float speed = 0.05f;
    float resetThreshold = 16.0f;
    float resetX = -16.0f;

    if(Bus1KeyMove){
        movebus1 += speed;
    }
    if (movebus1 > resetThreshold){
            movebus1 = resetX;
    }

    glutPostRedisplay();
    glutTimerFunc(20,UpdateBus1,0);
}

float movebus2 = 0.0f;
void Bus2_window1(float x, float y, float z){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(44, 76, 144);
    glVertex2f(-5.9, -1.65);
    glVertex2f(-5.9, -1.45);
    glVertex2f(-5.75, -1.45);
    glVertex2f(-5.75, -1.65);
    glEnd();

    glPopMatrix();
}

void Bus2_window2(float x, float y, float z){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(44, 76, 144);
    glVertex2f(-5.5, -2);
    glVertex2f(-5.5, -1.86);
    glVertex2f(-5.38, -1.86);
    glVertex2f(-5.38, -2);
    glEnd();

    glPopMatrix();
}

void Bus2()//BUS21
{
    if(day){

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(movebus2,0,0);

        glBegin(GL_POLYGON);
        glColor3ub(214, 8, 2);
        glVertex2f(-5.96, -1.8);
        glVertex2f(-5.96, -1.46);
        glVertex2f(-5.86, -1.38);
        glVertex2f(-4, -1.38);
        glVertex2f(-3.9, -1.48);
        glVertex2f(-3.9, -1.8);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(214, 8, 2);
        glVertex2f(-6, -2.18);
        glVertex2f(-6, -2.07);
        glVertex2f(-5.96, -2.03);
        glVertex2f(-3.95, -2.03);
        glVertex2f(-3.95, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(214, 8, 2);
        glVertex2f(-5.94, -2.03);
        glVertex2f(-5.94, -1.87);
        glVertex2f(-3.95, -1.87);
        glVertex2f(-3.95, -2.03);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(214, 8, 2);
        glVertex2f(-6, -1.87);
        glVertex2f(-6, -1.82);
        glVertex2f(-3.95, -1.82);
        glVertex2f(-3.95, -1.87);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 186, 67);
        glVertex2f(-6.02, -1.82);
        glVertex2f(-6.02, -1.8);
        glVertex2f(-3.9, -1.8);
        glVertex2f(-3.9, -1.82);
        glEnd();

        Bus2_window1(0,0,0);
        Bus2_window1(0.25,0,0);
        Bus2_window1(0.50,0,0);
        Bus2_window1(0.75,0,0);
        Bus2_window1(1,0,0);
        Bus2_window1(1.25,0,0);
        Bus2_window1(1.50,0,0);
        Bus2_window1(1.75,0,0);

        Line(-5.88, -1.72, -3.96, -1.72);

        Bus2_window2(0, 0, 0);
        Bus2_window2(0.2, 0, 0);
        Bus2_window2(0.4, 0, 0);
        Bus2_window2(0.6, 0, 0);
        Bus2_window2(0.8, 0, 0);
        Bus2_window2(1, 0, 0);

        glBegin(GL_QUADS);
        glColor3ub(40, 45, 50);
        glVertex2f(-6.02, -2.2);
        glVertex2f(-6.02, -2.18);
        glVertex2f(-3.9, -2.18);
        glVertex2f(-3.9, -2.2);
        glEnd();

        Line(-5.96, -2.08, -5.78, -2.08);
        Line(-5.53, -2.08, -4.28, -2.08);

        glBegin(GL_QUADS);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.93, -2.03);
        glVertex2f(-5.93, -1.87);
        glVertex2f(-5.85, -1.87);
        glVertex2f(-5.85, -2.03);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(136, 8, 8);
        glVertex2f(-5.75, -2.18);
        glVertex2f(-5.75, -1.82);
        glVertex2f(-5.55, -1.82);
        glVertex2f(-5.55, -2.18);
        glEnd();

        Line(-5.65, -2.18, -5.65, -1.82);

        glBegin(GL_POLYGON);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.73, -1.96);
        glVertex2f(-5.73, -1.84);
        glVertex2f(-5.67, -1.84);
        glVertex2f(-5.67, -1.96);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.63, -1.96);
        glVertex2f(-5.63, -1.84);
        glVertex2f(-5.57, -1.84);
        glVertex2f(-5.57, -1.96);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.73, -2.16);
        glVertex2f(-5.73, -1.99);
        glVertex2f(-5.67, -1.99);
        glVertex2f(-5.67, -2.16);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.63, -2.16);
        glVertex2f(-5.63, -1.99);
        glVertex2f(-5.57, -1.99);
        glVertex2f(-5.57, -2.16);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 234, 127);
        glVertex2f(-4.1, -2.18);
        glVertex2f(-4.1, -1.82);
        glVertex2f(-4.08, -1.82);
        glVertex2f(-4.08, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(134, 5, 3);
        glVertex2f(-4.25, -2.18);
        glVertex2f(-4.25, -1.82);
        glVertex2f(-4.1, -1.82);
        glVertex2f(-4.1, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(134, 5, 3);
        glVertex2f(-4.1, -1.84);
        glVertex2f(-4.1, -1.82);
        glVertex2f(-3.95, -1.82);
        glVertex2f(-3.95, -1.84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(209, 20, 3);
        glVertex2f(-4.25, -2.18);
        glVertex2f(-4.25, -2.16);
        glVertex2f(-4.08, -2.16);
        glVertex2f(-4.08, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(134, 8, 8);
        glVertex2f(-4.08, -2.18);
        glVertex2f(-4.08, -1.84);
        glVertex2f(-3.95, -1.84);
        glVertex2f(-3.95, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(210, 43, 43);
        glVertex2f(-4.08, -1.98);
        glVertex2f(-4.08, -1.84);
        glVertex2f(-3.97, -1.84);
        glVertex2f(-3.97, -1.98);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(210, 43, 43);
        glVertex2f(-4.08, -2.15);
        glVertex2f(-4.08, -2.11);
        glVertex2f(-3.97, -2.11);
        glVertex2f(-3.97, -2.15);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(210, 43, 43);
        glVertex2f(-4.08, -2.08);
        glVertex2f(-4.08, -2.05);
        glVertex2f(-3.97, -2.05);
        glVertex2f(-3.97, -2.08);
        glEnd();

        Circle(0.18, -5.34, -2.22, 0, 0, 0);
        Circle(0.10, -5.34, -2.22, 114, 107, 104);

        Circle(0.18, -4.46, -2.22, 0, 0, 0);
        Circle(0.10, -4.46, -2.22, 114, 107, 104);

        glPopMatrix();
    }
    else{

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(movebus2,0,0);

        glBegin(GL_POLYGON);
        glColor3ub(160, 8, 2);
        glVertex2f(-5.96, -1.8);
        glVertex2f(-5.96, -1.46);
        glVertex2f(-5.86, -1.38);
        glVertex2f(-4, -1.38);
        glVertex2f(-3.9, -1.48);
        glVertex2f(-3.9, -1.8);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(160, 8, 2);
        glVertex2f(-6, -2.18);
        glVertex2f(-6, -2.07);
        glVertex2f(-5.96, -2.03);
        glVertex2f(-3.95, -2.03);
        glVertex2f(-3.95, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(160, 8, 2);
        glVertex2f(-5.94, -2.03);
        glVertex2f(-5.94, -1.87);
        glVertex2f(-3.95, -1.87);
        glVertex2f(-3.95, -2.03);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(160, 8, 2);
        glVertex2f(-6, -1.87);
        glVertex2f(-6, -1.82);
        glVertex2f(-3.95, -1.82);
        glVertex2f(-3.95, -1.87);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 186, 67);
        glVertex2f(-6.02, -1.82);
        glVertex2f(-6.02, -1.8);
        glVertex2f(-3.9, -1.8);
        glVertex2f(-3.9, -1.82);
        glEnd();

        Bus2_window1(0,0,0);
        Bus2_window1(0.25,0,0);
        Bus2_window1(0.50,0,0);
        Bus2_window1(0.75,0,0);
        Bus2_window1(1,0,0);
        Bus2_window1(1.25,0,0);
        Bus2_window1(1.50,0,0);
        Bus2_window1(1.75,0,0);

        Line(-5.88, -1.72, -3.96, -1.72);

        Bus2_window2(0, 0, 0);
        Bus2_window2(0.2, 0, 0);
        Bus2_window2(0.4, 0, 0);
        Bus2_window2(0.6, 0, 0);
        Bus2_window2(0.8, 0, 0);
        Bus2_window2(1, 0, 0);

        glBegin(GL_QUADS);
        glColor3ub(40, 45, 50);
        glVertex2f(-6.02, -2.2);
        glVertex2f(-6.02, -2.18);
        glVertex2f(-3.9, -2.18);
        glVertex2f(-3.9, -2.2);
        glEnd();

        Line(-5.96, -2.08, -5.78, -2.08);
        Line(-5.53, -2.08, -4.28, -2.08);

        glBegin(GL_QUADS);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.93, -2.03);
        glVertex2f(-5.93, -1.87);
        glVertex2f(-5.85, -1.87);
        glVertex2f(-5.85, -2.03);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(136, 8, 8);
        glVertex2f(-5.75, -2.18);
        glVertex2f(-5.75, -1.82);
        glVertex2f(-5.55, -1.82);
        glVertex2f(-5.55, -2.18);
        glEnd();

        Line(-5.65, -2.18, -5.65, -1.82);

        glBegin(GL_POLYGON);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.73, -1.96);
        glVertex2f(-5.73, -1.84);
        glVertex2f(-5.67, -1.84);
        glVertex2f(-5.67, -1.96);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.63, -1.96);
        glVertex2f(-5.63, -1.84);
        glVertex2f(-5.57, -1.84);
        glVertex2f(-5.57, -1.96);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.73, -2.16);
        glVertex2f(-5.73, -1.99);
        glVertex2f(-5.67, -1.99);
        glVertex2f(-5.67, -2.16);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(44, 76, 144);
        glVertex2f(-5.63, -2.16);
        glVertex2f(-5.63, -1.99);
        glVertex2f(-5.57, -1.99);
        glVertex2f(-5.57, -2.16);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 234, 127);
        glVertex2f(-4.1, -2.18);
        glVertex2f(-4.1, -1.82);
        glVertex2f(-4.08, -1.82);
        glVertex2f(-4.08, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(134, 5, 3);
        glVertex2f(-4.25, -2.18);
        glVertex2f(-4.25, -1.82);
        glVertex2f(-4.1, -1.82);
        glVertex2f(-4.1, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(134, 5, 3);
        glVertex2f(-4.1, -1.84);
        glVertex2f(-4.1, -1.82);
        glVertex2f(-3.95, -1.82);
        glVertex2f(-3.95, -1.84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(209, 20, 3);
        glVertex2f(-4.25, -2.18);
        glVertex2f(-4.25, -2.16);
        glVertex2f(-4.08, -2.16);
        glVertex2f(-4.08, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(134, 8, 8);
        glVertex2f(-4.08, -2.18);
        glVertex2f(-4.08, -1.84);
        glVertex2f(-3.95, -1.84);
        glVertex2f(-3.95, -2.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(170, 43, 43);
        glVertex2f(-4.08, -1.98);
        glVertex2f(-4.08, -1.84);
        glVertex2f(-3.97, -1.84);
        glVertex2f(-3.97, -1.98);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(170, 43, 43);
        glVertex2f(-4.08, -2.15);
        glVertex2f(-4.08, -2.11);
        glVertex2f(-3.97, -2.11);
        glVertex2f(-3.97, -2.15);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(170, 43, 43);
        glVertex2f(-4.08, -2.08);
        glVertex2f(-4.08, -2.05);
        glVertex2f(-3.97, -2.05);
        glVertex2f(-3.97, -2.08);
        glEnd();

        Circle(0.18, -5.34, -2.22, 0, 0, 0);
        Circle(0.10, -5.34, -2.22, 114, 107, 104);

        Circle(0.18, -4.46, -2.22, 0, 0, 0);
        Circle(0.10, -4.46, -2.22, 114, 107, 104);

        glPopMatrix();
    }
}

bool Bus2KeyMove = true;
void UpdateBus2(int value)//UBUS09
{

    float speed = 0.05f;
    float resetThreshold = -16.0f;
    float resetX = 16.0f;

    if(Bus2KeyMove){
        movebus2 -= speed;
    }
    if (movebus2 < resetThreshold){
            movebus2 = resetX;
    }

    glutPostRedisplay();
    glutTimerFunc(20,UpdateBus2,0);
}

float moveAmbulance = 0.0f;
void Ambulance_Window_Line(float x1, float y1, float x2, float y2)
{
    glColor3ub(42, 141, 97);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void Ambulance()//AMB22
{

    if(day){

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(moveAmbulance,0,0);

        glBegin(GL_POLYGON);
        glColor3ub(235, 248, 254);
        glVertex2f(5.65, -1.18);
        glVertex2f(5.65, -0.54);
        glVertex2f(6.9, -0.54);
        glVertex2f(6.9, -0.75);
        glVertex2f(7.2, -0.75);
        glVertex2f(7.4, -0.95);
        glVertex2f(7.6, -0.95);
        glVertex2f(7.6, -1.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(5.65, -1.22);
        glVertex2f(5.65, -1.18);
        glVertex2f(7.6, -1.18);
        glVertex2f(7.6, -1.22);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(105, 202, 204);
        glVertex2f(6.95, -0.95);
        glVertex2f(6.95, -0.8);
        glVertex2f(7.17, -0.8);
        glVertex2f(7.32, -0.95);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(105, 202, 204);
        glVertex2f(6.45, -0.9);
        glVertex2f(6.45, -0.65);
        glVertex2f(6.75, -0.65);
        glVertex2f(6.75, -0.9);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(105, 202, 204);
        glVertex2f(6.15, -0.9);
        glVertex2f(6.15, -0.65);
        glVertex2f(6.35, -0.65);
        glVertex2f(6.35, -0.9);
        glEnd();

        Circle(0.17 ,5.9, -0.75, 42, 140, 99);

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(5.78, -0.78);
        glVertex2f(5.78, -0.72);
        glVertex2f(6.02, -0.72);
        glVertex2f(6.02, -0.78);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(5.87, -0.88);
        glVertex2f(5.87, -0.62);
        glVertex2f(5.93, -0.62);
        glVertex2f(5.93, -0.88);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(42, 140, 99);
        glVertex2f(5.65, -1.04);
        glVertex2f(5.65, -1);
        glVertex2f(7.6, -1);
        glVertex2f(7.6, -1.04);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);
        glVertex2f(5.65, -1.1);
        glVertex2f(5.65, -1.04);
        glVertex2f(7.6, -1.04);
        glVertex2f(7.6, -1.1);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(178, 179, 183);
        glVertex2f(6.86, -1.2);
        glVertex2f(6.86, -0.54);
        glVertex2f(6.9, -0.54);
        glVertex2f(6.9, -1.2);
        glEnd();

        Ambulance_Window_Line(6.95, -0.95, 6.95, -0.8);
        Ambulance_Window_Line(6.95, -0.95, 7.32, -0.95);
        Ambulance_Window_Line(6.95, -0.8, 7.17, -0.8);
        Ambulance_Window_Line(7.17, -0.8, 7.32, -0.95);

        Ambulance_Window_Line(6.45, -0.9, 6.45, -0.65);
        Ambulance_Window_Line(6.45, -0.9, 6.75, -0.9);
        Ambulance_Window_Line(6.45, -0.65, 6.75, -0.65);
        Ambulance_Window_Line(6.75, -0.65, 6.75, -0.9);

        Ambulance_Window_Line(6.15, -0.9, 6.15, -0.65);
        Ambulance_Window_Line(6.15, -0.9, 6.35, -0.9);
        Ambulance_Window_Line(6.15, -0.65, 6.35, -0.65);
        Ambulance_Window_Line(6.35, -0.65, 6.35, -0.9);

        Circle(0.19 ,6, -1.2, 0, 0, 0);
        Circle(0.12 ,6, -1.2, 114, 107, 104);

        Circle(0.19 ,7.3, -1.2, 0, 0, 0);
        Circle(0.12 ,7.3, -1.2, 114, 107, 104);

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(7.04, -0.75);
        glVertex2f(7.04, -0.68);
        glVertex2f(7.12, -0.68);
        glVertex2f(7.12, -0.75);
        glEnd();

        glPopMatrix();

    }
    else{

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(moveAmbulance,0,0);

        glBegin(GL_POLYGON);
        glColor3ub(220, 220, 220);
        glVertex2f(5.65, -1.18);
        glVertex2f(5.65, -0.54);
        glVertex2f(6.9, -0.54);
        glVertex2f(6.9, -0.75);
        glVertex2f(7.2, -0.75);
        glVertex2f(7.4, -0.95);
        glVertex2f(7.6, -0.95);
        glVertex2f(7.6, -1.18);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(5.65, -1.22);
        glVertex2f(5.65, -1.18);
        glVertex2f(7.6, -1.18);
        glVertex2f(7.6, -1.22);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(44, 169, 179);
        glVertex2f(6.95, -0.95);
        glVertex2f(6.95, -0.8);
        glVertex2f(7.17, -0.8);
        glVertex2f(7.32, -0.95);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(44, 169, 179);
        glVertex2f(6.45, -0.9);
        glVertex2f(6.45, -0.65);
        glVertex2f(6.75, -0.65);
        glVertex2f(6.75, -0.9);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(44, 169, 179);
        glVertex2f(6.15, -0.9);
        glVertex2f(6.15, -0.65);
        glVertex2f(6.35, -0.65);
        glVertex2f(6.35, -0.9);
        glEnd();

        Circle(0.17 ,5.9, -0.75, 42, 140, 99);

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(5.78, -0.78);
        glVertex2f(5.78, -0.72);
        glVertex2f(6.02, -0.72);
        glVertex2f(6.02, -0.78);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(5.87, -0.88);
        glVertex2f(5.87, -0.62);
        glVertex2f(5.93, -0.62);
        glVertex2f(5.93, -0.88);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(42, 140, 99);
        glVertex2f(5.65, -1.04);
        glVertex2f(5.65, -1);
        glVertex2f(7.6, -1);
        glVertex2f(7.6, -1.04);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);
        glVertex2f(5.65, -1.1);
        glVertex2f(5.65, -1.04);
        glVertex2f(7.6, -1.04);
        glVertex2f(7.6, -1.1);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(178, 179, 183);
        glVertex2f(6.86, -1.2);
        glVertex2f(6.86, -0.54);
        glVertex2f(6.9, -0.54);
        glVertex2f(6.9, -1.2);
        glEnd();

        Ambulance_Window_Line(6.95, -0.95, 6.95, -0.8);
        Ambulance_Window_Line(6.95, -0.95, 7.32, -0.95);
        Ambulance_Window_Line(6.95, -0.8, 7.17, -0.8);
        Ambulance_Window_Line(7.17, -0.8, 7.32, -0.95);

        Ambulance_Window_Line(6.45, -0.9, 6.45, -0.65);
        Ambulance_Window_Line(6.45, -0.9, 6.75, -0.9);
        Ambulance_Window_Line(6.45, -0.65, 6.75, -0.65);
        Ambulance_Window_Line(6.75, -0.65, 6.75, -0.9);

        Ambulance_Window_Line(6.15, -0.9, 6.15, -0.65);
        Ambulance_Window_Line(6.15, -0.9, 6.35, -0.9);
        Ambulance_Window_Line(6.15, -0.65, 6.35, -0.65);
        Ambulance_Window_Line(6.35, -0.65, 6.35, -0.9);

        Circle(0.19 ,6, -1.2, 0, 0, 0);
        Circle(0.12 ,6, -1.2, 114, 107, 104);

        Circle(0.19 ,7.3, -1.2, 0, 0, 0);
        Circle(0.12 ,7.3, -1.2, 114, 107, 104);

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(7.04, -0.75);
        glVertex2f(7.04, -0.68);
        glVertex2f(7.12, -0.68);
        glVertex2f(7.12, -0.75);
        glEnd();

        glPopMatrix();
    }
}

bool AmbulanceKeyMove = true;
void UpdateAmbulance (int value)//UAMB10
{

    float speed = 0.05f;
    float resetThreshold = 16.0f;
    float resetX = -16.0f;

    if(AmbulanceKeyMove){
        moveAmbulance += speed;
    }
    if (moveAmbulance > resetThreshold){
            moveAmbulance = resetX;
    }

    glutPostRedisplay();
    glutTimerFunc(20,UpdateAmbulance,0);
}

float wave1X = -8.5f;
float wave2X = -1.5f;
float wave3X = 7.0f;
float wave4X = -6.5f;
float wave5X = 0.0f;
float wave6X = 5.5f;
float wave7X = -8.5f;
float wave8X = -1.5f;
float wave9X = 7.0f;

void SeaWaves()
{
    glColor3ub(255, 255, 255);

    glPushMatrix();
    glTranslatef(wave1X, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -4.05f);
    glVertex2f(0.0f, -4.0f);
    glVertex2f(2.0f, -4.0f);
    glVertex2f(2.0f, -4.05f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave2X, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -4.05f);
    glVertex2f(0.0f, -4.0f);
    glVertex2f(2.0f, -4.0f);
    glVertex2f(2.0f, -4.05f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave3X, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -4.05f);
    glVertex2f(0.0f, -4.0f);
    glVertex2f(2.0f, -4.0f);
    glVertex2f(2.0f, -4.05f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave4X, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -5.55f);
    glVertex2f(0.0f, -5.5f);
    glVertex2f(2.0f, -5.5f);
    glVertex2f(2.0f, -5.55f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave5X, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -5.55f);
    glVertex2f(0.0f, -5.5f);
    glVertex2f(2.0f, -5.5f);
    glVertex2f(2.0f, -5.55f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave6X, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -5.55f);
    glVertex2f(0.0f, -5.5f);
    glVertex2f(2.0f, -5.5f);
    glVertex2f(2.0f, -5.55f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave7X, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -7.05f);
    glVertex2f(0.0f, -7.0f);
    glVertex2f(2.0f, -7.0f);
    glVertex2f(2.0f, -7.05f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave8X, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -7.05f);
    glVertex2f(0.0f, -7.0f);
    glVertex2f(2.0f, -7.0f);
    glVertex2f(2.0f, -7.05f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(wave9X, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -7.05f);
    glVertex2f(0.0f, -7.0f);
    glVertex2f(2.0f, -7.0f);
    glVertex2f(2.0f, -7.05f);
    glEnd();

    glPopMatrix();
}

void Wavemoving(int value)//UWAVE11
{
    float speed = 0.02f;
    float resetThreshold = 12.0f;
    float resetX = -12.0f;

    wave1X += speed; if (wave1X > resetThreshold) wave1X = resetX;
    wave2X += speed; if (wave2X > resetThreshold) wave2X = resetX;
    wave3X += speed; if (wave3X > resetThreshold) wave3X = resetX;
    wave4X += speed; if (wave4X > resetThreshold) wave4X = resetX;
    wave5X += speed; if (wave5X > resetThreshold) wave5X = resetX;
    wave6X += speed; if (wave6X > resetThreshold) wave6X = resetX;
    wave7X += speed; if (wave7X > resetThreshold) wave7X = resetX;
    wave8X += speed; if (wave8X > resetThreshold) wave8X = resetX;
    wave9X += speed; if (wave9X > resetThreshold) wave9X = resetX;

    glutPostRedisplay();
    glutTimerFunc(16, Wavemoving, 0);
}

void Sea()//SEA23
{

    if(day){

    glBegin(GL_QUADS);
    glColor3ub(0,197,255);
    glVertex2f(-10,-8);
    glVertex2f(-10,-3);
    glVertex2f(10,-3);
    glVertex2f(10,-8);
    glEnd();
    }
    else{
    glBegin(GL_QUADS);
    glColor3ub(44,76,144);
    glVertex2f(-10,-8);
    glVertex2f(-10,-3);
    glVertex2f(10,-3);
    glVertex2f(10,-8);
    glEnd();
    }

    SeaWaves();

}

void Fish_Ship_Window1(float x, float y, float z)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(5, 174, 207);
    glVertex2f(-1, -5.25);
    glVertex2f(-1, -5.15);
    glVertex2f(-0.9, -5.15);
    glVertex2f(-0.9, -5.25);
    glEnd();

    Line(-1, -5.25, -1, -5.15);
    Line(-1, -5.25, -0.9, -5.25);
    Line(-1, -5.15, -0.9, -5.15);
    Line(-0.9, -5.15, -0.9, -5.25);

    glPopMatrix();
}

void Fish_Ship_Window2(float x, float y, float z)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    Circle(0.07, -0.28, -5.42, 0, 0, 0);
    Circle(0.06, -0.28, -5.42, 5, 174, 207);

    glPopMatrix();
}

float fishShipPosition = 0.0f;
void Fish_Ship()//FISH25
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(fishShipPosition,0,0);

    if(day){

        glBegin(GL_QUADS);
        glColor3ub(140, 66, 67);
        glVertex2f(-1.28, -5.85);
        glVertex2f(-1.4, -5.6);
        glVertex2f(0.3, -5.6);
        glVertex2f(0.032, -5.85);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(254, 244, 185);
        glVertex2f(-1.16, -5.6);
        glVertex2f(-1.16, -5.32);
        glVertex2f(-0.15, -5.32);
        glVertex2f(-0.15, -5.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(197, 197, 197);
        glVertex2f(-0.68, -5.6);
        glVertex2f(-0.6, -5.52);
        glVertex2f(0.39, -5.52);
        glVertex2f(0.3, -5.6);
        glEnd();

        Fish_Ship_Window2(0, 0, 0);
        Fish_Ship_Window2(-0.25, 0, 0);
        Fish_Ship_Window2(-0.50, 0, 0);
        Fish_Ship_Window2(-0.75, 0, 0);

        glBegin(GL_QUADS);
        glColor3ub(13, 37, 85);
        glVertex2f(-1.2, -5.32);
        glVertex2f(-1.2, -5.3);
        glVertex2f(-0.1, -5.3);
        glVertex2f(-0.1, -5.32);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(242, 188, 116);
        glVertex2f(-1.05, -5.3);
        glVertex2f(-1.05, -5.1);
        glVertex2f(-0.25, -5.1);
        glVertex2f(-0.25, -5.3);
        glEnd();

        Fish_Ship_Window1(0, 0, 0);
        Fish_Ship_Window1(0.2, 0, 0);
        Fish_Ship_Window1(0.4, 0, 0);
        Fish_Ship_Window1(0.6, 0, 0);

        glBegin(GL_QUADS);
        glColor3ub(197, 197, 197);
        glVertex2f(-0.55, -4.85);
        glVertex2f(-0.55, -4.75);
        glVertex2f(-0.35, -4.75);
        glVertex2f(-0.35, -4.85);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(200, 0, 0);
        glVertex2f(-0.55, -4.95);
        glVertex2f(-0.55, -4.85);
        glVertex2f(-0.35, -4.85);
        glVertex2f(-0.35, -4.95);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(56, 83, 113);
        glVertex2f(-0.55, -5.1);
        glVertex2f(-0.55, -4.95);
        glVertex2f(-0.35, -4.95);
        glVertex2f(-0.35, -5.1);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(140, 66, 67);
        glVertex2f(-0.95, -5.1);
        glVertex2f(-0.95, -5);
        glVertex2f(-0.65, -5);
        glVertex2f(-0.65, -5.1);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(56, 83, 113);
        glVertex2f(-1.14, -5.3);
        glVertex2f(-1.14, -4.72);
        glVertex2f(-1.12, -4.72);
        glVertex2f(-1.12, -5.3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(56, 83, 113);
        glVertex2f(-1.18, -4.78);
        glVertex2f(-1.18, -4.76);
        glVertex2f(-1.08, -4.76);
        glVertex2f(-1.08, -4.78);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(-1.16, -4.72);
        glVertex2f(-1.16, -4.68);
        glVertex2f(-1.1, -4.68);
        glVertex2f(-1.1, -4.72);
        glEnd();

        Line(-1.16, -4.72, -1.1, -4.72);
        Line(-1.16, -4.72, -1.16, -4.68);
        Line(-1.16, -4.68, -1.1, -4.68);
        Line(-1.1, -4.72, -1.1, -4.68);

        Line(-1.12, -4.76, -1.4, -5.6);
        Line(-1.12, -4.76, -1.26, -5.6);

        Line(-1.14, -4.76, -0.95, -5);
        Line(-1.14, -4.76, -0.75, -5);

        glBegin(GL_QUADS);
        glColor3ub(56, 83, 113);
        glVertex2f(0.18, -5.52);
        glVertex2f(0.18, -4.72);
        glVertex2f(0.2, -4.72);
        glVertex2f(0.2, -5.52);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(56, 83, 113);
        glVertex2f(0.14, -4.78);
        glVertex2f(0.14, -4.76);
        glVertex2f(0.24, -4.76);
        glVertex2f(0.24, -4.78);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(0.16, -4.72);
        glVertex2f(0.16, -4.68);
        glVertex2f(0.22, -4.68);
        glVertex2f(0.22, -4.72);
        glEnd();

        Line(0.16, -4.72, 0.22, -4.72);
        Line(0.16, -4.72, 0.16, -4.68);
        Line(0.16, -4.68, 0.22, -4.68);
        Line(0.22, -4.72, 0.22, -4.68);

        Line(0.2, -4.76, -0.25, -5.3);
        Line(0.2, -4.76, -0.15, -5.52);

    }
    else{

        glBegin(GL_QUADS);
        glColor3ub(107, 41, 42);
        glVertex2f(-1.28, -5.85);
        glVertex2f(-1.4, -5.6);
        glVertex2f(0.3, -5.6);
        glVertex2f(0.032, -5.85);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 232, 138);
        glVertex2f(-1.16, -5.6);
        glVertex2f(-1.16, -5.32);
        glVertex2f(-0.15, -5.32);
        glVertex2f(-0.15, -5.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(197, 197, 197);
        glVertex2f(-0.68, -5.6);
        glVertex2f(-0.6, -5.52);
        glVertex2f(0.39, -5.52);
        glVertex2f(0.3, -5.6);
        glEnd();

        Fish_Ship_Window2(0, 0, 0);
        Fish_Ship_Window2(-0.25, 0, 0);
        Fish_Ship_Window2(-0.50, 0, 0);
        Fish_Ship_Window2(-0.75, 0, 0);

        glBegin(GL_QUADS);
        glColor3ub(13, 37, 85);
        glVertex2f(-1.2, -5.32);
        glVertex2f(-1.2, -5.3);
        glVertex2f(-0.1, -5.3);
        glVertex2f(-0.1, -5.32);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(228, 140, 51);
        glVertex2f(-1.05, -5.3);
        glVertex2f(-1.05, -5.1);
        glVertex2f(-0.25, -5.1);
        glVertex2f(-0.25, -5.3);
        glEnd();

        Fish_Ship_Window1(0, 0, 0);
        Fish_Ship_Window1(0.2, 0, 0);
        Fish_Ship_Window1(0.4, 0, 0);
        Fish_Ship_Window1(0.6, 0, 0);

        glBegin(GL_QUADS);
        glColor3ub(197, 197, 197);
        glVertex2f(-0.55, -4.85);
        glVertex2f(-0.55, -4.75);
        glVertex2f(-0.35, -4.75);
        glVertex2f(-0.35, -4.85);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(200, 0, 0);
        glVertex2f(-0.55, -4.95);
        glVertex2f(-0.55, -4.85);
        glVertex2f(-0.35, -4.85);
        glVertex2f(-0.35, -4.95);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.55, -5.1);
        glVertex2f(-0.55, -4.95);
        glVertex2f(-0.35, -4.95);
        glVertex2f(-0.35, -5.1);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(109, 41, 42);
        glVertex2f(-0.95, -5.1);
        glVertex2f(-0.95, -5);
        glVertex2f(-0.65, -5);
        glVertex2f(-0.65, -5.1);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-1.14, -5.3);
        glVertex2f(-1.14, -4.72);
        glVertex2f(-1.12, -4.72);
        glVertex2f(-1.12, -5.3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-1.18, -4.78);
        glVertex2f(-1.18, -4.76);
        glVertex2f(-1.08, -4.76);
        glVertex2f(-1.08, -4.78);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(-1.16, -4.72);
        glVertex2f(-1.16, -4.68);
        glVertex2f(-1.1, -4.68);
        glVertex2f(-1.1, -4.72);
        glEnd();

        Line(-1.16, -4.72, -1.1, -4.72);
        Line(-1.16, -4.72, -1.16, -4.68);
        Line(-1.16, -4.68, -1.1, -4.68);
        Line(-1.1, -4.72, -1.1, -4.68);

        Line(-1.12, -4.76, -1.4, -5.6);
        Line(-1.12, -4.76, -1.26, -5.6);

        Line(-1.14, -4.76, -0.95, -5);
        Line(-1.14, -4.76, -0.75, -5);

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(0.18, -5.52);
        glVertex2f(0.18, -4.72);
        glVertex2f(0.2, -4.72);
        glVertex2f(0.2, -5.52);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(0.14, -4.78);
        glVertex2f(0.14, -4.76);
        glVertex2f(0.24, -4.76);
        glVertex2f(0.24, -4.78);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(0.16, -4.72);
        glVertex2f(0.16, -4.68);
        glVertex2f(0.22, -4.68);
        glVertex2f(0.22, -4.72);
        glEnd();

        Line(0.16, -4.72, 0.22, -4.72);
        Line(0.16, -4.72, 0.16, -4.68);
        Line(0.16, -4.68, 0.22, -4.68);
        Line(0.22, -4.72, 0.22, -4.68);

        Line(0.2, -4.76, -0.25, -5.3);
        Line(0.2, -4.76, -0.15, -5.52);

    }
    glPopMatrix();
}

bool FishShipStop = false;

void updateFishShip(int value)//UFISHS13
{
    if (!FishShipStop) {
        fishShipPosition += 0.03f;
        if (fishShipPosition > 14.0f) {
            fishShipPosition = -10.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateFishShip, 0);
}



void Cruise_Ship_Window1(float x, float y, float z)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(5, 174, 207);
    glVertex2f(-7, -4.2);
    glVertex2f(-7, -4.1);
    glVertex2f(-6.9, -4.1);
    glVertex2f(-6.9, -4.2);
    glEnd();

    Line(-7, -4.2, -6.9, -4.2);
    Line(-7, -4.2, -7, -4.1);
    Line(-7, -4.1, -6.9, -4.1);
    Line(-6.9, -4.2, -6.9, -4.1);

    glPopMatrix();
}

void Cruise_Ship_Window2(float x, float y, float z)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    Circle(0.08,-7.48, -4.48, 0, 0, 0);
    Circle(0.06,-7.48, -4.48, 5, 174, 207);

    glPopMatrix();
}

float Cruise_ShipPosition = 0.0f;
void Cruise_Ship()//CRUISE24
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(Cruise_ShipPosition,0,0);

    if(day){

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-7.4, -4.8);
        glVertex2f(-7.6, -4.6);
        glVertex2f(-4.6, -4.6);
        glVertex2f(-4.9, -4.8);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(81, 13, 98);
        glVertex2f(-5.3, -4.3);
        glVertex2f(-5.3, -4.15);
        glVertex2f(-4.65, -4.15);
        glVertex2f(-4.55, -4.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.6, -4.6);
        glVertex2f(-7.82, -4.4);
        glVertex2f(-7.82, -4.34);
        glVertex2f(-5.22, -4.34);
        glVertex2f(-5.2, -4.3);
        glVertex2f(-4.18, -4.3);
        glVertex2f(-4.6, -4.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-7.6, -4.34);
        glVertex2f(-7.5567567543833, -4.2600000022784);
        glVertex2f(-5.18, -4.26);
        glVertex2f(-5.22, -4.34);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.5567567543833, -4.2600000022784);
        glVertex2f(-7.2, -3.6);
        glVertex2f(-5.6, -3.6);
        glVertex2f(-5.18, -4.26);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(240, 240, 240);
        glVertex2f(-6.4, -3.6);
        glVertex2f(-6.2, -3.4);
        glVertex2f(-5.9, -3.4);
        glVertex2f(-5.7, -3.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.32, -3.58);
        glVertex2f(-6.28, -3.53);
        glVertex2f(-5.835, -3.53);
        glVertex2f(-5.78, -3.58);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.24, -3.49);
        glVertex2f(-6.19, -3.44);
        glVertex2f(-5.91, -3.44);
        glVertex2f(-5.865, -3.49);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(240, 240, 240);
        glVertex2f(-6.07, -3.6);
        glVertex2f(-6.07, -3.4);
        glVertex2f(-6.03, -3.4);
        glVertex2f(-6.03, -3.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.7, -4.2);
        glVertex2f(-6.7, -4.1);
        glVertex2f(-5.446, -4.1);
        glVertex2f(-5.382, -4.2);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.7, -4);
        glVertex2f(-6.7, -3.9);
        glVertex2f(-5.57273, -3.9);
        glVertex2f(-5.509, -4);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.7, -3.8);
        glVertex2f(-6.7, -3.7);
        glVertex2f(-5.7, -3.7);
        glVertex2f(-5.6364, -3.8);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-7.05, -3.6);
        glVertex2f(-7.05, -3.3);
        glVertex2f(-6.9, -3.3);
        glVertex2f(-6.9, -3.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.1, -3.3);
        glVertex2f(-7.1, -3.2);
        glVertex2f(-6.85, -3.2);
        glVertex2f(-6.85, -3.3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-6.7, -3.6);
        glVertex2f(-6.7, -3.3);
        glVertex2f(-6.55, -3.3);
        glVertex2f(-6.55, -3.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(240, 240, 240);
        glVertex2f(-6.75, -3.3);
        glVertex2f(-6.75, -3.2);
        glVertex2f(-6.5, -3.2);
        glVertex2f(-6.5, -3.3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(240, 240, 240);
        glVertex2f(-7.05, -3.45);
        glVertex2f(-7.05, -3.4);
        glVertex2f(-6.9, -3.4);
        glVertex2f(-6.9, -3.45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(240, 240, 240);
        glVertex2f(-6.7, -3.45);
        glVertex2f(-6.7, -3.4);
        glVertex2f(-6.55, -3.4);
        glVertex2f(-6.55, -3.45);
        glEnd();

        Cruise_Ship_Window1(0, 0, 0);
        Cruise_Ship_Window1(-0.2, 0, 0);
        Cruise_Ship_Window1(-0.4, 0, 0);
        Cruise_Ship_Window1(0, 0.2, 0);
        Cruise_Ship_Window1(-0.2, 0.2, 0);
        Cruise_Ship_Window1(0.1, 0.4, 0);
        Cruise_Ship_Window1(-0.1, 0.4, 0);

        Cruise_Ship_Window2(0, 0, 0);
        Cruise_Ship_Window2(0.5, 0, 0);
        Cruise_Ship_Window2(1, 0, 0);
        Cruise_Ship_Window2(1.5, 0, 0);
        Cruise_Ship_Window2(2, 0, 0);
        Cruise_Ship_Window2(2.5, 0, 0);

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-7.2216, -3.64);
        glVertex2f(-7.2, -3.6);
        glVertex2f(-5.6, -3.6);
        glVertex2f(-5.57455, -3.64);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-4.43, -4.3);
        glVertex2f(-4.43, -3.6);
        glVertex2f(-4.4, -3.6);
        glVertex2f(-4.4, -4.3);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(255, 0, 0);
        glVertex2f(-4.43, -3.9);
        glVertex2f(-4.75, -3.75);
        glVertex2f(-4.43, -3.6);
        glEnd();

    }
    else{

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-7.4, -4.8);
        glVertex2f(-7.6, -4.6);
        glVertex2f(-4.6, -4.6);
        glVertex2f(-4.9, -4.8);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(81, 13, 98);
        glVertex2f(-5.3, -4.3);
        glVertex2f(-5.3, -4.15);
        glVertex2f(-4.65, -4.15);
        glVertex2f(-4.55, -4.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(210, 210, 210);
        glVertex2f(-7.6, -4.6);
        glVertex2f(-7.82, -4.4);
        glVertex2f(-7.82, -4.34);
        glVertex2f(-5.22, -4.34);
        glVertex2f(-5.2, -4.3);
        glVertex2f(-4.18, -4.3);
        glVertex2f(-4.6, -4.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-7.6, -4.34);
        glVertex2f(-7.5567567543833, -4.2600000022784);
        glVertex2f(-5.18, -4.26);
        glVertex2f(-5.22, -4.34);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(220, 220, 220);
        glVertex2f(-7.5567567543833, -4.2600000022784);
        glVertex2f(-7.2, -3.6);
        glVertex2f(-5.6, -3.6);
        glVertex2f(-5.18, -4.26);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(220, 220, 220);
        glVertex2f(-6.4, -3.6);
        glVertex2f(-6.2, -3.4);
        glVertex2f(-5.9, -3.4);
        glVertex2f(-5.7, -3.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.32, -3.58);
        glVertex2f(-6.28, -3.53);
        glVertex2f(-5.835, -3.53);
        glVertex2f(-5.78, -3.58);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.24, -3.49);
        glVertex2f(-6.19, -3.44);
        glVertex2f(-5.91, -3.44);
        glVertex2f(-5.865, -3.49);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(220, 220, 220);
        glVertex2f(-6.07, -3.6);
        glVertex2f(-6.07, -3.4);
        glVertex2f(-6.03, -3.4);
        glVertex2f(-6.03, -3.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.7, -4.2);
        glVertex2f(-6.7, -4.1);
        glVertex2f(-5.446, -4.1);
        glVertex2f(-5.382, -4.2);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.7, -4);
        glVertex2f(-6.7, -3.9);
        glVertex2f(-5.57273, -3.9);
        glVertex2f(-5.509, -4);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(5, 174, 207);
        glVertex2f(-6.7, -3.8);
        glVertex2f(-6.7, -3.7);
        glVertex2f(-5.7, -3.7);
        glVertex2f(-5.6364, -3.8);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-7.05, -3.6);
        glVertex2f(-7.05, -3.3);
        glVertex2f(-6.9, -3.3);
        glVertex2f(-6.9, -3.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(220, 220, 220);
        glVertex2f(-7.1, -3.3);
        glVertex2f(-7.1, -3.2);
        glVertex2f(-6.85, -3.2);
        glVertex2f(-6.85, -3.3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-6.7, -3.6);
        glVertex2f(-6.7, -3.3);
        glVertex2f(-6.55, -3.3);
        glVertex2f(-6.55, -3.6);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(220, 220, 220);
        glVertex2f(-6.75, -3.3);
        glVertex2f(-6.75, -3.2);
        glVertex2f(-6.5, -3.2);
        glVertex2f(-6.5, -3.3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(220, 220, 220);
        glVertex2f(-7.05, -3.45);
        glVertex2f(-7.05, -3.4);
        glVertex2f(-6.9, -3.4);
        glVertex2f(-6.9, -3.45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(220, 220, 220);
        glVertex2f(-6.7, -3.45);
        glVertex2f(-6.7, -3.4);
        glVertex2f(-6.55, -3.4);
        glVertex2f(-6.55, -3.45);
        glEnd();

        Cruise_Ship_Window1(0, 0, 0);
        Cruise_Ship_Window1(-0.2, 0, 0);
        Cruise_Ship_Window1(-0.4, 0, 0);
        Cruise_Ship_Window1(0, 0.2, 0);
        Cruise_Ship_Window1(-0.2, 0.2, 0);
        Cruise_Ship_Window1(0.1, 0.4, 0);
        Cruise_Ship_Window1(-0.1, 0.4, 0);

        Cruise_Ship_Window2(0, 0, 0);
        Cruise_Ship_Window2(0.5, 0, 0);
        Cruise_Ship_Window2(1, 0, 0);
        Cruise_Ship_Window2(1.5, 0, 0);
        Cruise_Ship_Window2(2, 0, 0);
        Cruise_Ship_Window2(2.5, 0, 0);

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-7.2216, -3.64);
        glVertex2f(-7.2, -3.6);
        glVertex2f(-5.6, -3.6);
        glVertex2f(-5.57455, -3.64);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(53, 69, 84);
        glVertex2f(-4.43, -4.3);
        glVertex2f(-4.43, -3.6);
        glVertex2f(-4.4, -3.6);
        glVertex2f(-4.4, -4.3);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(200, 0, 0);
        glVertex2f(-4.43, -3.9);
        glVertex2f(-4.75, -3.75);
        glVertex2f(-4.43, -3.6);
        glEnd();

    }
    glPopMatrix();
}

bool Cruise_Ship_Stop = false;

void updateCruise_Ship(int value)//UCRUISES12
{
    if (!Cruise_Ship_Stop) {
        Cruise_ShipPosition += 0.03f;
        if (Cruise_ShipPosition > 18.0f) {
            Cruise_ShipPosition = -10.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateCruise_Ship, 0);
}

void Cargo_ShipLine(float x1, float y1, float x2, float y2)
{
    glColor3ub(240, 240, 240);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void Cargo_Ship_Window(float x, float y, float z)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(5, 174, 207);
    glVertex2f(6.4, -6.8);
    glVertex2f(6.4, -6.7);
    glVertex2f(6.5, -6.7);
    glVertex2f(6.5, -6.8);
    glEnd();

    Line(6.4, -6.8, 6.4, -6.7);
    Line(6.4, -6.8, 6.5, -6.8);
    Line(6.4, -6.7, 6.5, -6.7);
    Line(6.5, -6.8, 6.5, -6.7);

    glPopMatrix();
}

void Cargo_Ship_BodyPart(float x, float y, float z)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_POLYGON);
    glColor3ub(10, 55, 123);
    glVertex2f(4.4, -7.35);
    glVertex2f(4.4, -7.25);
    glVertex2f(4.45, -7.25);
    glVertex2f(4.45, -7.35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(1, 44, 87);
    glVertex2f(4.38, -7.25);
    glVertex2f(4.38, -7.22);
    glVertex2f(4.47, -7.22);
    glVertex2f(4.47, -7.25);
    glEnd();

    glPopMatrix();
}

void Container(float x, float y, float z, float r, float g, float b)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(4.1, -6.95);
    glVertex2f(4.1, -6.75);
    glVertex2f(4.5, -6.75);
    glVertex2f(4.5, -6.95);
    glEnd();

    Line(4.1, -6.95, 4.1, -6.75);
    Line(4.1, -6.95, 4.5, -6.95);
    Line(4.1, -6.75, 4.5, -6.75);
    Line(4.5, -6.95, 4.5, -6.75);

    glPopMatrix();
}

float Cargo_ShipPosition = 0.0f;
void Cargo_Ship()//CARGO25
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(Cargo_ShipPosition,0,0);

    if(day){

        Container(0, 0.2, 0, 194, 194, 194);
        Container(0.4, 0.2, 0, 250, 228, 46);
        Container(0.8, 0.2, 0, 17, 85, 186);
        Container(1.2, 0.2, 0, 194, 194, 194);
        Container(1.6, 0.2, 0, 194, 3, 8);

        Container(0, 0, 0, 44, 185, 44);
        Container(0.4, 0, 0, 60, 60, 60);
        Container(0.8, 0, 0, 200, 0, 0);
        Container(1.2, 0, 0, 255, 228, 66);
        Container(1.6, 0, 0, 22, 85, 191);

        Container(0, -0.2, 0, 0, 73, 186);
        Container(0.4, -0.2, 0, 220, 220, 220);
        Container(0.8, -0.2, 0, 14, 155, 14);
        Container(1.2, -0.2, 0, 70, 70, 70);
        Container(1.6, -0.2, 0, 194, 194, 194);

        Container(0, -0.4, 0, 194, 194, 194);
        Container(0.4, -0.4, 0, 61, 61, 59);
        Container(0.8, -0.4, 0, 213, 19, 10);
        Container(1.2, -0.4, 0, 244, 225, 27);
        Container(1.6, -0.4, 0, 0, 162, 14);

        glBegin(GL_POLYGON);
        glColor3ub(200, 0, 0);
        glVertex2f(6.85, -7.6);
        glVertex2f(6.85, -7.4);
        glVertex2f(7.05, -7.4);
        glVertex2f(6.95, -7.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(10, 55, 123);
        glVertex2f(3.7, -7.6);
        glVertex2f(3.47275, -7.35);
        glVertex2f(7.11428, -7.35);
        glVertex2f(7.1, -7.4);
        glVertex2f(6.6, -7.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(10, 55, 123);
        glVertex2f(3.47275, -7.35);
        glVertex2f(3.2, -7.05);
        glVertex2f(3.95, -7.05);
        glVertex2f(4.2, -7.35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(10, 55, 123);
        glVertex2f(6, -7.35);
        glVertex2f(6.2, -7.05);
        glVertex2f(7.2, -7.05);
        glVertex2f(7.11428, -7.35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(6.3, -7.05);
        glVertex2f(6.3, -6.4);
        glVertex2f(6.8, -6.4);
        glVertex2f(7.1, -6.7);
        glVertex2f(7.1, -7.05);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(10, 55, 123);
        glVertex2f(6.8, -6.4);
        glVertex2f(6.875, -6.3);
        glVertex2f(7.1, -6.3);
        glVertex2f(7.1, -6.7);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(200, 0, 0);
        glVertex2f(6.875, -6.3);
        glVertex2f(6.95, -6.2);
        glVertex2f(7.1, -6.2);
        glVertex2f(7.1, -6.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(6.3, -6.4);
        glVertex2f(6.1, -6.2);
        glVertex2f(6.8, -6.2);
        glVertex2f(6.8, -6.4);
        glEnd();

        Line(6.3, -6.4, 6.8, -6.4);

        glBegin(GL_POLYGON);
        glColor3ub(5, 174, 207);
        glVertex2f(6.25, -6.35);
        glVertex2f(6.15, -6.25);
        glVertex2f(6.4, -6.25);
        glVertex2f(6.4, -6.35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(5, 174, 207);
        glVertex2f(6.47, -6.35);
        glVertex2f(6.47, -6.25);
        glVertex2f(6.7, -6.25);
        glVertex2f(6.7, -6.35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(240, 240, 240);
        glVertex2f(6.7, -7.05);
        glVertex2f(6.7, -6.86);
        glVertex2f(6.8, -6.86);
        glVertex2f(6.8, -7.05);
        glEnd();

        Line(6.7, -7.05, 6.7, -6.86);
        Line(6.7, -7.05, 6.8, -7.05);
        Line(6.7, -6.86, 6.8, -6.86);
        Line(6.8, -7.05, 6.8, -6.86);

        Circle(0.01, 6.78, -6.97, 0, 0, 0);

        Cargo_Ship_Window(0, 0, 0);
        Cargo_Ship_Window(0.2, 0, 0);
        Cargo_Ship_Window(0.4, 0, 0);
        Cargo_Ship_Window(0, 0.2, 0);
        Cargo_Ship_Window(0.2, 0.2, 0);

        Circle(0.1, 3.72, -7.22, 255, 255, 255);
        Circle(0.08, 3.72, -7.22, 69,118,247);

        Cargo_ShipLine(3.5, -7.05, 3.6, -6.8);
        Cargo_ShipLine(3.7, -7.05, 3.6, -6.8);
        Cargo_ShipLine(3.6, -7.05, 3.6, -6.72);
        Cargo_ShipLine(3.55, -6.8, 3.65, -6.8);
        Circle(0.04, 3.6, -6.7, 255, 255, 255);

        Cargo_Ship_BodyPart(0, 0, 0);
        Cargo_Ship_BodyPart(0.3, 0, 0);
        Cargo_Ship_BodyPart(0.6, 0, 0);
        Cargo_Ship_BodyPart(0.9, 0, 0);
        Cargo_Ship_BodyPart(1.2, 0, 0);
        Cargo_Ship_BodyPart(1.5, 0, 0);

    }
    else{

        Container(0, 0.2, 0, 194, 194, 194);
        Container(0.4, 0.2, 0, 250, 228, 46);
        Container(0.8, 0.2, 0, 17, 85, 186);
        Container(1.2, 0.2, 0, 194, 194, 194);
        Container(1.6, 0.2, 0, 194, 3, 8);

        Container(0, 0, 0, 44, 185, 44);
        Container(0.4, 0, 0, 60, 60, 60);
        Container(0.8, 0, 0, 200, 0, 0);
        Container(1.2, 0, 0, 255, 228, 66);
        Container(1.6, 0, 0, 22, 85, 191);

        Container(0, -0.2, 0, 0, 73, 186);
        Container(0.4, -0.2, 0, 220, 220, 220);
        Container(0.8, -0.2, 0, 14, 155, 14);
        Container(1.2, -0.2, 0, 70, 70, 70);
        Container(1.6, -0.2, 0, 194, 194, 194);

        Container(0, -0.4, 0, 194, 194, 194);
        Container(0.4, -0.4, 0, 61, 61, 59);
        Container(0.8, -0.4, 0, 213, 19, 10);
        Container(1.2, -0.4, 0, 244, 225, 27);
        Container(1.6, -0.4, 0, 0, 162, 14);

        glBegin(GL_POLYGON);
        glColor3ub(200, 0, 0);
        glVertex2f(6.85, -7.6);
        glVertex2f(6.85, -7.4);
        glVertex2f(7.05, -7.4);
        glVertex2f(6.95, -7.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(53, 69, 84);
        glVertex2f(3.7, -7.6);
        glVertex2f(3.47275, -7.35);
        glVertex2f(7.11428, -7.35);
        glVertex2f(7.1, -7.4);
        glVertex2f(6.6, -7.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(53, 69, 84);
        glVertex2f(3.47275, -7.35);
        glVertex2f(3.2, -7.05);
        glVertex2f(3.95, -7.05);
        glVertex2f(4.2, -7.35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(53, 69, 84);
        glVertex2f(6, -7.35);
        glVertex2f(6.2, -7.05);
        glVertex2f(7.2, -7.05);
        glVertex2f(7.11428, -7.35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(220, 220, 220);
        glVertex2f(6.3, -7.05);
        glVertex2f(6.3, -6.4);
        glVertex2f(6.8, -6.4);
        glVertex2f(7.1, -6.7);
        glVertex2f(7.1, -7.05);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(10, 55, 123);
        glVertex2f(6.8, -6.4);
        glVertex2f(6.875, -6.3);
        glVertex2f(7.1, -6.3);
        glVertex2f(7.1, -6.7);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(200, 0, 0);
        glVertex2f(6.875, -6.3);
        glVertex2f(6.95, -6.2);
        glVertex2f(7.1, -6.2);
        glVertex2f(7.1, -6.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(220, 220, 220);
        glVertex2f(6.3, -6.4);
        glVertex2f(6.1, -6.2);
        glVertex2f(6.8, -6.2);
        glVertex2f(6.8, -6.4);
        glEnd();

        Line(6.3, -6.4, 6.8, -6.4);

        glBegin(GL_POLYGON);
        glColor3ub(5, 174, 207);
        glVertex2f(6.25, -6.35);
        glVertex2f(6.15, -6.25);
        glVertex2f(6.4, -6.25);
        glVertex2f(6.4, -6.35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(5, 174, 207);
        glVertex2f(6.47, -6.35);
        glVertex2f(6.47, -6.25);
        glVertex2f(6.7, -6.25);
        glVertex2f(6.7, -6.35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(220, 220, 220);
        glVertex2f(6.7, -7.05);
        glVertex2f(6.7, -6.86);
        glVertex2f(6.8, -6.86);
        glVertex2f(6.8, -7.05);
        glEnd();

        Line(6.7, -7.05, 6.7, -6.86);
        Line(6.7, -7.05, 6.8, -7.05);
        Line(6.7, -6.86, 6.8, -6.86);
        Line(6.8, -7.05, 6.8, -6.86);

        Circle(0.01, 6.78, -6.97, 0, 0, 0);

        Cargo_Ship_Window(0, 0, 0);
        Cargo_Ship_Window(0.2, 0, 0);
        Cargo_Ship_Window(0.4, 0, 0);
        Cargo_Ship_Window(0, 0.2, 0);
        Cargo_Ship_Window(0.2, 0.2, 0);

        Circle(0.1, 3.72, -7.22, 255, 255, 255);
        Circle(0.08, 3.72, -7.22, 69,118,247);

        Cargo_ShipLine(3.5, -7.05, 3.6, -6.8);
        Cargo_ShipLine(3.7, -7.05, 3.6, -6.8);
        Cargo_ShipLine(3.6, -7.05, 3.6, -6.72);
        Cargo_ShipLine(3.55, -6.8, 3.65, -6.8);
        Circle(0.04, 3.6, -6.7, 255, 255, 255);

        Cargo_Ship_BodyPart(0, 0, 0);
        Cargo_Ship_BodyPart(0.3, 0, 0);
        Cargo_Ship_BodyPart(0.6, 0, 0);
        Cargo_Ship_BodyPart(0.9, 0, 0);
        Cargo_Ship_BodyPart(1.2, 0, 0);
        Cargo_Ship_BodyPart(1.5, 0, 0);

    }
    glPopMatrix();
}

bool Cargo_Ship_Stop = false;
void updateCargo_Ship(int value)//UCARGOS14
{
    if (!Cargo_Ship_Stop) {
        Cargo_ShipPosition -= 0.03f;
        if (Cargo_ShipPosition < -17.5f) {
            Cargo_ShipPosition = 10.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateCargo_Ship, 0);
}

 void Screen1(){

     Sky();
     Sun(-8.2,6.8,0.8,100);
     Cloud();
     Hot_Air_Balloon();
     Sea();
     Land();
     Watch_Tower();
     Mountain();
     Road();
     Traffic_Light();
     Tower();
     Wind_Turbine();
     House1();
     House2();
     School();
     House3();
     Car1();
     Car2();
     Bus1();
     Bus2();
     Ambulance();
     Road_Side_Tree();
     Lamppost_Light();
     drawRaindrops();
     Cruise_Ship();
     Fish_Ship();
     Cargo_Ship();
     Plane();
}

void Screen2(){}

void display(){

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(1);

    glMatrixMode(GL_MODELVIEW);
    if(screenOne){
        Screen1();
    }
    else if(screenTwo){
        Screen2();
    }
    glFlush();
    glutSwapBuffers();
}

void handleMouse(int button, int state, int x, int y)//Handle mouse press
{
	if (button == GLUT_LEFT_BUTTON)
	{
        day=true;
    }
    if (button == GLUT_RIGHT_BUTTON)
	{
	    day=false;
    }
    if (state == GLUT_DOWN) {
        if (button == 3) {
            planeSpeed += 0.01f;
        } else if (button == 4) {
            planeSpeed -= 0.01f; //std::max(0.01f, planeSpeed - 0.01f);
        }
    }
    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)//Handle key press
{
    if(screenOne){
        switch (key) {

            case 'N':
            case 'n':
                Car1KeyMove =! Car1KeyMove; //Car1
                break;

            case 'U':
            case 'u':
                Bus2KeyMove =! Bus2KeyMove; //Bus2
                break;

            case 'M':
            case 'm':
                Bus1KeyMove =! Bus1KeyMove; //Bus1
                break;

            case 'A':
            case 'a':
                Car2KeyMove =! Car2KeyMove; // Car2
                break;

            case 'S':
            case 's':
                AmbulanceKeyMove =! AmbulanceKeyMove; //Ambulance
                break;

            case 'F':
            case 'f':
                FishShipStop =! FishShipStop; // Fish Ship
                break;

            case 'C':
            case 'c':
                Cruise_Ship_Stop =! Cruise_Ship_Stop; //Cruise Ship
                break;

            case 'K':
            case 'k':
                Cargo_Ship_Stop =! Cargo_Ship_Stop; //Cargo Ship
                break;

            case 'P':
            case 'p':
                planeRunning =! planeRunning; //Plane
                break;

            case 'r':
                rain = !rain;  // rain
                break;

            case 'R':
                raindrop =!raindrop;  // Toggle rain
                break;

            case'1':
                screenOne=true;
                screenTwo=false;
                break;

            case'2':
                screenOne=false;
                screenTwo=true;
                break;
        }
    }
    else if(screenTwo){
        switch (key) {

            case'1':
                screenOne=true;
                screenTwo=false;
                break;

            case'2':
                screenOne=false;
                screenTwo=true;
                break;
        }
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Seaside City");
	gluOrtho2D(-10, 10, -8 ,8);
	glutInitWindowSize(320, 320);
	glutDisplayFunc(display);

	glutTimerFunc(0, RainUpdate, 0);
	glutTimerFunc(0, Updatecloud, 0);
	glutTimerFunc(0, Hot_Air_Ballon_update, 0);
	glutTimerFunc(0, update_Plane, 0);
	glutTimerFunc(20, Wind_Turbine_update, 0);
    School_Clock_update(0);
	glutTimerFunc(0, UpdateCar1, 0);
	glutTimerFunc(0, UpdateCar2, 0);
	glutTimerFunc(0, UpdateBus1, 0);
    glutTimerFunc(0, UpdateBus2, 0);
    glutTimerFunc(0, UpdateAmbulance, 0);
    glutTimerFunc(0, Wavemoving, 0);
    glutTimerFunc(0, updateCruise_Ship, 0);
    glutTimerFunc(0, updateFishShip, 0);
    glutTimerFunc(0, updateCargo_Ship, 0);

    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);

	glutMainLoop();
	return 0;
}
