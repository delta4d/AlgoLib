// Binary Searh Tree
// calculate sum[1..n] with log(n)

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10086;

inline int lowbit(const int x) {
	return x & -x;
}

struct BIT {
	int n;
	int x[MAXN + 1];

	void init(int _n=MAXN) {
		n = _n;
		memset(x, 0, sizeof(x));
	}
	void modify(int p, int off) {
		for (; p<=n; p+=lowbit(p)) x[p] += off;
	}
	int sum(int p) {
		int tot = 0;
		for (; p>=1; p-=lowbit(p)) tot += x[p];
		return tot;
	}
};
