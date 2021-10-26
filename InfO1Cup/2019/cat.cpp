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
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int &a : arr)
			cin >> a;
		{
			bool ok = 1;
			int w = 0;
			for(int i = 0; i < n / 2; i++) {
				if(arr[i] + arr[n - i - 1] != n + 1)
					ok = false;
				w += arr[i] > n / 2;
			}
			if(!ok || w % 2) {
				cout << "-1\n";
				continue;
			}
		}
		vector<int> owo(n / 2);
		for(int i = 0; i < n / 2; i++)
			owo[i] = (arr[i] > n / 2 ? -(n + 1 - arr[i]) : arr[i]);
		vector<int> pos(n / 2 + 1);
		vector<pair<int, int>> ans;
		int tag = -1;
		for(int i = 0; i < n / 2; i++) {
			pos[abs(owo[i])] = i;
		}

		for(int i = 0; i < n / 2; i++) {
			if(pos[i + 1] == i) {
				if(owo[i] < 0) {
					if(tag == -1)
						tag = i;
					else {
						ans.push_back({i, tag});
						ans.push_back({i, n - tag - 1});
						owo[i] *= -1;
						owo[tag] *= -1;
						tag = -1;
					}
				}
			}
			else {
				int g = pos[i + 1];
				if(owo[g] < 0) {
					ans.push_back({i, n - g - 1});
					owo[g] *= -1;
					owo[i] *= -1;
				}
				else {
					ans.push_back({i, g});
				}
				swap(pos[i + 1], pos[abs(owo[i])]);
				swap(owo[g], owo[i]);
			}
		}

		cout << ans.size() << ' ' << ans.size() << '\n';
		for(const auto &[a, b] : ans)
			cout << a + 1 << ' ' << b + 1 << '\n';
	}
}
