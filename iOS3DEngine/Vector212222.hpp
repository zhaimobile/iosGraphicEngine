//
//  Vector.hpp
//  iOS3DEngine
//
//  Created by Mo on 10/02/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef iOS3DEngine_Vector_hpp
#define iOS3DEngine_Vector_hpp

#include <cmath>

const float Pi = 4 * std::atan(1.0f);
const float TwoPi = 2 * Pi;

template <typename T>
struct Vector4T
{    
    ////data and Pointer
    T x;
    T y;
    T z;
    T w;
    
    const T* Pointer() const
    {
        return &x;
    }   
    
    ////constructors
    //The default constructor creates (0,0,0,1)
    Vector4T() : x(0), y(0), z(0), w(1){}
    
    //The explicit constructor creates a vector with the given components.
    Vector4T(const T x, const T y, const T z, const T w=1): x(x), y(y), z(z), w(w){}
    
    ////accessor
    T operator[](unsigned i) const
    {
        if (i == 0) return x;
        if (i == 1) return y;
        if (i == 2) return z;
        return w;
    }
    T& operator[](unsigned i)
    {
        if (i == 0) return x;
        if (i == 1) return y;
        if (i == 2) return z;
        return w;
    }
    
    ////////////////////////////
    //methods for x y z and w // 
    ////////////////////////////
    
    // set the vector back to (0,0,0,1)
    void clear()
    {
        x = y = z = 0;
        w=1;
    }
    
    //Writer
    template <typename P>
    P* Write(P* pData)
    {
        Vector4T<T>* pVector = (Vector4T<T>*) pData;
        *pVector++ = *this;
        return (P*) pVector;
    }
    
    //dot for x y z w
    T dot4(const Vector4T& v) const
    {
        return x * v.x + y * v.y + z * v.z + w * v.w;
    }
    
    //lerp for x y z w
    Vector4T lerp4(float t, const Vector4T& v) const
    {
        return Vector4T(x * (1 - t) + v.x * t,
                        y * (1 - t) + v.y * t,
                        z * (1 - t) + v.z * t,
                        w * (1 - t) + v.w * t);
    }
    
    ///////////////////////////////////
    //methods for x y z //w no change// 
    ///////////////////////////////////
    
    Vector4T Lerp(float t, const Vector4T& v) const
    {
        return Vector4T(x * (1 - t) + v.x * t,
                        y * (1 - t) + v.y * t,
                        z * (1 - t) + v.z * t);
    }
    
    //-  |+ - * /   
    void invert()
    {
        x = -x;
        y = -y;
        x = -z;
    }
    //    //don't know if it is correct
    //    void operator-()
    //    {
    //        x = -x;
    //        y = -y;
    //        x = -z;
    //    }
    Vector4T operator-() const
    {
        return Vector4T(-x, -y, -z);
    }
    
    void operator+=(const Vector4T& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }
    Vector4T operator+(const Vector4T& v) const
    {
        return Vector4T(x + v.x, y + v.y,  z + v.z);
    }
    
    void operator-=(const Vector4T& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }
    Vector4T operator-(const Vector4T& v) const
    {
        return Vector4T(x - v.x, y - v.y,  z - v.z);
    }
    
    void operator*=(const T s)
    {
        x *= s;
        y *= s;
        z *= s;
    }
    Vector4T operator*(const T s) const
    {
        return Vector4T(x * s, y * s, z * s);
    }
    
    /////////////////////////////////////// 
    //magnitude normalise  trim    
    /** Gets the squared magnitude of this vector. */
    T squareMagnitude() const
    {
        return x * x + y * y + z * z;
    }
    
    /** Gets the magnitude of this vector. */
    T magnitude() const
    {
        //return real_sqrt(x*x+y*y+z*z);
        return std::sqrt(x * x + y * y + z * z);
    }
    
    //modified below
    /** Turns a non-zero vector into a vector of unit length. */
    void normalise()
    {
        T l = magnitude();
        if (l > 0)
        {
            (*this) *= ((T)1)/l;
        }
    }
    
    //over write by the above
    //    void Normalize()
    //    {
    //        float s = 1.0f / std::sqrt(x * x + y * y + z * z);
    //        x *= s;
    //        y *= s;
    //        z *= s;
    //    }/
    
    //modified below
    // Returns the normalised version of a vector.
    Vector4T unit() const
    {
        Vector4T result = *this;
        result.normalise();
        return result;
    }
    
    //over write by the above
    //    Vector4T Normalized() const 
    //    {
    //        Vector4T v = *this;
    //        v.Normalize();
    //        return v;
    //    }
    
    void trim(T size)
    {
        if (squareMagnitude() > size*size)
        {
            normalise();
            x *= size;
            y *= size;
            z *= size;
        }
    }      
    
