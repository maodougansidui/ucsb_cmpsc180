#include <iostream>
#include <vector>

#include "CGL/vector2D.h"

#include "mass.h"
#include "rope.h"
#include "spring.h"

namespace CGL {

    Rope::Rope(Vector2D start, Vector2D end, int num_nodes, float node_mass, float k, vector<int> pinned_nodes)
    {
        // TODO (Part 1): Create a rope starting at `start`, ending at `end`, and containing `num_nodes` nodes.
        masses.resize(num_nodes);
        springs.resize(num_nodes-1);
        float each_x=(end.x-start.x)/(num_nodes-1);
        float each_y=(end.y-start.y)/(num_nodes-1);
        for (int i=0; i<(int)masses.size(); ++i){
            Vector2D cur(start.x+i*each_x,start.y+i*each_y);
            Mass* curNode= new Mass(cur,node_mass,false);
            masses[i]=curNode;
        }
        for (auto& idx: pinned_nodes){
            masses[idx]->pinned=true;
        }
        for (int i=0; i<(int)springs.size();++i){
            Spring* tmp= new Spring(masses[i],masses[i+1],k);
            springs[i]=tmp;
        }
    }

    void Rope::simulateEuler(float delta_t, Vector2D gravity) {
        for (auto &s : springs) {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
            Vector2D b_minus_a=s->m2->position-s->m1->position;
            Vector2D force_b_a=-(s->k)*b_minus_a.unit()*(b_minus_a.norm()-s->rest_length);
            Vector2D force_a_b=-force_b_a;
            s->m1->forces+=force_a_b;
            s->m2->forces+=force_b_a;
        }

        for (auto &m : masses) {
            if (!m->pinned) {
                // TODO (Part 2): Add the force due to gravity, then compute the new velocity and position
                m->forces+=gravity;
                m->velocity=m->velocity+m->forces/m->mass*delta_t;
                m->position=m->position+m->velocity*delta_t;
		// comment out explicit euler
		// m->position=m->position+m->velocity*delta_t;
            }

            // TODO (Part 2): Reset all forces on each mass
            m->forces.x=0.0;
            m->forces.y=0.0;
        }
    }

    void Rope::simulateVerlet(float delta_t, Vector2D gravity) {
        for (auto &s : springs) {
            // TODO (Part 3): Simulate one timestep of the rope using explicit Verlet
            // TODO (Part 3): Move each mass by the half displacement
            float fa=(s->m2->position-s->m1->position).norm()-s->rest_length;
            Vector2D dis=(s->m2->position-s->m1->position).unit()*fa;
            if (s->m1->pinned==false) s->m1->position+=dis/2;
            if (s->m2->pinned==false) s->m2->position-=dis/2;
        }
        float damp_factor=0.00005;
        for (auto &m : masses) {
            if (!m->pinned) {
                Vector2D temp_position = m->position;
                Vector2D old_p=m->last_position;
                // TODO (Part 3.1): Set the new position of the rope mass
                // TODO (Part 4): Add global Verlet damping
                m->position=temp_position+(1-damp_factor)*(temp_position-old_p)+gravity*delta_t*delta_t;
                m->last_position=temp_position;
            }
        }
    }


}
