// ?/100
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define EMT ios::sync_with_stdio(0); cin.tie(0);

const int N = 5e5 + 25;
vector<ll> sqt[N];
ll invv[N];
int p;
ll mpow(ll a, int b) {
	ll res = 1;
	for(; b; b >>= 1, a = a * a % p)
		if(b & 1)
			res = res * a % p;
	return res;
}
ll inv(int a) { return invv[(a + p) % p]; }

signed main() { EMT
	ll A, B, C, D, E, F, G, H, I;
	cin >> A >> B >> C >> D >> E >> F >> G >> H >> I >> p;
	for(ll i = 0; i < p; i++)
		sqt[i * i % p].push_back(i), invv[i] = mpow(i, p - 2);

	vector<pair<int, int>> ans;
	for(ll x = 0; x < p; x++) {
		ll c = A * x % p * x % p * x + E * x % p * x + H * x;
		c = (c % p + p) % p;
		if(c == 0)
			ans.push_back({x, 0});
	}
	for(ll w = 0; w < p; w++) {
		ll a = (H * w + I) % p;// Hw + I
		ll b = (E * w * w % p + F * w % p + G) % p;// Ew^2 + Fw + G
		ll c = (A * w % p * w % p * w % p + B * w % p * w + C * w % p + D) % p;// Aw^3 + Bw^2 + Cw + D
		if(a == b && b == c && c == 0) { // 0 = 0
			for(ll z = 0; z < p; z++)
				if(z && inv(z))
					ans.push_back({w * inv(z) % p, inv(z) % p});
		}
		else if(a == b && b == 0) { // c = 0
			continue;
		}
		else if(a == 0) {// bz + c = 0
			ll z = (p - c) * inv(b) % p;// z = -c / b
			if(z && inv(z))
				ans.push_back({w * inv(z) % p, inv(z) % p});
		}
		else { // az^2 + bz + c = 0
			ll xdd = (b * b % p - 4 * a * c % p + p) % p;// b^2 - 4ac
			for(const auto &d : sqt[xdd]) {
				ll z  = (d - b + p) * inv(2 * a) % p; // z = (d - b) / (2a)
				if(z && inv(z))
					ans.push_back({w * inv(z) % p, inv(z) % p});
			}
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for(const auto &[x, y] : ans)
		cout << (x + p) % p << ' ' << (y + p) % p << '\n';
}
