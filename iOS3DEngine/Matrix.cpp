#include "MathEngine.hpp"
#include <math.h>

//default constructor
Matrix::Matrix( float m0,  float m1,  float m2,  float m3,
				float m4,  float m5,  float m6,  float m7,
				float m8,  float m9,  float m10, float m11,
				float m12, float m13, float m14, float m15)
{
	this->m0 = m0;
	this->m1 = m1;
	this->m2 = m2;
	this->m3 = m3;
	this->m4 = m4;
	this->m5 = m5;
	this->m6 = m6;
	this->m7 = m7;
	this->m8 = m8;
	this->m9 = m9;
	this->m10 = m10;
	this->m11 = m11;
	this->m12 = m12;
	this->m13 = m13;
	this->m14 = m14;
	this->m15 = m15;
}

//vector copy constructor
Matrix::Matrix(const Vect& v0, const Vect& v1, const Vect& v2, const Vect& v3 )
{
	this->m0 = v0[x];
	this->m1 = v0[y];
	this->m2 = v0[z];
	this->m3 = v0[w];
	this->m4 = v1[x];
	this->m5 = v1[y];
	this->m6 = v1[z];
	this->m7 = v1[w];
	this->m8 = v2[x];
	this->m9 = v2[y];
	this->m10 =v2[z];
	this->m11 =v2[w];
	this->m12 =v3[x];
	this->m13 =v3[y];
	this->m14 =v3[z];
	this->m15 =v3[w];
}

//copy constructor
Matrix::Matrix(const Matrix& mat)
{
	this->m0 = mat.m0;
	this->m1 = mat.m1;
	this->m2 = mat.m2;
	this->m3 = mat.m3;
	this->m4 = mat.m4;
	this->m5 = mat.m5;
	this->m6 = mat.m6;
	this->m7 = mat.m7;
	this->m8 = mat.m8;
	this->m9 = mat.m9;
	this->m10 = mat.m10;
	this->m11 = mat.m11;
	this->m12 = mat.m12;
	this->m13 = mat.m13;
	this->m14 = mat.m14;
	this->m15 = mat.m15;
}

//assignment constructor or assignment operator
Matrix& Matrix::operator=(const Matrix& mat)
{
	this->m0 = mat.m0;
	this->m1 = mat.m1;
	this->m2 = mat.m2;
	this->m3 = mat.m3;
	this->m4 = mat.m4;
	this->m5 = mat.m5;
	this->m6 = mat.m6;
	this->m7 = mat.m7;
	this->m8 = mat.m8;
	this->m9 = mat.m9;
	this->m10 = mat.m10;
	this->m11 = mat.m11;
	this->m12 = mat.m12;
	this->m13 = mat.m13;
	this->m14 = mat.m14;
	this->m15 = mat.m15;

	return *this;
}

////sepical constructors
//construct a ZERO or IDENTITY Matrix
Matrix::Matrix(MatrixSpecialType type)
{
   if(type == ZERO)
   {
      this->m0 = 0;
      this->m1 = 0;
      this->m2 = 0;
      this->m3 = 0;
      this->m4 = 0;
      this->m5 = 0;
      this->m6 = 0;
      this->m7 = 0;
      this->m8 = 0;
      this->m9 = 0;
      this->m10 = 0;
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 0;
   }
   else if(type == IDENTITY)
   {
      this->m0 = 1;
      this->m1 = 0;
      this->m2 = 0;
      this->m3 = 0;
      this->m4 = 0;
      this->m5 = 1;
      this->m6 = 0;
      this->m7 = 0;
      this->m8 = 0;
      this->m9 = 0;
      this->m10 = 1;
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 1;
   }
      
}

//construct a translation Matrix
Matrix::Matrix(MatrixTransType, float x, float y, float z)
{
   this->m0 = 1;
   this->m1 = 0;
   this->m2 = 0;
   this->m3 = 0;
   this->m4 = 0;
   this->m5 = 1;
   this->m6 = 0;
   this->m7 = 0;
   this->m8 = 0;
   this->m9 = 0;
   this->m10 = 1;
   this->m11 = 0;
   this->m12 = x;
   this->m13 = y;
   this->m14 = z;
   this->m15 = 1;
}

