#pragma once
#include "data/geometry.h"

class plume_input
{
public:
	vec3 stack_origin;
	vec3 stack_direction;
	double stack_diameter;
	double stack_velocity;
	vec3 wind_direction;
	double wind_speed;
public:
	double airTemp;
public:
	int layer_height;
	int layer_radius;
	int layer_depth;
};

// @todo plume_gas 클래스를 임의 개수의 물성치, 임의 명칭의 물성치를 받도록 수정할 것
class plume_gas
{
public:
	plume_gas()
	{
		temperature = 0.0;
		co2 = 0.0;
		co = 0.0;
		h2o = 0.0;
	}
	plume_gas operator+(const plume_gas &temp) const {
		plume_gas result;
		result.temperature = temperature + temp.temperature;
		result.co2 = co2 + temp.co2;
		result.co = co + temp.co;
		result.h2o = h2o + temp.h2o;
		return result;
	}
	plume_gas operator*(double value){
		plume_gas result;
		result.temperature = temperature* value;
		result.co2 = co2* value;
		result.co = co* value;
		result.h2o = h2o*value;
		return result;
	}
public:
	double temperature;
	double co2;//atm
	double co;
	double h2o;
};