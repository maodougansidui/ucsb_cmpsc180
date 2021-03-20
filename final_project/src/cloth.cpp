#include <iostream>
#include <vector>

#include "CGL/vector2D.h"

#include "mass.h"
#include "cloth.h"
#include "spring.h"

namespace CGL {
    Cloth::Cloth(Vector3D start, float length, float num_nodes, float node_mass,
        Vector3D ks, float kd, vector<vector<int>> pinned_nodes){
        
        // intialize the masses points and springs
        int num_per_line=(int)(sqrt(num_nodes));
        float per_len= length/(num_per_line-1);
        masses.resize(num_per_line);
        for (int i=0; i<num_per_line; ++i){
            for (int j=0; j<num_per_line; ++j){
                Vector3D cur(start.x+i*per_len,start.y,start.z+j*per_len);
                Mass* curNode= new Mass(cur,node_mass,false);
                masses[i].push_back(curNode);
            }
        }
        for (auto& idx: pinned_nodes){
            masses[idx[0]][idx[1]]->pinned=true;
        }
        // we need to construct 3 vectors strings and connect each mass.
        // @param stretch_strings
        // @param shear_strings
        // @param bending_strings
        constructSprings(num_per_line, kd,ks);
    }
    void Cloth::constructSprings(int n, float kd, Vector3D ks){
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                if (j+1<n){
                    Spring* stret= new Spring(masses[i][j],masses[i][j+1],ks.x,kd);
                    stretch_s.push_back(stret);
                }
                if (i+1<n){
                    Spring* stret= new Spring(masses[i][j],masses[i+1][j],ks.x,kd);
                    stretch_s.push_back(stret);
                }
                if (i+1<n && j+1<n){
                    Spring* shear= new Spring(masses[i][j],masses[i+1][j+1],ks.y,kd);
                    shear_s.push_back(shear);
                }
                if (i+1<n && j-1>=0){
                    Spring* shear= new Spring(masses[i][j],masses[i+1][j-1],ks.y,kd);
                    shear_s.push_back(shear);
                }
                if (j+2<n){
                    Spring* bend= new Spring(masses[i][j],masses[i][j+2],ks.z,kd);
                    bend_s.push_back(bend);
                }
                if (i+2<n){
                    Spring* bend= new Spring(masses[i][j],masses[i+2][j],ks.z,kd);
                    bend_s.push_back(bend);
                }
            }
        }
    }
    

    void Cloth::simulateEuler(float delta_t, Vector3D gravity) {
        for (auto &s : stretch_s) {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
            Vector3D b_minus_a=s->m2->position-s->m1->position;
            Vector3D dir=b_minus_a.unit();
            Vector3D force_b_a=-(s->k)*dir*(b_minus_a.norm()-s->rest_length);
            Vector3D damp_b=-(s->kd)*dot(dir,s->m2->velocity-s->m1->velocity)*dir;
            force_b_a+=damp_b;
            Vector3D force_a_b=-force_b_a;

            s->m1->forces+=force_a_b;
            s->m2->forces+=force_b_a;
        }

        for (auto &s : shear_s) {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
            Vector3D b_minus_a=s->m2->position-s->m1->position;
            Vector3D dir=b_minus_a.unit();
            Vector3D force_b_a=-(s->k)*dir*(b_minus_a.norm()-s->rest_length);
            Vector3D damp_b=-(s->kd)*dot(dir,s->m2->velocity-s->m1->velocity)*dir;
            force_b_a+=damp_b;
            Vector3D force_a_b=-force_b_a;
            
            s->m1->forces+=force_a_b;
            s->m2->forces+=force_b_a;
        }

        for (auto &s : bend_s) {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
            Vector3D b_minus_a=s->m2->position-s->m1->position;
            Vector3D dir=b_minus_a.unit();
            Vector3D force_b_a=-(s->k)*dir*(b_minus_a.norm()-s->rest_length);
            Vector3D damp_b=-(s->kd)*dot(dir,s->m2->velocity-s->m1->velocity)*dir;
            force_b_a+=damp_b;
            Vector3D force_a_b=-force_b_a;
            
            s->m1->forces+=force_a_b;
            s->m2->forces+=force_b_a;
        }
        // vector<Mass*> compare;
        for (auto &row : masses) {
            for (auto &m: row){
                if (!m->pinned) {
                // TODO (Part 2): Add the force due to gravity, then compute the new velocity and position
                    // aerospace force calculated
                    Vector3D air_force=c_v*dot(area_normal,u_fluid-m->velocity)*area_normal;
                    m->forces+=gravity+air_force;
                    m->velocity=m->velocity+m->forces/m->mass*delta_t;
                    m->position=m->position+m->velocity*delta_t;
                }

                // TODO (Part 2): Reset all forces on each mass
                m->forces.x=0.0;
                m->forces.y=0.0;
                // compare.push_back(m);
            }
        }
        // for (int i=0; i<compare.size(); ++i){
        //     Vector3D correction;
        //     int size=0;
        //     for (int j=0; j<compare.size(); ++j){
        //         if (i==j)   continue;
        //         float dist= (compare[i]->position-compare[j]->position).norm();
        //         if (dist<=2*thickness){
        //             while (true){

        //             }
        //         }
        //     }
        // }
    }


}
