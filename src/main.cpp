#include "raylib.h"
#include "Planets/PlanetManager.hpp"
#include "Planets/PlanetTypes/Default.hpp"
#include "Planets/PlanetTypes/Stationary.hpp"

int main(void) {
    InitWindow(0, 0, "Planet playground");

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    ToggleFullscreen();

    DefaultPlanet* planet1 = new DefaultPlanet(100, 10, "Planet");
    planet1->SetPosition(Vector2{ 150, 350 });
    planet1->SetVelocity(Vector2{ 4, 0 });
    planet1->SetColor(ORANGE);

    DefaultPlanet* planet2 = new DefaultPlanet(10, 4, "Moon");
    planet2->SetPosition(Vector2{ 150, 550 });
    planet2->SetVelocity(Vector2{ 0.5, 0 });
    planet2->SetColor(DARKBLUE);

    // StationaryPlanet* star = new StationaryPlanet(1000, Vector2{ (float)screenWidth / 2, (float)screenHeight / 2 }, 8, "Star");
    // star->SetColor(YELLOW);

    PlanetManager planetManager;

    // Add our planets to the solarsystem
    planetManager.addPlanet(planet1);
    planetManager.addPlanet(planet2);
    // planetManager.addPlanet(star);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(BLACK);
            if (IsKeyPressed(KEY_D)) planetManager.toggleAllDebug();

            planetManager.RenderLoop();
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}