#ifndef CLOTH_H
#define CLOTH_H

#include "CGL/CGL.h"
#include "mass.h"
#include "spring.h"

using namespace std;

namespace CGL {

class Cloth {
public:
  Cloth(vector<vector<Mass *>> &masses, vector<Spring *> &stretch, vector<Spring *> &shear, vector<Spring *> &bend)
      : masses(masses), stretch_s(stretch), shear_s(shear), bend_s(bend) {}
  Cloth(Vector3D start, float length, float num_nodes, float node_mass,
        Vector3D ks, float kd, vector<vector<int>> pinned_nodes);

  void simulateVerlet(float delta_t, Vector3D gravity);
  void simulateEuler(float delta_t, Vector3D gravity);
  void constructSprings(int n, float kd, Vector3D ks);

  vector<vector<Mass *>> masses;
  vector<Spring *> stretch_s;
  vector<Spring *> shear_s;
  vector<Spring *> bend_s;
private:
  Vector3D u_fluid{0.0,0.098,0.0};
  Vector3D area_normal{0.0,1.0,0.0};
  float c_v=0.2;
  // float thickness= 0.1;
}; // struct Cloth
}
#endif /* CLOTH_H */
