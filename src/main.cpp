#include <iostream>
#include <raylib.h>
#include <vector>

#include "../include/ParticleSimulator.h"

int main() {

    InitWindow(800, 800, "Particles");
    SetTargetFPS(60);

    ParticleSimulator simulation{8,{400,400}, 100};

    while (!WindowShouldClose()) {

        simulation.update();
        simulation.render();

        BeginDrawing();
        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
