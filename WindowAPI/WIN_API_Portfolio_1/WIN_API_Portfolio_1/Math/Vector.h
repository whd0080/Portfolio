#pragma once
#include <math.h>

struct Vector {

public:
    Vector() :x(0.0f), y(0.0f) {}
    Vector(float x, float y) : x(x), y(y) {}
    Vector(const Vector& other) : x(other.x), y(other.y) {}
    ~Vector() {}

    float Dot(const Vector& other)
    {
        float result;
        result = (this->x * other.x) + (this->y * other.y);

        return result;
    }
    float Cross(const Vector& other)
    {
        float result;
        result = (this->x * other.y) - (this->y * other.x);

        return result;
    }
    float Length() const
    {

        return sqrtf((x * x) + (y * y));
    }

    Vector operator+(const Vector& other) const
    {

        Vector result;

        result.x = this->x + other.x;
        result.y = this->y + other.y;

        return result;
    }
    Vector operator-(const Vector& other) const
    {
        Vector result;

        result.x = this->x - other.x;
        result.y = this->y - other.y;

        return result;
    }
    Vector operator*(const float& value) const
    {
        return Vector(x * value, y * value);
    }
    Vector NormalVector() const
    {
        float length = Length();

        return Vector(x / length, y / length);
    }

    Vector& operator=(const Vector& other)
    {
        x = other.x;
        y = other.y;

        return *this;
    }
    Vector& operator+=(const Vector& other)
    {
        x += other.x;
        y += other.y;

        return *this;
    }
    Vector& operator-=(const Vector& other)
    {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    void Normalize()
    {
        float length = Length();

        x /= length;
        y /= length;
    }

    float Angle() const
    {
        return atan2(y, x);
    }

    float Angle(const Vector& other)
    {
        return Angle() - other.Angle();
    }

public:
    float x;
    float y;
};