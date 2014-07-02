#include <bits/stdc++.h>
using namespace std;

int const N = 400;
int const INF = 0x3f3f3f3f;

int w[N][N], lx[N], ly[N], a[N];
int mx[N], my[N], d;
bool vx[N], vy[N];

bool dfs(int x, int const n) {
	vx[x] = true;
	for (int y=0; y<n; ++y) if (!vy[y]) {
		if (lx[x] + ly[y] == w[x][y]) {
			vy[y] = true;
			if (my[y] == -1 || dfs(my[y], n)) {
				mx[x] = y, my[y] = x;
				return true;
			}
		} else {
			d = min(d, lx[x]+ly[y]-w[x][y]);
		}
	}
	return false;
}

void KM(int m, int n) {
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) lx[i] = max(lx[i], w[i][j]);
	for (int k=0; k<m; ++k) {
		memset(vx, false, sizeof(vx));
		memset(vy, false, sizeof(vy));
		d = INF;
		if (dfs(k, n)) continue;
		for (int i=0; i<m; ++i) if (vx[i]) lx[i] -= d;
		for (int i=0; i<n; ++i) if (vy[i]) ly[i] += d;
		--k;
	}
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("beloved.in", "r", stdin);
	freopen("beloved.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	for (int i=0,k; i<n; ++i) {
		scanf("%d", &k);
		for (int j=0,m; j<k; ++j) {
			scanf("%d", &m);
			w[i][m-1] = a[i] * a[i];
		}
	}
	KM(n, n);
	for (int i=0; i<n; ++i) {
		if (w[i][mx[i]]) printf("%d ", mx[i]+1);
		else printf("0 ");
	}
	return 0;
}

// 6995202	 2014-07-02 08:52:09	delta_4d	 B - Beloved Sons	 GNU C++0x	Accepted	62 ms	820 KB
