#pragma once

#include <vector>
#include "math/coord.h"
#include "data/timelist.h"
using namespace std;

#define solarpos coord_sphr

namespace atm
{
	class timeset
	{
	public:
		timeset()
		{
			start = settm(0,0,0,0,0,0);
			end = settm(0,0,0,0,0,0);
			step = settm(0,0,0,0,0,0);
		}
	public:
		bool set(tm st, tm et, tm dt)
		{
			start = st;
			end = et;
			step = dt;
			return updatelist();
		};

		bool updatelist()
		{
			return settimelist(start, end, step, timelist);
		};
	public:
		tm start;
		tm end;
		tm step;
		vector<tm> timelist;
	};

	class geoposition
	{
	public:
		geoposition()
		{
			latitude = 0.0;
			longitude = 0.0;
			altitude = 0.0;
		};
	public:
		double latitude;
		double longitude;
		double altitude;
	};

	class atmparam
	{
	public:
		atmparam()
		{
			atmm = 0;
			aslm = 0;
			cldm = 0;
			clda = 0.0;
			cldt = 0.0;
			rnrt = 0.0;
			wnds = 0.0;
			wndd = 0.0;
			visb = 0.0;
			gnde = 0.0;
			gndt = 0.0;
			airt = 0.0;
			humd = 0.0;
			prss = 0.0;
			wave = 0.0;
		}
	public:
		int atmm;
		int aslm;///에어로졸 모형
		int cldm;///구름 모형
		double clda;///구름 고도
		double cldt;///구름 두께
		double rnrt;///강수량
		double wnds;///풍속
		double wndd;///풍향
		double visb;///가시거리
		double gnde;// 지면 방사율
		double gndt;// 지면 온도
		double airt;// 대기 온도
		double humd;///상대습도
		double prss;///대기압
		double wave;///파장
	};

	

	class atmcondition
	{
	public:
		class timeatm
		{
			public:
			class UserDefinedModel									///기상정보 구조체
			{
			public:
				double	air_alt;										///고도
				double	air_prss;										///대기압
				double	air_temp;										///대기온도
				double	air_humd;										///상대습도
			};
			int tzone;
			tm tdata;
			geoposition pdata;
			atmparam mdata;
			vector<UserDefinedModel> adata;
		};
		
	public:
		vector<timeatm> tlist;
	};

	class weather
	{
	public:
		weather()
		{
		};
	public:
		tm time;
		solarpos solar_pos;

		double rad_solar_dir;
		double rad_solar_dff;
		double rad_sky_dff;
		double rad_land_dff;

		double windSpeed;///풍속
		double windDirection;///풍향
		double airTemp;///온도
		double humidity;///상대습도
		double pressure;///대기압
	};

	class spectral_data
	{
	public:
		spectral_data()
		{
		}
	public:
		double wavelength;
		double rad_solar_dir;
		double rad_solar_dff;
		double rad_sky_dff;
		double rad_land_dff;
		double rad_path;
		double transmittance;
	};

	class atm_thermal
	{
	public:
		class timeatm
		{
			public:
			tm tdata;
			geoposition pdata;
			weather wdata;
		};
	public:
		vector<timeatm> tlist;
	};

	class atm_infrared
	{
	public:
		class timeatm
		{
			public:
			tm tdata;
			geoposition pdata;
			spectral_data wdata;
		};
	public:
		vector<timeatm> tlist;
	};
}