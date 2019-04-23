#pragma once
#include "math/mathdefine.h"
#include "data/sensor.h"
#include <vector>
using namespace std;

enum PIXELELEMENT
{
	EID_SKY = -2,
	EID_GND = -1
};

enum PIXELPART
{
	PID_BKG = -1
};


namespace img
{
	class image
	{
	public:
		class pixelrad
		{
		public:
			pixelrad()
			{
				ph = 0;
				pv = 0;
				eid = EID_GND;
				pid = PID_BKG;
				rad = 0.0;
				ems = 0.0;
				rfl = 0.0;
				path = 0.0;
				trns = 0.0;
			}
		public:
			void set(int ph, int pv, int eid, int pid, double rad, double ems, double rfl, double path, double trns)
			{
				this->ph = ph;
				this->pv = pv;
				this->eid = eid;
				this->pid = pid;
				this->rad = rad;
				this->ems = ems;
				this->rfl = rfl;
				this->path = path;
				this->trns = trns;
			};
		public:
			int ph;
			int pv;
			int eid;
			int pid;
			double rad;
			double ems;
			double rfl;
			double path;
			double trns;
		};
		class radscale
		{
		public:
			double minRad;
			double maxRad;
		public:
			radscale() : minRad(FLT_MAX), maxRad(FLT_MIN) {}
			radscale(double min, double max) : minRad(min), maxRad(max){}
			radscale(const double& _min, const double& _max) : minRad(_min), maxRad(_max){}
		public:
			void update(double x)
			{
				minRad = min(minRad, x);
				maxRad = max(maxRad, x);
			};
		public:
			unsigned char convertRadToRGB(double rad){ return (unsigned char)((rad - minRad) / (maxRad - minRad) * 255); }
			double convertRGBToRad(unsigned char byte){ return (double)(minRad + (maxRad-minRad) * byte / 255); }
		};
	public:
		void resizepixel()
		{
			pixel.clear();
			vector<pixelrad> temph(hsize);
			pixel.resize(vsize, temph);
			for(int i=0; i<vsize; i++)
			{
				for(int j=0; j<hsize; j++)
				{
					pixel[i][j].pv = i;
					pixel[i][j].ph = j;
				}
			}
		};

		void initialize(unsigned int ph,unsigned int pv)
		{
			hsize = ph;
			vsize = pv;
			psize = ph*pv;
			resizepixel();			
		};
		void initialize()
		{
			hsize = sensor.res.pixel_h;
			vsize = sensor.res.pixel_v;
			psize = hsize * vsize;
			resizepixel();
		};
		
		//unsigned int getPixelNumber(unsigned int pxid_h,unsigned int pxid_v)
		//{
		//	return 
		//};
	public:
		unsigned int hsize;
		unsigned int vsize;
		unsigned int psize;
		snsr::sensordat sensor;
		vector<vector<pixelrad>> pixel;//[vertical][horizon]
		radscale scale;
	};
}