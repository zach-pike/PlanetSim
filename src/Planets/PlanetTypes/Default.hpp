#pragma once
#include "../BasePlanets.hpp"

class DefaultPlanet : public BasicPlanet {
    private:
        Vector2d pos;
        Vector2d vel;

        bool visible = true;
        float mass;
        float radius;
        std::string planetID;

        Color color = WHITE;

        bool debug = false;
    public:

        DefaultPlanet(float mass, float radius, std::string planetID) {
            DefaultPlanet::mass = mass;
            DefaultPlanet::radius = radius;

            DefaultPlanet::planetID = planetID;
        }

        void SetPosition(Vector2d pos) {
            DefaultPlanet::pos = pos;
        }

        Vector2d GetPosition() {
            return pos;
        }

        void SetVelocity(Vector2d vel) {
            DefaultPlanet::vel = vel;
        }

        Vector2d GetVelocity() {
            return vel;
        }

        void DrawPlanet() {
            if (visible) {
                DrawCircleV(pos.ToRaylib(), radius, color);
            }
        }

        void MoveByVelocity() {
            pos.x += vel.x;
            pos.y += vel.y;
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