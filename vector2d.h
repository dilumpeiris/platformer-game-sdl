#pragma once
#include <cmath>
class Vector2D
{
public:
    float x;
    float y;
    float mag;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D &Add(const Vector2D &vec);
    Vector2D &Substract(const Vector2D &vec);
    Vector2D operator+(const Vector2D &obj);
    Vector2D operator*(const Vector2D &obj);
    Vector2D operator/(const Vector2D &obj);
    Vector2D operator-(const Vector2D &obj);
    Vector2D operator*(const int val);
    Vector2D operator*(const float val);
    Vector2D operator/(const int val);
    void operator=(const float val);
    void operator=(const int val);
    void operator+=(const int val);
    void operator+=(const float val);
    void operator+=(const Vector2D &obj);
    void operator-=(const int val);
    void operator-=(const float val);
    void operator-=(const Vector2D &obj);
};

Vector2D::Vector2D()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->mag = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;

    this->mag = sqrt(pow(x, 2) + pow(y, 2));
}

Vector2D &Vector2D::Add(const Vector2D &vec)
{
    this->x += vec.x;
    this->y += vec.y;
    this->mag = sqrt(pow(x, 2) + pow(y, 2));
    return *this;
}
Vector2D &Vector2D::Substract(const Vector2D &vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    this->mag = sqrt(pow(x, 2) + pow(y, 2));
    return *this;
}

Vector2D Vector2D::operator*(float const val)
{
    Vector2D vec;

    vec.x = x * val;
    vec.y = y * val;

    vec.mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));

    return vec;
}
Vector2D Vector2D::operator*(int const val)
{
    Vector2D vec;

    vec.x = x * val;
    vec.y = y * val;

    vec.mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));

    return vec;
}
void Vector2D::operator=(float const val)
{
    x = val;
    y = val;
}
void Vector2D::operator=(int const val)
{
    x = val;
    y = val;
}
void Vector2D::operator+=(float const val)
{
    x = x + val;
    y = y + val;
}
void Vector2D::operator+=(int const val)
{
    x = x + val;
    y = y + val;
}

void Vector2D::operator-=(float const val)
{
    x = x - val;
    y = y - val;
}
void Vector2D::operator-=(int const val)
{
    x = x - val;
    y = y - val;
}
Vector2D Vector2D::operator/(int const val)
{
    Vector2D vec;

    vec.x = x / val;
    vec.y = y / val;

    vec.mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));

    return vec;
}
Vector2D Vector2D::operator+(Vector2D const &obj)
{
    Vector2D vec;

    vec.x = x + obj.x;
    vec.y = y + obj.y;

    vec.mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));

    return vec;
}
void Vector2D::operator+=(Vector2D const &obj)
{
    x = x + obj.x;
    y = y + obj.y;
}
void Vector2D::operator-=(Vector2D const &obj)
{
    x = x - obj.x;
    y = y - obj.y;
}
Vector2D Vector2D::operator-(Vector2D const &obj)
{
    Vector2D vec;

    vec.x = x - obj.x;
    vec.y = y - obj.y;

    vec.mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));

    return vec;
}
Vector2D Vector2D::operator*(Vector2D const &obj)
{
    Vector2D vec;

    vec.x = x * obj.x;
    vec.y = y * obj.y;

    vec.mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));

    return vec;
}
Vector2D Vector2D::operator/(Vector2D const &obj)
{
    Vector2D vec;

    vec.x = x / obj.x;
    vec.y = y / obj.y;

    vec.mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));

    return vec;
}
