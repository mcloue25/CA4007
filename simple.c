#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

// gcc filename.c -o filename glut32.lib -lopengl32 -lglu32 (-lm) if you need to use the math library
// filename

void display(void)
{
	// RGB Values g = 0, r = 0, b = 1
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON); //2D polygon  always starts with glBegina dn end with glEnd. 
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5); //vertices of the polygon in 2D, 
		glVertex2f(0.5,0.5);  // given in world co-ordinates
		glVertex2f(0.5,-0.5); // Default is in the middle of the screen 
	glEnd();

	glFlush();
	return;
}

int main(int argc, char **argv) // Gives tyoe of the variabke that the function returns
{
	glutInit(&argc, argv); // starts the whole system
	glutCreateWindow("simple"); //sets window size in pixels
	glutDisplayFunc(display); //in terms of origin of the screen (top left corner)
	glutMainLoop(); //Actuallt starts the whole thing
}