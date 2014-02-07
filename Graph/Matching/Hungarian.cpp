/**
* bipartite matching
* O(VE)
**/
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;

vector <int> e[MAXN];
bool v[MAXN];
int mx[MAXN], my[MAXN];

bool dfs(int x) {
	for (int i=(int)e[x].size()-1; i>=0; --i) {
		int y = e[x][i];
		if (v[y]) continue;
		v[y] = true;
		if (my[y] == -1 || dfs(my[y])) {
			mx[x] = y, my[y] = x;
			return true;
		}
	}
	return false;
}

int Hungarian(int n) {
	int ret = 0;
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	for (int i=0; i<n; ++i) {
		memset(v, false, sizeof(v));
		ret += dfs(i);
	}
	return ret;
}
