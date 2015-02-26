#include "MathEngine.hpp"
#include <math.h>

Vect::Vect()
	: x(0.0f), y(0.0f), z(0.0f),w(1.0f)
{
}

Vect::Vect(const float inX, const float inY, const float inZ, const float inW)
: x(inX), y(inY), z(inZ), w(inW)
{
}
	
Vect::Vect(const Vect &vect)
{
	this->x = vect.x;
	this->y = vect.y;
    this->z = vect.z;
	this->w = vect.w;
}

Vect::~Vect()
{
	//delete this;
}

// assignment operator
Vect &Vect::operator=(const Vect &vect)
{
    this->x = vect.x;
	this->y = vect.y;
    this->z = vect.z;
	this->w = vect.w;
		
	return *this;
}

const float Vect::operator[](x_enum ) const
{
	return ( this->x );
}
const float Vect::operator[](y_enum ) const
{
	return ( this->y );
}
const float Vect::operator[](z_enum ) const
{
	return ( this->z );
}
const float Vect::operator[](w_enum ) const
{
	return ( this->w );
}

void Vect::set(float x1, float y1, float z1, float w1)
{
	this->x = x1;
	this->y = y1;
	this->z = z1;
	this->w = w1;
}

void Vect::set(const Vect& vec)
{
   this->x = vec.x;
   this->y = vec.y;
   this->z = vec.z;
   this->w = vec.w;
}

const Vect Vect::operator+(const Vect& vect) const
{

	float x=this->x + vect.x;
	float y=this->y + vect.y;
	float z=this->z + vect.z;

	return Vect(x,y,z);
}

const Vect& Vect::operator+=(const Vect& vect)
{
	this->x += vect.x;
	this->y += vect.y;
	this->z += vect.z;
	this->w=1.0f;

	return *this;
}

const Vect Vect::operator-(const Vect& vect) const
{
	float x=this->x - vect.x;
	float y=this->y - vect.y;
	float z=this->z - vect.z;

	return Vect(x,y,z);
}

const Vect& Vect::operator-=(const Vect& vect)
{
	this->x -= vect.x;
	this->y -= vect.y;
	this->z -= vect.z;
	this->w=1.0f;

	return *this;
}


	//overload unary
const Vect Vect::operator+() const
{
	return Vect(this->x,this->y,this->z);
}
const Vect Vect:: operator-() const
{
	return Vect(-this->x,-this->y,-this->z);
}

// overload operator *=. scale by s
Vect& Vect::operator*=(float s)
{
	this->x *= s;
	this->y *= s;
	this->z *= s;
	this->w = 1.0f;
	
	return *this;
}

// overload operator *. scale by s
Vect Vect::operator*(float s) const
{
	Vect res;
	res.x = this->x * s;
	res.y = this->y * s;
	res.z = this->z * s;
	res.w = 1.0f;

	return res;
}
// s by vect
const Vect operator*(float s,const Vect& vect)
{
	Vect res =Vect(vect[x] * s,vect[y] *s, vect[z] *s);
	return res;
}

//todo  do I need to compare the w?
const bool Vect::isEqual(const Vect& vect,const float& epsilon) const
{
	return  Util::isEqual(this->x,vect.x,epsilon)&&
			Util::isEqual(this->y,vect.y,epsilon)&&
			Util::isEqual(this->z,vect.z,epsilon)&&
			Util::isEqual(this->w,vect.w,epsilon);
}

const bool Vect::isZero(const float& epsilon) const
{
	return  Util::isZero(this->x,epsilon)&&
			Util::isZero(this->y,epsilon)&&
			Util::isZero(this->z,epsilon);
}

const bool Vect::isEqual(const Vect& vect) const
{
	return  Util::isEqual(this->x,vect.x,0)&&
			Util::isEqual(this->y,vect.y,0)&&
			Util::isEqual(this->z,vect.z,0)&&
			Util::isEqual(this->w,vect.w,0);
}

const bool Vect::isZero() const
{
	return this->x == 0.0f && this->y == 0.0f && this->z == 0.0f && this->w == 0.0f;
}

const float Vect::dot(const Vect& vect)const
{
	return (this->x * vect.x +
			this->y * vect.y +
			this->z * vect.z);
}

const Vect Vect::cross(const Vect& vec) const
{
	Vect res;
	res.x = this->y*vec.z - this->z*vec.y;
	res.y = this->z*vec.x - this->x*vec.z;
	res.z = this->x*vec.y - this->y*vec.x;
	res.w = 1.0f;

	return res;
}

// overload operator * define Vector*Matrix
Vect Vect::operator*(const Matrix &mat) const
{
   Vect vec;

   vec.set(this->x*mat[m0] + this->y*mat[m4] + this->z*mat[m8]  + this->w*mat[m12],
		   this->x*mat[m1] + this->y*mat[m5] + this->z*mat[m9]  + this->w*mat[m13],
		   this->x*mat[m2] + this->y*mat[m6] + this->z*mat[m10] + this->w*mat[m14],
		   this->x*mat[m3] + this->y*mat[m7] + this->z*mat[m11] + this->w*mat[m15]);
  
   return vec;
}

// overload operator *= define Vector*=Matrix
void Vect::operator*=(const Matrix &mat)
{
   this->set(this->x*mat[m0] + this->y*mat[m4] + this->z*mat[m8]  + this->w*mat[m12],
			 this->x*mat[m1] + this->y*mat[m5] + this->z*mat[m9]  + this->w*mat[m13],
			 this->x*mat[m2] + this->y*mat[m6] + this->z*mat[m10] + this->w*mat[m14],
			 this->x*mat[m3] + this->y*mat[m7] + this->z*mat[m11] + this->w*mat[m15]);
}

// normalization output write over the original
const Vect& Vect::norm()
{
	float s = this->mag();
	this->x /= s;
	this->y /= s;
	this->z /= s;
	this->w = 1.0f;

	return *this;
}

const Vect Vect::getNorm() const
{
	Vect vect;
	float s = this->mag();
	vect.x = this-> x / s;
	vect.y = this-> y / s;
	vect.z = this-> z / s;
	vect.w = 1.0f;

	return vect;
}

const float Vect::mag() const
{
	return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
}

const float Vect::magSqr() const
{
	return (this->x*this->x + this->y*this->y + this->z*this->z);
}

const float Vect::getAngle(const Vect& vec) const
{
	float n = this->mag() * vec.mag();
	float n1 = this->x*vec.x;
	float n2 = this->y*vec.y;
	float n3 = this->z*vec.z;
	return acos((n1+n2+n3) / n);
}