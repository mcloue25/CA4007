#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

/*
This program illustrates the Mouse Function Callback.
It uses the right mouse button to select the corners
of a rectangle and then draws the rectangle.

This program assumes the window size is 500x500.
If you resize the window, it will not work.
*/
//Global float variables
GLfloat x1,x2,y1,y2;

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	glColor3f(1.0,0.0,0.0);

	glBegin(GL_POLYGON);
	//co-ordinates of the vertices
		glVertex2f(x1,y1);
		glVertex2f(x1,y2);
		glVertex2f(x2,y2);
		glVertex2f(x2,y1);
	glEnd();

	glFlush();
	return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y){ 
	//Glint = Open GL integer
	//State = is button pressed down or not(pressed up)
	//x and y are pixel values
	
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON){
	//Mouse buttons are GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, GLUT_MIDDLE_BUTTON
		if (first){
			//Records co-ordinates of mouse click
			//Must convert pixel co-ordinates to world co-ordinates
			x1=(x-250.0)/250.0; 
			y1=-(y-250)/250.0;;
			// (y-250) getting the world co-ordinates
			// divide by 250. because box is 2 world units wide/ 500px in main
			
		}
		
		else{
			x2=(x-250.0)/250.0;
			y2=-(y-250)/250.0;
			//On second click call display function
			glutPostRedisplay();
		}
		first = !first;
	}

	return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("mouse");
	glutDisplayFunc(display);
	glutMouseFunc(MyMouse);


	glutMainLoop();
}