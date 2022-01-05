// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EMiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EMiliaMyWife
	return 48763;
}();

const int N = 3e5 + 25, LGN = 19;
int anc[LGN][N], mn[LGN][N], state[N];
signed main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		x = -x;
		if(x > 0) {
			int r = i - 1;
			for(int j = LGN - 1; ~j; j--)
				if(mn[j][r] >= x)
					r = anc[j][r];
			assert(r > 0);
			anc[0][i] = r - 1;
			mn[0][i] = x;
		}
		else {
			state[i] = -x;
			anc[0][i] = i;
		}
		for(int j = 1; j < LGN; j++) {
			anc[j][i] = anc[j - 1][anc[j - 1][i]];
			mn[j][i] = min(mn[j - 1][i], mn[j - 1][anc[j - 1][i]]);
		}

		cout << state[anc[LGN - 1][i]] << '\n';
	}
}