//construct a scaling Matrix
Matrix::Matrix(MatrixScaleType, float x, float y, float z)
{
   this->m0 = x;
   this->m1 = 0;
   this->m2 = 0;
   this->m3 = 0;
   this->m4 = 0;
   this->m5 = y;
   this->m6 = 0;
   this->m7 = 0;
   this->m8 = 0;
   this->m9 = 0;
   this->m10 = z;
   this->m11 = 0;
   this->m12 = 0;
   this->m13 = 0;
   this->m14 = 0;
   this->m15 = 1;
}

//construct a rotation Matrix
Matrix::Matrix(MatrixRotType type, float angle)
{
   if(type == ROT_X)
   {
      this->m0 = 1;
      this->m1 = 0;
      this->m2 = 0;
      this->m3 = 0;
      this->m4 = 0;
      this->m5 = cos(angle);
      this->m6 = sin(angle);
      this->m7 = 0;
      this->m8 = 0;
      this->m9 = -sin(angle);
      this->m10 = cos(angle);
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 1;
   }
   else if(type == ROT_Y)
   {
      this->m0 = cos(angle);
      this->m1 = 0;
      this->m2 = -sin(angle);
      this->m3 = 0;
      this->m4 = 0;
      this->m5 = 1;
      this->m6 = 0;
      this->m7 = 0;
      this->m8 = sin(angle);
      this->m9 = 0;
      this->m10 = cos(angle);
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 1;
   }
   else if(type == ROT_Z)
   {
      this->m0 = cos(angle);
      this->m1 = sin(angle);
      this->m2 = 0;
      this->m3 = 0;
      this->m4 = -sin(angle);
      this->m5 = cos(angle);
      this->m6 = 0;
      this->m7 = 0;
      this->m8 = 0;
      this->m9 = 0;
      this->m10 = 1;
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 1;
   }
}

Matrix Matrix::Frustum(float left, float right, float bottom, float top, float near, float far)
{
    float a = 2 * near / (right - left);
    float b = 2 * near / (top - bottom);
    float c = (right + left) / (right - left);
    float d = (top + bottom) / (top - bottom);
    float e = - (far + near) / (far - near);
    float f = -2 * far * near / (far - near);
    Matrix m(
    a, 0, 0, 0,
    0, b, 0, 0,
    c, d, e, -1,
    0, 0, f, 1);
    return m;
}


/////////////////////////

//set ZERO or IDENTITY Matrix
void Matrix::set(MatrixSpecialType type)
{
   if(type == ZERO)
   {
      this->m0 = 0;
      this->m1 = 0;
      this->m2 = 0;
      this->m3 = 0;
      this->m4 = 0;
      this->m5 = 0;
      this->m6 = 0;
      this->m7 = 0;
      this->m8 = 0;
      this->m9 = 0;
      this->m10 = 0;
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 0;
   }
   else if(type == IDENTITY)
   {
      this->m0 = 1;
      this->m1 = 0;
      this->m2 = 0;
      this->m3 = 0;
      this->m4 = 0;
      this->m5 = 1;
      this->m6 = 0;
      this->m7 = 0;
      this->m8 = 0;
      this->m9 = 0;
      this->m10 = 1;
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 1;
   }
      
}

//set translation Matrix
void Matrix::set(MatrixTransType, float x, float y, float z)
{
   this->m0 = 1;
   this->m1 = 0;
   this->m2 = 0;
   this->m3 = 0;
   this->m4 = 0;
   this->m5 = 1;
   this->m6 = 0;
   this->m7 = 0;
   this->m8 = 0;
   this->m9 = 0;
   this->m10 = 1;
   this->m11 = 0;
   this->m12 = x;
   this->m13 = y;
   this->m14 = z;
   this->m15 = 1;
}

//set scaling Matrix
void Matrix::set(MatrixScaleType, float x, float y, float z)
{
   this->m0 = x;
   this->m1 = 0;
   this->m2 = 0;
   this->m3 = 0;
   this->m4 = 0;
   this->m5 = y;
   this->m6 = 0;
   this->m7 = 0;
   this->m8 = 0;
   this->m9 = 0;
   this->m10 = z;
   this->m11 = 0;
   this->m12 = 0;
   this->m13 = 0;
   this->m14 = 0;
   this->m15 = 1;
}

