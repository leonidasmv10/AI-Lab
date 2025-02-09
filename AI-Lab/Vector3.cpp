#include "stdafx.h"
#include "Vector3.h"

namespace Math
{
    // Constructores
    Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
    Vector3::Vector3(float scalar) : x(scalar), y(scalar), z(scalar), w(1.0f) {}
    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z), w(1.0f) {}
    Vector3::Vector3(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    // Operadores
    Vector3& Vector3::operator+=(const Vector3& other) {
        x += other.x; y += other.y; z += other.z;
        return *this;
    }

    Vector3& Vector3::operator-=(const Vector3& other) {
        x -= other.x; y -= other.y; z -= other.z;
        return *this;
    }

    Vector3 Vector3::operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 Vector3::operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 Vector3::operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 Vector3::operator/(float scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    bool Vector3::operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Vector3::operator!=(const Vector3& other) const {
        return !(*this == other);
    }

    // Métodos estáticos
    float Vector3::dot(const Vector3& v1, const Vector3& v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    Vector3 Vector3::cross(const Vector3& v1, const Vector3& v2) {
        return Vector3(
            v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x
        );
    }

    float Vector3::magnitude(const Vector3& v) {
        return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    Vector3 Vector3::normalize(const Vector3& v) {
        float mag = magnitude(v);
        return mag > 0 ? v / mag : Vector3();
    }

    float Vector3::angle(const Vector3& v1, const Vector3& v2) {
        float dotProduct = dot(v1, v2);
        float magnitudes = magnitude(v1) * magnitude(v2);
        return magnitudes > 0 ? std::acos(dotProduct / magnitudes) : 0.0f;
    }

    // Métodos de instancia
    void Vector3::normalize() {
        float mag = magnitude(*this);
        if (mag > 0) {
            x /= mag; y /= mag; z /= mag;
        }
    }

    void Vector3::add(const Vector3& v) {
        x += v.x; y += v.y; z += v.z;
    }

    // Sobrecarga de << para imprimir vectores
    std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        os << "Vector3(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
}