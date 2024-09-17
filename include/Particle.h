#ifndef SIMPLEPARTICLESYSTEM_PARTICLE_H
#define SIMPLEPARTICLESYSTEM_PARTICLE_H

#include <raylib.h>
#include "RenderIO.h"

class Particle : public RenderIO {

private:
    unsigned short lifeTime = 255;
    float curveValue{2};
    Vector2 position;
    float radius;
    double velocity{1};
    double acceleration;

    static double stochasticSample(double min, double max);

public:
    Particle(const Vector2 &position, float radius);
    Particle(float radius);

    void render() override;
};

#endif // SIMPLEPARTICLESYSTEM_PARTICLE_H
