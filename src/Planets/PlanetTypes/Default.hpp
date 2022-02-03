#pragma once
#include "../BasePlanets.hpp"

class DefaultPlanet : public BasicPlanet {
    private:
        Vector2 pos = { 0, 0 };
        Vector2 vel = { 0, 0 };

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

        void SetPosition(Vector2 pos) {
            DefaultPlanet::pos = pos;
        }

        Vector2 GetPosition() {
            return pos;
        }

        void SetVelocity(Vector2 vel) {
            DefaultPlanet::vel = vel;
        }

        Vector2 GetVelocity() {
            return vel;
        }

        void DrawPlanet() {
            if (visible) {
                DrawCircleV(pos, radius, color);
                // if (debug)
                    // DrawText(
                    //     FormatText(
                    //         "PLANET: %s X %d Y %d Vx %d Vy %d",
                    //         planetID.c_str(),
                    //         (int)pos.x,
                    //         (int)pos.y,
                    //         (int)vel.x,
                    //         (int)vel.y
                    //     ), 
                    //     pos.x + radius + 10, 
                    //     (pos.y - radius) - 5, 
                    //     20,
                    //     WHITE
                    // );
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

        bool CanBeDestroyed() const {
            return true;
        }
};