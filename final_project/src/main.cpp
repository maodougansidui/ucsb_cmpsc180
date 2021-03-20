// CGL
#include "CGL/CGL.h"
#include <unistd.h>
#include <GL/glut.h>
#include "application.h"

//STL
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef uint32_t gid_t;

using namespace std;
using namespace CGL;

// G L O B A L S  /////////////////

//Window
static int window_width=640, window_height=480;

char title[] = "3D Shapes";

static AppConfig config;
static Application *app;

static const int g_fps=60;
static const int g_frame_time = 15;
static const int refreshMills=(int) ((1.0f / g_fps) * 1000 - g_frame_time);

// F U N C T I O N S ////////////////

static void initGlutState(int, char**);
static void display();
static void reshape(GLsizei , GLsizei);
static void initGL();
static void timer(int value);
static void usage(const char *binaryName);

 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   int opt;

  while ((opt = getopt(argc, argv, "s:l:t:m:e:h:f:r:c:a:p:g:")) != -1) {
    switch (opt) {
    case 'm':
      config.mass = atof(optarg);
      break;
    case 'g':
      config.gravity = Vector3D(atof(argv[optind - 2]), atof(argv[optind-1]), atof(argv[optind]));
      optind++;
      break;
    case 's':
      config.steps_per_frame = atoi(optarg);
      break;
    default:
      usage(argv[0]);
      return 1;
    }
  }
   initGlutState(argc, argv);
   initGL();                       // Our own OpenGL initialization
   glutTimerFunc(0, timer, 0);
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}

static void initGlutState(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(window_width, window_height);
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow(title);
   app= new Application(config);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
}

void initGL() {
   app->init();
}

void display() {

   app->render();
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(90.0f, aspect, 0.1f, 100.0f);
}

/* Called back when timer expired [NEW] */
void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

void usage(const char *binaryName) {
  printf("Usage: %s [options] <scenefile>\n", binaryName);
  printf("Program Options:\n");
  printf("  -m  <FLOAT>            Mass per node\n");
  printf("  -g  <FLOAT> <FLOAT> <FLOAT>    Gravity vector (x, y, z)\n");
  printf("  -s  <INT>              Number of steps per simulation frame\n");
  printf("\n");
}
