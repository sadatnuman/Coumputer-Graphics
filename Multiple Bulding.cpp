#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

void building(float r, float g, float b, float x, float y, float z)
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glTranslatef(x,y,z);


    glBegin(GL_POLYGON);

    glColor3ub(r,g,b);

    glVertex2f(0.5,0.5);

    glVertex2f(5,0.5);

    glVertex2f(5,5);

    glVertex2f(0.5,5);

    glEnd();

    //window left_1

    glBegin(GL_POLYGON);

    glColor3ub(255,255,0);

    glVertex2f(1,3.5);

    glVertex2f(2,3.5);

    glVertex2f(2,4.5);

    glVertex2f(1,4.5);

    glEnd();

    //window left_2

    glBegin(GL_POLYGON);

    glColor3ub(255,255,0);

    glVertex2f(1,1.5);

    glVertex2f(2,1.5);

    glVertex2f(2,2.5);

    glVertex2f(1,2.5);

    glEnd();

    //window right_1

    glBegin(GL_POLYGON);

    glVertex2f(3.5,3.5);

    glVertex2f(4.5,3.5);

    glVertex2f(4.5,4.5);

    glVertex2f(3.5,4.5);

    glEnd();

    //window left_2

    glBegin(GL_POLYGON);

    glColor3ub(255,255,0);

    glVertex2f(3.5,1.5);

    glVertex2f(4.5,1.5);

    glVertex2f(4.5,2.5);

    glVertex2f(3.5,2.5);

    glEnd();

    //Door

    glBegin(GL_POLYGON);

    glColor3ub(255,255,0);

    glVertex2f(2.25,0.5);

    glVertex2f(3.25,0.5);

    glVertex2f(3.25,2);

    glVertex2f(2.25,2);

    glEnd();

    glPopMatrix();

}

void display() {

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque

	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    building(255,0,0,0,0,0);

    building(255,0,255,-7,0,0);
    building(255,0,255,-14,0,0);
    building(255,0,255,-20,0,0);



    //building(255,0,255,1,-5,0);

	glFlush();  // Render now

}

/* Main function: GLUT runs as a console application starting at main()  */

int main(int argc, char** argv) {

	glutInit(&argc, argv);                 // Initialize GLUT

	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title

	glutInitWindowSize(320, 320);   // Set the window's initial width & height

	glutDisplayFunc(display); // Register display callback handler for window re-paint

	gluOrtho2D(-18,18,-18,18);

	glutMainLoop();           // Enter the event-processing loop

	return 0;

}

