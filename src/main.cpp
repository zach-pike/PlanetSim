#include "raylib.h"
#include "Planets/PlanetManager.hpp"
#include "Planets/PlanetTypes/Default.hpp"
#include "Planets/PlanetTypes/Stationary.hpp"
#include "Planets/Helper.hpp"

void DrawTextureAroundCenter(Texture2D texture, float x, float y, float rot, float scale) {
            DrawTexturePro(texture,
                Rectangle{ 0, 0, (float)texture.width, (float)texture.height },
                Rectangle{ x, y, (float)texture.width * scale, (float)texture.height * scale },
                Vector2{ ((float)(texture.width) * scale) / 2, ((float)(texture.height) * scale ) },
                rot,
                RED
            );
}

int main(void) {
    InitWindow(0, 0, "Planet playground");

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    ToggleFullscreen();

    Image arrowImg = LoadImage("arrowv2.png");
    Texture2D arrow = LoadTextureFromImage(arrowImg);

    StationaryPlanet* star = new StationaryPlanet(5000, Vector2{ (float)screenWidth / 2, (float)screenHeight / 2 }, 10, "Star");
    // star->SetPosition(Vector2{ 500, 800 });
    // star->SetVelocity(Vector2{ 1.5, 0 });
    star->SetColor(YELLOW);

    PlanetManager planetManager;

    // Add our planets to the solarsystem
    planetManager.addPlanet(star);

    SetTargetFPS(60);

    bool isDragging = false;
    Vector2 dragStartPos = { 0, 0 };

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(BLACK);
            if (IsKeyPressed(KEY_D)) planetManager.toggleAllDebug();

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                if (!isDragging) {
                    isDragging = true;

                    dragStartPos = GetMousePosition();
                }
            }

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                // Draw a fake sphere for our soon to be planet

                DrawCircleV(dragStartPos, 10, Color{ 255, 255, 255, 127 });

                Vector2 curPos = GetMousePosition();

                auto riseOverRun = calculateRiseOverRun(curPos, dragStartPos);

                float distance = calculateDistance(riseOverRun);

                // Angle calculation
                float angle = calculateAngle(riseOverRun);

                DrawTextureAroundCenter(arrow, dragStartPos.x, dragStartPos.y, angle + 90, distance / 1000);
            }

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                isDragging = false;

                Vector2 curPos = GetMousePosition();

                auto riseOverRun = calculateRiseOverRun(curPos, dragStartPos);

                float distance = calculateDistance(riseOverRun);

                // Angle calculation
                float angle = calculateAngle(riseOverRun);
                float angleRad = degreesToRadians(angle);

                // Figure out our velocitys
                float VelX = ( distance * cos(angleRad) ) / 25;
                float VelY = ( distance * sin(angleRad) ) / 25;

                // Make a planet with theese parameters
                DefaultPlanet* tempPlanet = new DefaultPlanet(20, 10, "Planet");
                tempPlanet->SetPosition(dragStartPos);
                tempPlanet->SetVelocity(Vector2{ VelX, VelY });

                planetManager.addPlanet(tempPlanet);
            }

            planetManager.RenderLoop();
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}