#pragma once
#include "data/geometry.h"
#include "data/plume.h"

namespace fin
{

	bool fin_out_patran(char* path, geometry& data);
	bool fin_restmpl_patran(char* path, vector<plume_gas>& data);
	int fin_rst_patran(char* path, vector<plume_gas>& data);
};
namespace fout
{

};
