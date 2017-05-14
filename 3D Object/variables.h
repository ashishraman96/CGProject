const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const char* WINDOW_TITLE = "Wiggle Wiggle";

GLfloat vertices[][3] = {{0.0,-1.0,-1.0}, {0.0,0.75,0.0}, {-1.0,-1.0,1.0}, {1.0,-1.0,1.0}};
GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},	{0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,1.0,1.0}, };

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;

float speed = 0.0;
float zoomer = 1.0;

bool rotation = false; //to check if rotation has started or not
bool fpsMode = false;

//Variables used for FPS and FPS calculation
float fps;
int frameCount = 0;
int currentTime = 0;
int previousTime = 0;
