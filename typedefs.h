#ifndef __TYPEDEFS_H__
#define __TYPEDEFS_H__

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cstdio>

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, std::string> pistr;
typedef std::pair<std::string, int> pstri;


#define DEF_VEC(T) typedef std::vector<T> v ## T

DEF_VEC(int);	// vint
DEF_VEC(ull);	// vull
DEF_VEC(ll);	// vll
DEF_VEC(double);	//vdouble
DEF_VEC(float);		//vfloat
DEF_VEC(bool);	// vbool
DEF_VEC(pii);	// vpii
DEF_VEC(pistr);	//vpistr
DEF_VEC(pstri); // vpstri
DEF_VEC(vint);	// vvint

#endif
