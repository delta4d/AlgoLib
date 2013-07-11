// number of (i, j) s.t.i < j && xi > xj
// x[] is array to be count, t[] is a tmp array
int inversion(int x[], int t[], int L, int R) {
	if (L >= R) return 0;
	int M = (L + R) >> 1, i, j, k;
	int ret = inversion(x, t, L, M) + inversion(x, t, M+1, R);
	for (i=L, j=M+1, k=0; i<=M && j<=R; ) {
		if (x[i] > x[j]) ret += M - i + 1, t[k++] = x[j++];
		else t[k++] = x[i++];
	}
	for (; i<=M; t[k++]=x[i++]);
	for (; j<=R; t[k++]=x[j++]);
	for (i=L; i<=R; ++i) x[i] = t[i-L];
	return ret;
}
