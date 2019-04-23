#pragma once
#include <vector>
using namespace std;

class bc_assigntmp_p
{
public:
	bc_assigntmp_p()
	{
		pid = 0;
		assignedtmp = -1.0;
	}
public:
	int pid;
	double assignedtmp;
};

class temperature
{
public:
	temperature()
	{
		eid = 0;
		temperature_f = -1.0;
		temperature_b = -1.0;
	}
public:
	int eid;
	double temperature_f;
	double temperature_b;
};
class thermal
{
public:
	int vsize;
	int esize;
	int psize;
	vector<bc_assigntmp_p> bc_at_p;
	vector<temperature> tmp;
};
