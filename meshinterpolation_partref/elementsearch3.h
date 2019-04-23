#pragma once
#include "math/vec3.h"
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

/*inline double
dist3(element_self eself_src, element_self eself_trg)
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


void search_nearElement3(vector<element_self>& eself_src, vector<element_self>& eself_trg, vector<int>& result, vector<part>& src_part, vector<part>& trg_part)
{
	// eself_src와 eself_trg 간 centroid 거리 비교
	// 예 : double dist3 = eself_trg[i].centroid.distance(eself_src[j]);

	// 거리가 최소가 되는 eself_src의 index result에 저장
	// 예 : result[i] = j

	/*if(src_part.size() != trg_part.size()){
		printf("undefined");
		return;
	}*/
	double d;
	double best_dist = 0;
	element_self* best;
	int i = 0, j = 0, k = 0;

	result.resize(eself_trg.size());
	best = &eself_src[src_part[0].eid[0]];
	
	/*best_dist = dist(eself_src[src_part[0].eid[0]], eself_trg[0]);*/
	best_dist = eself_src[src_part[0].eid[0]].centroid.distance(eself_trg[0].centroid);

	for(k = 0 ; k < trg_part.size() ; k++){

		for(i = 0 ; i < trg_part[trg_part[k].pid].eid.size() ; i++){

			best = &eself_src[src_part[trg_part[k].pid].eid[0]];

			best_dist = eself_src[src_part[trg_part[k].pid].eid[0]].centroid.distance(eself_trg[trg_part[trg_part[k].pid].eid[i]].centroid);
			/*best_dist = dist(eself_src[src_part[trg_part[k].pid].eid[0]], eself_trg[trg_part[trg_part[k].pid].eid[i]]);*/

			for(j = 0 ; j < src_part[trg_part[k].pid].eid.size(); j++){

				d = eself_src[src_part[trg_part[k].pid].eid[j]].centroid.distance(eself_trg[trg_part[trg_part[k].pid].eid[i]].centroid);
				//d = dist(eself_src[src_part[trg_part[k].pid].eid[j]], eself_trg[trg_part[trg_part[k].pid].eid[i]]);

				if (d < best_dist){

					best = &eself_src[src_part[trg_part[k].pid].eid[j]];

					best_dist = d;
			
					//printf("trg : %d, src : %d, best dist^2(%f)\n\n", trg_part[trg_part[k].pid].eid[i], src_part[trg_part[k].pid].eid[j], best_dist);
		
				}
			}
		
			/*printf(">> searching for (%g, %g, %g)\n"
		
				"found (%g, %g, %g)\nindex : %d\n\n",
		
				eself_trg[trg_part[trg_part[k].pid].eid[i]].centroid.x, eself_trg[trg_part[trg_part[k].pid].eid[i]].centroid.y, eself_trg[trg_part[trg_part[k].pid].eid[i]].centroid.z,
		
				best->centroid.x, best->centroid.y, best->centroid.z, best->eid);*/

			result[trg_part[trg_part[k].pid].eid[i]] = best->eid;
		}
	
	}
};