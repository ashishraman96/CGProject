#include "variables.h"
float sinA, sinB, sinC;

void instructions() {
	cout << "                             *****INSTRUCTIONS*****                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "F/f : FPS Display ON/OFF" << endl;
	cout << "W/w : Fly ON/OFF" << endl;
	cout << "D/d : Disco Mode ON/OFF" << endl;
	cout << "R/r: Rotation Mode ON/OFF" << endl;
	cout << "x/y/z: Change Axis of Rotation" << endl;
	cout << "+/: Increase/Decrease speed of Rotation" << endl;
	cout << "v/b: Zoom In / Zoom Out" << endl;
	cout << "O/o : Display In-App Function States" << endl;
	cout << " c : Clear Console Screen" << endl;
	cout << " Esc: Quit" << endl;
	cout << "--------------------------------------------------------------------------------" << endl << endl;
}

float timeElapsed = 0;

void timer(int value) {
	if (whoosh) {
		timeElapsed += 0.02;
		glutPostRedisplay();
		glutTimerFunc(10, timer, 0);
	}
}

float timeElapsed1 = 0;
void timer1(int value) {
	if (discoMode) {
		timeElapsed1 += 0.02;
		glutPostRedisplay();
		glutTimerFunc(10, timer1, 0);
	}
}

