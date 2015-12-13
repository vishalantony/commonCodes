#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include <iostream>

using namespace std;

template<typename T>
void SWAP(T * a, T * b) {
	T x = *a;
	*a = *b;
	*b = x;
}

template<typename T>
bool QS_compare(T a, T b) {
	return a <= b;
}

template<typename T>
T * partition(T * a, T * b, bool (*comp)(T a, T b) = QS_compare) {
	T * s = a;
	T * e = b;
	T v = *s;
	while(s < e) {
		while(s <= b && comp(*s, v)) s++;
		while(!comp(*e, v) && e > a) e--;
		if(s < e)
			SWAP(s, e);
	}
	SWAP(a, e);
	return e;
}

// give starting address, ending address and compare function
// if no compare function is given, uses a default compare function.
template<typename T>
void quicksort(T * a, T * b, bool (*comp)(T a, T b) = QS_compare) {
	if(a >= b) return;
	T* m = partition(a, b, comp);
	quicksort(a, m-1, comp);
	quicksort(m+1, b, comp);
}

#endif
