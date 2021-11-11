#pragma once
#include <iostream>
#include <math.h>
#include "Math.h"
#include "raylib.h"

#define MK_ACROSS_OP(op) V2<T>& operator op##=(const V2<T>& vec) { \
    this->x op##= vec.x; \
    this->y op##= vec.y; \
    return *this; \
} \
friend V2<T> operator op (const V2<T> &vec1, const V2<T> &vec2) { \
    V2<T> vec(vec1.x, vec1.y); \
    vec op##= vec2; \
    return vec; \
} \

#define MK_SCALAR_OP(op) V2<T>& operator op##=(T scalar) { \
    this->x op##= scalar; \
    this->y op##= scalar; \
    return *this; \
} \
friend V2<T> operator op (const V2<T> &vec1, T scalar) { \
    V2<T> vec(vec1.x, vec1.y); \
    vec op##= scalar; \
    return vec; \
} \

template<typename T>
struct V2 {
    T x;
    T y;
    V2() : x{0}, y{0} {}
    V2(T xVal, T yVal) : x{xVal}, y{yVal} {}
    friend std::ostream& operator<<(std::ostream& stream, const V2<T>& vec) {
        stream << vec.x << ", " << vec.y;
        return stream;
    }
    MK_ACROSS_OP(+)
    MK_ACROSS_OP(-)
    MK_ACROSS_OP(*)
    MK_ACROSS_OP(/)
    MK_SCALAR_OP(*)
    MK_SCALAR_OP(/)
    double Magnitude() const {
        T a = x * x;
        T b = y * y;
        double d = sqrt((double)(a + b));
        return d;
    }
    double SquareMagnitude() const {
        return Max(std::abs(x), std::abs(y));
    }
    V2<T> Unit() const {
        V2<T> vec(x, y);
        T magnitude = Magnitude();
        return vec / magnitude;
    }
    T Dot(const V2<T> vector) const {
        return (x * vector.x) + (y * vector.y);
    }
    template<typename T2>
    operator V2<T2>() const {
        return V2<T2>(x, y);
    }

    bool operator ==(const V2<T>& vec) {
        return x == vec.x && y == vec.y;
    }
    bool operator !=(const V2<T>& vec) {
        return !(*this == vec);
    }

    Vector2 ToRaylib() {
        return Vector2{(float)x, (float)y};
    }
};

using Vector2f = V2<float>;
using Vector2d = V2<double>;
using Vector2u = V2<uint>;
using Vector2i = V2<int>;