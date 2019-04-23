#pragma once
#include "float.h"
#define _USE_MATH_DEFINES // for C
#include "math.h"
#include <assert.h>

const double deg2rad = M_PI / 180.0;
const double rad2deg = 180.0 / M_PI;

template <typename T>
T clamp(T x, T low, T high);

double wrap(double x, double low, double high);

bool nealyEqual(double a, double b, double epsilon);