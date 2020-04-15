#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

// This program draws a sphere using the Quadric functions.

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0,3.0,3.0,0.0,0.0,0.0,0.0,1.0,0.0);

	GLUquadricObj *MySphere;
	MySphere = gluNewQuadric();
	gluQuadricDrawStyle(MySphere, GLU_LINE);
	gluSphere(MySphere,0.5,12,12);

	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glFrustum(-1.0,1.0,-1.0,1.0,4.0,6.0);


	glViewport(0,0,w,h);
	return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("sphere");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);


	glutMainLoop();
}