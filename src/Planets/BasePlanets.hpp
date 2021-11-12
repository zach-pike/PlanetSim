#pragma once
#include "raylib.h"
#include "Helper.hpp"
#include <cmath>
#include <string>

class BasicPlanet {
    public:
        virtual void SetPosition(Vector2) = 0;
        virtual void SetVelocity(Vector2) = 0;

        virtual Vector2 GetVelocity() = 0;
        virtual Vector2 GetPosition() = 0;

        virtual bool GetVisible() = 0;
        virtual void SetVisible(bool) = 0;

        virtual float GetRadius() = 0;
        virtual void SetRadius(float) = 0;

        virtual Color GetColor() = 0;
        virtual void SetColor(Color) = 0;

        virtual bool CanBeDestroyed() const = 0;

        virtual void ToggleDebug() = 0;

        virtual void DrawPlanet() = 0;

        virtual void MoveByVelocity() = 0;

        virtual float GetMass() = 0;

        virtual std::string GetID() = 0;
};