//set rotation Matrix
void Matrix::set(MatrixRotType type, float angle)
{
   if(type == ROT_X)
   {
      this->m0 = 1;
      this->m1 = 0;
      this->m2 = 0;
      this->m3 = 0;
      this->m4 = 0;
      this->m5 = cos(angle);
      this->m6 = sin(angle);
      this->m7 = 0;
      this->m8 = 0;
      this->m9 = -sin(angle);
      this->m10 = cos(angle);
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 1;
   }
   else if(type == ROT_Y)
   {
      this->m0 = cos(angle);
      this->m1 = 0;
      this->m2 = -sin(angle);
      this->m3 = 0;
      this->m4 = 0;
      this->m5 = 1;
      this->m6 = 0;
      this->m7 = 0;
      this->m8 = sin(angle);
      this->m9 = 0;
      this->m10 = cos(angle);
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 1;
   }
   else if(type == ROT_Z)
   {
      this->m0 = cos(angle);
      this->m1 = sin(angle);
      this->m2 = 0;
      this->m3 = 0;
      this->m4 = -sin(angle);
      this->m5 = cos(angle);
      this->m6 = 0;
      this->m7 = 0;
      this->m8 = 0;
      this->m9 = 0;
      this->m10 = 1;
      this->m11 = 0;
      this->m12 = 0;
      this->m13 = 0;
      this->m14 = 0;
      this->m15 = 1;
   }
}

////set Rows
//void Matrix::set(MatrixRowType type, const Vect& vect)
//{
//   if(type == ROW_0)
//      this->v0 = vect;
//   else if(type == ROW_1)
//      this->v1 = vect;
//   else if(type == ROW_2)
//      this->v2 = vect;
//   else if(type == ROW_3)
//      this->v3 = vect;
//}
//
////set Matrix with vectors
//void Matrix::set(const Vect& vect0, const Vect& vect1, const Vect& vect2, const Vect& vect3)
//{
//   this->v0 = vect0;
//   this->v1 = vect1;
//   this->v2 = vect2;
//   this->v3 = vect3;
//}
//
////get Rows
//Vect Matrix::get(MatrixRowType type) const
//{
//   if(type == ROW_0)
//      return this->v0;
//   else if(type == ROW_1)
//      return this->v1;
//   else if(type == ROW_2)
//      return this->v2;
//   else if(type == ROW_3)
//      return this->v3;
//   else
//      return Vect(0.0f, 0.0f, 0.0f);
//}


////overloade arithmetic operator
//Matrix unary +
const Matrix Matrix::operator+() const
{
	return *this;
}

//Matrix unary -
const Matrix Matrix::operator-() const
{
   return Matrix(-this->m0, -this->m1, -this->m2,  -this->m3,
				 -this->m4, -this->m5, -this->m6,  -this->m7,
				 -this->m8, -this->m9, -this->m10, -this->m11,
				 -this->m12,-this->m13,-this->m14, -this->m15);
}

//Matrix operator += 
Matrix& Matrix::operator+=(const Matrix& mat)
{
	this->m0+= mat.m0;
	this->m1+= mat.m1;
	this->m2+= mat.m2;
	this->m3+= mat.m3;
	this->m4+= mat.m4;
	this->m5+= mat.m5;
	this->m6+= mat.m6;
	this->m7+= mat.m7;
	this->m8+= mat.m8;
	this->m9+= mat.m9;
	this->m10+= mat.m10;
	this->m11+= mat.m11;
	this->m12+= mat.m12;
	this->m13+= mat.m13;
	this->m14+= mat.m14;
	this->m15+= mat.m15;

	return *this;
}

//Matrix operator +
Matrix Matrix::operator+(const Matrix& mat) const
{
   return Matrix(this->m0+mat.m0,	this->m1+mat.m1,	this->m2+mat.m2,	this->m3+mat.m3,
				 this->m4+mat.m4,	this->m5+mat.m5,	this->m6+mat.m6,	this->m7+mat.m7,
				 this->m8+mat.m8,	this->m9+mat.m9,	this->m10+mat.m10,	this->m11+mat.m11,
				 this->m12+mat.m12, this->m13+mat.m13,	this->m14+mat.m14,	this->m15+mat.m15);
}

//Matrix operator -=
Matrix& Matrix::operator-=(const Matrix& mat)
{
	this->m0 -= mat.m0;
	this->m1 -= mat.m1;
	this->m2 -= mat.m2;
	this->m3 -= mat.m3;
	this->m4 -= mat.m4;
	this->m5 -= mat.m5;
	this->m6 -= mat.m6;
	this->m7 -= mat.m7;
	this->m8 -= mat.m8;
	this->m9 -= mat.m9;
	this->m10 -= mat.m10;
	this->m11 -= mat.m11;
	this->m12 -= mat.m12;
	this->m13 -= mat.m13;
	this->m14 -= mat.m14;
	this->m15 -= mat.m15;

	return *this;
}

