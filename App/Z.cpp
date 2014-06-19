#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int const N = 1e6 + 1e4 + 10;

char W[N], T[N], s[N];
int z[N]; // s[0..z[i]-1] = s[i..i+z[i]-1]

int Z(char p[], int lp, char t[], int lt) {
	strcpy(s, p), s[lp] = '#', strcpy(s+lp+1, t);
	int n = lp + lt + 1, ret = 0;
	for (int i=1,l=0,r=0; i<n; ++i) {
		if (i <= r) z[i] = min(z[i-l], r-i+1);
		else z[i] = 0;
		while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
		ret += z[i] == lp;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return ret;
}

int main() {
	int tc;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s", W, T);
		printf("%d\n", Z(W, (int)strlen(W), T, (int)strlen(T)));
	}
	return 0;
}

// 12984275	delta_4d	3461	Accepted	6308K	172MS	G++	683B	2014-06-19 13:04:26