void triangle(int a, int b, int c) {
	glBegin(GL_TRIANGLES);
	glColor3fv(colors[a]);
	glVertex3fv(trivertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(trivertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(trivertices[c]);
	glEnd();
}

void colorTriangle(void) {
	glScalef(zoomer, zoomer, zoomer);
	triangle(0,1,2); //front
	triangle(0,2,3); //right
	triangle(0,3,4); //back
	triangle(0,4,1); //left
	glBegin(GL_POLYGON);
	glColor3fv(colors[0]);
	glVertex3fv(trivertices[1]);
	glColor3fv(colors[1]);
	glVertex3fv(trivertices[2]);
	glColor3fv(colors[2]);
	glVertex3fv(trivertices[3]);
	glColor3fv(colors[3]);
	glVertex3fv(trivertices[4]);
	glEnd();
}

void polygon(int a, int b, int c , int d) {
 	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(polyvertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(polyvertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(polyvertices[c]);
	glColor3fv(colors[d]);
	glVertex3fv(polyvertices[d]);
	glEnd();
}

void colorCube(void) {
	glScalef(zoomer, zoomer, zoomer);
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(0,1,5,4);
}

void spinCube() {
	theta[axis] += speed;
	if( theta[axis] > 360.0 )
		theta[axis] -= 360.0;
	if(theta[axis] <= 0.0)
		theta[axis] = 0.0;
	glutPostRedisplay();
}

void rotate() {
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

}

void I()
{
	//glScalef(zoomer, zoomer, zoomer);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// ======
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(-0.6, 0.8 + sinA, 0);
	glVertex3f(-0.6, 0.4 + sinA, 0);
	glVertex3f(-0.2, 0.4 + sinB, 0);
	glVertex3f(0.2, 0.4 + sinB, 0);
	glVertex3f(0.6, 0.4 + sinC, 0);
	glVertex3f(0.6, 0.8 + sinC, 0);
	glEnd();
	/*
	||
	||
	||
	*/
	//glColor3f(1.0,0.0,1.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-0.2, 0.4 + sinB, 0.0);
	glVertex3f(0.2, 0.4 + sinB, 0);
	glVertex3f(0.2, -0.4 + sinB, 0);
	glVertex3f(-0.2, -0.4 + sinB, 0.0);
	glEnd();
	// ======
	//glColor3f(0.0,1.0,1.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.6, -0.8 + sinC, 0);
	glVertex3f(0.6, -0.4 + sinC, 0);
	glVertex3f(0.2, -0.4 + sinB, 0);
	glVertex3f(-0.2, -0.4 + sinB, 0);
	glVertex3f(-0.6, -0.4 + sinA, 0);
	glVertex3f(-0.6, -0.8 + sinA, 0);
	glEnd();
}

void discoitems() {

	glPushMatrix();
	glTranslatef(-1.1,0.9,0.5);
	glScalef(-0.11,-0.11,-0.11);
	rotate();
	glutWireSphere(1.0,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.2, -0.9, 0.2);
	glScalef(-0.5,-0.5,-0.5);
	rotate();
	I();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2,-0.3,0.14);
	glScalef(0.13,0.13,0.13);
	rotate();
	glutWireTorus(0.3,1.0,7,7);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.7,1.3,-0.1);
	glScalef(-0.2,-0.2,-0.2);
	rotate();
	colorTriangle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5,0.9,0.4);
	glScalef(0.11,0.11,0.11);
	rotate();
	colorCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5,-0.9,0.4);
	glScalef(0.19,0.19,0.19);
	rotate();
	glutWireIcosahedron();
	glPopMatrix();
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
		drawText(-5 * asp_rat, 2.9 * asp_rat, "                                       ");
		if(pyramid)
			drawText(-5 * asp_rat, 2.9 * asp_rat, "Object: Pyramid");
		if(cube)
			drawText(-5 * asp_rat, 2.9 * asp_rat, "Object: Cube");
		if(cone)
			drawText(-5 * asp_rat, 2.9 * asp_rat, "Object: Cone");
		if(torus)
			drawText(-5 * asp_rat, 2.9 * asp_rat, "Object: Torus");
		if(sphere)
			drawText(-5 * asp_rat, 2.9 * asp_rat, "Object: Sphere");
		if(dodecahedron)
			drawText(-5 * asp_rat, 2.9 * asp_rat, "Object: Dodecahedron");
		if(octahedron)
			drawText(-5 * asp_rat, 2.9 * asp_rat, "Object: Octahedron");
		if(tetrahedron)
			drawText(-5 * asp_rat, 2.9 * asp_rat, "Object: Tetrahedron");
		if(icosahedron)
			drawText(-5 * asp_rat, 2.9 * asp_rat, "Object: Icosahedron");

		if (discoMode)	{
			drawText(-5 * asp_rat, 2.7 * asp_rat, "                                       ");
			drawText(-5 * asp_rat, 2.7 * asp_rat, "Disco-Mode : ON");
		}
		else {
			drawText(-5* asp_rat, 2.7 * asp_rat, "                                       ");
			drawText(-5 * asp_rat, 2.7 * asp_rat, "Disco-Mode : OFF");
		}

		if (whoosh)	{
			drawText(-5 * asp_rat, 2.5 * asp_rat, "                                       ");
			if(flyside)
				drawText(-5 * asp_rat, 2.5 * asp_rat, "Fly-Mode : Horizontal");
			if(flyup)
				drawText(-5 * asp_rat, 2.5 * asp_rat, "Fly-Mode : Vertical");
		}
		else {
			drawText(-5 * asp_rat, 2.5 * asp_rat, "                                       ");
			drawText(-5 * asp_rat, 2.5 * asp_rat, "Fly-Mode : OFF");
		}

		if (rotation) {
			drawText(-5 * asp_rat, 2.3 * asp_rat, "                                       ");
			drawText(-5 * asp_rat, 2.3 * asp_rat, "Rotation-Mode : ON");
		}
		else {
			drawText(-5 * asp_rat, 2.3 * asp_rat, "                                       ");
			drawText(-5 * asp_rat, 2.3 * asp_rat, "Rotation-Mode : OFF");
		}

		if (fpsMode) {
			drawText(-5 * asp_rat, 2.1 * asp_rat, "                                       ");
			drawText(-5 * asp_rat, 2.1 * asp_rat, "FPS : ON (Check Console)");
		}
		else
		{
			drawText(-5 * asp_rat, 2.1 * asp_rat, "                                       ");
			drawText(-5 * asp_rat, 2.1 * asp_rat, "FPS : OFF");
		}
	}
}