//Matrix operator -
Matrix Matrix::operator-(const Matrix& mat) const
{
   return Matrix(this->m0-mat.m0,	this->m1-mat.m1,	this->m2-mat.m2,	this->m3-mat.m3,
				 this->m4-mat.m4,	this->m5-mat.m5,	this->m6-mat.m6,	this->m7-mat.m7,
				 this->m8-mat.m8,	this->m9-mat.m9,	this->m10-mat.m10,	this->m11-mat.m11,
				 this->m12-mat.m12, this->m13-mat.m13,	this->m14-mat.m14,	this->m15-mat.m15);
}

//Matrix Multiply *=
Matrix& Matrix::operator*=(const Matrix& mat)
{
	Matrix matTemp = *this;
	this->m0 = matTemp.m0*mat.m0 + matTemp.m1*mat.m4 + matTemp.m2*mat.m8 + matTemp.m3*mat.m12;
	this->m1 = matTemp.m0*mat.m1 + matTemp.m1*mat.m5 + matTemp.m2*mat.m9 + matTemp.m3*mat.m13;
	this->m2 = matTemp.m0*mat.m2 + matTemp.m1*mat.m6 + matTemp.m2*mat.m10 + matTemp.m3*mat.m14;
	this->m3 = matTemp.m0*mat.m3 + matTemp.m1*mat.m7 + matTemp.m2*mat.m11 + matTemp.m3*mat.m15;
	this->m4 = matTemp.m4*mat.m0 + matTemp.m5*mat.m4 + matTemp.m6*mat.m8 + matTemp.m7*mat.m12;
	this->m5 = matTemp.m4*mat.m1 + matTemp.m5*mat.m5 + matTemp.m6*mat.m9 + matTemp.m7*mat.m13;
	this->m6 = matTemp.m4*mat.m2 + matTemp.m5*mat.m6 + matTemp.m6*mat.m10 + matTemp.m7*mat.m14;
	this->m7 = matTemp.m4*mat.m3 + matTemp.m5*mat.m7 + matTemp.m6*mat.m11 + matTemp.m7*mat.m15;
	this->m8 = matTemp.m8*mat.m0 + matTemp.m9*mat.m4 + matTemp.m10*mat.m8 + matTemp.m11*mat.m12;
	this->m9 = matTemp.m8*mat.m1 + matTemp.m9*mat.m5 + matTemp.m10*mat.m9 + matTemp.m11*mat.m13;
	this->m10 = matTemp.m8*mat.m2 + matTemp.m9*mat.m6 + matTemp.m10*mat.m10 + matTemp.m11*mat.m14;
	this->m11 = matTemp.m8*mat.m3 + matTemp.m9*mat.m7 + matTemp.m10*mat.m11 + matTemp.m11*mat.m15;
	this->m12 = matTemp.m12*mat.m0 + matTemp.m13*mat.m4 + matTemp.m14*mat.m8 + matTemp.m15*mat.m12;
	this->m13 = matTemp.m12*mat.m1 + matTemp.m13*mat.m5 + matTemp.m14*mat.m9 + matTemp.m15*mat.m13;
	this->m14 = matTemp.m12*mat.m2 + matTemp.m13*mat.m6 + matTemp.m14*mat.m10 + matTemp.m15*mat.m14;
	this->m15 = matTemp.m12*mat.m3 + matTemp.m13*mat.m7 + matTemp.m14*mat.m11 + matTemp.m15*mat.m15;

	return *this;
}

