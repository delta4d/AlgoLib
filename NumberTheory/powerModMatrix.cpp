/*
* MOD 为模， MAXN为最大维
* matrix_mul(int, int[][], int[][])为计算两个n*n的矩阵的积，结果保留在x中，矩阵起点从0开始 
* matrix_binary_exp(int, int[][], int)为计算x ^ exp % MOD，其中x为n*n的矩阵，exp为指数，返回结果在x中 
* 复杂度O(n^3lg(exp))
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000007;
const int MAXN = 10;

void matrix_mul(const int n, int x[][MAXN], int y[][MAXN]) {
	int i, j, k;
	int tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) for (k=0; k<n; ++k) {
		tmp[i][j] = (tmp[i][j] + x[i][k] * y[k][j]) % MOD;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}

void matrix_binary_exp(const int n, int x[][MAXN], int exp) {
	int i, j, k;
	int tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));
	for (i=0; i<n; ++i) tmp[i][i] = 1;
	while (exp) {
		if (exp & 1) matrix_mul(n, tmp, x);
		matrix_mul(n, x, x);
		exp >>= 1;
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) x[i][j] = tmp[i][j];
}
