#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include "variables.h"

#include<iostream>
using namespace std;

void instructions() {
	cout << "                             *****INSTRUCTIONS*****                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	//cout << " m : Mesh-View ON/OFF" << endl;
	cout << "F/f : FPS Display ON/OFF" << endl;
	//cout << " -space- : Dance ON/OFF" << endl;
	//cout << " w : Fly 'I' ON/OFF" << endl;
	//cout << " d : Disco Mode ON/OFF" << endl;
	cout << "R/r: Rotation Mode ON/OFF" << endl;
	cout << "x/y/z: Change Axis of Rotation" << endl;
	cout << "1/2: Increase/Decrease speed of Rotation" << endl;
	cout << "v/b: Zoom In / Zoom Out" << endl;
	//cout << " n : Change Color of the 'I'" << endl;
	cout << "O/o : Display In-App Function States" << endl;
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
	glScalef(zoomer, zoomer, zoomer);
	triangle(0,2,3);
	triangle(0,2,1);
	triangle(3,0,1);
	triangle(2,3,1);
}

void display(void) {

	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glLoadIdentity();
	 checkForText();
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

void updatedisplay(int value) {
	//To update the display repeatedly
	glutPostRedisplay();
	frameCount++;
	//  Get the number of milliseconds since glutInit called
	//  (or first call to glutGet(GLUT ELAPSED TIME)).
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	//  Calculate time passed
	int timeInterval = currentTime - previousTime;
	if (timeInterval > 1000)
	{
		//  calculate the number of frames per second
		fps = frameCount / (timeInterval / 1000.0f);
		//  Set time
		previousTime = currentTime;
		//  Reset frame count
		frameCount = 0;
	}
	glutTimerFunc(10, updatedisplay, 0);
}

void displayFPS(int value) {
	if (fpsMode)
		cout << "FPS : " << fps << endl;

	glutTimerFunc(1000, displayFPS, 0);
}

void drawText(float x, float y, char *text) {
	int length = strlen(text);		//Grabs the length of the text

	glColor3f(0, 0, 0);

	//Position to draw the text
	glRasterPos2f(x, y);

	glDisable(GL_TEXTURE);
	glDisable(GL_TEXTURE_2D);
	for (int i = 0; i < length; i++)
	{
		//2nd parameter is sent as integers as the function needs the ASCII codes
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE);
}

void checkForText() {
	if (inAppDisplay) {
		/*if (dancing) {
			drawText(-2 * asp_rat, 1.9 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.9 *asp_rat, "Dancing-Mode : ON");
		}
		else {
			drawText(-2 * asp_rat, 1.9 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.9 * asp_rat, "Dancing-Mode : OFF");
		}*/

		/*if (disco_mode)	{
			drawText(-2 * asp_rat, 1.8 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.8 * asp_rat, "Disco-Mode : ON");
		}
		else {
			drawText(-2 * asp_rat, 1.8 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.8 * asp_rat, "Disco-Mode : OFF");
		}*/

		/*if (whoosh)	{
			drawText(-2 * asp_rat, 1.7 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.7 * asp_rat, "Fly-Mode : ON");
		}
		else {
			drawText(-2 * asp_rat, 1.7 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.7 * asp_rat, "Fly-Mode : OFF");
		}*/

		/*if (meshview) {
			drawText(-2 * asp_rat, 1.6 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.6 * asp_rat, "Meshview : ON");
		}
		else {
			drawText(-2 * asp_rat, 1.6 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.6 * asp_rat, "Meshview : OFF");
		}*/

		if (rotation) {
			drawText(-2 * asp_rat, 1.5 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.5 * asp_rat, "Rotation-Mode : ON");
			//drawText(-2 * asp_rat, 1.5 * asp_rat, "Speed: ")
		}
		else {
			drawText(-2 * asp_rat, 1.5 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.5 * asp_rat, "Rotation-Mode : OFF");
		}

		if (fpsMode) {
			drawText(-2 * asp_rat, 1.4 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.4 * asp_rat, "FPS : ON (Check Cosole)");
		}
		else
		{
			drawText(-2 * asp_rat, 1.4 * asp_rat, "                                       ");
			drawText(-2 * asp_rat, 1.4 * asp_rat, "FPS : OFF");
		}
	}
}

void keyboard(unsigned char btn, int x, int y) {

	if(btn == 'r' || btn == 'R') {
		if(rotation) {
			speed = 0.0;
			rotation = !rotation;
			cout << "Stopped Rotation!" << endl;
		}
		else {
			speed = 1.0;
			rotation = !rotation;
			cout << "Started Rotation" << endl;
		}
	}

	if(btn == '1') {
		if(rotation) {
			speed += 1.0;
			cout << "Speed Increased" << endl;
		}
	}


	if(btn == '2') {
		if(rotation) {
			speed -= 1.0;
			cout << "Speed Decreased" << endl;
		}
	}

	if(btn == 'x' || btn =='X') {
		if(rotation) {
			axis = 1;
			cout << "X-axis rotation!" <<endl;
		}
		else
			cout << "Please begin rotation first!";
	}
	if(btn == 'y' || btn =='Y') {
		if(rotation) {
			axis = 0;
			cout << "Y-axis rotation!" <<endl;
		}
		else
			cout << "Please begin rotation first!";
	}
	if(btn == 'z' || btn =='Z') {
		if(rotation) {
			axis = 2;
			cout << "Z-axis rotation!" <<endl;
		}
		else
			cout << "Please begin rotation first!";
	}

	if (btn == 'f' || btn == 'F') {
		fpsMode = !fpsMode;
		if (fpsMode)
			cout << endl << "FPS View ON!" << endl;
		else
			cout << endl << "FPS View OFF!" << endl;
	}

	if (btn == 'v' || btn == 'V') {
		cout << "Zooming In!" << endl;
		zoomer += 0.01;
	}
	if (btn == 'b' || btn == 'B') {
		cout << "Zooming Out!" << endl;
		if (zoomer <= 0)
			zoomer = 0.0;
		else
			zoomer -= 0.01;
	}

	if (btn == 'o' || btn == 'O') {
		inAppDisplay = !inAppDisplay;
		if (inAppDisplay)
			cout << "In App Text Display : ON!" << endl;
		else
			cout << "In App Text Display : OFF!" << endl;
	}

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
  if (w <= h) {
  	glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
		asp_rat = (float)w/(float)h;
	}
  else {
    glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
		asp_rat = (float)h/(float)w;
	}

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	instructions();
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
  glutCreateWindow(WINDOW_TITLE);
	glClearColor(1.0,1.0,1.0,1.0);
	updatedisplay(0);
	displayFPS(0);
  glutReshapeFunc(myReshape);
  glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
  glutMainLoop();
  return 0;
}
