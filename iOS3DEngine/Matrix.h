#ifndef ENGINE_MATH_MATRIX_H
#define ENGINE_MATH_MATRIX_H

// SIMD includes
//#include <xmmintrin.h>
//#include <smmintrin.h> 

#include "Enum.h"

class Matrix
{
public:
	//default constructor
	Matrix( float m0 = 0.0, float m1 = 0.0, float m2 = 0.0, float m3 = 0.0,
			float m4 = 0.0, float m5 = 0.0, float m6 = 0.0, float m7 = 0.0,
			float m8 = 0.0, float m9 = 0.0, float m10 =0.0, float m11 =0.0,
			float m12 =0.0, float m13 =0.0, float m14 =0.0, float m15 =0.0);
	//vector copy constructor
	Matrix(const Vect& v0, const Vect& v1, const Vect& v2, const Vect& v3 );
	//copy constructor
	Matrix(const Matrix& );
	//assignment constructor
	Matrix& operator=(const Matrix& mat); 
	//deconstructor
	~Matrix(){}

	//sepical constructors
	Matrix(MatrixSpecialType type); // construct a zero or identity matrix
	Matrix(MatrixTransType type, float x, float y, float z); // construct a transition matrix
	Matrix(MatrixScaleType type, float x, float y, float z); // construct a scaling matrix
	Matrix(MatrixRotType type, float angle); // construct a rotation matrix
    static Matrix Frustum(float left, float right, float bottom, float top, float near, float far);
    
    const float* Pointer() const
    {
        return &m0;
    }
    

	//getter //return data components //return value
	float operator[](m0_enum)const{return this->m0;}
	float operator[](m1_enum)const{return this->m1;}
	float operator[](m2_enum)const{return this->m2;}
	float operator[](m3_enum)const{return this->m3;}
	float operator[](m4_enum)const{return this->m4;}
	float operator[](m5_enum)const{return this->m5;}
	float operator[](m6_enum)const{return this->m6;}
	float operator[](m7_enum)const{return this->m7;}
	float operator[](m8_enum)const{return this->m8;}
	float operator[](m9_enum)const{return this->m9;}
	float operator[](m10_enum)const{return this->m10;}
	float operator[](m11_enum)const{return this->m11;}
	float operator[](m12_enum)const{return this->m12;}
	float operator[](m13_enum)const{return this->m13;}
	float operator[](m14_enum)const{return this->m14;}
	float operator[](m15_enum)const{return this->m15;}

	//setter //return reference components //& for assigment 
	float& operator[](m0_enum){return this->m0;}
	float& operator[](m1_enum){return this->m1;}
	float& operator[](m2_enum){return this->m2;}
	float& operator[](m3_enum){return this->m3;}
	float& operator[](m4_enum){return this->m4;}
	float& operator[](m5_enum){return this->m5;}
	float& operator[](m6_enum){return this->m6;}
	float& operator[](m7_enum){return this->m7;}
	float& operator[](m8_enum){return this->m8;}
	float& operator[](m9_enum){return this->m9;}
	float& operator[](m10_enum){return this->m10;}
	float& operator[](m11_enum){return this->m11;}
	float& operator[](m12_enum){return this->m12;}
	float& operator[](m13_enum){return this->m13;}
	float& operator[](m14_enum){return this->m14;}
	float& operator[](m15_enum){return this->m15;}

	////set spicial types Matrix
	//set ZERO or IDENTITY Matrix
	void set(MatrixSpecialType type);
	//set Translation Matrix
	void set(MatrixTransType, float x, float y, float z);
	// set scaling Matrix
	void set(MatrixScaleType, float x, float y, float z);
	// set rotation Matrix
	void set(MatrixRotType type, float angle); 
   
	////setter and getter for rows
//	void set(MatrixRowType type, const Vect& vec);
//	void set(const Vect& vect0, const Vect& vect1, const Vect& vect2 ,const Vect& vect3);
//	Vect get(MatrixRowType type) const;

	////overloade arithmetic operator
	//Matrix unary
	const Matrix operator +()const;//why add  const here?
	const Matrix operator -()const;
	//Matrix + - * operators with the other Matrix
	Matrix& operator += (const Matrix& mat);
	Matrix  operator +  (const Matrix& mat) const; 
	Matrix& operator -= (const Matrix& mat);
	Matrix  operator -  (const Matrix& mat) const;
	Matrix& operator *= (const Matrix& mat);
	Matrix  operator *  (const Matrix& mat)const;
	//Matrix scale overload operators
	Matrix& operator *= (float s);
	Matrix  operator *  (float s) const;

	///Matrix comparison operators
	//if the matrixs is equal to the other
	bool isEqual(const Matrix& mat) const;	
	// if the matrix==IDENTITY	
	bool isIdentity() const;
	// if the matrix==IDENTITY with espilon
	bool isIdentity(float espilon) const;

	////Matrix functions
	const float det() const;//determinant
    void T();//self transpose 
    Matrix getT() const;//transpose
    void inv();//self inverse
    Matrix getInv() const;//inverse

private:

// Level 4 complains nameless struct/union ...
#pragma warning( disable : 4201)

union 
		{
//		struct 
//			{
//			Vect v0;
//			Vect v1;
//			Vect v2;
//			Vect v3;
//			};

		struct 
			{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;	
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
			};
		};
};

Matrix operator*(const float s, Matrix& mat); 

#endif