//Matrix Multiply *
Matrix Matrix::operator*(const Matrix& mat) const
{
	float m0 = this->m0*mat.m0 + this->m1*mat.m4 + this->m2*mat.m8 + this->m3*mat.m12;
	float m1 = this->m0*mat.m1 + this->m1*mat.m5 + this->m2*mat.m9 + this->m3*mat.m13;
	float m2 = this->m0*mat.m2 + this->m1*mat.m6 + this->m2*mat.m10 + this->m3*mat.m14;
	float m3 = this->m0*mat.m3 + this->m1*mat.m7 + this->m2*mat.m11 + this->m3*mat.m15;
	float m4 = this->m4*mat.m0 + this->m5*mat.m4 + this->m6*mat.m8 + this->m7*mat.m12;
	float m5 = this->m4*mat.m1 + this->m5*mat.m5 + this->m6*mat.m9 + this->m7*mat.m13;
	float m6 = this->m4*mat.m2 + this->m5*mat.m6 + this->m6*mat.m10 + this->m7*mat.m14;
	float m7 = this->m4*mat.m3 + this->m5*mat.m7 + this->m6*mat.m11 + this->m7*mat.m15;
	float m8 = this->m8*mat.m0 + this->m9*mat.m4 + this->m10*mat.m8 + this->m11*mat.m12;
	float m9 = this->m8*mat.m1 + this->m9*mat.m5 + this->m10*mat.m9 + this->m11*mat.m13;
	float m10 = this->m8*mat.m2 + this->m9*mat.m6 + this->m10*mat.m10 + this->m11*mat.m14;
	float m11 = this->m8*mat.m3 + this->m9*mat.m7 + this->m10*mat.m11 + this->m11*mat.m15;
	float m12 = this->m12*mat.m0 + this->m13*mat.m4 + this->m14*mat.m8 + this->m15*mat.m12;
	float m13 = this->m12*mat.m1 + this->m13*mat.m5 + this->m14*mat.m9 + this->m15*mat.m13;
	float m14 = this->m12*mat.m2 + this->m13*mat.m6 + this->m14*mat.m10 + this->m15*mat.m14;
	float m15 = this->m12*mat.m3 + this->m13*mat.m7 + this->m14*mat.m11 + this->m15*mat.m15;

	return Matrix(m0,m1,m2,m3,
				m4,m5,m6,m7,
				m8,m9,m10,m11,
				m12,m13,m14,m15);
}

//Matrix operator scale *=
Matrix& Matrix::operator*=(float s)
{
	this->m0*= s;
	this->m1*= s;
	this->m2*= s;
	this->m3*= s;
	this->m4*= s;
	this->m5*= s;
	this->m6*= s;
	this->m7*= s;
	this->m8*= s;
	this->m9*= s;
	this->m10*= s;
	this->m11*= s;
	this->m12*= s;
	this->m13*= s;
	this->m14*= s;
	this->m15*= s;

	return *this;
}

//Matrix operator scale *
Matrix Matrix::operator*(float f) const
{
   return Matrix(f*this->m0, f*this->m1, f*this->m2,  f*this->m3,
				 f*this->m4, f*this->m5, f*this->m6,  f*this->m7,
				 f*this->m8, f*this->m9, f*this->m10, f*this->m11,
				 f*this->m12,f*this->m13,f*this->m14, f*this->m15);
}

//Matrix out-side operator scale *
Matrix operator*(const float f, Matrix& mat)
{
   return Matrix(f*mat[m0], f*mat[m1], f*mat[m2],  f*mat[m3],
				 f*mat[m4], f*mat[m5], f*mat[m6],  f*mat[m7],
				 f*mat[m8], f*mat[m9], f*mat[m10], f*mat[m11],
				 f*mat[m12],f*mat[m13],f*mat[m14], f*mat[m15]);
}


///Matrix comparison operators
//if the matrixs is equal to the other
bool Matrix::isEqual(const Matrix& mat) const
{
//   return(	this->get(ROW_0).isEqual(mat.get(ROW_0))&&
//			this->get(ROW_1).isEqual(mat.get(ROW_1))&&
//			this->get(ROW_2).isEqual(mat.get(ROW_2))&&
//			this->get(ROW_3).isEqual(mat.get(ROW_3)));
    
    
    return
    Util::isEqual(mat.m0,this->m0,0)&&
    Util::isEqual(mat.m1,this->m1,0)&&
    Util::isEqual(mat.m2,this->m2,0)&&
    Util::isEqual(mat.m3,this->m3,0)&&
    Util::isEqual(mat.m4,this->m4,0)&&
    Util::isEqual(mat.m5,this->m5,0)&&
    Util::isEqual(mat.m6,this->m6,0)&&
    Util::isEqual(mat.m7,this->m7,0)&&
    Util::isEqual(mat.m8,this->m8,0)&&
    Util::isEqual(mat.m9,this->m9,0)&&
    Util::isEqual(mat.m10,this->m10,0)&&
    Util::isEqual(mat.m11,this->m11,0)&&
    Util::isEqual(mat.m12,this->m12,0)&&
    Util::isEqual(mat.m13,this->m13,0)&&
    Util::isEqual(mat.m14,this->m14,0)&&
    Util::isEqual(mat.m15,this->m15,0);
    
}

