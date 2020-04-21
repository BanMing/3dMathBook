/******************************************************************
** 文件名: MathUtil.cpp
** 创建人: BanMing 
** 日  期: 4/21/2020, 8:44:54 AM
** 描  述:  

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

#include <math.h>

#include "MathUtil.h"
#include "Vector3.h"

const Vector3 kZeroVector(0.0f, 0.0f, 0.0f);

// 通过加上适当的2pi倍数，将角度限制在-pi到pi的区间内
float wrapPi(float theta)
{
    theta += kPi;
    theta -= floor(theta * k1Over2Pi) * k2Pi;
    theta -= kPi;
    return theta;
}

// 和acos相同，但如果x超出范围将返回最为接近的有效值
// 返回值在0到pi之间，和c语言中的标准acos函数相同
float safeAcos(float x)
{

    if (x <= -1.0f)
    {
        return kPi;
    }

    if (x >= 1.0f)
    {
        return 0;
    }

    return acos(x);
}