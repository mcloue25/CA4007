#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

/*
This program illustrates the Mouse Function Callback.
It uses the right mouse button to select the corners
of a rectangle and then draws the rectangle.

This is a revised version of the program MouseFunction.
This version should work even when the window is resized.
*/

GLfloat x1,x2,yy1,y2;
GLfloat hh;

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	glColor3f(1.0,0.0,0.0);

	glBegin(GL_POLYGON);
		glVertex2f(x1,yy1);
		glVertex2f(x1,y2);
		glVertex2f(x2,y2);
		glVertex2f(x2,yy1);
	glEnd();

	glFlush();
	return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y){
	
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON){
		
		if (first){
			x1=x; 
			yy1=hh-y;
		}
		
		else{
			x2=x;
			y2=hh-y;
			glutPostRedisplay();
		}
		first = !first;
	}

	return;
}
// GLsizei give width and height in terms of pixel values
void MyReshape(GLsizei w, GLsizei h){
	// New values of the window
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Sets the size of the window in world space
	gluOrtho2D(0.0,(GLfloat)w,0.0,(GLfloat)h); //(GLfloat)w = RHS of view window
	//setting the w & h of the screen in pixels to world co-ordinates
	glViewport(0,0,w,h);
	hh=h; //Stroing h as global variable
	return;
}


int main(int argc, char **argv){
	
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("mouse");
	glutDisplayFunc(display);
	//Reshape used for reshaping the window
	glutReshapeFunc(MyReshape);
	glutMouseFunc(MyMouse);

	glutMainLoop();
}