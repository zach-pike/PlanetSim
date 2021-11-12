#include "raylib.h"
#include "Planets/PlanetManager.hpp"
#include "Planets/PlanetTypes/Default.hpp"
#include "Planets/PlanetTypes/Stationary.hpp"
#include "Vector2.h"
#include <memory>

int main(void) {
    InitWindow(0, 0, "Planet playground");

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    ToggleFullscreen();

    auto planet1 = std::make_shared<DefaultPlanet>(1000, 10, Vector2d( 150, 350 ), Vector2d( 4, 0 ), "Planet");
    planet1->SetColor(ORANGE);

    auto planet2 = std::make_shared<DefaultPlanet>(10, 4, Vector2d( 150, 550 ), Vector2d( 0.5, 0 ), "Moon");
    planet2->SetColor(DARKBLUE);

    auto star = std::make_shared<StationaryPlanet>(1000, 8, Vector2d( (double)screenWidth / 2, (double)screenHeight / 2 ), "Star");
    star->SetColor(YELLOW);

    PlanetManager planetManager;

    // Add our planets to the solarsystem
    planetManager.addPlanet(planet1);
    planetManager.addPlanet(planet2);
    planetManager.addPlanet(star);

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