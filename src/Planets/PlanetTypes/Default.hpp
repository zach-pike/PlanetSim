#pragma once
#include "../BasePlanets.hpp"

class DefaultPlanet : public BasicPlanet {
    private:
        Vector2d pos;
        Vector2d vel;
        Vector2d force;

        bool visible = true;
        float mass;
        float radius;
        std::string planetID;

        Color color = WHITE;

        bool debug = false;
    public:

        DefaultPlanet(float vMass, float vRadius, Vector2d vPos, Vector2d vVel, std::string vPlanetID) : mass{vMass}, radius{vRadius}, pos{vPos}, vel{vVel}, planetID{vPlanetID} {}

        Vector2d GetPosition() {
            return pos;
        }

        Vector2d GetVelocity() {
            return vel;
        }

        void ApplyForce(Vector2d newForce) {
            force += newForce;
        }

        void ApplyForceScalarTowards(double scalar, Vector2d towards) {
            ApplyForce((towards - pos) * scalar);
        }

        void DrawPlanet() {
            if (visible) {
                DrawCircleV(pos.ToRaylib(), radius, color);
            }
        }

        void PhysicsStep() {
            auto accel = force / mass;

            vel += accel;
            pos += vel;
            force = Vector2d();
        }

        float GetMass() {
            return mass;
        }

        std::string GetID() {
            return planetID;
        }

        void SetVisible(bool vis) {
            DefaultPlanet::visible = vis;
        }

        bool GetVisible() {
            return DefaultPlanet::visible;
        }

        float GetRadius() {
            return radius;
        }

        void SetRadius(float rad) {
            DefaultPlanet::radius = rad;
        }

        Color GetColor() {
            return color;
        }

        void SetColor(Color color) {
            DefaultPlanet::color = color;
        }

        void ToggleDebug() {
            debug = !debug;
        }
};