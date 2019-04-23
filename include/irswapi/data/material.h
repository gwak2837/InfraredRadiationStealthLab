#pragma once

#include <vector>
#include <algorithm>
#include "math/mathfunction.h"
#include <stdarg.h>

using namespace std;

class material_thermal
{
public:
	material_thermal()
	{
		mid = 0;
		density = 0.0;
		conductivity = 0.0;
		specificheat = 0.0;
		for(int i=0; i<255; i++){ name[i] = 0; }
	};

public:
	char name[255];
	int mid;
	double density;
	double conductivity;
	double specificheat;
};

class material_paint
{
public:
	class wpaint
	{
	public:
		wpaint()
		{
			wavelength = 0.0;
			rfl_diff = 0.0;
			ems_diff = 0.0;
		};
	public:
		double wavelength;
		double rfl_diff;
		double ems_diff;
	};

public:
	material_paint()
	{
		for(int i=0; i<255; i++){ name[i] = 0; }
		mid = 0;
		brdf_Fresnel = 0.0;
		brdf_Lobe = 0.0;
		abs_solar = 0.0;
		ems_thermal = 0.0;
		thermalConductance = 0.0;
		wcount = 0;
	};

	void setpcount(int w)
	{
		wcount = w;
		wp_vec.clear();
		wp_vec.resize(wcount);
	};

public:
	char name[255];
	int mid;
	double brdf_Fresnel;
	double brdf_Lobe;
	double abs_solar;
	double ems_thermal;
	double thermalConductance;
	int wcount;
	vector<wpaint> wp_vec;
	double wmin;
	double wmax;
};


class partmat
{
public:
	partmat(){
		pid = 0;
		for(int i=0; i<255; i++){ name[i] = 0; }
		mid_thm = 0;
		mid_pnt = 0;
		thickness = 0.0;
	}
public:
	int pid; // part ID
	char name[255]; // part name
	int mid_thm;
	int mid_pnt;
	double thickness;
};


//class material_db
//{
//public:
//	void clear()
//	{
//		mthm_vec.clear();
//		mpnt_vec.clear();
//	};
//public:
//	vector<material_thermal> mthm_vec;
//	vector<material_paint> mpnt_vec;
//};

class material_set
{
public:
	void clear()
	{
		pmat_vec.clear();
		mthm_vec.clear();
		mpnt_vec.clear();
	};

	bool set_part_material(int pid, int mid_material)
	{
		if((unsigned int)pid < pmat_vec.size() && (unsigned int)mid_material < mthm_vec.size())
		{
			pmat_vec[pid].mid_thm = mid_material;
			return true;
		}
		else
		{
			return false;
		}
	};

	bool set_part_paint(int pid, int mid_paint)
	{
		if((unsigned int)pid < pmat_vec.size() && (unsigned int)mid_paint < mpnt_vec.size())
		{
			pmat_vec[pid].mid_pnt = mid_paint;
			return true;
		}
		else
		{
			return false;
		}
	};
	bool set_part_thickness(int pid, double thickness)
	{
		if((unsigned int)pid < pmat_vec.size() && thickness > 0.0)
		{
			pmat_vec[pid].thickness = thickness;
			return true;
		}
		else
		{
			return false;
		}
	};
	

	void duplicate_part(material_set& in)
	{
		strcpy_s(this->name, in.name);
		this->pmat_vec = in.pmat_vec;
	};

	void extract(material_set& in)
	{
		strcpy_s(this->name, in.name);
		this->pmat_vec = in.pmat_vec;

		int psize = in.pmat_vec.size();

		vector<pair<int, int>> mtid_match;
		vector<pair<int, int>> mpid_match;
		int mtcount = 0;
		int mpcount = 0;
		for(int i=0; i<psize; i++)
		{
			int pos = isFirstExist(mtid_match, pmat_vec[i].mid_thm);
			if(pos == -1)
			{
				mthm_vec.push_back( in.mthm_vec[pmat_vec[i].mid_thm] );
				mthm_vec[mtcount].mid = mtcount;

				pair<int, int> temp(pmat_vec[i].mid_thm, mtcount); 
				mtid_match.push_back(temp);

				pmat_vec[i].mid_thm = mtcount;

				mtcount++;
			}
			else
			{
				pmat_vec[i].mid_thm = mtid_match[pos].second;
			}

			pos = isFirstExist(mpid_match, pmat_vec[i].mid_pnt);
			if(pos == -1)
			{
				mpnt_vec.push_back( in.mpnt_vec[pmat_vec[i].mid_pnt] );
				mpnt_vec[mpcount].mid = mpcount;

				pair<int, int> temp(pmat_vec[i].mid_pnt, mpcount); 
				mpid_match.push_back(temp);
				
				pmat_vec[i].mid_pnt = mpcount;

				mpcount++;
			}
			else
			{
				pmat_vec[i].mid_pnt = mpid_match[pos].second;
			}
		}
	};

	int isFirstExist(vector<pair<int, int>>& data, int key)
	{
		int result = -1;
		int size = data.size();

		for(int i=0; i<size; i++)
		{
			if(data[i].first == key)
			{
				result = i;
				break;
			}
		}

		return result;
	};

public:
	char name[255];//파일 이름
public:
	vector<partmat> pmat_vec;
	vector<material_thermal> mthm_vec;
	vector<material_paint> mpnt_vec;
};

//void arrangePartIndex(material_set& partindex,	material_set& partresult);