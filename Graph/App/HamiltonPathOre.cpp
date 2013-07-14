// hamilton path with Ore condition: 
//     for u, v in G, deg(u) + deg(v) >= n

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

bool e[MAXN][MAXN], v[MAXN];
char buf[MAXN*10];
int head, tail, len;
int nxt[MAXN], pre[MAXN];

void list_info(const int n) {
	for (int i=0; i<n; ++i) printf("%d: %d %d\n", i, pre[i], nxt[i]);
	puts("==================");
}

// extend path from node r, d is the direction
void extend_path(const int r, const int n, const bool d) {
	for (int x=r,ff=1; ff; ) {
		v[x] = true, ff = 0;
		for (int i=0; !ff && i<n; ++i) if (!v[i] && e[x][i]) {
			++len;
			if (d) nxt[x] = i, pre[i] = x, x = i, ff = 1, tail = i, nxt[tail] = -1;
			else pre[x] = i, nxt[i] = x, x = i, ff = 1, head = i, pre[head] = -1;
		}
	}
}

void hamilton_path(const int n) {
	memset(v, false, sizeof(v));
	head = 0, tail = 0, len = 1;
	extend_path(0, n, true);
	extend_path(0, n, false);
	while (true) {
//		list_info(n);
		if (e[head][tail]) {
			if (len == n) break;
			for (int i=head; i>=0; i=nxt[i]) {
				bool find_one = false;
				for (int j=0; j<n; ++j) if (!v[j] && e[i][j]) {
					find_one = true;
					if (i != head) {
						nxt[tail] = head, pre[head] = tail;
						tail = pre[i];
					}
					nxt[j] = i, pre[i] = j;
					head = j, pre[head] = -1;
					nxt[tail] = -1;
					break;
				}
				if (find_one) break;
			}
			++len;
		} else {
			for (int i=head; nxt[i]>=0; i=nxt[i]) {
				int j = nxt[i];
				if (e[head][j] && e[i][tail]) {
					for (int k=j; k>=0; k=pre[k]) swap(pre[k], nxt[k]);
					nxt[i] = tail, pre[tail] = i;
					tail = j, nxt[tail] = -1;
					break;
				}
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n); gets(buf);
	for (int i=0,j,k; i<n; ++i) {
		gets(buf);
		for (k=0,j=0; buf[k]; ++k) {
			if (buf[k] == ' ') j && (e[i][j-1] = true, j = 0);
			else j = j * 10 + buf[k] - '0';
		}
		j && (e[i][j-1] = true);
	}
	hamilton_path(n);
	for (int k=head; ; k=nxt[k]) if (!k) {
		for (int i=k; i>=0; i=nxt[i]) printf("%d ", i+1);
		break;
	}
	for (int k=head; k>0; k=nxt[k]) printf("%d ", k+1);
	puts("1");
	return 0;
}

// 1458413	14.07.13 08:40	delta	 122	.CPP	Accepted	31 ms	1891 kb
