#pragma once
#include "data/material.h"

namespace fin
{
bool fin_dat_material(char* path, vector<material_thermal>& data);
bool fin_dat_paint(char* path, vector<material_paint>& data);

bool fin_asm(char* path, material_set& data);
}

namespace fout
{
bool fout_asm(char* dir, material_set& data);
}