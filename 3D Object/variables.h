const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const char* WINDOW_TITLE = "Wiggle Wiggle";

GLfloat vertices[][3] = {{0.0,-1.0,-1.0}, {0.0,0.75,0.0}, {-1.0,-1.0,1.0}, {1.0,-1.0,1.0}};
GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},	{0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,1.0,1.0}, };

float speed = 0.0;

bool rotation = false; //to check if rotation has started or not

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;