// if the matrix==IDENTITY	
bool Matrix::isIdentity() const
{
//   Matrix mat(IDENTITY);
//   return(	this->get(ROW_0).isEqual(mat.get(ROW_0))&&
//			this->get(ROW_1).isEqual(mat.get(ROW_1))&&
//			this->get(ROW_2).isEqual(mat.get(ROW_2))&&
//			this->get(ROW_3).isEqual(mat.get(ROW_3)));
    
    return
    Util::isEqual(1,this->m0,0)&&
    Util::isEqual(0,this->m1,0)&&
    Util::isEqual(0,this->m2,0)&&
    Util::isEqual(0,this->m3,0)&&
    Util::isEqual(0,this->m4,0)&&
    Util::isEqual(1,this->m5,0)&&
    Util::isEqual(0,this->m6,0)&&
    Util::isEqual(0,this->m7,0)&&
    Util::isEqual(0,this->m8,0)&&
    Util::isEqual(0,this->m9,0)&&
    Util::isEqual(1,this->m10,0)&&
    Util::isEqual(0,this->m11,0)&&
    Util::isEqual(0,this->m12,0)&&
    Util::isEqual(0,this->m13,0)&&
    Util::isEqual(0,this->m14,0)&&
    Util::isEqual(1,this->m15,0);
    
    
}

// if the matrix==IDENTITY with espilon
bool Matrix::isIdentity(float espilon) const
{
	return
		Util::isEqual(1,this->m0,espilon)&&
		Util::isEqual(0,this->m1,espilon)&&
		Util::isEqual(0,this->m2,espilon)&&
		Util::isEqual(0,this->m3,espilon)&&
		Util::isEqual(0,this->m4,espilon)&&
		Util::isEqual(1,this->m5,espilon)&&
		Util::isEqual(0,this->m6,espilon)&&
		Util::isEqual(0,this->m7,espilon)&&
		Util::isEqual(0,this->m8,espilon)&&
		Util::isEqual(0,this->m9,espilon)&&
		Util::isEqual(1,this->m10,espilon)&&
		Util::isEqual(0,this->m11,espilon)&&
		Util::isEqual(0,this->m12,espilon)&&
		Util::isEqual(0,this->m13,espilon)&&
		Util::isEqual(0,this->m14,espilon)&&
		Util::isEqual(1,this->m15,espilon);
}


////Matrix functions
//determinant
const float Matrix::det() const
{
	float value = this->m0*this->m5*this->m10*this->m15 + this->m0*this->m6*this->m11*this->m13 + this->m0*this->m7*this->m9*this->m14
		+ this->m1*this->m4*this->m11*this->m14 + this->m1*this->m6*this->m8*this->m15 + this->m1*this->m7*this->m10*this->m12
		+ this->m2*this->m4*this->m9*this->m15 + this->m2*this->m5*this->m11*this->m12 + this->m2*this->m7*this->m8*this->m13
		+ this->m3*this->m4*this->m10*this->m13 + this->m3*this->m5*this->m8*this->m14 + this->m3*this->m6*this->m9*this->m12
		- this->m0*this->m5*this->m11*this->m14 - this->m0*this->m6*this->m9*this->m15 - this->m0*this->m7*this->m10*this->m13
		- this->m1*this->m4*this->m10*this->m15 - this->m1*this->m6*this->m11*this->m12 - this->m1*this->m7*this->m8*this->m14
		- this->m2*this->m4*this->m11*this->m13 - this->m2*this->m5*this->m8*this->m15 - this->m2*this->m7*this->m9*this->m12
		- this->m3*this->m4*this->m9*this->m14 - this->m3*this->m5*this->m10*this->m12 - this->m3*this->m6*this->m8*this->m13;
	return value;
}

//self transpose 
void Matrix::T()
{
   Matrix tmpMat = *this;
   this->m1 = tmpMat.m4;
   this->m2 = tmpMat.m8;
   this->m3 = tmpMat.m12;
   this->m4 = tmpMat.m1;
   this->m6 = tmpMat.m9;
   this->m7 = tmpMat.m13;
   this->m8 = tmpMat.m2;
   this->m9 = tmpMat.m6;
   this->m11 = tmpMat.m14;
   this->m12 = tmpMat.m3;
   this->m13 = tmpMat.m7;
   this->m14 = tmpMat.m11;
}

