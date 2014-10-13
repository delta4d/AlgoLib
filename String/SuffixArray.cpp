// string s[] are based 0
// sa[], r[], height[] are all based 1

#include <bits/stdc++.h>
using namespace std;

int const MAXN = 100000 + 10;

int sa[MAXN], r[MAXN], cnt[MAXN], tmp[MAXN];
int h[MAXN], height[MAXN];
char s[MAXN];

void radix_sort(const int step, const int len) {
	memset(tmp, 0, sizeof(tmp));

	memset(cnt, 0, sizeof(cnt));
	for (int i=1; i<=len; ++i) ++cnt[r[i+step]];
	for (int i=1; i<MAXN; ++i) cnt[i] += cnt[i-1];
	for (int i=len; i>0; --i) tmp[cnt[r[i+step]]--] = i;

	memset(cnt, 0, sizeof(cnt));
	for (int i=1; i<=len; ++i) ++cnt[r[i]];
	for (int i=1; i<MAXN; ++i) cnt[i] += cnt[i-1];
	for (int i=len; i>0; --i) sa[cnt[r[tmp[i]]]--] = tmp[i];
	
	for (int i=1; i<=len; ++i) tmp[i] = r[i];
	r[sa[1]] = 1;
	for (int i=2,p=1; i<=len; ++i) {
		if (tmp[sa[i]] != tmp[sa[i-1]] || tmp[sa[i]+step] != tmp[sa[i-1]+step]) ++p;
		r[sa[i]] = p;
	}
}

void get_sa(char s[], const int len) {
	memset(r, 0, sizeof(r));
	for (int i=0; i<len; ++i) r[i+1] = s[i];
	radix_sort(0, len);
	for (int step=1; step<=len; step<<=1) {
		radix_sort(step, len);
	}
}

void get_height(char s[], const int len) {
	memset(h, 0, sizeof(h));
	for (int i=1; i<=len; ++i) if (r[i] != 1) {
		int p = max(0, h[i-1] - 1), j = sa[r[i] - 1];
		while (i + p - 1 < len && j + p - 1 < len && s[i+p-1] == s[j+p-1]) ++p;
		h[i] = p;
	}
	for (int i=1; i<=len; ++i) height[r[i]] = h[i];
}

void get_lcp(const int len) {
	for (int i=0; i<=len; ++i) rmq[i][0] = height[i];
	for (int k=1; (1<<k)<=len; ++k) {
		for (int i=0; i<=len; ++i) {
			rmq[i][k] = rmq[i][k-1];
			int k2 = 1 << (k - 1);
			if (i + k2 <= len) rmq[i][k] = min(rmq[i][k], rmq[i+k2][k-1]);
		}
	}
}

int lcp(int l, int r) {
	if (l == r) return len - l + 1;
	l = ::r[l], r = ::r[r];
	if (l > r) swap(l, r);
	++l;
	int k = 0;
	while ((1 << k) < r - l + 2) ++k; --k;
	int ret = min(rmq[l][k], rmq[r-(1<<k)+1][k]);
	return ret;
}
