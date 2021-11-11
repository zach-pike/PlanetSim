#pragma once
#include "raylib.h"
#include "Helper.hpp"
#include <cmath>
#include <string>
#include "../Vector2.h"

class BasicPlanet {
    public:
        virtual void SetPosition(Vector2d) = 0;
        virtual void SetVelocity(Vector2d) = 0;

        virtual Vector2d GetVelocity() = 0;
        virtual Vector2d GetPosition() = 0;

        virtual bool GetVisible() = 0;
        virtual void SetVisible(bool) = 0;

        virtual float GetRadius() = 0;
        virtual void SetRadius(float) = 0;

        virtual Color GetColor() = 0;
        virtual void SetColor(Color) = 0;

        virtual void ToggleDebug() = 0;

        virtual void DrawPlanet() = 0;

        virtual void MoveByVelocity() = 0;

        virtual float GetMass() = 0;

        virtual std::string GetID() = 0;
};