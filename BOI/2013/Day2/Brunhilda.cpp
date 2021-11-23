// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 1e7 + 25;
int ans[N], owo[N];
signed main() {
	int m, q;
	cin >> m >> q;
	vector<int> pr(m);
	for(int &a : pr)
		cin >> a;
	memset(ans, 0x3f, sizeof ans);
	memset(owo, 0x3f, sizeof owo);
	for(int a : pr)
		for(int i = a; i < N; i += a)
			owo[i] = min(owo[i], i - a);
	int r = INF;
	for(int a : pr)
		r = min(r, (N - 1) - (N - 1) % a);
	for(int i = N - 1; i; i--) {
		int g = r;
		r = min(r, owo[i]);
		owo[i] = g;
	}
	ans[0] = 0;
	for(int i = 1; i < N; i++)
		ans[i] = ans[owo[i]] + 1;
	while(q--) {
		int n;
		cin >> n;
		if(ans[n] >=  INF)
			cout << "oo\n";
		else
			cout << ans[n] << '\n';
	}
}
