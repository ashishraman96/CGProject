#include <stdlib.h>
#include <GL/glut.h>
#include "variables.h"

#include<iostream>
using namespace std;

void instructions() {
	cout << "                             *****INSTRUCTIONS*****                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	//cout << " m : Mesh-View ON/OFF" << endl;
	//cout << " f : FPS Display ON/OFF" << endl;
	//cout << " -space- : Dance ON/OFF" << endl;
	//cout << " w : Fly 'I' ON/OFF" << endl;
	//cout << " d : Disco Mode ON/OFF" << endl;
	cout << "R/r: Rotation Mode ON/OFF" << endl;
	cout << "x/y/z: Change Axis of Rotation" << endl;
	cout << "1/2: Increase/Decrease speed of Rotation" << endl;
	//cout << " z/x: Zoom In / Zoom Out" << endl;
	//cout << " n : Change Color of the 'I'" << endl;
	//cout << " o : Display In-App Function States" << endl;
	cout << " c : Clear Console Screen" << endl;
	cout << " Esc: Quit" << endl;
	cout << "--------------------------------------------------------------------------------" << endl << endl;
}

void triangle(int a, int b, int c) {
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	glEnd();
}

void colorcube(void) {
	triangle(0,2,3);
	triangle(0,2,1);
	triangle(3,0,1);
	triangle(2,3,1);
}



void display(void) {

	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glLoadIdentity();
	 glRotatef(theta[0], 1.0, 0.0, 0.0);
	 glRotatef(theta[1], 0.0, 1.0, 0.0);
	 glRotatef(theta[2], 0.0, 0.0, 1.0);

	 colorcube();
	 glFlush();
	 glutSwapBuffers();
}

void spinCube() {

	theta[axis] += speed;
	if( theta[axis] > 360.0 )
		theta[axis] -= 360.0;
	if(theta[axis] <= 0.0)
		theta[axis] = 0.0;
	glutPostRedisplay();
}



void keyboard(unsigned char btn, int x, int y) {

	if(btn == 'r' || btn == 'R') {
		if(rotation) {
			speed = 0.0;
			rotation = false;
		}
		else {
			speed = 1.0;
			rotation = true;
		}
	}

	if(btn == '1')
		if(rotation)
			speed += 1.0;

	if(btn == '2')
		if(rotation)
			speed -= 1.0;

	if(btn == 'x' || btn =='X')
		axis = 0;
	if(btn == 'y' || btn =='Y')
		axis = 1;
	if(btn == 'z' || btn =='Z')
		axis = 2;

	if(btn == 27)
		exit(0);

	if (btn == 'c' || btn == 'C') {
		system("clear");
		instructions();
	}
}

void myReshape(int w, int h) {
	glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (w <= h)
  	glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
  else
    glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	instructions();
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
  glutCreateWindow(WINDOW_TITLE);
  glutReshapeFunc(myReshape);
  glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
  glutMainLoop();
  return 0;
}
