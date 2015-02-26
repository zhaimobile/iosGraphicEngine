#ifndef ENGINE_MATH_VECT_H
#define ENGINE_MATH_VECT_H

// Includes to handle SIMD register types
//#include <xmmintrin.h>
//#include <smmintrin.h> 

#include "Enum.h"

// forward declare
class Matrix;

class Vect
{
public:

	////constructors
	//default constuctor
	Vect();
	//individual constuctor
	Vect(const float inX, const float inY, const float inZ, const float inW = 1.0f);
	//copy constructor	
	Vect(const Vect &cVect);
	//destructor constuctor
	~Vect();
	//assignment constructor or assignment operator 
	Vect& operator=(const Vect&); 

	//accessors
	const float operator[](x_enum ) const;
	const float operator[](y_enum ) const;
	const float operator[](z_enum ) const;
	const float operator[](w_enum ) const;

	//setor
	float &operator[](const x_enum) {return this->x;}
	float &operator[](const y_enum) {return this->y;}
	float &operator[](const z_enum) {return this->z;}
	float &operator[](const w_enum) {return this->w;}
	
	// set vector
	void set(float x, float y, float z, float w=1.0f); // set Vect
	void set(const Vect &vec); // set Vect using Vect object

	//overload Vect + Vect
	const Vect operator+(const Vect&) const;
	//overload Vect += Vect
	const Vect& operator+=(const Vect&);
	//overload Vect + Vect
	const Vect operator-(const Vect&) const;
	//overload Vect += Vect
	const Vect& operator-=(const Vect&);

	//overload Vect unary
	const Vect operator+() const;	
	const Vect operator-() const;
	//overload Vect scale
	Vect operator*(float s) const;
	Vect& operator*=(float s);

	//isEqual()
	const bool isEqual(const Vect&,const float&) const; 
	const bool isEqual(const Vect& vect) const;
	//isZero()
	const bool isZero(const float& epsilon) const;
	const bool isZero() const;

	//Vect dot product
	const float dot(const Vect& vect)const;
	//Vect cross product
	const Vect cross(const Vect& vect)const;

	//overload operator * define Vector*Matrix
	Vect operator*(const Matrix & mat)const;
	//overload operator *= define Vector*=Matrix
	void operator*=(const Matrix & mat); 

	//founctions
	const Vect& norm();
	const Vect  getNorm() const;
	const float mag() const;
	const float magSqr() const;
	const float getAngle(const Vect& vec) const;

private:

// Level 4 complains nameless struct/union ...
#pragma warning( disable : 4201)
	// anonymous union
	union 
	{
		//__m128	m;

		// anonymous struct
		struct 
			{
			float x;
			float y;
			float z;
			float w;
			};
	};
};

// overload operator * scale by s
const Vect operator*(float s, const Vect& vect);

#endif