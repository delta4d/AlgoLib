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

template <typename T = int>
struct BIT {
	int n;
	T x[MAXN + 1];

	void init(int _n=MAXN) {
		n = _n;
		memset(x, 0, n*sizeof(T));
	}

	void add(int p, T off) {
		for (; p<=n; p+=lowbit(p)) x[p] += off;
	}

	void add_interval(int l, int r, T off) {
		add(l, off);
		add(r+1, -off);
	}

	// [1..p]
	T sum(int p) {
		T tot = T();
		for (; p>=1; p-=lowbit(p)) tot += x[p];
		return tot;
	}

	T get(int p) {
		return sum(p) - sum(p-1);
	}

	void set(int p, T v) {
		add(p, v-get(v));	
	}
};
