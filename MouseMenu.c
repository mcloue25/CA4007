#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
/*
This program illustrates the Mouse Function Callback.
It uses the left mouse button to select the corners
of a rectangle and then draws the rectangle.
The right mouse button pops up a menu. The first
option clears the screen. The second exits the program.
This program assumes the window size is 500x500.
If you resize the window, it will not work.
*/
GLfloat x1,x2,y1,y2;



void display(void)
{
glClearColor(0.0,0.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(3.0);
glColor3f(1.0,0.0,0.0);
glFlush();
return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{
static int first=1;
if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
{
if (first)
{
x1=(x-250.0)/250.0;
y1=-(y-250.0)/250.0;
}
else
{
x2=(x-250.0)/250.0;
y2=-(y-250.0)/250.0;
glBegin(GL_POLYGON);
glVertex2f(x1,y1);
glVertex2f(x1,y2);
glVertex2f(x2,y2);
glVertex2f(x2,y1);
glEnd();
glFlush();
}

first = !first;
}
return;
}

void mymenu(int value)
{
if(value == 1) {glClear(GL_COLOR_BUFFER_BIT); glFlush();}
if(value == 2) exit(0);
}

int main(int argc, char **argv)
{
GLint id;
glutInit(&argc, argv);
glutInitWindowSize(500,500);
glutInitWindowPosition(500,200);
glutCreateWindow("mouse");
glutDisplayFunc(display);
glutMouseFunc(MyMouse);
id = glutCreateMenu(mymenu);
//Adding options to the menu
glutAddMenuEntry("clear",1);
glutAddMenuEntry("exit",2);
//Attaching a menu to the right click  button
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
}
