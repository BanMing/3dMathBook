//
// Created by WP on 4/22/2020.
//

//四元数为什么能解决万向锁？
//任意一个角度只有一个数值表示，这里给出的解释，三个数表示会出现“簇”这样的问题，用四个数表示方位就避免了该问题。
#include <assert.h>
#include <math.h>

#include "Quaternion.h"
#include "MathUtil.h"
#include "Vector3.h"
#include "EulerAngles.h"

//全局数据
//全局单位四元数，注意Quaternion类没有构造函数，因为我们并不需要
const Quaternion kQuaternionIdentity = {
        1.0f, 0.0f, 0.0f, 0.0f
};

//成员函数

//构造绕指定轴旋转的四元数
void Quaternion::setToRotateAboutX(float theta) {

    //    计算半角
    float thetaOver2 = theta * .5f;

    //赋值
    w = cosf(thetaOver2);
    x = sinf(thetaOver2);
    y = 0.0f;
    z = 0.0f;
}

void Quaternion::setToRotateAboutY(float theta) {
    // 计算半角
    float thetaOver2 = theta * .5f;

    //赋值
    w = cosf(thetaOver2);
    x = 0.0f;
    y = sinf(thetaOver2);
    z = 0.0f;
}

void Quaternion::setToRotateAboutZ(float theta) {
    // 计算半角
    float thetaOver2 = theta * .5f;

    //赋值
    w = cosf(thetaOver2);
    x = 0.0f;
    y = 0.0f;
    z = sinf(thetaOver2);
}

void Quaternion::setToRotateAboutAxis(const Vector3 &axis, float theta) {
    // 旋转轴必须标准化
    assert(fabs(axis.VectorMag() - 1.0f) < 0.01f);
   
    //计算半角和sin值
    float thetaOver2 = theta * .5f;
    float sinThetaOver2 = sinf(thetaOver2);

    //赋值
    w = cosf(thetaOver2);
    x = axis.x * sinThetaOver2;
    y = axis.y * sinThetaOver2;
    z = axis.z * sinThetaOver2;
}

//构造执行物体一惯性旋转四元数
//方位参数由欧拉角形式给出
//10.6.5
void Quaternion::setToRotateObjectToInertial(const EulerAngles &orientation) {
    //计算半角的sin和cos值
    float sp, sb, sh;
    float cp, cb, ch;
    sinCos(&sp, &cp, orientation.pitch * .5f);
    sinCos(&sb, &cb, orientation.bank * .5f);
    sinCos(&sh, &ch, orientation.heading * .5f);

    //计算结果
    w = ch * cp * cb + sh * sp * sb;
    x = ch * sp * cb + sh * cp * sb;
    y = -ch * sp * sb + sh * cp * cb;
    z = -sh * sp * cb + ch * cp * sb;
}

//构造执行惯性-物体旋转的四元数
//
//方位参数由欧拉角形式给出
//10.6.5
void Quaternion::setToRotateInertialToObject(const EulerAngles &orientation) {

    //计算半角的sin和cos值
    float sp, sb, sh;
    float cp, cb, ch;
    sinCos(&sp, &cp, orientation.pitch * .5f);
    sinCos(&sb, &cb, orientation.bank * .5f);
    sinCos(&sh, &ch, orientation.heading * .5f);

    //计算结果
    w = ch * cp * cb + sh * sp * sb;
    x = -ch * sp * cb - sh * cp * sb;
    y = ch * sp * sb - sh * cp * cb;
    z = sh * sp * cb - ch * cp * sb;
}

//四元数叉乘运算，用以连接多个角位移
//乘的顺序是从左向右
//这和四元数叉乘的“标准”相反 10.4.8
Quaternion Quaternion::operator*(const Quaternion &a) const {
    Quaternion result;

    result.w = w * a.w - x * a.x - y * a.y - z * a.z;
    result.x = w * a.x - x * a.w - z * a.y - y * a.z;
    result.y = w * a.y - y * a.w - x * a.z - z * a.x;
    result.z = w * a.z - z * a.w - y * a.x - x * a.y;

    return result;
}