    //////////////////////////////////////////////    
    //componentProduct
    /**
     * Calculates and returns a component-wise product of this
     * vector with the given vector.
     */
    Vector4T componentProduct(const Vector4T &vector) const
    {
        return Vector4T(x * vector.x, y * vector.y, z * vector.z);
    }
    
    /**
     * Performs a component-wise product with the given vector and
     * sets this vector to its result.
     */
    void componentProductUpdate(const Vector4T &vector)
    {
        x *= vector.x;
        y *= vector.y;
        z *= vector.z;
    }
    
    ///////////////////////////////////////
    //Cross | vectorProduct| %    
    /**
     * Calculates and returns the vector product of this vector
     * with the given vector.
     */
    
    //modified from Cross(...) to cross(...)
    Vector4T cross(const Vector4T &vector) const
    {
        return Vector4T(y*vector.z-z*vector.y,
                        z*vector.x-x*vector.z,
                        x*vector.y-y*vector.x);
    }
    
    Vector4T vectorProduct(const Vector4T &vector) const
    {
        return Vector4T(y*vector.z-z*vector.y,
                        z*vector.x-x*vector.z,
                        x*vector.y-y*vector.x);
    }
    // same as above
    Vector4T operator%(const Vector4T &vector) const
    {
        return Vector4T(y*vector.z-z*vector.y,
                        z*vector.x-x*vector.z,
                        x*vector.y-y*vector.x);
    }
    
    /**
     * Updates this vector to be the vector product of its current
     * value and the given vector.
     */
    void operator %=(const Vector4T &vector)
    {
        *this = cross(vector);
    }
    
    ///////////////////////////////////////    
    //dot |scalarProduct |*  |addScaledVector
    
    /**
     * Calculates and returns the scalar product of this vector
     * with the given vector.
     */
    T dot(const Vector4T &vector) const
    {
        return x*vector.x + y*vector.y + z*vector.z;
    }
    //replaced by above
    //    T Dot(const Vector4T& v) const
    //    {
    //        return x * v.x + y * v.y + z * v.z;
    //    }    
    //same as above
    T scalarProduct(const Vector4T &vector) const
    {
        return x*vector.x + y*vector.y + z*vector.z;
    }
    //same as above
    T operator *(const Vector4T &vector) const
    {
        return x*vector.x + y*vector.y + z*vector.z;
    }
    
    //Adds the given vector to this, scaled by the given amount.
    void addScaledVector(const Vector4T& vector, T scale)
    {
        x += vector.x * scale;
        y += vector.y * scale;
        z += vector.z * scale;
    }
    
    //////////////////////////////////////////////////     
    //compare     
    /** Checks if the two vectors have identical components. */    
    bool operator==(const Vector4T& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }
    
    /** Checks if the two vectors have non-identical components. */
    bool operator!=(const Vector4T& v) const
    {
        return !(*this == v);
    }
    
    /**
     * Checks if this vector is component-by-component less than
     * the other.
     *
     * @note This does not behave like a single-value comparison:
     * !(a < b) does not imply (b >= a).
     */
    bool operator<(const Vector4T& v) const
    {
        return x < v.x && y < v.y && z < v.z;
    }
    
    /**
     * Checks if this vector is component-by-component less than
     * the other.
     *
     * @note This does not behave like a single-value comparison:
     * !(a < b) does not imply (b >= a).
     */
    bool operator>(const Vector4T& v) const
    {
        return x > v.x && y > v.y && z > v.z;
    }
    
    /**
     * Checks if this vector is component-by-component less than
     * the other.
     *
     * @note This does not behave like a single-value comparison:
     * !(a <= b) does not imply (b > a).
     */
    bool operator<=(const Vector4T& v) const
    {
        return x <= v.x && y <= v.y && z <= v.z;
    }
    
    /**
     * Checks if this vector is component-by-component less than
     * the other.
     *
     * @note This does not behave like a single-value comparison:
     * !(a <= b) does not imply (b > a).
     */
    bool operator>=(const Vector4T& v) const
    {
        return x >= v.x && y >= v.y && z >= v.z;
    }
    
    ////////////////////////
    // define some static //
    ////////////////////////
    
    //    const static Vector4T GRAVITY;
    //    const static Vector4T HIGH_GRAVITY;
    //    const static Vector4T UP;
    //    const static Vector4T RIGHT;
    //    const static Vector4T OUT_OF_SCREEN;
    //    const static Vector4T X;
    //    const static Vector4T Y;
    //    const static Vector4T Z;
};

typedef Vector4T<int> ivec4;
typedef Vector4T<float> vec4;

#endif