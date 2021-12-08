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

ll mpow(ll a, int b) {
	ll res = 1;
	for(a %= MOD; b; b >>= 1, a = a * a % MOD)
		if(b & 1)
			res = res * a % MOD;
	return res;
}

signed main() {
	ll n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i], arr[i]--;
	vector<ll> fac(n + 1, 1), inv_fac(n + 1);
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % MOD;
	for(int i = 0; i <= n; i++)
		inv_fac[i] = mpow(fac[i], MOD - 2);

	auto cnm = [&](int n, int m) {
		if(n < m)
			return ll(0);
		return fac[n] * inv_fac[n - m] % MOD * inv_fac[m] % MOD;
	};

	ll ans = fac[n] * n % MOD * n % MOD;
	const ll inv_2 = mpow(2, MOD - 2), inv_6 = mpow(6, MOD - 2);

	for(int i = 0; i < n; i++) {
		ll g = n * n % MOD * (n - 1) % MOD * inv_2 % MOD;
		ll w = n * (n - 1) % MOD * (2 * n - 1) % MOD * inv_6 % MOD;
		if(arr[i] != i) {
			ans = (ans - fac[n - 2] * (g - w + MOD) % MOD * 2 % MOD + MOD) % MOD;
		}
	}

	vector<bool> vis(n);
	ll r = 0;
	map<int, int> owo;
	auto solve = [&](int k) {
		ll r = 0;
		ll g = fac[n - k] * fac[k / 2] % MOD * fac[k / 2] % MOD;
		return g * (cnm(n, k) + cnm(n, k + 1)) % MOD;
	};
	for(int i = 0; i < n; i++) {
		if(vis[i])
			continue;
		int x = i, sz = 0;
		while(!vis[x]) {
			sz++;
			vis[x] = true;
			x = arr[x];
		}
		owo[sz]++;
	}
	for(const auto &[x, c] : owo) {
		if(x % 2 == 0)
			r = (r + c * 2 * solve(x)) % MOD;
	}
	cout << (ans + r) % MOD << '\n';
}
