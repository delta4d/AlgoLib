#include <bits/stdc++.h>
using namespace std;

int const N = 20;

double r1, r2;
double R[N+1][N+1];

double f(double x) {
	return sqrt((r1*r1-x*x)*(r2*r2-x*x));
}

double romberg(double a, double b) {
	if (a > b) swap(a, b);
	R[0][0] = (b - a) * (f(a) + f(b)) / 2;
	for (int i=1; i<=N; ++i) {
		double h = (b - a) / (1 << i);
		for (int k=1; k<=(1<<(i-1)); ++k) {
			R[i][0] += f((2*k-1)*h);
		}
		R[i][0] *= h;
		R[i][0] += R[i-1][0] / 2;
	}
	for (int i=0; i<=N; ++i) {
		for (int j=1; j<=i; ++j) {
			R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / ((1ll << (2 * j)) - 1);
		}
	}
	return R[N][N];
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("twocyl.in", "r", stdin);
	freopen("twocyl.out", "w", stdout);
#endif
	scanf("%lf%lf", &r1, &r2);
	if (r1 > r2) swap(r1, r2);
	printf("%.4lf\n", 8*romberg(0, r1));
	return 0;
}

// 6996429	 2014-07-02 13:26:40	delta_4d	 I - Two Cylinders	 GNU C++0x	Accepted	 62 ms	 200 KB
