const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const char* WINDOW_TITLE = "Wiggle Wiggle";

GLfloat vertices[][3] = {{0.0,-1.0,-1.0}, {0.0,0.75,0.0}, {-1.0,-1.0,1.0}, {1.0,-1.0,1.0}};
GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},	{0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,1.0,1.0}, };

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;

float asp_rat;
float speed = 0.0;
float zoomer = 1.0;

bool rotation = false; //to check if rotation has started or not
bool fpsMode = false;
bool inAppDisplay = false;

//Variables used for FPS and FPS calculation
float fps;
int frameCount = 0;
int currentTime = 0;
int previousTime = 0;

void instructions(void);			//Display "commands" on the console
void updatedisplay(int value);
void displayFPS(int value);
void checkForText(void);
void keyboard(unsigned char btn, int x, int y);
