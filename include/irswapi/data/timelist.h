#pragma once
#include <time.h>
#include <vector>

using namespace std;
tm settm(int s, int m, int h, int dd, int dm, int dy);
bool settimelist(tm start, tm end, tm period, vector<tm>& list);

