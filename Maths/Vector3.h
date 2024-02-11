#pragma once
#include <cmath>
class Vector3
{
public:
    float x, y, z;
    Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } { }

    bool operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator !=(const Vector3& other) const {
        return x != other.x || y != other.y || z != other.z;
    }

    float magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    float squareMagnitude() const {
        float result = magnitude() * magnitude();
        return result;
    }
    
    static float Dot(Vector3& one, const Vector3& two) { 
        Vector3 resultVector = one* two;
        float resultFloat = one.x + one.y + one.z;

        return resultFloat;
    }

    static Vector3 Cross(Vector3& one, Vector3& two) {
        Vector3 newV{ 0,0,0 }; 
        newV.x = one.y * two.z - one.z * two.y;
        newV.y = one.z * two.x - one.x * two.z;
        newV.z = one.x * two.y - one.y * two.x;
        return newV;
    }

    static float Distance(Vector3& one, Vector3& two) {
        return (one - two).magnitude();
    }


    Vector3 normalize() {
        return *this / magnitude();
    }

    // Negation
    Vector3 operator-() {
        x *= -1;
        y *= -1;
        z *= -1;
        return Vector3(x, y, z);
    }

    // Multiplication
    Vector3 operator*(const Vector3& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return Vector3(x, y, z);
    }

    // Division
    Vector3 operator/(const Vector3& other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return Vector3(x, y, z);
    }

    Vector3 operator/(float other) {
        x /= other;
        y /= other;
        z /= other;
        return Vector3(x, y, z);
    }

    // Addition
    Vector3 operator+(Vector3& const other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return Vector3(x, y, z);
    }

    // Subtraction
    Vector3 operator-(Vector3& const other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return Vector3(x, y, z);
    }
};