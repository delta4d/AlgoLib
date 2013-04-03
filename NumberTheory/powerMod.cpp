// x^e % MOD
template <class T> T powerMod(T x, T e, const T MOD) {
	T ret = 1;
	while (e) {
		if (e & 1) ret = ret * x % MOD;
		x = x * x  % MOD;
		e >>= 1;
	}
	return ret;
}