//transpose
Matrix Matrix::getT() const
{
	Matrix tmpMat;
	tmpMat.m0 = this->m0;
	tmpMat.m1 = this->m4;
	tmpMat.m2 = this->m8;
	tmpMat.m3 = this->m12;
	tmpMat.m4 = this->m1;
	tmpMat.m5 = this->m5;
	tmpMat.m6 = this->m9;
	tmpMat.m7 = this->m13;
	tmpMat.m8 = this->m2;
	tmpMat.m9 = this->m6;
	tmpMat.m10 = this->m10;
	tmpMat.m11 = this->m14;
	tmpMat.m12 = this->m3;
	tmpMat.m13 = this->m7;
	tmpMat.m14 = this->m11;
	tmpMat.m15 = this->m15;
   
	return tmpMat;
}

//inverse result stored in the same matrix
void Matrix::inv()
{
   Matrix mat = *this;
   float dot=1/this->det();
   this->m0 = mat.m5*mat.m10*mat.m15 + mat.m6*mat.m11*mat.m13 + mat.m7*mat.m9*mat.m14 - mat.m5*mat.m11*mat.m14 - mat.m6*mat.m9*mat.m15 - mat.m7*mat.m10*mat.m13;
   this->m1 = mat.m1*mat.m11*mat.m14 + mat.m2*mat.m9*mat.m15 + mat.m3*mat.m10*mat.m13 - mat.m1*mat.m10*mat.m15 - mat.m2*mat.m11*mat.m13 - mat.m3*mat.m9*mat.m14;
   this->m2 = mat.m1*mat.m6*mat.m15 + mat.m2*mat.m7*mat.m13 + mat.m3*mat.m5*mat.m14 - mat.m1*mat.m7*mat.m14 - mat.m2*mat.m5*mat.m15 - mat.m3*mat.m6*mat.m13;
   this->m3 = mat.m1*mat.m7*mat.m10 + mat.m2*mat.m5*mat.m11 + mat.m3*mat.m6*mat.m9 - mat.m1*mat.m6*mat.m11 - mat.m2*mat.m7*mat.m9 - mat.m3*mat.m5*mat.m10;
   this->m4 = mat.m4*mat.m11*mat.m14 + mat.m6*mat.m8*mat.m15 + mat.m7*mat.m10*mat.m12 - mat.m4*mat.m10*mat.m15 - mat.m6*mat.m11*mat.m12 - mat.m7*mat.m8*mat.m14;
   this->m5 = mat.m0*mat.m10*mat.m15 + mat.m2*mat.m11*mat.m12 + mat.m3*mat.m8*mat.m14 - mat.m0*mat.m11*mat.m14 - mat.m2*mat.m8*mat.m15 - mat.m3*mat.m10*mat.m12;
   this->m6 = mat.m0*mat.m7*mat.m14 + mat.m2*mat.m4*mat.m15 + mat.m3*mat.m6*mat.m12 - mat.m0*mat.m6*mat.m15 - mat.m2*mat.m7*m12 - mat.m3*mat.m4*mat.m14;
   this->m7 = mat.m0*mat.m6*mat.m11 + mat.m2*mat.m7*mat.m8 + mat.m3*mat.m4*mat.m10 - mat.m0*mat.m7*mat.m10 - mat.m2*mat.m4*m11 - mat.m3*mat.m6*mat.m8;
   this->m8 = mat.m4*mat.m9*mat.m15 + mat.m5*mat.m11*mat.m12 + mat.m7*mat.m10*mat.m13 - mat.m4*mat.m11*mat.m13 - mat.m5*mat.m8*m15 - mat.m7*mat.m9*mat.m12;
   this->m9 = mat.m0*mat.m11*mat.m13 + mat.m1*mat.m8*mat.m15 + mat.m3*mat.m9*mat.m12 - mat.m0*mat.m9*mat.m15 - mat.m1*mat.m11*m12 - mat.m3*mat.m8*mat.m13;
   this->m10 = mat.m0*mat.m5*mat.m15 + mat.m1*mat.m7*mat.m12 + mat.m3*mat.m8*mat.m13 - mat.m0*mat.m7*mat.m13 - mat.m1*mat.m4*m15 - mat.m3*mat.m5*mat.m12;
   this->m11 = mat.m0*mat.m7*mat.m9 + mat.m1*mat.m4*mat.m11 + mat.m3*mat.m5*mat.m8 - mat.m0*mat.m5*mat.m11 - mat.m1*mat.m7*m8 - mat.m3*mat.m4*mat.m9;
   this->m12 = mat.m4*mat.m10*mat.m13 + mat.m5*mat.m8*mat.m14 + mat.m6*mat.m9*mat.m12 - mat.m4*mat.m9*mat.m14 - mat.m5*mat.m10*m12 - mat.m6*mat.m8*mat.m13;
   this->m13 = mat.m0*mat.m9*mat.m14 + mat.m1*mat.m10*mat.m12 + mat.m2*mat.m8*mat.m13 - mat.m0*mat.m10*mat.m13 - mat.m1*mat.m8*m14 - mat.m2*mat.m9*mat.m12;
   this->m14 = mat.m0*mat.m6*mat.m13 + mat.m1*mat.m4*mat.m14 + mat.m2*mat.m5*mat.m12 - mat.m0*mat.m5*mat.m14 - mat.m1*mat.m6*m12 - mat.m2*mat.m4*mat.m13;
   this->m15 = mat.m0*mat.m5*mat.m10 + mat.m1*mat.m6*mat.m8 + mat.m2*mat.m4*mat.m9 - mat.m0*mat.m6*mat.m9 - mat.m1*mat.m4*m10 - mat.m2*mat.m5*mat.m8;

   *this*=dot;
}

