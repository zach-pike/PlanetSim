#pragma once
#include <cmath>

// Helper functions in future...

struct RiseOverRun {
    float rise;
    float run;
};

float degreesToRadians(float degrees) {
    return degrees * ( PI / 180.0f );
}

RiseOverRun calculateRiseOverRun(Vector2 pos1, Vector2 pos2) {
    float a = pos1.y - pos2.y;
    float b = pos1.x - pos2.x;

    return RiseOverRun{ a, b };
}

float calculateDistance(RiseOverRun riseoverrun) {
    return sqrt(pow(riseoverrun.rise, 2) + pow(riseoverrun.run, 2));
}

float calculateForce(float distance, float mass1, float mass2, float G) {
    return (G * mass1 * mass2) / pow(distance, 2);
}

float calculateAngle(RiseOverRun rr) {
    float angle = (atan2(rr.rise, rr.run) * RAD2DEG) - 180;
    if (angle < 0) angle += 360;

    return angle;
}

Vector2 splitForceVector(float force, float angleRadians) {
    return Vector2{
        (float)(force * cos(angleRadians)),
        (float)(force * sin(angleRadians))
    };
}