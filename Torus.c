#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

//This program draws a torus

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0,3.0,3.0,0.0,0.0,0.0,0.0,1.0,0.0);

//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);


	glutWireTorus(0.5,0.75,12,12);

	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glFrustum(-2.0,2.0,-2.0,2.0,4.0,7.0);


	glViewport(0,0,w,h);
	return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("torus");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);


	glutMainLoop();
}