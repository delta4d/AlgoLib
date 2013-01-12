#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10086;
typedef int T;
#define _cp(x, y) ((x) < (y))

int dp[MAXN], p[MAXN];
int x[MAXN], path[MAXN];

int LIS(T x[], int path[], const int n) {
	int i, j, k(0);
	for (i=0; i<n; ++i) {
		int left(1), right(k), mid;
		j = 0;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (_cp(x[dp[mid]], x[i])) j = mid, left = mid + 1;
			else right = mid - 1;
		}
		p[i] = dp[j];
		if (j == k || x[i] < x[dp[j+1]]) dp[j+1] = i, k = max(k, j+1);
	}
	i = dp[k], j = k;
	while (j--) {
		path[j] = i;
		i = p[i];
	}
	return k;
}

// ZOJ 2136
int main() {
	int i, j, k;
	int m, n;
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%d", x+i);
		printf("%d\n", LIS(x, path, n));
		if (tc) puts("");
	}

	return 0;
}

