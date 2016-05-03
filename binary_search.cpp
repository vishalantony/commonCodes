#include "typedefs.h"
#include "quicksort.h"

using namespace std;

// sample program to find upper and lower limit using binary search algorithm

int upper_bound(vint & num, int start, int end, int find) {
	if(start > end) return start;
	int mid = (start+end)>>1;
	if(num[mid] <= find) return upper_bound(num, mid+1, end, find);
	return upper_bound(num, start, mid-1, find);
}

int lower_bound(vint & num, int start, int end, int find) {
	if(start > end) return start;
	int mid = (start + end) >> 1;
	if(num[mid] < find) return lower_bound(num, mid+1, end, find);
	return lower_bound(num, start, mid-1, find);
}

int main(void) {
	int len;
	cin >> len;
	vint numbers(len);
	for(int i = 0; i < len; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());
	for(int i = 0; i < len; i++) {
		cout << numbers[i] << ' ';
	}
	cout << endl;
	cout << upper_bound(numbers, 0, len-1, 5) << endl;
	cout << lower_bound(numbers, 0, len-1, 5) << endl;
	return 0;
}

