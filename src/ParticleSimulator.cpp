//
// Created by Kacper Zimmer on 17/09/2024.
//

#include "../include/ParticleSimulator.h"

void ParticleSimulator::render() {

    for(Particle& particle : this->particleContainer){
        particle.render();
    }
}
