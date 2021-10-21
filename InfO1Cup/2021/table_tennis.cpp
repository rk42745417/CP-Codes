// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const ll LINF = ll(1e18) + ll(1e15);
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n + k);
	for(int &x : arr)
		cin >> x;
	const int m = n + k;
	vector<int> ans;
	ans.reserve(n);
	auto run = [&](int s) {
		int rest = k, l = 0, r = m - 1;
		while(rest >= 0 && ans.size() < n) {
			if(arr[l] + arr[r] == s) {
				ans.push_back(arr[l]);
				ans.push_back(arr[r]);
				l++;
				r--;
			}
			else if(arr[l] + arr[r] > s)
				rest--, r--;
			else
				rest--, l++;
		}
	};
	if(m <= 4 * k) {
		for(int i = 0; i <= k; i++) {
			for(int j = 0; j + i <= k; j++) {
				run(arr[i] + arr[m - j - 1]);
				if(ans.size() == n) {
					sort(ans.begin(), ans.end());
					for(int a : ans)
						cout << a << ' ';
					cout << '\n';
					return 0;
				}
				ans.clear();
			}
		}
	}
	else {
		map<int, int> cnt;
		for(int i = 0; i < 2 * k; i++)
			for(int j = 0; j < 2 * k; j++)
				cnt[arr[i] + arr[m - j - 1]]++;
		for(const auto &[s, c] : cnt) {
			if(c >= k) {
				run(s);
				if(ans.size() == n) {
					sort(ans.begin(), ans.end());
					for(int a : ans)
						cout << a << ' ';
					cout << '\n';
					return 0;
				}
				ans.clear();
			}
		}
	}
}
