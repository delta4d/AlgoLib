#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 128;

struct ModularLinearEquation {
	int n;
	ll a[MAXN], x[MAXN], b, p; // ax = b (mod p)
	ll d[MAXN]; // dk = (a1, a2, ..., ak)

	void init(int _n, ll _b, ll _p) {
		n = _n, b = _b, p = _p;
		b %= p;
	}

	bool ok() {
		d[0] = a[0];
		for (int i=1; i<n; ++i) d[i] = __gcd(d[i-1], a[i]);
		d[n] = __gcd(d[n-1], p);
		return b % d[n] == 0;
	}

	// ax + by = (a, b)
	ll ext_gcd(ll a, ll b, ll &x, ll &y) {
		if (!b) {
			x = 1, y = 0;
			return a;
		}	
		ll ret = ext_gcd(b, a%b, x, y);
		ll t = x;
		x = y, y = t - a / b * y;
		return ret;
	}

	// no solution or return one solution
	bool run() {
		if (!ok()) return false;
		ll yi, m, rem = b;
		for (int i=n-1; i>=0; --i) {
			m = i ? __gcd(d[i-1], p) : p;
			ext_gcd(a[i], m, x[i], yi);
			x[i] %= m;
			if (x[i] < 0) x[i] += m;
			x[i] = x[i] * rem / __gcd(m, a[i]) % p;
			rem = (rem - a[i] * x[i]) % p;
			if (rem < 0) rem += p;
		}
		return true;
	}
} mle;

int main() {
	ll N, P, B;

	cin >> N >> P >> B;
	mle.init(N, B, P);
	for (int i=0; i<N; ++i) cin >> mle.a[i];
	if (!mle.run()) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	for (int i=0; i<N; ++i) cout << mle.x[i] << (i == N - 1 ? "\n" : " ");

	return 0;
}

// 1463295	19.07.13 11:47	delta	 140	.CPP	Accepted	15 ms	899 kb
