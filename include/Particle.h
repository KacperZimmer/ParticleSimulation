#ifndef SIMPLEPARTICLESYSTEM_PARTICLE_H
#define SIMPLEPARTICLESYSTEM_PARTICLE_H

#include <raylib.h>
#include "RenderIO.h"
#include "UpdateIO.h"

class Particle : public RenderIO, public UpdateIO{

private:
    unsigned short lifeTime = 255;
    float curveValue{1000};
    Vector2 position;
    Vector2 initalPosition;
    float currentTime{};
    float radius;
    double velocity{1};
    double acceleration;
public:
    void update() override;

    float getCurrentTime() const;


public:
    Particle(const Vector2 &position, float radius);

    Particle(float radius);

    double stochasticSample(double min, double max);

    void render() override;

    unsigned short getLifeTime() const;

    double getAcceleration() const;

    float getCurveValue() const;

    const Vector2 &getInitalPosition() const;

    const Vector2 &getPosition() const;

    float getRadius() const;

    double getVelocity() const;

    void setLifeTime(unsigned short lifeTime);

    void setAcceleration(double acceleration);

    void setCurrentTime(float currentTime);

    void setCurveValue(float curveValue);

    void setInitalPosition(const Vector2 &initalPosition);

    void setPosition(const Vector2 &position);

    void setRadius(float radius);

    void setVelocity(double velocity);
};

#endif // SIMPLEPARTICLESYSTEM_PARTICLE_H
