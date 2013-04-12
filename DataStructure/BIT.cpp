// Binary Searh Tree
// calculate sum[1..n] with log(n)

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

inline int lowbit(const int x) {
	return x & -x;
}

template <class T>
struct BIT {
	int n;
	T x[MAXN + 1];

	void init(LL _n=MAXN) {
		n = _n;
		memset(x, 0, sizeof(x));
	}
	void add(int p, T off) {
		for (; p<=n; p+=lowbit(p)) x[p] += off;
	}
	void add_interval(int l, int r, T off) {
		add(l, off);
		add(r+1, -off);
	}
	T sum(int p) {
		T tot = 0;
		for (; p>=1; p-=lowbit(p)) tot += x[p];
		return tot;
	}
};

