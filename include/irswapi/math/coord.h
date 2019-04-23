#pragma once
#include "math/vec3.h"


class coord_sphr
{
public:
	coord_sphr()
	{
		range = 0.0;
		azimuth = 0.0;
		zenith = 0.0;
	}
public:
	double range;
	double azimuth;
	double zenith;
};

// 직교좌표계 벡터에서 구면좌표계 구조체로 좌표 변환
void ChangeRectToSphr2(vec3& rect, coord_sphr& sphr);

// 구면좌표계 구조체에서 직교좌표계 벡터로 좌표 변환
void ChangeSphrToRect2(coord_sphr& sphr, vec3& rect);