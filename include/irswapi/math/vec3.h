#pragma once
#include "math/mathfunction.h"
#include "math/mathdefine.h"
#define COSMAX  1.0
#define COSMIN -1.0
// º¤ÅÍ ±¸Á¶Ã¼
class vec3
{
public:
	vec3()
	{
		clear();
	};
	vec3(double X, double Y, double Z)
	{
		x = X; y = Y; z = Z;
	};
public:
	void clear()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	};
	vec3 operator+(const vec3 &temp) const {// + ¿¬»êÀÚ¿¡ ´ëÇØ x,y,z µ¡¼À
		vec3 result;
		result.x = x + temp.x;
		result.y = y + temp.y;
		result.z = z + temp.z;
		return result;
	}
	vec3 operator-(const vec3 &temp) const {// + ¿¬»êÀÚ¿¡ ´ëÇØ x,y,z »¬¼À
		vec3 result;
		result.x = x - temp.x;
		result.y = y - temp.y;
		result.z = z - temp.z;
		return result;
	}
	vec3 operator*(double value){
		vec3 result;
		result.x = x * value;
		result.y = y * value;
		result.z = z * value;
		return result;
	}
	vec3 operator/(double value){
		vec3 result;
		result.x = x / value;
		result.y = y / value;
		result.z = z / value;
		return result;
	}
public:
	bool isZero(){ return (x == 0) && (y == 0) && (z == 0); }
public:
	// º¤ÅÍ Å©±â// |P|
	double magnitude(){	return sqrt(x*x + y*y + z*z);};
	//// º¤ÅÍ ÇÕ//P + Q
	//vec3 addition(vec3 other){	return this + other; }
	//// º¤ÅÍ Â÷//P to Q
	//vec3 subtraction(vec3 other){	return this - other; }
	// º¤ÅÍ ³»Àû
	double innerProduct(vec3 other){return x*other.x + y*other.y + z*other.z;	}
	// º¤ÅÍ ¿ÜÀû : this x other
	vec3 crossProduct(vec3 other)
	{
		vec3 result;
		result.x = y * other.z - z * other.y;
		result.y = z * other.x - x * other.z;
		result.z = x * other.y - y * other.x;
		return result;
	};
	// º¤ÅÍ Á¤±ÔÈ­
	void Normalize()
	{
		double mag = this->magnitude();
		x = x / mag; y = y / mag; z = z / mag;
	};
	void setOpposite(){
		x = -x;		y = -y;		z = -z;
	};
	vec3 getOpposite(){
		vec3 result(-x, -y, -z);
		return result;
	};
public:
	void getArray(double data[3])
	{
		x = data[0];
		y = data[1];
		z = data[2];
	};
	void substitution(double X,double Y,double Z){ x = X; y = Y; z = Z;};// ´ëÀÔ
public:
	double distance(vec3& temp)
	{
		return sqrt(pow(x - temp.x, 2.0) + pow(y - temp.y, 2.0) + pow(z - temp.z, 2.0));
	};

	bool isequal(vec3& temp)
	{
		return x == temp.x && y == temp.y && z == temp.z;
	};
public:
	double angleDegree(vec3& temp)
	{
		//debug
		double x = this->innerProduct(temp) / this->magnitude() / temp.magnitude();

		if(x < COSMIN)
		{
			if(nealyEqual(x, COSMIN, 1e-15))
			{
				x = COSMIN;
			}
		}
		else if(x>COSMAX)
		{
			if(nealyEqual(x, COSMAX, 1e-15))
			{
				x = COSMAX;
			}
		}
		else{

		}
		//double ac = acos(x);

		return acos( x ) * rad2deg;
	};
public:
	// Rodrigues' rotation formula
	void rotation(vec3 axis, double deg)
	{
		vec3 temp = *this;
		double rad = deg * deg2rad;
		temp = temp * cos(rad) + axis.crossProduct(temp) * sin(rad) + axis * axis.innerProduct(temp) * (1-cos(rad));
		*this = temp;
	};

public:
	double x;
	double y;
	double z;
};

//void CentroidTri(vec3& point1, vec3& point2, vec3& point3, vec3& Centroid);
//void CentroidRect(vec3 point1, vec3 point2, vec3 point3, vec3 point4, vec3 Centroid);

