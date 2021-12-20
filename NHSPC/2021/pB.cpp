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
};

ld dis(ll x, ll y, ll a, ll b) {
	return sqrtl((x - a) * (x - a) + (y - b) * (y - b));
}
ll dot(ll a, ll b, ll c, ll d) {
	return a * c + b * d;
}

signed main() {
	ll x, y, n;
	cin >> x >> y >> n;
	ll px, py;
	cin >> px >> py;
	ld ans = dis(x, y, px, py);
	for(int i = 0; i < n; i++) {
		int rx, ry;
		cin >> rx >> ry;
		ans = min(ans, dis(rx, ry, x, y));

		ll r = rx - px, g = ry - py;
		ll c = r * ry - g * rx;
		if(dot(r, g, x - px, y - py) > 0 && dot(-r, -g, x - rx, y - ry) > 0)
			ans = min(ans, ld(abs(g * x - r * y + c)) / sqrtl(g * g + r * r));
		px = rx;
		py = ry;
	}
	cout << fixed << setprecision(15) << ans << '\n';
}
