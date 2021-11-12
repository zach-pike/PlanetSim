#pragma once
#include "../BasePlanets.hpp"

class StationaryPlanet : public BasicPlanet {
    private:
        Vector2 pos;
        float mass;
        float radius;
        std::string pid;

        Color color = WHITE;
        bool debug = false;

    public:
        StationaryPlanet(float mass, Vector2 pos, float radius, std::string id) {
            StationaryPlanet::mass = mass;
            StationaryPlanet::pos = pos;
            StationaryPlanet::radius = radius;
            StationaryPlanet::pid = id;
        }

        void SetPosition(Vector2 pos) {
            StationaryPlanet::pos = pos;
        }

        void SetVelocity(Vector2 vel) {
            // Daedon at the door
        }

        Vector2 GetVelocity() {
            return Vector2{ 0, 0 };
        }

        Vector2 GetPosition() {
            return pos;
        }

        void DrawPlanet() {
            DrawCircleV(pos, radius, color);

            if (debug)
                DrawText(
                    FormatText(
                        "PLANET: %s X %d Y %d",
                        pid.c_str(),
                        (int)pos.x,
                        (int)pos.y
                    ), 
                    pos.x + radius + 10, 
                    (pos.y - radius) - 5, 
                    20,
                    WHITE
                );
        }

        void MoveByVelocity() {}

        float GetMass() {
            return mass;
        }

        std::string GetID() {
            return pid;
        }

        void SetVisible(bool vis) {}

        bool GetVisible() {
            return true;
        }

        float GetRadius() {
            return radius;
        }

        void SetRadius(float rad) {
            StationaryPlanet::radius = rad;
        }

        Color GetColor() {
            return color;
        }

        void SetColor(Color color) {
            StationaryPlanet::color = color;
        }

        void ToggleDebug() {
            debug = !debug;
        }

        bool CanBeDestroyed() const {
            return false;
        }
};