#include <GL/glut.h>
#include <cmath>
#include <stdlib.h>
#include <iostream>
//#include <GLUT/glut.h>

using namespace std;

void render(void);

void keyboard(unsigned char c, int x, int y);

void mouse(int button, int state, int x, int y);

const float r = 1.0;
const float g = 1.0;
const float b = 1.0;

const float dragon_r = 0.0;
const float dragon_g = 0.5;
const float dragon_b = 0.0;

const float border_r = 1.0;
const float border_g = 0.0;
const float border_b = 0.0;

const float breath_r = 1.0;
const float breath_g = 0.0;
const float breath_b = 0.0;

const float DEG2RAD = 3.14159/180;
const float scaleconst  = 0.002;

bool first = true;

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

void DrawFullCircle(float cx, float cy, float r, int num_segments, int begindraw, int enddraw, bool isBreath) {
    glBegin(GL_TRIANGLE_FAN);
    if (isBreath) {
        glColor3f(breath_r, breath_g, breath_b);
    } else {
        glColor3f(r, g, b);
    }
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0 * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(border_r, border_g, border_b);
    for(int ii = begindraw; ii < min(num_segments, enddraw); ii++)
    {
        float theta = 2.0 * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

void DrawPartCircle(float cx, float cy, float r, int num_segments, int begindraw, int enddraw)
{
    cout << "air besar anda";
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(r, g, b);
    for(int ii = begindraw; ii < min(enddraw, num_segments); ii++)
    {
        float theta = 2.0 * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(border_r, border_g, border_b);
    for(int ii = begindraw; ii < min(enddraw, num_segments); ii++)
    {
        float theta = 2.0 * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
    cout << " baunya tidak sedap" << endl;
}

void DrawRectangle(float x1, float y1, float x2, float y2) {
    glColor3f(r, g, b);
    glRectf(x1,y1,x2,y2);
}

void DrawPolygon(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void DrawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINE_STRIP);
    glColor3f(border_r, border_g, border_b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void DrawBackground() {
    glBegin(GL_POLYGON);
    float _y = 1500;
    glColor3f(0.4, 0.6, 1);
    glVertex2f(-1000, 800+_y);
    glVertex2f(1000, 800+_y);

    glColor3f(r, g, b);
    glVertex2f(1000, -1000);
    glVertex2f(-1000, -1000);

    glEnd();
}

void DrawSun(float cx, float cy, float r, int num_segments, int begindraw, int enddraw) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 0.6);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0 * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * 1.1 * cosf(theta);//calculate the x component
        float y = r * 1.1 * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 0.0);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0 * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();


    for(int ii = 0; ii < 50; ii++)
    {
        float theta = 2.0 * 3.1415926f * float(ii) / float(50);//get the current angle

        float x1 = r * 1.15 * cosf(theta);  //calculate the x component
        float y1 = r * 1.15 * sinf(theta);  //calculate the y component

        float x2 = r * 1.4 * cosf(theta);  //calculate the x component
        float y2 = r * 1.4 * sinf(theta);  //calculate the y component


        glBegin(GL_LINES);

        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(x1 + cx, y1 + cy);
        glVertex2f(x2 + cx, y2 + cy);

        glEnd();
    }
}


/* =========================================*/
/*                   MAIN                   */
/* =========================================*/

void render(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    //=> SCALE
    if (first) {
        glScalef(scaleconst, scaleconst, scaleconst);
        glTranslatef(-300, 105, 0);
        first = false;
    }

    //=> SHAPES

    DrawBackground();
    DrawSun(600, 200, 100, 1000, 0, 1000);
    glutSwapBuffers();
}

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("DU RAH GHHHOOONN ZZZZZHHH");

    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
}

void keyboard(unsigned char c, int x, int y) {
    if (c == 27) {
        exit(0);
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON) {
        exit(0);
    }
}






