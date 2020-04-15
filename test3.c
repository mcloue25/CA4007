#include <math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"   
float xshift = 5.0;
void onInitialization( ) { //creating the light source
 glEnable(GL_LIGHTING);
 glEnable(GL_DEPTH_TEST); 
 GLfloat diffuse[]={0.8, 0.8, 0.8, 1.0};
 GLfloat pos[]={0.5, 0.0, 0.8, 0.0};
 glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
 glLightfv(GL_LIGHT0, GL_POSITION, pos);
 glEnable(GL_LIGHT0);
 glRotatef(-90, 1, 0, 0); //we want to see the top of the teapot
}
void onDisplay( ) {
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 //rotating on every frame (for testing purposes only)
 glRotatef(5,xshift,5,1);
 glutSolidCube(0.5);;
    glFinish();
    glutSwapBuffers();
}
void onKeyboard(unsigned char key, int x, int y) {
 if (key==32){ //do rotation upon hitting the Space key
  glutPostRedisplay();
 }
 if (key == 'q'){
  xshift ++;
  glRotatef(45,xshift,5,1);
  glutPostRedisplay();
 }
}
int main(int argc, char **argv) {
    glutInit(&argc, argv); 
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Teapot");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    onInitialization();
    glutDisplayFunc(onDisplay);
    glutKeyboardFunc(onKeyboard);
    glutMainLoop();
    return 0;
}