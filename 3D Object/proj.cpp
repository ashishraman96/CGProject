#include <stdlib.h>
#include <GL/glut.h>

GLfloat vertices[][3] = {{0.0,-1.0,-1.0}, {0.0,0.75,0.0}, {-1.0,-1.0,1.0}, {1.0,-1.0,1.0}};

GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},	{0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,1.0,1.0}, };

float speed = 0.0;

bool flag = false; //to check if rotation has started or not

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

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;

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



void keybaord(unsigned char btn, int x, int y) {

	if(btn == '9') {
		speed += 1.0;
		flag = true;
	}

	if(btn == '0') {
		speed = 0.0;
		flag = false;
	}

	if(btn == 'x')
		axis = 0;
	if(btn == 'y')
		axis = 1;
	if(btn == 'z')
		axis = 2;

	if(btn == 'i')
		if(flag == true)
			speed += 1.0;

	if(btn == 'o')
		speed -= 1.0;
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
	glutInit(&argc, argv);

/* need both double buffering and z buffer */

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Rotating a Color Cube");
  glutReshapeFunc(myReshape);
  glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutKeyboardFunc(keybaord);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
  glutMainLoop();
  return 0;
}
