#pragma once
#include "data/geometry.h"

namespace fin
{
	bool fin_geo(char* path, geometry& data);

	bool fin_obj_wavefront(char* path, geometry& data);
	bool fin_nas_ansa(char* path, geometry& data);
};
namespace fout
{
	bool fout_geo(char* dir, geometry& data);
	bool fout_nas(char* dir, geometry& data);
	bool fout_obj(char* dir, geometry& data);
};
