#ifndef CGL_APPLICATION_H
#define CGL_APPLICATION_H

// STL
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// libCGL
#include "CGL/CGL.h"
#include "CGL/osdtext.h"

#include "cloth.h"

using namespace std;

namespace CGL {

struct AppConfig {
  AppConfig() {
    // Rope config variables
    mass = 1;
    ks = 0.002f;
    kd = 2.0f;
    kshear = 0.004f;
    kbending =0.006f;
    // Environment variables
    gravity = Vector3D(0, -0.2,0);
    steps_per_frame = 64;
  }

  float mass;
  float ks;
  float kd;
  float kshear;
  float kbending;

  float steps_per_frame;
  Vector3D gravity;
};

class Application {
public:
  Application(AppConfig config);
  ~Application();

  void init();
  void render();
  void resize(size_t w, size_t h);

  string name();
  string info();

  void keyboard_event(int key, int event, unsigned char mods);
  // void cursor_event(float x, float y);
  // void scroll_event(float offset_x, float offset_y);
  // void mouse_event(int key, int event, unsigned char mods);

private:
  AppConfig config;

  Cloth *clothEuler;
  Cloth *ropeVerlet;

  size_t screen_width;
  size_t screen_height;

}; // class Application

} // namespace CGL

#endif // CGL_APPLICATION_H
