#include "../include/Particle.h"
#include <iostream>
#include <random>


void Particle::render() {

    DrawCircle(this->position.x, this->position.y, this->radius, {50,0,0,(unsigned char) lifeTime});
}


Particle::Particle(const Vector2 &position, float radius) {

    this->position.x = position.x + stochasticSample(-5,5);
    this->position.y = position.y + stochasticSample(-3,3);
    this->initalPosition = position;
    this->radius = radius;
    this->acceleration = stochasticSample(0.1,0.5);
    this->curveValue = stochasticSample(-5,5);

}

double Particle::stochasticSample(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min,max);


    return dis(gen);
}

unsigned short Particle::getLifeTime() const {
    return lifeTime;
}

double Particle::getAcceleration() const {
    return acceleration;
}

float Particle::getCurveValue() const {
    return curveValue;
}

const Vector2 &Particle::getInitalPosition() const {
    return initalPosition;
}

const Vector2 &Particle::getPosition() const {
    return position;
}

float Particle::getRadius() const {
    return radius;
}

double Particle::getVelocity() const {
    return velocity;
}

void Particle::update() {

    if(lifeTime > 0) lifeTime -= 5;
    this->currentTime += GetFrameTime();


    this->velocity += this->acceleration;
    this->position.y += this->velocity;
    this->position.x += curveValue ;
}

void Particle::setLifeTime(unsigned short lifeTime) {
    Particle::lifeTime = lifeTime;
}

void Particle::setAcceleration(double acceleration) {
    Particle::acceleration = acceleration;
}

void Particle::setCurrentTime(float currentTime) {
    Particle::currentTime = currentTime;
}

void Particle::setCurveValue(float curveValue) {
    Particle::curveValue = curveValue;
}

void Particle::setInitalPosition(const Vector2 &initalPosition) {
    Particle::initalPosition = initalPosition;
}

void Particle::setPosition(const Vector2 &position) {
    Particle::position = position;
}

void Particle::setRadius(float radius) {
    Particle::radius = radius;
}

void Particle::setVelocity(double velocity) {
    Particle::velocity = velocity;
}

float Particle::getCurrentTime() const {
    return currentTime;
}

