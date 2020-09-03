
#include <math.h>

#ifndef INC_3D_MATH_BOOK_VECTOR3_H
#define INC_3D_MATH_BOOK_VECTOR3_H

class Vector3
{
public:
    float x, y, z;

    // 默认构造函数
    Vector3() {}

    // 复制构造函数
    Vector3(const Vector3 &a) : x(a.x), y(a.y), z(a.z) {}

    // 带参数
    Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

    ~Vector3() { x = y = z = 0; };

    // 重载赋值运算符，并返回引用，以实现左值
    Vector3 &operator=(const Vector3 &a)
    {
        x = a.x;
        y = a.y;
        z = a.z;
        return *this;
    }

    // 重载“==”
    bool operator==(const Vector3 &a) const
    {
        return x == a.x && y == a.y && z == a.z;
    }

    // 重载“!=”
    bool operator!=(const Vector3 &a) const
    {
        return x != a.x || y != a.y || z != a.z;
    }

    // 向量运算

    // 向量置零
    void Zero() { x = y = z = 0.0f; }

    // 负号
    Vector3 operator-() const
    {
        return Vector3(-x, -y, -z);
    }

    // 相减
    Vector3 operator-(const Vector3 &a) const
    {
        return Vector3(x - a.x, y - a.y, z - a.z);
    }

    // 相加
    Vector3 operator+(const Vector3 &a) const
    {
        return Vector3(x + a.x, y + a.y, z + a.z);
    }

    // 与标量相乘与相除
    Vector3 operator*(float a) const
    {
        return Vector3(a * x, a * y, a * z);
    }

    Vector3 operator/(float a) const
    {
        return Vector3(x / a, y / a, z / a);
    }

    // 重载自运算
    Vector3 operator+=(Vector3 &a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }

    Vector3 operator-=(Vector3 &a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        return *this;
    }

    Vector3 operator*=(Vector3 &a)
    {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        return *this;
    }

    Vector3 operator/=(Vector3 &a)
    {
        x /= a.x;
        y /= a.y;
        z /= a.z;
        return *this;
    }

    // 向量标准化
    void Normalize()
    {
        float magSq = x * x + y * y + z * z;
        // 检查除0
        if (magSq > 0.0f)
        {
            float oneOverMag = 1.0f / sqrtf(magSq);
            x *= oneOverMag;
            y *= oneOverMag;
            z *= oneOverMag;
        }
    }

    // 向量点乘
    float operator*() const
    {
        return x * x + y * y + z * z;
    }

    // 求向量的模
    float VectorMag() const
    {
        return sqrtf(x * x + y * y + z * z);
    }

    // 计算两个向量的叉乘
    Vector3 CrossProduct(const Vector3 &b) const
    {
        return Vector3(y * b.z - z * b.y,
                       z * b.x - x * b.z,
                       x * b.y - y * b.x);
    }

    // 实现向量点乘
    float DotProduct(const Vector3 &b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }

    // 计算两点的距离
    float Distance(const Vector3 &b) const
    {
        float dx = x - b.x;
        float dy = y - b.y;
        float dz = z - b.z;
        return sqrtf(dx * dx + dy * dy + dz * dz);
    }
};

// 非成员函数
extern const Vector3 kZeroVector;

#endif