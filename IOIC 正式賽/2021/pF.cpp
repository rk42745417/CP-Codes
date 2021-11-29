#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

const int N = 3e5 + 25;
unordered_set<int> mx[N];
vector<int> prime_factors[N];
signed main() { EmiliaMyWife
	for(int i = 2; i < N; i++) {
		if(prime_factors[i].empty())
			for(int j = i; j < N; j += i)
				prime_factors[j].push_back(i);
	}

	int t;
	cin >> t;
	while(t--) {
		int n, ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			mx[i].clear();
			mx[i].insert(0);
		}
		for(int i = 1, x; i <= n; i++) {
			cin >> x;
			if(x == 1 && i == 1) {
				ans = 1;
			}
			bool ok = 0;
			for(int a : prime_factors[i]) {
				if(mx[a].count(x - 1))
					ok = true;
			}
			if(ok) {
				ans = max(ans, x);
				for(int a : prime_factors[i])
					mx[a].insert(x);
			}
		}
		cout << ans << '\n';
	}
}
