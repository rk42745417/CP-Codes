// 50/50
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(4e18) + ll(2e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		vector<ll> cnt(26);
		int it = 0;
		auto solve = [&](int a) {
			int cur = 1;
			while(it < s.size() && s[it] != '-') {
				if('2' <= s[it] && s[it] <= '9')
					cur = s[it] - '0', it++;
				else if('A' <= s[it] && s[it] <= 'Z') {
					if(it + 1 < s.size() && '2' <= s[it + 1] && s[it + 1] <= '9')
						cnt[s[it] - 'A'] += cur * (s[it + 1] - '0') * a, it += 2;
					else
						cnt[s[it] - 'A'] += cur * a, it++;
				}
				else if(s[it] == '+')
					cur = 1, it++;
			}
		};
		solve(1);
		it += 2;
		solve(-1);
		bool ok = 1;
		for(int i = 0; i < 26; i++)
			ok &= cnt[i] == 0;
		cout << (ok ? "DA" : "NE") << '\n';
	}
}
