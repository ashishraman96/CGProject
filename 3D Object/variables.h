#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>

#include<iostream>
using namespace std;

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
const char* WINDOW_TITLE = "Wiggle Wiggle";

int c_menu;

GLfloat vertices[][3] = {{0.0,1.0,0.0}, {-1.0,-1.0,1.0}, {1.0,-1.0,1.0}, {1.0,-1.0,-1.0}, {-1.0,-1.0,-1.0}};
GLfloat colors[][3] = {{0.3,0.1,0.5},{1.0,0.0,0.0},	{0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,1.0,1.0}, };

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;

float asp_rat = 1080.0/1920.0;
float speed = 0.0;
float zoomer = 1.0;
int toggle = 0;
float whooshFactor = 10;

bool meshview = false;
bool rotation = false; //to check if rotation has started or not
bool fpsMode = false;
bool inAppDisplay = false;
bool discoMode = false;
bool whoosh = false;
bool cube = false;
bool prism = false;
bool lighting = false;
//Variables used for FPS and FPS calculation
float fps;
int frameCount = 0;
int currentTime = 0;
int previousTime = 0;

void instructions(void);
void timer(int value);
void timer2(int value);
void triangle(int a, int b, int c);
void rotate();
void colorcube(void);
void display(void);
void spincube();
void discoitems();
void updatedisplay(int value);
void displayFPS(int value);
void drawText(float x, float y, char *text);
void checkForText(void);
void updateDisco(int value);
void keyboard(unsigned char btn, int x, int y);
void myReshape(int w, int h);
