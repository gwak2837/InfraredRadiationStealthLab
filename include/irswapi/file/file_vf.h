#pragma once
#include "data/viewfactor.h"
#include <stdio.h>
#include <vector>
using namespace std;

//namespace fin
//{
//}

namespace fout
{
	errno_t fopen_vf(FILE* fp, char* dir, char* name);
	void print_vf(FILE* fp, viewfactor& tempvf);
	void print_vfset(FILE* fp, vector<viewfactor>& tempvfset);

	//bool fout_vf(char* dir, char* name, vector<viewfactor>& tempvfset);
	void reset_vf(char* dir, char* name);
	bool fout_vf(char* dir, char* name, vector<viewfactor>& tempvfset, int precision);
}