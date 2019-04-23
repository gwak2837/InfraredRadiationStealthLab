#pragma once

//#include "vec3.h"
#include "math/coord.h"

#define m_to_mm 1000 

enum COORDBASE
{
	COORD_SPHR = 0,
	COORD_RECT = 1
};

enum FOV_TYPE
{
	FOV_INSTANTANEOUS = 0,
	FOV_TOTAL = 1
};

enum FOV_UNIT
{
	FOV_MRAD= 0,
	FOV_DEGREE = 1
};

namespace snsr
{
	class pos_rect
	{
	public:
		vec3 pos;
		vec3 dir;
		vec3 up;
		vec3 right;
	};

	class pos_sphr
	{
	public:
		pos_sphr()
		{
			roll = 0.0;
		}
	public:
		coord_sphr pos;
		double roll;
	};

	class senposition
	{
	public:
		senposition()
		{
			coordbase = COORD_SPHR;
		}
	public:
		int coordbase;
		pos_rect pos_rect;
		pos_sphr pos_sphr;
	};

	class senresolution
	{
	public:
		senresolution()
		{
			pixel_h = 0;
			pixel_v = 0;
			fovunit = FOV_DEGREE;
			fov_h = 0.0;
			fov_v = 0.0;
			ifov_h = 0.0;
			ifov_v = 0.0;
		}
	public:
		int pixel_h;
		int pixel_v;

		int fovunit;

		double fov_h;
		double fov_v;
		double ifov_h;
		double ifov_v;
	};

	class sensordat
	{
	public:
		senposition pos;
		senresolution res;
	};
}