void updateDisco(int value) {
	toggle++;
	if (discoMode) {
		if (toggle == 1)
			glClearColor(213.0, 0.0, 0.0, 0.0);
		else if (toggle == 2)
			glClearColor(0.0, 255.0, 0.0, 0.0);
		else if (toggle == 3)
			glClearColor(0.6, 0.2, 0.7, 0.0);
		else {
			glClearColor(0.0, 61.0, 255.0, 0.0);
			toggle = 0;

		}

		glutPostRedisplay();
		glutTimerFunc(250, updateDisco, 0);
	}
	else
		glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void) {

	float tanX, sinY;
 if(discoMode)
 {

		 sinA = 0.2 * sin(timeElapsed1 - 1.5);
		 sinB = 0.2 * sin(timeElapsed1 - 0.5);
		 sinC = 0.2 * sin(timeElapsed1 + 0.5);
 }
	if (whoosh) {
		if(flyside) {
			tanX = tan(timeElapsed - 1.5);
			sinY = sin(timeElapsed + 1.5);
		}
		if(flyup) {
			tanX = sin(timeElapsed - 1.5);
			sinY = tan(timeElapsed + 1.5);
		}
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
	glPushMatrix();
	if (whoosh) {
		if (zoomer > 1) {
			glTranslatef(tanX, sinY, zoomer);
		}
	 	else if (zoomer < 1) {
	 		glTranslatef(tanX, sinY, -zoomer);
	 	}
	 	else
	 		glTranslatef(tanX, sinY, 0);
  	}

		if(pyramid) {
	 		rotate();
			glScalef(zoomer, zoomer, zoomer);
	 		colorTriangle();
  	}
  	if(cube) {
	 		rotate();
			glScalef(zoomer, zoomer, zoomer);
	 		colorCube();
  	}
		if(cone) {
			rotate();
			glScalef(zoomer, zoomer, zoomer);
			glLineWidth(2.0);
			glutWireCone(1.0,1.5,20,20);
  	}
		if(torus) {
			rotate();
			glScalef(zoomer, zoomer, zoomer);
			glLineWidth(2.0);
			glutWireTorus(0.3,1.0,20,20);
  	}
		if(sphere) {
			rotate();
			glScalef(zoomer, zoomer, zoomer);
			glLineWidth(2.0);
			glutWireSphere(1.0,20,20);
		}
		if(dodecahedron) {
			rotate();
			glScalef(zoomer - 0.5, zoomer - 0.5, zoomer - 0.5);
			glColor3f(0.3,0.6,0.9);
			glLineWidth(10.0);
			glutWireDodecahedron();
  	}
		if(octahedron) {
			rotate();
			glScalef(zoomer - 0.2, zoomer - 0.2, zoomer - 0.2);
			glColor3f(0.5,0.5,0.5);
			glLineWidth(10.0);
			glutWireOctahedron();
  	}
		if(tetrahedron) {
			rotate();
			glScalef(zoomer - 0.2, zoomer - 0.2, zoomer - 0.2);
			glColor3f(0.1,0.3,0.1);
			glLineWidth(10.0);
			glutWireTetrahedron();
  	}
		if(icosahedron) {
			rotate();
			glScalef(zoomer - 0.2, zoomer - 0.2, zoomer - 0.2);
			glColor3f(0.6,0.2,0.5);
			glLineWidth(10.0);
			glutWireIcosahedron();
		}
		glPopMatrix();
  	if(discoMode)
 			discoitems();
		checkForText();
		glFlush();
		glutSwapBuffers();
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

	if(btn == '+') {
		if(rotation) {
			speed += 1.0;
			cout << "Speed Increased" << endl;
		}
	}


	if(btn == '-') {
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

	if (btn == 'd' || btn == 'D') {
		discoMode = !discoMode;
		toggle = 0;
		if (discoMode)
			cout << endl << "Disco - Mode ON!" << endl;
		else
			cout << endl << "Disco - Mode OFF!" << endl;

			dancing!=dancing;
			timer1(0);
		updateDisco(0);

	}

	if (btn == 'w' || btn == 'W') {
		whoosh = !whoosh;
		timeElapsed = 0;
		if (whoosh)
			cout << endl << "Fly Mode ON!" << endl;
		else
			cout << endl << "Fly Mode OFF!" << endl;
		timer(0);
	}

	if (btn == 'l' || btn == 'L') {
		lighting = !lighting;
		if (lighting)
			cout << endl << "Lighting ON!" << endl;
		else
			cout << endl << "Lighting OFF!" << endl;
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
		//asp_rat = (float)w/(float)h;
	}
  else {
    glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
		//asp_rat = (float)h/(float)w;
	}

	glMatrixMode(GL_MODELVIEW);
}

void main_menu(int index) {
  switch (index) {
		case 1:
			if(!pyramid) {
				initializer();
				pyramid = true;
				cout << endl << "Pyramid!" << endl;
			}
			break;
		case 2:
			if(!cube) {
				initializer();
				cube = true;
				cout << endl << "Cube!" << endl;
			}
			break;

		case 3:
			if(!cone) {
				initializer();
				cone = true;
				cout << endl << "Cone!" << endl;
			}
			break;

		case 4:
			if(!torus) {
				initializer();
				torus = true;
				cout << endl << "Torus!" << endl;
			}
			break;

		case 5:
			if(!sphere) {
				initializer();
				sphere = true;
				cout << endl << "Sphere!" << endl;
			}
			break;

		case 6:
			if(!dodecahedron) {
				initializer();
				dodecahedron = true;
				cout << endl << "Dodecahedron!" << endl;
			}
			break;

		case 7:
			if(!octahedron) {
				initializer();
				octahedron = true;
				cout << endl << "Octahedron!" << endl;
			}
			break;

		case 8:
			if(!tetrahedron) {
				initializer();
				tetrahedron = true;
				cout << endl << "Tetrahedron!" << endl;
			}
			break;

		case 9:
				if(!icosahedron) {
					initializer();
					icosahedron = true;
					cout << endl << "Icosahedron!" << endl;
				}
				break;

		case 10:
			if(!flyside) {
				flyside = true;
				flyup = false;
				cout << endl << "Horizontal Flying!" << endl;
			}
			break;

		case 11:
			if(!flyup) {
				flyup = true;
				flyside = false;
				cout << endl << "Vertical Flying!" << endl;
			}
			break;
  }
}

void menuInit() {
	int subObj, subFly;
	subObj = glutCreateMenu(main_menu);
	glutAddMenuEntry("Pyramid",1);
	glutAddMenuEntry("Cube",2);
	glutAddMenuEntry("Cone",3);
	glutAddMenuEntry("Torus",4);
	glutAddMenuEntry("Sphere",5);
	glutAddMenuEntry("Dodecahedron",6);
	glutAddMenuEntry("Octahedron",7);
	glutAddMenuEntry("Tetrahedron",8);
	glutAddMenuEntry("Icosahedron",9);

	subFly = glutCreateMenu(main_menu);
	glutAddMenuEntry("Horizontal",10);
	glutAddMenuEntry("Vertical",11);


	c_menu=glutCreateMenu(main_menu);
	glutAddSubMenu("Objects",subObj);
	glutAddSubMenu("Fly Direction",subFly);
	//glutAddMenuEntry("Comet",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
	instructions();
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
  glutCreateWindow(WINDOW_TITLE);
	glClearColor(0.0,0.0,0.0,0.0);
	updatedisplay(0);
	displayFPS(0);
	glutIdleFunc(spinCube);
  glutReshapeFunc(myReshape);
  glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(500, updateDisco, 0);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	menuInit();
  glutMainLoop();
  return 0;
}
