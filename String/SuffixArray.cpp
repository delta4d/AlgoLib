#include <bits/stdc++.h>
using namespace std;

int const MAXN = 100000 + 10;

int sa[MAXN], r[MAXN], cnt[MAXN], tmp[MAXN];
int h[MAXN], height[MAXN], z[MAXN], last[MAXN];
char s[MAXN], b[MAXN];

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
