#include "vec3.h"
#include <cmath>
#include <string>

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(const Vec2& v, int z) : x(v.x), y(v.y), z(z) {}

Vec3::Vec3(int x, int y, int z) : x(x), y(y), z(z) {}

int Vec3::width() const { return x; }
int Vec3::height() const { return y; }
int Vec3::depth() const { return z; }
int Vec3::GetFlattenedSize() const { return x * y * z; }

void Vec3::SetX(int x) { this->x = x; }
void Vec3::SetY(int y) { this->y = y; }
void Vec3::SetZ(int z) { this->z = z; }

std::string Vec3::ToString() const {
    return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z);
}

Vec3 Vec3::operator-() const { return {-x, -y, -z}; }
int Vec3::operator[](int i) const { return (&x)[i]; }
int& Vec3::operator[](int i) { return (&x)[i]; }

bool Vec3::operator==(const Vec3 &v) const {
    return x == v.x && y == v.y && z == v.z;
}

Vec3& Vec3::operator+=(const Vec3 &v) {
    x += v.x; y += v.y; z += v.z;
    return *this;
}

Vec3& Vec3::operator+=(int t) {
    x += t; y += t; z += t;
    return *this;
}

Vec3& Vec3::operator*=(int t) {
    x *= t; y *= t; z *= t;
    return *this;
}

Vec3& Vec3::operator/=(int t) {
    x /= t; y /= t; z /= t;
    return *this;
}

Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return {u.x + v.x, u.y + v.y, u.z + v.z};
}

Vec3 operator+(const Vec3 &u, int val) {
    return {u.x + val, u.y + val, u.z + val};
}

Vec3 operator+(int val, const Vec3 &u) {
    return u + val;
}

Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return {u.x - v.x, u.y - v.y, u.z - v.z};
}

Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return {u.x * v.x, u.y * v.y, u.z * v.z};
}

Vec3 operator*(int t, const Vec3 &v) {
    return {t * v.x, t * v.y, t * v.z};
}

Vec3 operator*(const Vec3 &v, int t) {
    return t * v;
}

Vec3 operator/(Vec3 v, int t) {
    return {v.x / t, v.y / t, v.z / t};
}

std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
    return out << "Vec3(" << v.x << ' ' << v.y << ' ' << v.z << ")";
}
