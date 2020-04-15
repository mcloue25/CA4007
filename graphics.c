#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

/* This program draws a cylinder and then rotates it by 90 degs.
Then it places a cuboid on top of the cylinder
*/

GLfloat eyex=1.0,eyey= 2.0,eyez=2.0;

void display(void)
{
	//Buffer
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	//Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat position [4] = {0.3,0.6,1.0,1.0};
	glLightfv(GL_LIGHT0,GL_POSITION,position); 
	
	GLfloat  ambient[4] = {0.33 , 0.22 , 0.03 , 1.0 };
	GLfloat  diffuse[4] = {0.78 , 0.57 , 0.11 , 1.0 };
	GLfloat specular[4] = {0.99 , 0.91 , 0.81 , 1.0 };

	GLfloat shininess = 27.8; //32.0;
	GLfloat normal[3] = {0.0,0.0,-1.0};
	//GLfloat position[4] = {0.3,0.6,1.0,1.0};
	// x, y, z

	glClearColor(0.0,0.0,1.0,1.0);

	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); 
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex,eyey,eyez,0.0,0.0,0.0,0.0,1.0,0.0);
	GLUquadricObj *MyCylinder;
	MyCylinder = gluNewQuadric();
	gluQuadricDrawStyle(MyCylinder, GLU_FILL);
	glRotatef(-90.0,1.0,0.0,0.0);
	
	// Creates the vase
	gluCylinder(MyCylinder,0.5,0.5,1.5,12,12); 
	
	// Creates the stem 
	gluCylinder(MyCylinder,0.05,0.1,2.0,12,12); 
	glTranslatef(0.0,0.0,2.0);
	glRotatef(45.0,1.0,0.0,0.0);
	
	GLUquadricObj *flower;
	
	// Creates the flower
	flower = gluNewQuadric();
	gluQuadricDrawStyle(flower, GLU_FILL);
	gluSphere(flower,0.25,12,12);
	
	glFlush();
	return;

}


void MySpecial(GLint key, GLint x, GLint y){
	//Uses the arrow keys

	if(key == GLUT_KEY_RIGHT) eyex += 0.01;
	else if(key == GLUT_KEY_LEFT) eyex -= 0.01;
	if(key == GLUT_KEY_UP) eyey += 0.01;
	else if(key == GLUT_KEY_DOWN) eyey -= 0.01;

	glutPostRedisplay();

	glFlush();
	return;
}
	


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,6.0);


	glViewport(0,0,w,h);
	return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cylinder");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial); //Uses the arrow keys


	glutMainLoop();
}


