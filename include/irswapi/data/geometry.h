#pragma once

#include <vector>
#include "math/mathfunction.h"
#include <stdarg.h>

using namespace std;

#define OPENMP_ELEMENT

	enum shape
	{
		TRIANGLE = 3,
		RECTANGLE = 4
	};

class vertex
{
public:
	vertex()
	{
		vid = 0;
	};
public:
	int vid; // vertex ID
	vec3 coord; // xyz 좌표
};

class element
{
public:
	element()
	{
		eid = 0;
		pid = 0;
		shape = 0;
	};
	bool setShape(int s)
	{
		bool result = false;
		if(s == TRIANGLE || s == RECTANGLE)
		{
			this->shape = s;
			this->vid.resize(s);
			result = true;
		}
		return result;
	};
public:
	int eid; // element ID
	int pid; // part ID
	int shape; // shape index(3-triangle, 4-rectangle)
	vector<int> vid; // 구성 vertex ID
};

class part
{
public:
	part(){
		pid = 0;
		for(int i=0; i<255; i++){ name[i] = 0; }
	}
public:
	int pid; // part ID
	char name[255]; // part name
	vector<int> eid; // part에 소속된 element ID
};

class element_self
{
public:
	element_self()
	{
		eid = 0;
		surface_area = 0.0;
	};
public:
	int eid; // element ID
	double surface_area; // 표면적
	vec3 centroid; // 중심좌표
	vec3 normal; // 수직벡터
};

class adjacent
{
public:
	adjacent()
	{
		adj_eid = -1;//adjacent element 없는 상태로 초기화
		L1 = 0.0;
		L2 = 0.0;
		side_area = 0.0;
		isEdge = false;

		sidev.first = -1;
		sidev.second = -1;
	};
public:
	int adj_eid; // 인접 격자 번호
	double L1; // eid 격자에 가까운 인접거리(Li)
	double L2; // adj_eid 격자에 가까운 인접거리(Lj)
	double side_area; // 인접 면적
	bool isEdge; // 모서리 여부(true-평면, false-모서리)
	// 모서리인 경우, 두 격자가 한 평면에 위치하지 않음

	pair<int, int> sidev; // 인접 모서리를 구성하는 vertex
};

class element_adj
{
public:
	element_adj()
	{
		eid = 0;
	};
public:
	int eid; // element ID
	vector<adjacent> adj; // 인접 격자 별 정보
};

class geometry
{
public:
	void clear()
	{
		vertex_vec.clear();
		element_vec.clear();
		part_vec.clear();
		eself_vec.clear();
		eadj_vec.clear();
	};

	void resize_vertex(int size)
	{
		vertex_vec.resize(size);
	};
	void resize_element(int size)
	{
		element_vec.resize(size);
		eself_vec.resize(size);
		eadj_vec.resize(size);
	};
	void resize_part(int size)
	{
		part_vec.resize(size);
	};

public:
	char name[255];//파일 이름
public:
	vector<vertex> vertex_vec;
	vector<element> element_vec;
	vector<part> part_vec;
public:
	vector<element_self> eself_vec;
	vector<element_adj> eadj_vec;
};


double ElementTriArea(double a, double b, double c);

void CentroidTri(vec3& point1, vec3& point2, vec3& point3, vec3& Centroid);
void CentroidRect(vec3& point1, vec3& point2, vec3& point3, vec3& point4, vec3& Centroid);

void calc_normal(vec3& normal, vec3& v1, vec3& v2, vec3& v3);

double calc_area_tri(double a, double b, double c);
double calc_area_tri(vec3& v1, vec3& v2, vec3& v3);
double calc_area_rect(vec3& v1, vec3& v2, vec3& v3, vec3& v4);

bool calc_element_self(geometry& data);

//vec3 averagePoint(int psize, ...)
//{
//	vec3 result;
//	va_list ap;
//	va_start(ap, psize);
//	for(int i=0; i<psize; i++)
//	{
//		vec3 pt = va_arg(ap, vec3);
//		result = result+pt;
//	}
//	va_end(ap);
//	result = result/psize;
//	return result;
//};

vec3 averagePoint(vector<vec3>& vset);
vec3 averagePoint(vector<vertex>& vset);
vec3 averagePoint(vector<vertex>& vset, vector<int>& vid);

void addElement(geometry& data, vector<vec3>& vset);