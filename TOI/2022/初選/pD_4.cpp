// 24/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(4e18) + ll(2e15);
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int a, b;
	cin >> a >> b;
	assert(b % 2 == 0);
	if(a == 1) {
		cout << string(b - 2, '2') << "022" << '\n';
		cout << "220" << string(b - 2, '2') << '\n';
	}
	else {
		cout << string(b - 1, '2') << "002" << string(a - 2, '0') << '\n';
		cout << string(a - 1, '0') << "220" << string(b - 2, '2') << '\n';
	}
}
