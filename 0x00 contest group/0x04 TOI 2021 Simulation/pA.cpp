#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;

const int N = 1e6 + 25;
ll fac[N];

ll solve(int n, string &s, bool inv) {
	if(n == s.size())
		return 0;
	if((s[n] == '0') ^ inv)
		return solve(n + 1, s, (s[n] == '1') ^ inv);
	return (solve(n + 1, s, (s[n] == '1') ^ inv) + fac[s.size() - n - 1]) % MOD;
}

signed main() { EMT
	fac[0] = 1;
	for(int i = 1; i < N; i++)
		fac[i] = fac[i - 1] * 2 % MOD;

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << solve(0, s, 0) << '\n';
	}
}
