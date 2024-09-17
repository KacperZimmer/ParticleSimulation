

#ifndef SIMPLEPARTICLESYSTEM_PARTICLESIMULATOR_H
#define SIMPLEPARTICLESYSTEM_PARTICLESIMULATOR_H

#include <vector>
#include "Particle.h"
class ParticleSimulator : public RenderIO {

    std::vector<Particle> particleContainer{};

    void render() override;

    ParticleSimulator(size_t size);
};


#endif //SIMPLEPARTICLESYSTEM_PARTICLESIMULATOR_H
