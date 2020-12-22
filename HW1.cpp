/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <cmath>

using namespace std;

void redraw( void ) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0.0);
    glVertex3f(.5, 0, 0.0);
    glVertex3f(0.25, 0.35, 0.0);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<5;i++){
        glVertex3f(.1*cos(2.0*M_PI*(i/5.0))+0.25,.1*sin(2.0*M_PI*(i/5.0))+0.75,0.0);
    }
    glEnd();

    glColor4f(1,1,0,0.5);
    glBegin(GL_POLYGON);
    for(int i=0;i<6;i++){
        glVertex3f(.2*cos(2.0*M_PI*(i/6.0))+.25,.2*sin(2.0*M_PI*(i/6.0))+.75,0);
    }
    glEnd();

    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    for(int i=0;i<7;i++){
        glVertex3f(.2*cos(2.0*M_PI*(i/7.0))+.75,.2*sin(2.0*M_PI*(i/7.0))+0.25,0);
    }
    glEnd();

    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
    for(int i=0;i<8;i++){
        glVertex3f(.2*cos(2.0*M_PI*(i/8.0))+.75,.2*sin(2.0*M_PI*(i/8.0))+.75,0);
    }
    glEnd();

    glColor4f(1, 0, 0,0.5);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0, 0.0);
    glVertex3f(0.25,0.5, 0.0);
    glVertex3f(.75,0.5, 0.0);
    glVertex3f(.75,0,0);
    glEnd();

    glutSwapBuffers();

    }

    int main(int argc, char *argv[]) {

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
        glutMainLoop();
        return 0;

        }
