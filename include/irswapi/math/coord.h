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

// ������ǥ�� ���Ϳ��� ������ǥ�� ����ü�� ��ǥ ��ȯ
void ChangeRectToSphr2(vec3& rect, coord_sphr& sphr);

// ������ǥ�� ����ü���� ������ǥ�� ���ͷ� ��ǥ ��ȯ
void ChangeSphrToRect2(coord_sphr& sphr, vec3& rect);