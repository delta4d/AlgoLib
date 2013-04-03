// a * x + b * y = gcd(a, b)
template <class T> T extGcd(T a, T b, T &x, T &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}	
	T ret = extGcd(b, a%b, x, y);
	T t = x;
	x = y, y = t - a / b * y;
	return ret;
}

// find x such that a * x % n = 1, (a, n) = 1
template <class T> T modInv(T a, T n) {
	T x, y;
	extGcd(a, n, x, y);
	x %= n;
	if (x < 0) x += n;
	return x;
}
