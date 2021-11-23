// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

ll dp[18][10][10];

ll solve(ll x) {
	if(x == ll(1e18))
		x--;
	string s = to_string(x);
	ll res = 0;
	for(int i = 0; i < s.size(); i++) {
		for(int j = (!i && i + 1 < s.size()); j < s[i] - '0'; j++) {
			if(i && j == s[i - 1] - '0')
				continue;
			if(i > 1 && j == s[i - 2] - '0')
				continue;
			if(i + 1 == s.size()) {
				res++;
				continue;
			}
			for(int k = 0; k < 10; k++) {
				if(k == j)
					continue;
				if(i && k == s[i - 1] - '0')
					continue;
				for(int w = 0; w < 10; w++) {
					if(w == j)
						continue;
					res += dp[s.size() - i - 2][k][w];
				}
			}
		}
		if(i && s[i] == s[i - 1])
			break;
		if(i > 1 && s[i] == s[i - 2])
			break;
		if(i + 1 == s.size())
			res++;
	}
	for(int i = 1; i < s.size(); i++) {
		for(int j = 1; j < 10; j++) {
			if(i + 1 == s.size()) {
				res++;
				continue;
			}
			for(int k = 0; k < 10; k++) {
				if(k == j)
					continue;
				for(int w = 0; w < 10; w++) {
					if(w == j)
						continue;
					res += dp[s.size() - i - 2][k][w];
				}
			}
		}
		if(i + 1 == s.size())
			res++;
	}

	return res;
}

signed main() {
	for(int i = 0; i < 10; i++)
		dp[0][i][i] = 1;
	for(int i = 1; i < 18; i++) {
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < 10; k++) {
				if(k == j)
					continue;
				for(int w = 0; w < 10; w++) {
					if(w == j)
						continue;
					dp[i][j][k] += dp[i - 1][k][w];
				}
			}
		}
	}
	ll a, b;
	cin >> a >> b;
	ll x = solve(b);
	if(a)
		x -= solve(a - 1);
	cout << x << '\n';
}
