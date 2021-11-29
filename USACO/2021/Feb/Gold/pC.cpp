// ?/100
#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = 2e18;
const double EPS = 1e-9;

const int N = 40;
ll fac[N];

ll get(vector<int> cur) {
	ll res = 0;
	for(int i = 0; i < N; i++)
		res += cur[i] * fac[i];
	return res;
}
ll query2(vector<int> a, vector<int> b, vector<int> bit, bool stze) {
	ll mx = get(b), res = 0;
	for(ll i = get(a) + 1 - stze; i <= mx; i++) {
		bool ok = 1;
		for(int j = 0; j < N; j++)
			if(bit[j] == 2 && i / fac[j] % 3)
				ok = 0;
		res += ok;
	}
	return res;
}
ll query(vector<int> cur, vector<int> bit) {
	vector<ll> can(N);
	can[0] = 1;
	for(int i = 1; i < N; i++) {
		if(bit[i - 1] == 0)
			can[i] = can[i - 1] * 3;
		else
			can[i] = can[i - 1];
		//cout << can[i] << '\n';
	}
	ll ans = 0;
	for(int i = N - 1; ~i; i--) {
		//cout << cur[i] << " \n"[i ==0];
		if(bit[i] == 0) {
			ans += cur[i] * can[i];
		}
		else {
			if(cur[i]) {
				ans += can[i];
				return ans;
			}
		}
	}
	return ans + 1;
}

signed main() { EMT
	fac[0] = 1;
	for(int i = 1; i < N; i++)
		fac[i] = fac[i - 1] * 3;

	int q;
	cin >> q;
	while(q--) {
		ll x, y, d;
		cin >> d >> x >> y;

		if(d > 300) {
			cout << 1000000000000000001LL << '\n';
			continue;
		}
		if(y < x)
			swap(x, y);
		ll w = y - x;
		vector<int> bit(N);
		for(int i = 0; i < N; i++)
			bit[i] = w / fac[i] % 3;
		bool ok = 1;
		vector<int> r(N), l(N);
		for(int i = N - 1; ~i; i--) {
			//cout << 2 * fac[i] << '\n';
			if(bit[i] == 1) {
				ok = 0;
				break;
			}
			r[i] = (x + d) / fac[i] % 3;
			if(x)
				l[i] = (x - 1) / fac[i] % 3;
		}
		if(!ok) {
			cout << "0\n";
			continue;
		}
		cout << query2(l, r, bit, x == 0) << '\n';
		//if(x == 0)
			//cout << query(r, bit) << '\n';
		//else
			//cout << query(r, bit) - query(l, bit) << '\n';
	}
}
