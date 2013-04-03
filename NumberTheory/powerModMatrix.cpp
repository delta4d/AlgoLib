/*
 * matrix_mul(int, int[][], int[][]) calc two nxn matrix, result is in x
 * matrix_binary_exp(int, int[][], int) calc x ^ exp % MOD, x is an nxn matrix, result is in x
 * complexity O(n^3*log(exp))
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
