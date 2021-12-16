// 11/100
#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("avx2")
//#pragma GCC optimize("unroll-loops")

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const double EPS = 1e-9;

signed main() { EMT
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	while(q--) {
		int l, r, u;
		cin >> l >> r >> u;
		int mn = -INF;
		for(int i = l; i < r; i++)
			mn = max(mn, a[i]);
		if(mn > u) {
			cout << "-1\n";
			continue;
		}
		vector<ll> nd(n + 1);
		ll has = 0, ans = 0, s = 0;
		deque<int> st;
		for(int i = r - 1; i >= l; i--) {
			while(s + a[i] - has > u) {
				ll w = min(nd[st.front()] - has, s + a[i] - has - u);
				//cerr << s << ' ' << has << ' ' << w << '\n';
				ans += w * b[st.front()];
				has += w;
				if(nd[st.front()] == has)
					st.pop_front();
			}
			while(st.size() && b[st.back()] >= b[i])
				st.pop_back();
			s += a[i];
			nd[i] = s;
			st.push_back(i);
		}
		while(s - has) {
			ll w = min(nd[st.front()] - has, s - has);
				//cerr << s << ' ' << has << ' ' << w << '\n';
			ans += w * b[st.front()];
			has += w;
			if(nd[st.front()] == has)
				st.pop_front();
		}
		cout << ans << '\n';
	}
}
