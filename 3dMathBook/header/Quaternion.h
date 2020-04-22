//
// Created by WP on 4/22/2020.
//

#ifndef INC_3D_MATH_BOOK_QUATERNION_H
#define INC_3D_MATH_BOOK_QUATERNION_H

class Vector3;

class EulerAngles;

//实现在3D中表示角位移的四元数
class Quaternion {
public:

    //公共数据

    //四元数的四个值，通常是不需要直接处理他们的
    //然而仍然把他们甚至为public，这是为了不给某些操作（如文件I/O)带来不必要的复杂性
    float w, x, y, z;

    //公共操作

    // 置为单位四元数
    void identity() {
        w = 1.0f;
        x = y = z = 0.0f;
    }


    //构造函数
    void setToRotateAboutX(float theta);

    void setToRotateAboutY(float theta);

    void setToRotateAboutZ(float theta);

    // 构造执行物体一惯性旋转的四元数，方位参数用欧拉角形式给出
    void setToRotateObjectToInertial(const EulerAngles &orientation);

    void setToRotateInertialToInertial(const EulerAngles &orientation);
};

#endif //INC_3D_MATH_BOOK_QUATERNION_H
