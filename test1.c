#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

GLfloat xshift=0.0, yshift, zshift=0.0;

GLfloat x1,z1,x2,z2;

GLfloat eyex=0.0,eyey=0.7,eyez=1.0;

GLfloat objects[10][20];

GLint k=0,nobjects=0,item=1;

GLint win1,win2, win3;


void wall(GLfloat xx1,GLfloat zz1,GLfloat xx2,GLfloat zz2){
	
	glBegin(GL_POLYGON);	
	glVertex3f(xx2,0.0,zz2);
	glVertex3f(xx2,1.0,zz2);
	glVertex3f(xx1,1.0,zz1);
	glVertex3f(xx1,0.0,zz1);
	glEnd();
 	
	return;
}

// ----------------------------- Table Components -----------------------------------------------

void tabletop(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.3,0.05,0.3);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void tableleg(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.05,0.3,0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void table(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	tabletop(0.0,0.325,0.0);
	tableleg(0.15,0.15,0.15);
	tableleg(-0.15,0.15,0.15);
	tableleg(0.15,0.15,-0.15);
	tableleg(-0.15,0.15,-0.15);
	glPopMatrix();

	return;
}

// ---------------------------------- Bed Components ----------------------------------------------

void mattress(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.6,0.2,0.6);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void leg(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.05,0.1,0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void bed(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	mattress(0.0,0.2,0.0);
	leg(0.25,0.05,0.25);
	leg(-0.25,0.05,0.25);
	leg(0.25,0.05,-0.25);
	leg(-0.25,0.05,-0.25);
	glPopMatrix();

	return;
}

// ----------------------------------- Chair Components -------------------------------------------

void chairSeat(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.3,0.05,0.3);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void chairFrontLeg(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.05,0.3,0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void chairBackLeg(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.05,0.6,0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void chairTopbar(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.3,0.05,0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}



void chair(GLfloat x, GLfloat y, GLfloat z){
	
	glPushMatrix();
	glTranslatef(x,y,z);
	chairSeat(0.0,0.325,0.0);
	chairFrontLeg(0.15,0.15,0.15);
	chairFrontLeg(-0.15,0.15,0.15);
	chairBackLeg(0.15,0.3,-0.15);
	chairBackLeg(-0.15,0.3,-0.15);
	chairTopbar(0.0,0.6,-0.15);
	glPopMatrix();
	
	return;
}



void display(void){
	
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pos[4] = {0.0,1.0,1.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex,eyey,eyez,0.0,0.0,0.0,0.0,1.0,0.0);
	
	// The Floor is a 2x2 polygon
	glPushMatrix();
	glBegin(GL_POLYGON);
	//glNormal3f(0.0,1.0,0.0); // In the X, Z plane with the normal pointing upwards
	glVertex3f(-2.0,0.0,0.5);
	glVertex3f(2.0,0.0,0.5);
	glVertex3f(2.0,0.0,-1.5);
	glVertex3f(-2.0,0.0,-1.5);
	glEnd();
	glPopMatrix();


	for(k=0; k<nobjects; k++){
		
		if(objects[0][k] == 1)
			bed(objects[1][k],0.0,objects[3][k]);
		else if(objects[0][k] == 2)
			table(objects[1][k],0.0,objects[3][k]);
		else if(objects[0][k] == 3)
			chair(objects[1][k],0.0,objects[3][k]);
		//Addon
		else
			wall(objects[1][k],objects[2][k],objects[3][k],objects[4][k]);
	}
	
	if(item == 1)
		bed(xshift,0.0,zshift);
	else if(item ==2)
		table(xshift,0.0,zshift);
	
	else if(item == 3)
		chair(xshift,0.0,zshift);
	//Addon
	else
		wall(x1,z1,x2,z2);
	

	glFlush();
	return;
}

void PlanDisplay(void){
	
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pos[4] = {0.0,1.0,1.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0);
	
	
	glPushMatrix();
	glBegin(GL_POLYGON);
	//glNormal3f(0.0,1.0,0.0);
	glVertex3f(-2.0,0.0,0.5);
	glVertex3f(2.0,0.0,0.5);
	glVertex3f(2.0,0.0,-1.5);
	glVertex3f(-2.0,0.0,-1.5);
	glEnd();
	glPopMatrix();


	for(k=0; k<nobjects; k++){
		
	if(objects[0][k] == 1)
		bed(objects[1][k],0.0,objects[3][k]);
	else if(objects[0][k] == 2)
		table(objects[1][k],0.0,objects[3][k]);
	
	else
		chair(objects[1][k],0.0,objects[3][k]);
	}
	
	if(item == 1)
		bed(xshift,0.0,zshift);
	else if(item == 2)
		table(xshift,0.0,zshift);
	else 
		chair(xshift,0.0,zshift);
	//Addon

	

	glFlush();
	return;
}

void ElevationDisplay(void){
	
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pos[4] = {0.0,1.0,1.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
	
	
	glPushMatrix();
	glBegin(GL_POLYGON);
	//glNormal3f(0.0,1.0,0.0);
	glVertex3f(-2.0,0.0,0.5);
	glVertex3f(2.0,0.0,0.5);
	glVertex3f(2.0,0.0,-1.5);
	glVertex3f(-2.0,0.0,-1.5);
	glEnd();
	glPopMatrix();


	for(k=0; k<nobjects; k++){
		
	if(objects[0][k] == 1)
		bed(objects[1][k],0.0,objects[3][k]);
	
	else if(objects[0][k] == 2)
		table(objects[1][k],0.0,objects[3][k]);
	
	else
		chair(objects[1][k],0.0,objects[3][k]);
	//Addon
	}
	
	if(item == 1)
		bed(xshift,0.0,zshift);
	else if(item == 2)
		table(xshift,0.0,zshift);
	else 
		chair(xshift,0.0,zshift); //COuld add a yshift if yu wanted to puyt things on top of one another 
	//Addon

	

	glFlush();
	return;
} 

void MySpecial(GLint key, GLint x, GLint y){
	//Uses the arrow keys

	if(key == GLUT_KEY_RIGHT) xshift += 0.1;
	else if(key == GLUT_KEY_LEFT) xshift -= 0.1;
	if(key == GLUT_KEY_UP) zshift += 0.1;
	else if(key == GLUT_KEY_DOWN) zshift -= 0.1;

	glutPostRedisplay();
	glutPostWindowRedisplay(win2);
	glutPostWindowRedisplay(win3);

	glFlush();
	return;
}

void MyKeyboard(unsigned char key, GLint x, GLint y){

	if(key == 'q') {
		//Addon
		if(item < 4){
			objects[0][k]=item;
			objects[1][k]=xshift;
			objects[2][k]=0.0;
			objects[3][k]=zshift;
		}
		else{
			objects[0][k]=item;
			objects[1][k]=x1;
			objects[2][k]=z1;
			objects[3][k]=x2;
			objects[4][k]=z2;
		}
		
	nobjects++;
	}


	if(key == 'a')eyex += 0.01;
	if(key == 's')eyex -= 0.01;
	if(key == 'w')eyey += 0.01;
	if(key == 'x')eyey -= 0.01;
	if(key == 'o')eyez += 0.01;
	if(key == 'p')eyez -= 0.01;

	glutPostRedisplay();
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

void PlanReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
//	glFrustum(-1.0,1.0,-1.0,1.0,0.3,5.0);
//	gluPerspective(60,1.0,0.3,5.0);
	glViewport(0,0,w,h);
	return;
}

void mymenu(int value)
{
item=value;
glutPostRedisplay();
glutPostWindowRedisplay(win2);
glutPostWindowRedisplay(win3);
return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON)
	{
		if (first)
		{
			x1=(x-250.0)/125.0; 
			z1=(y-250)/125.0;
		}
		else
		{
			x2=(x-250.0)/125.0;
			z2=(y-250)/125.0;
			glutPostRedisplay();
			glutPostWindowRedisplay(win1);
			
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
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	win1 = glutCreateWindow("interiors");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(MySpecial); //Uses the arrow keys
	glutKeyboardFunc(MyKeyboard);

	glutCreateMenu(mymenu);
	glutAddMenuEntry("bed",1);
	glutAddMenuEntry("table",2);
	glutAddMenuEntry("chair",3);
	glutAddMenuEntry("wall",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	//Addon
	//Separate Glut create and display function for each window 
	win2 = glutCreateWindow("plan");
	glutDisplayFunc(PlanDisplay);	
	glutReshapeFunc(PlanReshape);
	
	win3 = glutCreateWindow("Elevation");
	glutDisplayFunc(ElevationDisplay);
	glutMouseFunc(MyMouse);

	//glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}