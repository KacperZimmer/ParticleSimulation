

#ifndef SIMPLEPARTICLESYSTEM_PARTICLESIMULATOR_H
#define SIMPLEPARTICLESYSTEM_PARTICLESIMULATOR_H

#include <vector>
#include "Particle.h"
#include "UpdateIO.h"

class ParticleSimulator : public RenderIO, public UpdateIO{

private:
    std::vector<Particle> particleContainer{};
    float timeBeforeUpdate{};
    Vector2 initialPosition;
    float radius{};
    size_t containerSize;
public:
    void render() override;
    void update() override;
    ParticleSimulator(float radius, Vector2 initialPosition, size_t quantity);
};


#endif //SIMPLEPARTICLESYSTEM_PARTICLESIMULATOR_H
