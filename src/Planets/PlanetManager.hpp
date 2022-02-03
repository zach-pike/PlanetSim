#pragma once

#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <stdio.h>

#include "BasePlanets.hpp"

#include "raylib.h"

class PlanetManager {
    private:
        std::vector<BasicPlanet*> planets;
        const float G = 0.7;
        const float restrictMassMovement = 10;

        struct PlanetCopyInfo {
            BasicPlanet* planetToUpdate;
            Vector2 velocity;
        };

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
        PlanetManager() {}

        void toggleAllDebug() {
            for (auto planet : planets) {
                planet->ToggleDebug();
            }
        }

        void addPlanet(BasicPlanet* planet) {
            planets.push_back(planet);
        }

        void RenderLoop() {
            // First we make a copy of all the info about the planets so we can update them all when we are done

            // DrawText(FormatText("Number of rendered planets: %d using ~%lu bytes", planets.size(), sizeof(BasicPlanet) * planets.size()), 0, 13, 12, WHITE);

            // To stop adding of the same planet
            std::set<std::vector<BasicPlanet*>::iterator> toRemove;

            for (auto planet : planets) {
                // Calculate new velocitys for every planet
                for (auto otherPlanet : planets) {
                    // Check to see if we need to do this iteration
                    if (otherPlanet != planet) {

                        // Planet collision
                        if (
                            CheckCollisionCircles(
                                planet->GetPosition(),
                                planet->GetRadius(),
                                otherPlanet->GetPosition(),
                                otherPlanet->GetRadius()
                            )
                        ) {
                            // pop planets from planets array if they can be destoyed

                            if (planet->CanBeDestroyed()) {
                                auto it = std::find(planets.begin(), planets.end(), planet);
                                toRemove.insert(it);
                            }

                            if (otherPlanet->CanBeDestroyed()) {
                                auto it = std::find(planets.begin(), planets.end(), otherPlanet);
                                toRemove.insert(it);
                            }

                            // Restart loop
                            continue;
                        }

                        // We know the planet is not the one were drawing

                        // Calculate the distance between the current planet and the other planet
                        // Trigonometry time
                        auto currentPlanetPos = planet->GetPosition();
                        auto otherPlanetPos = otherPlanet->GetPosition();

                        int a = currentPlanetPos.y - otherPlanetPos.y;
                        int b = currentPlanetPos.x - otherPlanetPos.x;

                        // Hypotenuse holds our distance
                        float hypoteneuse = sqrt(pow(a, 2) + pow(b, 2));

                        // Math here...

                        float force = planet->GetMass() * otherPlanet->GetMass() / pow(hypoteneuse, 2);
                        float angleDeg = (atan2(a, b) * RAD2DEG) - 180;

                        if (angleDeg < 0) angleDeg += 360;

                        float angleRad = angleDeg * DEG2RAD;

                        // printf("Angle of %s to %s %f\n", planet->GetID().c_str(), otherPlanet->GetID().c_str(), angleDeg);

                        // DrawTextureAroundCenter(arrow, currentPlanetPos.x, currentPlanetPos.y, angleDeg + 90);

                        // Calculate Force
                        float F = (G * planet->GetMass() * otherPlanet->GetMass()) / pow(hypoteneuse, 2);

                        float Fx = F * cos(angleRad);
                        float Fy = F * sin(angleRad);

                        auto otherPlanetVelocity = planet->GetVelocity();

                        otherPlanetVelocity.x += Fx / ( planet->GetMass() / restrictMassMovement );
                        otherPlanetVelocity.y += Fy / ( planet->GetMass() / restrictMassMovement );

                        planet->SetVelocity(otherPlanetVelocity);
                    }
                }

                planet->DrawPlanet();
                planet->MoveByVelocity();
            }

            // Remove the collided planets
            for (;;) {
                if (toRemove.size() == 0) break;

                planets.erase(*--toRemove.end());


                toRemove.erase(--toRemove.end());
            }
        }
};
