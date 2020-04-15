#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

GLfloat xshift=0.0,yshift=0.0;
void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

	glTranslatef(xshift,0.0,0.0);
	glTranslatef(0.0,yshift,0.0);
	glutWireCube(0.5);
	
	glFlush();
	return;
}

void MySpecial(GLint key, GLint x, GLint y)
{
if(key == GLUT_KEY_RIGHT) 
xshift+=0.1; 
else if(key == GLUT_KEY_LEFT)
xshift-=0.1;
else if(key == GLUT_KEY_DOWN)
yshift-=0.1;
else if(key == GLUT_KEY_UP)
yshift+=0.1;
glutPostRedisplay();
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
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(MySpecial);


	glutMainLoop();
}