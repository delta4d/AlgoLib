const int MAXN = 1000 + 86;

inline int lowbit(const int x) {
	return x & -x;
}

struct BIT2 {
	int m, n;
	int a[MAXN][MAXN];

	void init(int _m=MAXN, int _n=MAXN) {
		m = _m, n = _n;
		memset(a, 0, sizeof(a));
	}

	void add(int x, int y, const int off) {
		for (int i=x; i<=m; i+=lowbit(i)) {
			for (int j=y; j<=n; j+=lowbit(j)) a[i][j] += off;
		}
	}

	// x1 <= x2, y1 <= y2
	void add_rectangle(int x1, int y1, int x2, int y2, const int off) {
		add(x1, y1, off);
		add(x1, y2+1, off);
		add(x2+1, y1, off);
		add(x2+1, y2+1, off);
	}

	int sum(int x, int y) {
		int tot = 0;	
		for (int i=x; i>0; i-=lowbit(i)) {
			for (int j=y; j>0; j-=lowbit(j)) tot += a[i][j];
		}
		return tot;
	}
};
