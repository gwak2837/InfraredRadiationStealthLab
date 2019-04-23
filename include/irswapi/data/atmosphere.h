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
		int aslm;///������� ����
		int cldm;///���� ����
		double clda;///���� ��
		double cldt;///���� �β�
		double rnrt;///������
		double wnds;///ǳ��
		double wndd;///ǳ��
		double visb;///���ðŸ�
		double gnde;// ���� �����
		double gndt;// ���� �µ�
		double airt;// ��� �µ�
		double humd;///������
		double prss;///����
		double wave;///����
	};

	

	class atmcondition
	{
	public:
		class timeatm
		{
			public:
			class UserDefinedModel									///������� ����ü
			{
			public:
				double	air_alt;										///��
				double	air_prss;										///����
				double	air_temp;										///���µ�
				double	air_humd;										///������
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

		double windSpeed;///ǳ��
		double windDirection;///ǳ��
		double airTemp;///�µ�
		double humidity;///������
		double pressure;///����
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