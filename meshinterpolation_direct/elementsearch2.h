#pragma once
#include "math/vec3.h"
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

/*inline double
dist2(element_self eself_src, element_self eself_trg)
{
	double t, d = 0;
	t = eself_src.centroid.x - eself_trg.centroid.x;
	d += (t * t);
	t = eself_src.centroid.y - eself_trg.centroid.y;
	d += (t * t);
	t = eself_src.centroid.z - eself_trg.centroid.z;
	d += (t * t);
	return d;
}*/


void search_nearElement2(vector<element_self>& eself_src, vector<element_self>& eself_trg, vector<int>& result)
{
	// eself_src와 eself_trg 간 centroid 거리 비교
	// 예 : double dist2 = eself_trg[i].centroid.distance(eself_src[j]);

	// 거리가 최소가 되는 eself_src의 index result에 저장
	// 예 : result[i] = j

	double d;
	double best_dist = 0;
	element_self* best;
	
	for(int i = 0 ; i < eself_trg.size() ; i++){
		best = &eself_src[0];

		// @comment 거리 비교 시 아래 구문으로 교체 바람
		best_dist = eself_src[0].centroid.distance(eself_trg[i].centroid);

		//best_dist = dist2(eself_src[0], eself_trg[i]);
		for(int j = 1 ; j < eself_src.size(); j++){
			d = eself_src[j].centroid.distance(eself_trg[i].centroid);
			//d = dist2(eself_src[j], eself_trg[i]);
			if (d < best_dist){
				*best = eself_src[j];
				best_dist = d;
			}
		}
		/*
		printf(">> searching for (%g, %g, %g)\n"
			"found (%g, %g, %g)\nindex : %d\n\n",
			eself_trg[i].centroid.x, eself_trg[i].centroid.y, eself_trg[i].centroid.z,
			best->centroid.x, best->centroid.y, best->centroid.z, best->eid);*/

		result.push_back(best->eid);
	}
};