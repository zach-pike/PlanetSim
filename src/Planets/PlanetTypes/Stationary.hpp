#pragma once
#include "../BasePlanets.hpp"

class StationaryPlanet : public BasicPlanet {
    private:
        Vector2d pos;
        float mass;
        float radius;
        std::string pid;

        Color color = WHITE;
        bool debug = false;

    public:
        StationaryPlanet(float mass, Vector2d pos, float radius, std::string id) {
            StationaryPlanet::mass = mass;
            StationaryPlanet::pos = pos;
            StationaryPlanet::radius = radius;
            StationaryPlanet::pid = id;
        }

        void SetPosition(Vector2d pos) {
            StationaryPlanet::pos = pos;
        }

        void SetVelocity(Vector2d vel) {
            // Daedon at the door
        }

        Vector2d GetVelocity() {
            return Vector2d( 0, 0 );
        }

        Vector2d GetPosition() {
            return pos;
        }

        void DrawPlanet() {
            DrawCircleV(pos.ToRaylib(), radius, color);
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
};