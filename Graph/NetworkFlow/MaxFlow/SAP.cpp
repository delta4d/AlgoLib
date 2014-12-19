#include <bits/stdc++.h>
using namespace std;

int const MAX_V = 1000000;
int const MAX_E = 1000000;
int const INF = 0x3f3f3f3f;

struct SAP {
	int source, sink, ep, n;
	int to[MAX_E], w[MAX_E], head[MAX_V], nxt[MAX_E];
	int dis[MAX_V], gap[MAX_V];
	bool v[MAX_V];

	void init(int _source, int _sink) {
		source = _source, sink = _sink, ep = 0, n = 0;
		memset(v, false, sizeof(v));
		memset(dis, 0, sizeof(dis));
		memset(gap, 0, sizeof(gap));
		memset(head, -1, sizeof(head));
	}

	void __add_edge(int x, int y, int z) {
		if (!v[x]) v[x] = true, ++n;
		if (!v[y]) v[y] = true, ++n;
		to[ep] = y, w[ep] = z, nxt[ep] = head[x], head[x] = ep;
		++ep;
	}

	void add_edge(int x, int y, int z) {
		__add_edge(x, y, z);
		__add_edge(y, x, 0);
	}

	int dfs(int x, int flow) {
		if (x == sink) return flow;
		int unflowed = flow;
		for (int i=head[x]; ~i; i=nxt[i]) if (w[i]) {
			int y = to[i];
			if (dis[x] == dis[y] + 1) {
				int delta = dfs(y, min(unflowed, w[i]));
				w[i] -= delta, w[i^1] += delta, unflowed -= delta;
				if (!unflowed) return flow;
			}
		}
		if (--gap[dis[x]] == 0) dis[source] = n;
		++gap[++dis[x]];
		return flow - unflowed;
	}

	int flow() {
		int ret = 0;
		while (dis[source] < n) {
			ret += dfs(source, INF);
		}
		return ret;
	}
};

SAP sap;


// http://www.codechef.com/problems/RIN

int X[111][111], mx[111];

int main() {
	int n, m, k, tot = 0;
	scanf("%d%d%d", &n, &m, &k);
	int source = n * m, sink = source + 1;
	sap.init(source, sink);
	for (int i=0; i<n; ++i) {
		mx[i] = 0;
		for (int j=0; j<m; ++j) {
			scanf("%d", X[i]+j);
			mx[i] = max(mx[i], X[i][j]);
		}
		tot += mx[i];
	}
	for (int i=0; i<n; ++i) {
		int x = source;
		for (int j=0; j<m; ++j) {
			int y = i * m + j;
			if (X[i][j] != -1) sap.add_edge(x, y, mx[i]-X[i][j]);
			else sap.add_edge(x, y, INF);
			x = y;
		}
		sap.add_edge(x, sink, INF);
	}
	for (int a,b; k--; ) {
		scanf("%d%d", &a, &b), --a, --b;
		for (int i=0; i<m; ++i) {
			int x = i ? a * m + i - 1: source;
			int y = b * m + i;
			sap.add_edge(x, y, INF);
		}
	}
	tot -= sap.flow();
	printf("%.2lf\n", (double)tot/n);
	return 0;
}

