#pragma once
#include <assert.h>
#include "math/mathdefine.h"

const double normalangle = 90.0;

	enum facetype
	{
		FRONTWARD = true,
		BACKWARD = false
	};

class viewfactor
{	
public:
	viewfactor(){
		eid_1 = -1;
		eid_2 = -1;
		ftype_1 = true;
		ftype_2 = true;
		F_12 = 0.0;
		F_21 = 0.0;
	}

	viewfactor(int e1, int e2)
	{
		eid_1 = e1;
		eid_2 = e2;
		ftype_1 = true;
		ftype_2 = true;
		F_12 = 0.0;
		F_21 = 0.0;
	}

	void set(int e1, int e2, bool f1, bool f2, double vf12, double vf21)
	{
		eid_1 = e1;
		eid_2 = e2;
		ftype_1 = f1;
		ftype_2 = f2;
		F_12 = vf12;
		F_21 = vf21;
	};



	bool setFaceType_e1(double centerline_angle)
	{
		if(centerline_angle < normalangle ){
			ftype_1 = FRONTWARD;
			return true;
		}
		else if(centerline_angle > normalangle ){
			ftype_1 = BACKWARD;
			return true;
		}
		else{
			assert(centerline_angle == normalangle && "viewfactor:: error! from setting face type with normal angle");
			return false;
		}
	};
	bool setFaceType_e2(double centerline_angle)
	{
		if(centerline_angle < normalangle ){
			ftype_2 = FRONTWARD;
			return true;
		}
		else if(centerline_angle > normalangle ){
			ftype_2 = BACKWARD;
			return true;
		}
		else{
			assert(centerline_angle == normalangle && "viewfactor:: error! set face type with normal angle");
			return false;
		}
	};


public:
	int eid_1;
	int eid_2;
	bool ftype_1;//격자 i의 앞면에 대한 값인지
	bool ftype_2;//격자 j의 앞면에 대한 값인지
	double F_12;	//격자 i를 떠난 복사에너지가 격자 j에 도달하는 분율
	double F_21;	//격자 i를 떠난 복사에너지가 격자 j에 도달하는 분율
};
//
//class viewfactor_bkg
//{
//	viewfactor_bkg()
//	{
//		i_f(-1,-1)
//	}
//	public:
//	viewfactor i_f;
//	viewfactor i_b;
//};

class vf_cmode
{
public:
	vf_cmode(){
		subdivision_criterion = FLT_MAX;
		distance_limit = FLT_MAX;
		solidangle_limit = 0.0;
		precision = 16;
	}
	// 격자 세분화 시 기준 입체각[sr]
	// <= 0.0 : 세분화 적용하지 않음
	// > 0.0 : 세분화 적용함
	double subdivision_criterion;

	// 격자 간 계산 제한 거리
	// <= 0.0 : 격자 간 계산 제한 적용하지 않음
	// > 0.0 : 격자 간 계산 제한 적용함
	double distance_limit;

	// 격자 간 계산 제한 입체각
	double solidangle_limit;

	int precision;
};