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
const ll LINF = 1e18;

inline ll dot(pair<ll, ll> &a, pair<ll, ll> &b, pair<ll, ll> &c) {
	return (b.first - a.first) * (c.first - a.first) + (b.second - a.second) * (c.second - a.second);
}
inline ll cross(pair<ll, ll> &a, pair<ll, ll> &b, pair<ll, ll> &c) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}
inline ll cal(vector<pair<ll, ll>> &arr) {
	ll res = 0;
	for(int i = 1; i + 1 < arr.size(); i++)
		res += abs(cross(arr[0], arr[i], arr[i + 1])) / 2;
	return res;
}

signed main() { EMT
	int q;
	cin >> q;
	vector<pair<ll, ll>> arr(3);
	for(int i = 0; i < 3; i++)
		cin >> arr[i].first >> arr[i].second;
	cout << cal(arr) << '\n';
	while(q--) {
		ll x, y;
		cin >> x >> y;
		arr.push_back({x, y});
		vector<pair<ll, ll>> dw, up;
		sort(arr.begin(), arr.end());
		for(int i = 0; i < arr.size(); i++) {
			while(dw.size() > 1 && cross(dw[dw.size() - 2], dw.back(), arr[i]) < 0)
				up.push_back(dw.back()), dw.pop_back();
			dw.push_back(arr[i]);
		}
		reverse(up.begin(), up.end());
		for(auto &x : up)
			dw.push_back(x);

		cout << cal(dw) << '\n';
	}
}
