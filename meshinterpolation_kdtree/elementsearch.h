#pragma once
#include "file/file_cad.h"
#include "math/vec3.h"
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct kd_node_t{
	double x[3];
	struct kd_node_t *left, *right;
	int index;
};

inline double
dist(struct kd_node_t *a, struct kd_node_t *b, int dim)
{
	double t, d = 0;
	while (dim--) {
		t = a->x[dim] - b->x[dim];
		d += t * t;
	}
	return d;
}
inline void swap(struct kd_node_t *x, struct kd_node_t *y) {
	double tmp[3];
	int temp;
	memcpy(tmp,  x->x, sizeof(tmp));
	memcpy(x->x, y->x, sizeof(tmp));
	memcpy(y->x, tmp,  sizeof(tmp));
	temp = x->index;
	x->index = y->index;
	y->index = temp;
}


/* see quickselect method */
struct kd_node_t*
	find_median(struct kd_node_t *start, struct kd_node_t *end, int idx)
{
	if (end <= start) return NULL;
	if (end == start + 1)
		return start;
	struct kd_node_t *p, *store, *md = start + (end - start) / 2;
	double pivot;
	while (1) {
		pivot = md->x[idx];
		swap(md, end - 1);
		for (store = p = start; p < end; p++) {	
			if (p->x[idx] < pivot) {
				if (p != store)	
					swap(p, store);	
				store++;
			}
		}
		swap(store, end - 1);

		/* median has duplicate values */
		if (store->x[idx] == md->x[idx])
			return md;

		if (store > md) end = store;
		else        start = store;
	}
}

struct kd_node_t*
	make_tree(struct kd_node_t *t, int len, int i, int dim)
{
	struct kd_node_t *n;

	if (!len) return 0;

	if ((n = find_median(t, t + len, i))) {
		i = (i + 1) % dim;
		n->left  = make_tree(t, n - t, i, dim);
		n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
	}
	return n;
}


void nearest(struct kd_node_t *root, struct kd_node_t *nd, int i, int dim,
struct kd_node_t **best, double *best_dist)
{
	double d, dx, dx2;

	if (!root) return;
	d = dist(root, nd, dim);
	dx = root->x[i] - nd->x[i];
	dx2 = dx * dx;

	if (!*best || d < *best_dist) {
		*best_dist = d;
		*best = root;
	}

	/* if chance of exact match is high */
	if (!*best_dist) return;

	if (++i >= dim) i = 0;

	nearest(dx >= 0 ? root->left : root->right, nd, i, dim, best, best_dist);
	if (dx2 > *best_dist) return;
	nearest(dx >= 0 ? root->right : root->left, nd, i, dim, best, best_dist);
}

void search_nearElement(vector<element_self>& eself_src, vector<element_self>& eself_trg, vector<int>& result)
{
	// eself_src와 eself_trg 간 centroid 거리 비교
	// 예 : double dist = eself_trg[i].centroid.distance(eself_src[j]);

	// 거리가 최소가 되는 eself_src의 index result에 저장
	// 예 : result[i] = j

	int i;
	struct kd_node_t* node = (struct kd_node_t*) calloc(eself_src.size(), sizeof(struct kd_node_t));
	for(i = 0 ; i < eself_src.size() ; i++){
		node[i].x[0] = eself_src[i].centroid.x;
		node[i].x[1] = eself_src[i].centroid.y;
		node[i].x[2] = eself_src[i].centroid.z;
		node[i].index = eself_src[i].eid;
	}
	
	struct kd_node_t *root, *found;
	double best_dist;
	
	root = make_tree(node, eself_src.size(), 0, 3);	//node(테스트 좌표 정보), len(좌표 수), i(0), dim(3차원)

	for (i = 0 ; i < eself_trg.size() ; i++){
	
		best_dist = DBL_MAX;
		struct kd_node_t testNode = {{eself_trg[i].centroid.x, eself_trg[i].centroid.y, eself_trg[i].centroid.z}};

		found = 0;
		nearest(root, &testNode, 0, 3, &found, &best_dist);

		
		/*printf(">> searching for (%g, %g, %g)\n"
			"found (%g, %g, %g) dist %g\nindex : %d\n\n",
			testNode.x[0], testNode.x[1], testNode.x[2],
			found->x[0], found->x[1], found->x[2], sqrt(best_dist), found->index);*/

		result.push_back(found->index);

	}

	free(node);

};