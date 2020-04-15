#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>


void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pos[4] = {0.0,0.0,1.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glRotatef(90.0,1.0,0.0,0.0);
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

	GLfloat x,y=-1.0,z,theta=0.0;

	glBegin(GL_QUAD_STRIP);
	for(int i=0; i <500; i++)
	{
		theta += 0.1;
		x=0.6*cos(theta); z=0.6*sin(theta);
		y += 0.005;
		glNormal3f(x/0.6,0,z/0.6);
		glVertex3f(x,y,z);
		glVertex3f(x,y+0.07,z);
	}				
	glEnd();


	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.3,5.0);
//	gluPerspective(60,1.0,0.3,5.0);
	glViewport(0,0,w,h);
	return;
}




int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}