#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>
#include <stdio.h>

/*
This program illustrates some 3D operations.
It draws a wire cube with sides of length 0.5 in World Coordinates.
You can uses the glOrtho or glFrustum functions
to choose either orthographic or perspective projection.
You can use the gluLookAt function to choose the viewpoint, 
view direction and the up vector.
*/

float theta = M_PI/4;

float state = 0;
float state2 = 0;


int coords[64];
int totalCubes = 0;
float theta2[64],theta3[64];

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//==========================================================================================
	GLfloat  ambient[4] = {0.3, 0.0, 0.0, 1.0};
	GLfloat  diffuse[4] = {0.6, 0.0, 0.0, 1.0};
	GLfloat specular[4] = {0.8, 0.6, 0.6, 1.0};
	GLfloat shininess = 32.0;
	GLfloat normal[3] = {0.0,0.0,1.0};
	GLfloat position[4] = {1.0,1.0,1.0,1.0};
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);


	position[1]=cos(theta); position[2]=sin(theta);

	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	
	for(int i = totalCubes-1; i >= 0; i--) {
		GLfloat x = (coords[i*2]-250.0)/250.0;
		GLfloat y =	-(coords[i*2 + 1]-250.0)/250.0;
		// printf("cube x: %d cube y: %d\n",coords[i*2], coords[i*2 + 1]);
		glPushMatrix();
		glRotatef(theta2[i],0.0,1.0,0.0);
		glRotatef(theta3[i],1.0,0.0,0.0);
		glTranslatef(x, y, 0.0);
		glutSolidCube(0.5);
		glTranslatef(-x, -y, 0.0);
		
	}
	
	
	glutSwapBuffers();
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
	glFrustum(-1.0,1.0,-1.0,1.0,8.0,15.0);
	// gluPerspective(60,1.0,0.3,10.0);
	glViewport(0,0,w,h);
	return;
}


void mouseClicks(int button, int mouseState, int x, int y) {

	
    if(button == GLUT_LEFT_BUTTON && mouseState == GLUT_DOWN) {
		printf("x: %d, y: %d totalCubes: %d \n", x, y, totalCubes);
		coords[totalCubes*2    ] = x;
		coords[totalCubes*2 + 1] = y;
		theta2[totalCubes]=0.0;
		theta3[totalCubes]=0.0;
		totalCubes++;


		glutPostRedisplay();
    }
}

void rotate(int key, int x, int y) {

	if(key == GLUT_KEY_LEFT) theta2[totalCubes-1] += 5.0;
	if(key == GLUT_KEY_RIGHT) theta2[totalCubes-1] -= 5.0;
	if(key == GLUT_KEY_UP) theta3[totalCubes-1] +=5;
	if(key == GLUT_KEY_DOWN) theta3[totalCubes-1] -= 5.0; 
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,65);
	glutCreateWindow("cubes making!");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(mouseClicks);
	glutSpecialFunc(rotate);
	glutMainLoop();
}