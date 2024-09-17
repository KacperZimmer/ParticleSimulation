#include <iostream>
#include <raylib.h>
#include <vector>
#include "../include/Particle.h"

int main() {

    InitWindow(800, 800, "Particles");
    SetTargetFPS(60);

    std::vector<Particle> particles;

    Vector2 startPosition = {400.0f, 400.0f};
    particles.reserve(100);
    for (int i = 0; i < 50; ++i) {
        particles.emplace_back(startPosition, 10.0f);
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        for (auto& particle : particles) {
            particle.render();
        }

        EndDrawing();
    }

    CloseWindow();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
