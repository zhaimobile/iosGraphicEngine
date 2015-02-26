//
//  Matrix2.hpp
//  iOS3DEngine
//
//  Created by Mo on 10/02/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef iOS3DEngine_Matrix_hpp
#define iOS3DEngine_Matrix_hpp

#include "Vector.hpp"
template <typename T>
struct Matrix4 {
    
    T data[16];
    
    const T* Pointer() const
    {
        return data;
    }
    
    ////constructors
    Matrix4()
    {
        data[0] = 1; data[1]  = 0; data[2]  = 0; data[3]  = 0;
        data[4] = 0; data[5]  = 1; data[6]  = 0; data[7]  = 0;
        data[8] = 0; data[9]  = 0; data[10] = 1; data[11] = 0;
        data[12]= 0; data[13] = 0; data[14] = 0; data[15] = 1;
    }
    
    Matrix4(const Matrix4<T>& in)
    {
        data[0]  = in.data[0]; data[1]  = in.data[1];  data[2]  = in.data[2];  data[3]  = in.data[3];
        data[4]  = in.data[4]; data[5]  = in.data[5];  data[6]  = in.data[6];  data[7]  = in.data[7];
        data[8]  = in.data[8]; data[9]  = in.data[9];  data[10] = in.data[10]; data[11] = in.data[11];
        data[12] = in.data[12];data[13] = in.data[13]; data[14] = in.data[14]; data[15] = in.data[15];
    }
    
    Matrix4(const T* m)
    {
        data[0] = m[0];  data[1] = m[1];  data[2] = m[2];  data[3] = m[3];
        data[4] = m[4];  data[5] = m[5];  data[6] = m[6];  data[7] = m[7];
        data[8] = m[8];  data[9] = m[9];  data[10]= m[10]; data[11]= m[11];
        data[12]= m[12]; data[13]= m[13]; data[14]= m[14]; data[15]= m[15];
    }
    
    Matrix4 operator*(const Matrix4 &mat) const
    {
        Matrix4 m;
        
        m.data[0] = data[0]  * mat.data[0] + data[1]  * mat.data[4] + data[2]  * mat.data[8]  + data[3] *mat.data[12];
        m.data[1] = data[0]  * mat.data[1] + data[1]  * mat.data[5] + data[2]  * mat.data[9]  + data[3] *mat.data[13];
        m.data[2] = data[0]  * mat.data[2] + data[1]  * mat.data[6] + data[2]  * mat.data[10] + data[3] *mat.data[14];
        m.data[3] = data[0]  * mat.data[3] + data[1]  * mat.data[7] + data[2]  * mat.data[11] + data[3] *mat.data[15];
        m.data[4] = data[4]  * mat.data[0] + data[5]  * mat.data[4] + data[6]  * mat.data[8]  + data[7] *mat.data[12];
        m.data[5] = data[4]  * mat.data[1] + data[5]  * mat.data[5] + data[6]  * mat.data[9]  + data[7] *mat.data[13];
        m.data[6] = data[4]  * mat.data[2] + data[5]  * mat.data[6] + data[6]  * mat.data[10] + data[7] *mat.data[14];
        m.data[7] = data[4]  * mat.data[3] + data[5]  * mat.data[7] + data[6]  * mat.data[11] + data[7] *mat.data[15];
        m.data[8] = data[8]  * mat.data[0] + data[9]  * mat.data[4] + data[10] * mat.data[8]  + data[11] *mat.data[12];
        m.data[9] = data[8]  * mat.data[1] + data[9]  * mat.data[5] + data[10] * mat.data[9]  + data[11] *mat.data[13];
        m.data[10]= data[8]  * mat.data[2] + data[9]  * mat.data[6] + data[10] * mat.data[10] + data[11] *mat.data[14];
        m.data[11]= data[8]  * mat.data[3] + data[9]  * mat.data[7] + data[10] * mat.data[11] + data[11] *mat.data[15];
        m.data[12]= data[12] * mat.data[0] + data[13] * mat.data[4] + data[14] * mat.data[8]  + data[15] *mat.data[12];
        m.data[13]= data[12] * mat.data[1] + data[13] * mat.data[5] + data[14] * mat.data[9]  + data[15] *mat.data[13];
        m.data[14]= data[12] * mat.data[2] + data[13] * mat.data[6] + data[14] * mat.data[10] + data[15] *mat.data[14];
        m.data[15]= data[12] * mat.data[3] + data[13] * mat.data[7] + data[14] * mat.data[11] + data[15] *mat.data[15];
        
        return m;
    }
    
    Matrix4& operator *= (const Matrix4& b)
    {
        Matrix4 m = *this * b;
        return (*this = m);
    }
    
