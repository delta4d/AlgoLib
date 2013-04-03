// __gcd in 'algorithm' is a better option

template <class T> T gcd(T a, T b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	while (b) {
		T t = b;
		b = a % b;
		a = t;
	}
	return a;
}
