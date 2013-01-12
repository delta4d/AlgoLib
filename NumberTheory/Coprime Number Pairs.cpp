// using Inclusion¨Cexclusion principle to calculate the coprime number pairs on [1, m] x [1, n]. init() before using.
// time and space complexity both O(n)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000086;

int f[MAXN];
bool p[MAXN];

void init() {
	int i, j, k;
	memset(p, true, sizeof(p));
	for (i=2; i<MAXN; ++i) {
		if (p[i]) {
			++f[i];
			int ii = i * i;
			for (j=i<<1; j<MAXN; j+=i) {
				p[j] = false;
				if (j % ii == 0) f[j] = -1;
				else if (f[j] != -1) ++f[j];
			}
		}
	}
}

// unordered pairs 
int relative_prime(int m, int n) {
	int i, j, k;
	int tot;
	
	if (m > n) swap(m, n);
	for (tot=0,i=1; i<=m; ++i) if (f[i] != -1) {
		if (f[i] & 1) tot -= (m / i) * (n / i) - (m / i) * (m / i - 1) / 2;
		else tot += (m / i) * (n / i) - (m / i) * (m / i - 1) / 2;
	}
	return tot;
}

// ordered pairs
int relative_prime(int m, int n) {
	int i, j, k;
	int tot;
	
	if (m > n) swap(m, n);
	for (tot=0,i=1; i<=m; ++i) if (f[i] != -1) {
		if (f[i] & 1) tot -= (m / i) * (n / i);
		else tot += (m / i) * (n / i);
	}
	return tot;
}
