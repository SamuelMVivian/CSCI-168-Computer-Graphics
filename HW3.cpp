#include <GLUT/glut.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

struct points{
double x,y,z;
};

enum MouseState {
        MOUSE_NONE,
        LEFT_BUTTON_DOWN,
        RIGHT_BUTTON_DOWN
        };

MouseState mouseState;

double n=0;
double angle=0;
double angleB=0;

points mouseR={250,250,0};

points center={250,250,0};

points scale={1,1,1};

points scaleB={1,1,1};

points p[8]={{-100,-100,0},{100,-100,0},{100,100,0},{-100,100,0},{-25,-25,0},{-25,25,0},{25,25,0},{25,-25,0}};

void spin(){
    n=n+0.5;
}


void redraw( void ) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glTranslatef(center.x,center.y,center.z);
    glScalef(scale.x,scale.y,scale.z);
    glRotatef(angle,0,0,1);
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(p[0].x,p[0].y, p[0].z);
    glVertex3f(p[1].x,p[1].y, p[1].z);
    glVertex3f(p[2].x,p[2].y, p[2].z);
    glVertex3f(p[3].x,p[3].y, p[3].z);
    glEnd();

    glPushMatrix();
    glTranslatef(-50,-50,0);
    glRotatef(n,0,0,1);
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glVertex3f(p[5].x,p[5].y, p[5].z);
    glVertex3f(p[6].x,p[6].y, p[6].z);
    glVertex3f(p[7].x,p[7].y, p[7].z);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,-50,0);
    glRotatef(-n,0,0,1);
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glVertex3f(p[5].x,p[5].y, p[5].z);
    glVertex3f(p[6].x,p[6].y, p[6].z);
    glVertex3f(p[7].x,p[7].y, p[7].z);
    glEnd();
    glPopMatrix();
    glPopMatrix();


    glutPostRedisplay();
    glutSwapBuffers();
    }

void mousebutton(int button, int state, int n, int m) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            cout << n << " " << m << endl;
    mouseState = LEFT_BUTTON_DOWN;

    }else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            cout << n << " " << m << endl;
    mouseState = RIGHT_BUTTON_DOWN;
    mouseR.x=n;
    mouseR.y=m;
    scaleB=scale;
    angleB=angle;

     }else if (state == GLUT_UP) {
           mouseState = MOUSE_NONE;
        }
        glutPostRedisplay();
    }

void motion(int n, int m) {
    if(mouseState==LEFT_BUTTON_DOWN){
             //cout << n << " " << m << endl;

          center.x=n;
          center.y=m;
    }else if(mouseState==RIGHT_BUTTON_DOWN){
        //cout << n << " " << m << endl;
        float s=((mouseR.x-center.x)*(n-center.x)+(mouseR.y-center.y)*(m-center.y))/(pow(mouseR.x-center.x,2)+pow(mouseR.y-center.y,2));
        scale.x=s*scaleB.x;
        scale.y=s*scaleB.y;
        angle=angleB+(180/M_PI)*atan2(m-center.y,n-center.x);
    }
    }

    int main(int argc, char *argv[]) {

        glutIdleFunc(redraw);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow("HW3");
        glutPositionWindow(10,10);
        glutReshapeWindow(500,500);
        glClearColor(0.0,0.0,0.0,1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0,500,500,0,-10.0,10.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glutDisplayFunc(redraw);
        glutIdleFunc(spin);
        glutMotionFunc( motion);
        glutMouseFunc( mousebutton);
        glutMainLoop();
        return 0;

        }
