#include <vector>
#include <iostream>
#include <utility>
#include <climits>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX_R = 1000;
const int MAX_C = 1000;
const int infinity = INT_MAX;

struct opt {
	int height;
	int length;
	int lowest;
	bool set;
};

int mat[MAX_R][MAX_C];
opt dp[MAX_R][MAX_C];

void find(int i, int j, int rowlim, int collim) {
	
	#define OUTOFBOUNDS(i, j) (i < 0 || i >= rowlim || j < 0 || j >= collim)
	
	if(OUTOFBOUNDS(i, j)) return;
	if(dp[i][j].set) return;
	
	dp[i][j].set = true;
	
	if(!OUTOFBOUNDS(i+1, j) && (dp[i][j].height > dp[i+1][j].height)) {
		find(i+1, j, rowlim, collim);
		if(dp[i+1][j].length + 1 == dp[i][j].length) {
			dp[i][j].lowest = min(dp[i+1][j].lowest, dp[i][j].lowest);
		}
		else if(dp[i+1][j].length + 1 > dp[i][j].length) {
			dp[i][j].length = dp[i+1][j].length+1;
			dp[i][j].lowest = dp[i+1][j].lowest;
		}
	}
	
	if(!OUTOFBOUNDS(i-1, j) && (dp[i][j].height > dp[i-1][j].height)) {
		find(i-1, j, rowlim, collim);
		if(dp[i-1][j].length + 1 == dp[i][j].length) {
			dp[i][j].lowest = min(dp[i-1][j].lowest, dp[i][j].lowest);
		}
		else if(dp[i-1][j].length + 1 > dp[i][j].length) {
			dp[i][j].length = dp[i-1][j].length+1;
			dp[i][j].lowest = dp[i-1][j].lowest;
		}
	}
	
	if(!OUTOFBOUNDS(i, j+1) && (dp[i][j].height > dp[i][j+1].height)) {
		find(i, j+1, rowlim, collim);
		if(dp[i][j+1].length + 1 == dp[i][j].length) {
			dp[i][j].lowest = min(dp[i][j+1].lowest, dp[i][j].lowest);
		}
		else if(dp[i][j+1].length + 1 > dp[i][j].length) {
			dp[i][j].length = dp[i][j+1].length+1;
			dp[i][j].lowest = dp[i][j+1].lowest;
		}
	}
	
	if(!OUTOFBOUNDS(i, j-1) && (dp[i][j].height > dp[i][j-1].height)) {
		find(i, j-1, rowlim, collim);
		if(dp[i][j-1].length + 1 == dp[i][j].length) {
			dp[i][j].lowest = min(dp[i][j-1].lowest, dp[i][j].lowest);
		}
		else if(dp[i][j-1].length + 1 > dp[i][j].length) {
			dp[i][j].length = dp[i][j-1].length+1;
			dp[i][j].lowest = dp[i][j-1].lowest;
		}
	}
}

int main(void) {
	int row, col;
	memset(mat, -1, MAX_R * MAX_C * sizeof(mat[0][0]));
	
	cin >> row >> col;
	
	// read input
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++) {
			cin >> mat[i][j];
			dp[i][j].height = mat[i][j];
			dp[i][j].lowest = mat[i][j];
			dp[i][j].set = false;
			dp[i][j].length = 1;
		}
	
	
	
	int final_length = 0, final_diff = 0;
	
	// to prevent special cases which result in stack overflow due to large recursive chains
	int randomRun = rand()%(row*col);
	for(int i = 0; i < randomRun; i++) {
		find(rand()%row, rand()%col, row, col);
	}
	
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			find(i, j, row, col);
			
			if(final_length <= dp[i][j].length) {
				final_length = dp[i][j].length;
				final_diff = max(dp[i][j].height - dp[i][j].lowest, final_diff);
			}
		}
	}
	
	cout << final_length << " " << final_diff << endl;
	return 0;
}
