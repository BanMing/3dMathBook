//
// Created by BanMing on 2020/4/21.
//

#ifndef INC_3D_MATH_BOOK_EULERANGLES_H
#define INC_3D_MATH_BOOK_EULERANGLES_H

//预声明
class Quaternion;

class Matrix4x3;

class RotationMatrix;

//class EulerAngles
//用于表示heading-pitch-bank欧拉角

class EulerAngles {
public:

    //    公共数据
    //直接的表示方式
    //用弧度保存三个角度
    //    y,x,z
    float heading;
    float pitch;
    float bank;

    //    公共操作
    //缺省构造函数
    EulerAngles() {}

    //    接受三个参数
    EulerAngles(float h, float p, float b) : heading(h), pitch(p), bank(b) {}

    //归零操作
    void identity() { pitch = bank = heading = 0.0f; }

    //    变换为“限制集”欧拉角
    void canonize();

    //从四元数转换到欧拉角
    //输入的四元数假设为物体一惯性或惯性一物体四元数，如其名所示
    void fromObjectToInertialQuaternion(const Quaternion &q);

    void fromInertialToObjectQuaternion(const Quaternion &q);

    //从矩阵转换到欧拉角
    //输入矩阵假设为物体一世界或世界一物体转换矩阵
    //平移部分被省略，并且假设矩阵是正交的
    void fromObjectToWorldMatrix(const Matrix4x3 &m);

    void fromWorldToObjectMatrix(const Matrix4x3 &m);

    // 从旋转矩阵转换到欧拉角
    void fromRotationMatrix(const RotationMatrix &m);
};

//全局的“单位”欧拉角
extern const EulerAngles kEulerAnglesIdentity;
#endif //INC_3D_MATH_BOOK_EULERANGLES_H
