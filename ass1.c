#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

GLfloat zshift=0.0,rshift=0.0;

float theta = M_PI/4;

//Used to create a wheel
void wheel(GLfloat x, GLfloat z){
//Y co-ordinate will never change so no
	glPushMatrix();
	glTranslatef(x,-0.25,z);
	glRotatef(90,0.0,1.0,0.0);
	glRotatef(rshift,0.0,0.0,1.0);
	glutWireTorus(0.05,0.1,12,12);
	glPopMatrix();

	return;
}


void bottomFrame(GLfloat x, GLfloat y , GLfloat z){
//Y co-ordinate will never change so no
	glPushMatrix();
	//glutWireCube(0.5);
	glScalef(0.4, 0.2, 0.6);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void roof(GLfloat x, GLfloat y , GLfloat z){
//Y co-ordinate will never change so no
	glPushMatrix();
	//glutWireCube(0.5);
	glScalef(0.4, 0.4, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}


void car(){
	
	wheel(0.25,0.25);
	wheel(-0.25,0.25);
	wheel(0.25,-0.25);
	wheel(-0.25,-0.25);
	bottomFrame(0.4,0.15,0.6);
	roof(0.4, 0.4, 0.3);

	return;
}


void display(void){
	
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
	
	//Quadratic for the light pole
	/*GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	gluCylinder(quadratic,0.1f,0.1f,3.0f,32,32); */

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(1.0, -0.5, 0.5);
	gluLookAt(0.3, 0.6, 1.0,  0.5, 0.0, 0.0,  0.0, 0.1, 0.0);
	
//3 sets are as follows:
//where is the camera
//Where is the camera looking
//Modify the camera position to where it was ()
	
	//The bottom right corner
	glTranslatef(0.0,0.0,zshift);

	car();
	
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

void MyIdle()
{
zshift += 0.0005;
rshift += 5;

if(zshift > 1.0) zshift = -1.0l;
glutPostRedisplay();
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutIdleFunc(MyIdle);


	glutMainLoop();
}