//#ifdef __APPLE__

//#else
#include <GLUT/glut.h>
//#include <GL/glut.h>
//#endif

#include <stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;

struct points{
double x,y,z;
};

enum MouseState {
        MOUSE_NONE,
        LEFT_BUTTON_DOWN
        };

MouseState mouseState;

points p[5]={{.25,.25,0},{.75,.25,0},{.75,.75,0},{.25,.75,0},{0.5,0.5,0}};


void redraw( void ) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
    glVertex3f(p[0].x,p[0].y, p[0].z);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glVertex3f(p[3].x,p[3].y, p[3].z);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f(p[0].x,p[0].y, p[0].z);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glVertex3f(p[1].x,p[1].y, p[1].z);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex3f(p[1].x,p[1].y, p[1].z);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glVertex3f(p[2].x,p[2].y, p[2].z);
    glEnd();

    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex3f(p[2].x,p[2].y, p[2].z);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glVertex3f(p[3].x,p[3].y, p[3].z);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(p[0].x,p[0].y, p[0].z);
    glVertex3f(p[1].x,p[1].y, p[1].z);
    glVertex3f(p[1].x,p[1].y, p[1].z);
    glVertex3f(p[2].x,p[2].y, p[2].z);
    glVertex3f(p[2].x,p[2].y, p[2].z);
    glVertex3f(p[3].x,p[3].y, p[3].z);
    glVertex3f(p[3].x,p[3].y, p[3].z);
    glVertex3f(p[0].x,p[0].y, p[0].z);
    glVertex3f(p[0].x,p[0].y, p[0].z);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glVertex3f(p[1].x,p[1].y, p[1].z);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glVertex3f(p[2].x,p[2].y, p[2].z);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glVertex3f(p[3].x,p[3].y, p[3].z);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex3f(p[0].x,p[0].y, p[0].z);
    glVertex3f(p[1].x,p[1].y, p[1].z);
    glVertex3f(p[2].x,p[2].y, p[2].z);
    glVertex3f(p[3].x,p[3].y, p[3].z);
    glVertex3f(p[4].x,p[4].y, p[4].z);
    glPointSize(3);
    glEnd();

    glutSwapBuffers();
    }

void mousebutton(int button, int state, int n, int m) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            cout << n << " " << m << endl;
    mouseState = LEFT_BUTTON_DOWN;
    } else if (state == GLUT_UP) {
           mouseState = MOUSE_NONE;
        }
        glutPostRedisplay();
    }

void motion(int n, int m) {
    if(mouseState==LEFT_BUTTON_DOWN){
             cout << n << " " << m << endl;
            if((abs(p[0].x-((float)n/500.0))<0.1)&&(abs(p[0].y-((float)(abs(m-500))/500.0))<0.1)){
            p[0].x=(float)n/500.0;
            p[0].y=(float)(abs(m-500))/500.0;
        }else if((abs(p[1].x-((float)n/500.0))<0.1)&&(abs(p[1].y-((float)(abs(m-500))/500.0))<0.1)){
            p[1].x=(float)n/500.0;
            p[1].y=(float)(abs(m-500))/500.0;;
        }else if((abs(p[2].x-((float)n/500.0))<0.1)&&(abs(p[2].y-((float)(abs(m-500))/500.0))<0.1)){
            p[2].x=(float)n/500.0;
            p[2].y=(float)(abs(m-500))/500.0;;
        }else if((abs(p[3].x-((float)n/500.0))<0.1)&&(abs(p[3].y-((float)(abs(m-500))/500.0))<0.1)){
            p[3].x=(float)n/500.0;
            p[3].y=(float)(abs(m-500))/500.0;;
        }else if((abs(p[4].x-((float)n/500.0))<0.1)&&(abs(p[4].y-((float)(abs(m-500))/500.0))<0.1)){
            p[4].x=(float)n/500.0;
            p[4].y=(float)(abs(m-500))/500.0;;
        }
        glutPostRedisplay();
    }
    }

    int main(int argc, char *argv[]) {

        glutIdleFunc(redraw);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow("One triangle");
        glutPositionWindow(10,10);
        glutReshapeWindow(500,500);
        glClearColor(0.0,0.0,0.0,1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glutDisplayFunc(redraw);
        glutMotionFunc( motion);
        glutMouseFunc( mousebutton);
        glutMainLoop();
        return 0;

        }