// inverse 
Matrix Matrix::getInv() const
{
	Matrix mat;
	float dot=1/this->det();
	mat.m0 = m5*m10*m15 + m6*m11*m13 + m7*m9*m14 - m5*m11*m14 - m6*m9*m15 - m7*m10*m13;
	mat.m1 = m1*m11*m14 + m2*m9*m15 + m3*m10*m13 - m1*m10*m15 - m2*m11*m13 - m3*m9*m14;
	mat.m2 = m1*m6*m15 + m2*m7*m13 + m3*m5*m14 - m1*m7*m14 - m2*m5*m15 - m3*m6*m13;
	mat.m3 = m1*m7*m10 + m2*m5*m11 + m3*m6*m9 - m1*m6*m11 - m2*m7*m9 - m3*m5*m10;
	mat.m4 = m4*m11*m14 + m6*m8*m15 + m7*m10*m12 - m4*m10*m15 - m6*m11*m12 - m7*m8*m14;
	mat.m5 = m0*m10*m15 + m2*m11*m12 + m3*m8*m14 - m0*m11*m14 - m2*m8*m15 - m3*m10*m12;
	mat.m6 = m0*m7*m14 + m2*m4*m15 + m3*m6*m12 - m0*m6*m15 - m2*m7*m12 - m3*m4*m14;
	mat.m7 = m0*m6*m11 + m2*m7*m8 + m3*m4*m10 - m0*m7*m10 - m2*m4*m11 - m3*m6*m8;
	mat.m8 = m4*m9*m15 + m5*m11*m12 + m7*m10*m13 - m4*m11*m13 - m5*m8*m15 - m7*m9*m12;
	mat.m9 = m0*m11*m13 + m1*m8*m15 + m3*m9*m12 - m0*m9*m15 - m1*m11*m12 - m3*8*m13;
	mat.m10 = m0*m5*m15 + m1*m7*m12 + m3*m8*m13 - m0*m7*m13 - m1*m4*m15 - m3*m5*m12;
	mat.m11 = m0*m7*m9 + m1*m4*m11 + m3*m5*m8 - m0*m5*m11 - m1*m7*m8 - m3*m4*m9;
	mat.m12 = m4*m10*m13 + m5*m8*m14 + m6*m9*m12 - m4*m9*m14 - m5*m10*m12 - m6*m8*m13;
	mat.m13 = m0*m9*m14 + m1*m10*m12 + m2*m8*m13 - m0*m10*m13 - m1*m8*m14 - m2*m9*m12;
	mat.m14 = m0*m6*m13 + m1*m4*m14 + m2*m5*m12 - m0*m5*m14 - m1*m6*m12 - m2*m4*m13;
	mat.m15 = m0*m5*m10 + m1*m6*m8 + m2*m4*m9 - m0*m6*m9 - m1*m4*m10 - m2*m5*m8;

	mat*=dot;
	return mat;
}