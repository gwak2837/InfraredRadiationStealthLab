#pragma once
#include "data/geometry.h"
#include "data/material.h"

namespace fin
{
	bool fin_ems(char* path, vector<double>& data);
}

namespace fout
{
bool fout_ems(/*char* dir, geometry& data*/);

}
