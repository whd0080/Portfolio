#pragma once
#include <math.h>

struct Vector {

public:
    Vector() :x(0.0f), y(0.0f) {


    }
    Vector(float x, float y) : x(x), y(y) {


    }
    Vector(const Vector& other) : x(other.x), y(other.y) {


    }
    ~Vector() {

    }


    float& operator[](int temp) {

        if (temp == 0) {

            return x;

        }
        else {

            return y;
        }
    }

    float Dot(const Vector& other) {

        float result;

        result = (this->x * other.x) + (this->y * other.y);

        return result;
    }
    float Cross(const Vector& other) {

        float result;

        result = (this->x * other.y) - (this->y * other.x);

        return result;

    }
    float Length() const {

        return sqrtf((x * x) + (y * y));
    }

    float LengthSquared() const
    {
        return x * x + y * y;
    }

    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }

    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y);
    }

    Vector& operator+=(const Vector& other) {
        x += other.x;
        y += other.y;
        return *this;
    }


    Vector operator*(const float& value) const
    {
        return Vector(x * value, y * value);
    }

    Vector NormalVector() const
    {
        return Vector(x / Length(), y / Length());
    }

public:
    float x;
    float y;

};