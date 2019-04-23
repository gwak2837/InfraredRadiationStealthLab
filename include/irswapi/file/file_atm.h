#pragma once
#include "data/atmosphere.h"

namespace fin
{
bool fin_atm_model(char* path, atm::atmcondition& data);
bool fin_atm_thermal(char* path, atm::atm_thermal& data);
bool fin_atm_infrared(char* path, atm::atm_infrared& data);

bool fread_atm(char* path, atm::atmcondition& data);
bool fread_atm_kai(char* path, atm::atmcondition& data);
}

namespace fout
{
	bool fout_atm_thermal(char* path, atm::atm_thermal& data);
	bool fout_atm_infrared(char* path, atm::atm_infrared& data);

	bool fwrite_atm(char* dir, atm::atmcondition& cdata, atm::atm_thermal& rdata);
}
