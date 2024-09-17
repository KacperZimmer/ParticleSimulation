#include "../include/Particle.h"
#include <iostream>
#include <random>


void Particle::render() {
    if(lifeTime > 0) lifeTime -= 5;

    DrawCircle(this->position.x, this->position.y, this->radius, {0,0,0,(unsigned char) lifeTime});
    this->velocity += this->acceleration;
    this->position.y += this->velocity;
    this->position.x += curveValue;
}


Particle::Particle(const Vector2 &position, float radius) {

    this->position.x = position.x + stochasticSample(-1,1);
    this->position.y = position.y + stochasticSample(-1,1);
    this->radius = radius;
    this->acceleration = stochasticSample(0.1,0.5);
    this->curveValue = stochasticSample(-1,1);

}

double Particle::stochasticSample(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min,max);


    return dis(gen);
}

