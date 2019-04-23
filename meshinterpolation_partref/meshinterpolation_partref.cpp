// meshinterpolation_partref.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "file/file_cad.h"
#include "elementsearch3.h"

int _tmain(int argc, _TCHAR* argv[])
{
	geometry src;
	geometry dst;
	
	fin::fin_geo("../src/f16_1part_scaled.geo", src);
	fin::fin_geo("../src/f16_wingFraction.geo", dst);

	vector<int> result;

	search_nearElement3(src.eself_vec, dst.eself_vec, result, src.part_vec, dst.part_vec);
	int trg_num = dst.eself_vec.size();
	for(int i = 0; i < trg_num ; i++){
		printf("%dth index : %d\n", i + 1, result[i]);
	}
	
	return 0;
}

