#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie();
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

const int N = 1e6 + 25l;
const ll P = 100000007, Q = 541;
struct Hash {
	ll val[N], fac[N];
	void init(string &s) {
		fac[0] = 1;
		for(int i = 0; i < s.size(); i++) {
			if(i) {
				val[i] = val[i - 1] * Q % P;
				fac[i] = fac[i - 1] * Q % P;
			}
			val[i] = (val[i] + s[i]) % P;
		}
	}
	int query(int l, int r) {
		if(!l)
			return val[r];
		return (val[r] - val[l - 1] * fac[r - l + 1] % P + P) % P;
	}
} hsha, hshb;

signed main() { EmiliaMyWife
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	hsha.init(a);
	hshb.init(b);
	int ans = 0;
	for(int i = 0; i + m <= n; i++) {
		if(hsha.query(i, i + m - 1) == hshb.query(0, m - 1)) {
			ans = max(ans, m);
			continue;
		}
		int l = 1, r = m, tmp = 0;
		while(l < r) {
			int mi = l + r >> 1;
			if(hsha.query(i, i + mi - 1) != hshb.query(0, mi - 1))
				r = mi;
			else
				l = mi + 1;
		}
		tmp += l - 1;
		l = 1, r = m;
		while(l < r) {
			int mi = l + r >> 1;
			if(hsha.query(i + m - mi, i + m - 1) != hshb.query(m - mi, m - 1))
				r = mi;
			else
				l = mi + 1;
		}
		//cout << i << ' ' << tmp << ' ' << l - 1 << '\n';
		ans = max(ans, tmp + l - 1);
	}
	cout << ans << '\n';
}
