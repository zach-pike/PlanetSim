#pragma once
#include "../BasePlanets.hpp"

class StationaryPlanet : public BasicPlanet {
    private:
        Vector2d pos;
        float mass;
        float radius;
        std::string planetID;

        Color color = WHITE;
        bool debug = false;

    public:
        StationaryPlanet(float vMass, float vRadius, Vector2d vPos, std::string vPlanetID) : mass{vMass}, radius{vRadius}, pos{vPos}, planetID{vPlanetID} {}

        void ApplyForce(Vector2d) {}
        void ApplyForceScalarTowards(double, Vector2d) {}

        Vector2d GetVelocity() {
            return Vector2d( 0, 0 );
        }

        Vector2d GetPosition() {
            return pos;
        }

        void DrawPlanet() {
            DrawCircleV(pos.ToRaylib(), radius, color);
        }

        void PhysicsStep() {}

        float GetMass() {
            return mass;
        }

        std::string GetID() {
            return planetID;
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