#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

float theta = M_PI/4;

void display(void)
{
//	GLfloat  ambient[4] = {0.3, 0.0, 0.0, 1.0};
//	GLfloat  diffuse[4] = {0.6, 0.0, 0.0, 1.0};
//	GLfloat specular[4] = {0.8, 0.6, 0.6, 1.0};

	GLfloat  ambient[4] = {0.33 , 0.22 , 0.03 , 1.0 };
	GLfloat  diffuse[4] = {0.78 , 0.57 , 0.11 , 1.0 };
	GLfloat specular[4] = {0.99 , 0.91 , 0.81 , 1.0 };

	GLfloat shininess = 27.8; //32.0;
	GLfloat normal[3] = {0.0,0.0,-1.0};
	GLfloat position[4] = {0.0,0.0,1.0,1.0};

	glClearColor(0.0,0.0,1.0,1.0);

	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	position[1]=1.5*cos(theta); position[2]=1.5*sin(theta);

	glLightfv(GL_LIGHT0, GL_POSITION, position);


	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

/*	glNormal3fv(normal);
	glBegin(GL_POLYGON);
		glNormal3f(0.0f,0.0f,1.0);
		glVertex3f(0.5,-0.5,0.0);
		glVertex3f(0.5,0.5,0.0);
		glVertex3f(-0.5,0.5,0.0);
		glVertex3f(-0.5,-0.5,0.0);
	glEnd();
*/
	//glutSolidCube(0.5);
	glutSolidTorus(0.5,1.0,12,12);
	glutSwapBuffers();
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
//	glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);
	glViewport(0,0,w,h);
	return;
}

void MyIdle()
{

	theta += 0.001;
	if (theta > 2*M_PI) theta -= 2*M_PI;
	glutPostRedisplay();

	return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutIdleFunc(MyIdle);


	glutMainLoop();
}