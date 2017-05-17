#include<stdio.h>
#include<GL/glut.h>
void display()
{
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
		glVertex3f(0,0,1);
		glVertex3f(0,1,1);
		glVertex3f(1,1,1);
		glVertex3f(1,0,1);
	glEnd();
}
void init()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1,1,1,0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,499,0,499);
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   	 glutInitWindowSize(500, 500);
    	glutCreateWindow("Rotating a Color Cube");
        glutDisplayFunc(display);
	   glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
    glutMainLoop();
	return 0;
}


