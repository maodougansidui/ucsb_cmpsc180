#include <iostream>

#include "application.h"
#include "cloth.h"

#define GL_PI 3.141592654
namespace CGL {

Application::Application(AppConfig config) { this->config = config; }

Application::~Application() {}

void Application::init() {
  // Enable anti-aliasing and circular points.
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

  glPointSize(8);
  glLineWidth(4);

  glColor3f(1.0, 1.0, 1.0);
  
  Vector3D k_constraints(config.ks,config.kshear,config.kbending);

  clothEuler = new Cloth(Vector3D(-8,10,-15),10,81,config.mass,k_constraints,config.kd,
  {{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,8},{7,8},{8,8}});
  
}

void Application::render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
  // Render a color-cube consisting of 6 quads with different colors
  glLoadIdentity();                 // Reset the model-view matrix
  glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen

  clothEuler->simulateEuler(1 / config.steps_per_frame, config.gravity);
  Cloth *cloth=clothEuler;
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,1.0f);
    for (auto &row : cloth->masses) {
      for (auto &m : row){
        Vector3D p = m->position;
        glVertex3d(p.x, p.y, p.z);
      }
    }

    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,0.5f,0.0f);

    for (auto &s : cloth->stretch_s) {
      Vector3D p1 = s->m1->position;
      Vector3D p2 = s->m2->position;
      glVertex3d(p1.x, p1.y,p1.z);
      glVertex3d(p2.x, p2.y, p2.z);
    }
    for (auto &s : cloth->shear_s) {
      Vector3D p1 = s->m1->position;
      Vector3D p2 = s->m2->position;
      glVertex3d(p1.x, p1.y,p1.z);
      glVertex3d(p2.x, p2.y, p2.z);
    }
    for (auto &s : cloth->bend_s) {
      Vector3D p1 = s->m1->position;
      Vector3D p2 = s->m2->position;
      glVertex3d(p1.x, p1.y,p1.z);
      glVertex3d(p2.x, p2.y, p2.z);
    }

    glEnd();

}

void Application::resize(size_t w, size_t h) {
  screen_width = w;
  screen_height = h;

  float half_width = (float)screen_width / 2;
  float half_height = (float)screen_height / 2;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-half_width, half_width, -half_height, half_height, 1, 0);
}

void Application::keyboard_event(int key, int event, unsigned char mods) {
  switch (key) {
  case '-':
    if (config.steps_per_frame > 1) {
      config.steps_per_frame /= 2;
    }
    break;
  case '=':
    config.steps_per_frame *= 2;
    break;
  }
}

string Application::name() { return "Rope Simulator"; }

string Application::info() {
  ostringstream steps;
  steps << "Steps per frame: " << config.steps_per_frame;

  return steps.str();
}
}
