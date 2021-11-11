#pragma once

#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <memory>
#include "BasePlanets.hpp"
#include "raylib.h"



class PlanetManager {
    private:
        std::vector<std::shared_ptr<BasicPlanet>> planets;
        const float G = 3;
        const float restrictMassMovement = 10;

        struct PlanetCopyInfo {
            std::shared_ptr<BasicPlanet> planetToUpdate;
            Vector2 velocity;
        };
        Texture2D arrow;
        Image origImage;

        void DrawTextureAroundCenter(Texture2D texture, float x, float y, float rot) {
            DrawTexturePro(texture,
                Rectangle{ 0, 0, (float)texture.width, (float)texture.height },
                Rectangle{ x, y, (float)texture.width, (float)texture.height },
                Vector2{ (float)(texture.width) / 2, (float)(texture.height) },
                rot,
                WHITE
            );
        }

    public:
        PlanetManager() {
            origImage = LoadImage("arrow.png");

            arrow = LoadTextureFromImage(origImage);
        }

        void toggleAllDebug() {
            for (auto planet : planets) {
                planet->ToggleDebug();
            }
        }

        void addPlanet(std::shared_ptr<BasicPlanet> planet) {
            planets.push_back(planet);
        }

        void RenderLoop() {
            // First we make a copy of all the info about the planets so we can update them all when we are done

            for (auto planet : planets) {
                // Calculate new velocitys for every planet
                for (auto otherPlanet : planets) {
                    // Check to see if we need to do this iteration
                    if (otherPlanet != planet && otherPlanet->GetVisible() && planet->GetVisible()) {

                        // Star collision
                        if (
                            CheckCollisionCircles(
                                planet->GetPosition().ToRaylib(),
                                planet->GetRadius(),
                                otherPlanet->GetPosition().ToRaylib(),
                                otherPlanet->GetRadius()
                            )
                        ) {
                            planet->SetVisible(false);
                            otherPlanet->SetVisible(false);

                            continue;
                        }

                        // Planet gravity
                        
                    }
                }

                planet->DrawPlanet();
                planet->MoveByVelocity();
            }
        }
};