    Matrix4 Transposed() const
    {
        Matrix4 m;
        m.data[0] = data[0]; m.data[1] = data[4]; m.data[2] = data[8]; m.data[3] = data[12];
        m.data[4] = data[1]; m.data[5] = data[5]; m.data[6] = data[9]; m.data[7] = data[13];
        m.data[8] = data[2]; m.data[9] = data[6]; m.data[10]= data[10];m.data[11]= data[14];
        m.data[12] = data[3];m.data[13]= data[7]; m.data[14]= data[11];m.data[15]= data[15];
        return m;
    }
    
    
    static Matrix4<T> Identity()
    {
        Matrix4 m;
        m.data[0] = 1; m.data[1] = 0; m.data[2] = 0; m.data[3] = 0;
        m.data[4] = 0; m.data[5] = 1; m.data[6] = 0; m.data[7] = 0;
        m.data[8] = 0; m.data[9] = 0; m.data[10]= 1; m.data[11]= 0;
        m.data[12]= 0; m.data[13]= 0; m.data[14]= 0; m.data[15]= 1;
        return m;
    }
    
    static Matrix4<T> Translate(T x, T y, T z)
    {
        Matrix4 m;
        m.data[0] = 1; m.data[1] = 0; m.data[2] = 0; m.data[3] = 0;
        m.data[4] = 0; m.data[5] = 1; m.data[6] = 0; m.data[7] = 0;
        m.data[8] = 0; m.data[9] = 0; m.data[10]= 1; m.data[11]= 0;
        m.data[12]= x; m.data[13]= y; m.data[14]= z; m.data[15]= 1;
        return m;
    }    
    
    static Matrix4<T> Scale(T s)
    {
        Matrix4 m;        
        m.data[0] = s; m.data[1] = 0; m.data[2] = 0; m.data[3] = 0;
        m.data[4] = 0; m.data[5] = s; m.data[6] = 0; m.data[7] = 0;
        m.data[8] = 0; m.data[9] = 0; m.data[10]= s; m.data[11]= 0;
        m.data[12]= 0; m.data[13]= 0; m.data[14]= 0; m.data[15]= 1;  
        return m;
    }
    
    static Matrix4<T> Rotate(T degrees)
    {
        T radians = degrees * 3.14159f / 180.0f;
        T s = std::sin(radians);
        T c = std::cos(radians);
        
        //        Matrix4 m = Identity();
        //        m.data[0] =  c; m.data[1]= s;
        //        m.data[4] = -s; m.data[5] = c;
        //        return m;
        
        Matrix4 m;        
        m.data[0] = c;  m.data[1] = s; m.data[2] = 0; m.data[3] = 0;
        m.data[4] = -s; m.data[5] = c; m.data[6] = 0; m.data[7] = 0;
        m.data[8] = 0;  m.data[9] = 0; m.data[10]= 1; m.data[11]= 0;
        m.data[12]= 0;  m.data[13]= 0; m.data[14]= 0; m.data[15]= 1;  
        return m;        
    } 
    
    static Matrix4<T> Rotate(T degrees, const Vector4T<T>& axis)
    {
        T radians = degrees * 3.14159f / 180.0f;
        T s = std::sin(radians);
        T c = std::cos(radians);
        
        Matrix4 m = Identity();
        m.data[0] = c + (1 - c) * axis.x * axis.x;
        m.data[1] = (1 - c) * axis.x * axis.y - axis.z * s;
        m.data[2] = (1 - c) * axis.x * axis.z + axis.y * s;
        m.data[4] = (1 - c) * axis.x * axis.y + axis.z * s;
        m.data[5] = c + (1 - c) * axis.y * axis.y;
        m.data[6] = (1 - c) * axis.y * axis.z - axis.x * s;
        m.data[8] = (1 - c) * axis.x * axis.z - axis.y * s;
        m.data[9] = (1 - c) * axis.y * axis.z + axis.x * s;
        m.data[10]= c + (1 - c) * axis.z * axis.z;
        
        return m;
    }
        
    static Matrix4<T> Frustum(T left, T right, T bottom, T top, T near, T far)
    {
        T a = 2 * near / (right - left);
        T b = 2 * near / (top - bottom);
        T c = (right + left) / (right - left);
        T d = (top + bottom) / (top - bottom);
        T e = - (far + near) / (far - near);
        T f = -2 * far * near / (far - near);
        Matrix4 m;
        
        m.data[0] = a; m.data[1] = 0; m.data[2] = 0; m.data[3] = 0;
        m.data[4] = 0; m.data[5] = b; m.data[6] = 0; m.data[7] = 0;
        m.data[8] = c; m.data[9] = d; m.data[10]= e; m.data[11] = -1;
        m.data[12]= 0; m.data[13]= 0; m.data[14]= f; m.data[15] = 1;
        return m;
    }
};

typedef Matrix4<float> mat4;

#endif