#include <cstdio>
#include <vector>
using namespace std;

int const N = 1e7;

// lp[i] = least prime factor of i
int lp[N+1];
vector <int> p;

void gen_prime() {
	for (int i=2; i<N; ++i) {
		if (lp[i] == 0) lp[i] = i, p.push_back(i);
		for (auto pr: p) {
			if (pr > lp[i] || pr * i > N) break;
			lp[pr * i] = pr;
		}
	}
}

int main() {
	gen_prime();
	return 0;
}
