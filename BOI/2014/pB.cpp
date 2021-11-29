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

signed main() {
	int n;
	string s;
	cin >> n >> s;
	if(n % 2 == 0)
		return cout << "NOT POSSIBLE\n", 0;

	vector<ll> hsh(n), fac(n + 1, 1);
	hsh[0] = s[0];
	for(int i = 1; i < n; i++)
		hsh[i] = (hsh[i - 1] * 48763 + s[i]) % MOD;
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * 48763 % MOD;
	auto que = [&](int l, int r) {
		if(l > r)
			return ll(0);
		if(l == 0)
			return hsh[r];
		return (hsh[r] - hsh[l - 1] * fac[r - l + 1] % MOD + MOD) % MOD;
	};

	string ans;
	ll t = 0;
	for(int i = 0; i < n; i++) {
		int a = -1, b = - 1;
		if(i == n / 2) {
			if(que(0, i - 1) == que(i + 1, n - 1))
				a = 0, b = i - 1;
		}
		else if(i < n / 2) {
			if(que(0, i - 1) == que(n / 2 + 1, n / 2 + i) && que(i + 1, n / 2) == que(n / 2 + i + 1, n - 1))
				a = n / 2 + 1, b = n - 1;
		}
		else {
			if(que(0, i - n / 2 - 1) == que(n / 2, i - 1) && que(i - n / 2, n / 2 - 1) == que(i + 1, n - 1))
				a = 0, b = n / 2 - 1;
		}
///*
		if(~a) {
			//cout << "HERE " << s.substr(a, b - a + 1) << '\n';
			if(!ans.empty()) {
				if(t != que(a, b))
					return cout << "NOT UNIQUE\n", 0;
			}
			else {
				ans = s.substr(a, b - a + 1);
				t = que(a, b);
			}
		}
		//*/
	}
	if(!ans.empty())
		cout << ans << '\n';
	else
		cout << "NOT POSSIBLE\n";
}
