//
// Created by Kacper Zimmer on 17/09/2024.
//
#include "../include/ParticleSimulator.h"

void ParticleSimulator::render() {

    for(Particle& particle : this->particleContainer){
        particle.render();
    }
}

void ParticleSimulator::update() {

    this->timeBeforeUpdate += GetFrameTime();

        for (auto &i: this->particleContainer) {

            i.update();
            if(i.getCurrentTime() > 0.9){
                i.setCurrentTime(0.f);
                this->particleContainer.emplace_back(i.getInitalPosition(),i.getRadius());
            }
            if(this->timeBeforeUpdate > 0.001f) {
                this->particleContainer.emplace_back(i.getInitalPosition(), i.getRadius());
                this->timeBeforeUpdate = 0.f;
            }
        }

//    for(Particle& particle : this->particleContainer){
//
//        if(particle.getCurrentTime() > 0.7){
//            particle.setCurrentTime(0.f);
//            this->particleContainer.emplace_back(particle.getInitalPosition(),particle.getRadius());
//        }
//    }

    for(size_t particleIndex = 0; particleIndex < this->particleContainer.size(); ++particleIndex){
        if(particleContainer[particleIndex].getLifeTime() <= 0){
            this->particleContainer.erase(this->particleContainer.begin() + particleIndex);
        }

    }
}

ParticleSimulator::ParticleSimulator(float radius,Vector2 initialPosition, size_t quantity) : radius{radius}, initialPosition(initialPosition), containerSize{quantity}{

    this->particleContainer.reserve(containerSize);

    for(int i = 0; i < quantity; ++i){
        this->particleContainer.emplace_back(initialPosition, radius);
    }

}


