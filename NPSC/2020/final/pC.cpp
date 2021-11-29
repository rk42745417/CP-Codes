#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);

using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;

#define int ll
signed main() { EMT
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	vector<vector<pair<int, int>>> line(1000000 + 7);//l, r
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for(int i = 1, cnt = 1; i <= n; i++) {
		if(i == n || arr[i] != arr[i - 1]) {
			line[arr[i - 1]].push_back({i - cnt, i});
			cnt = 0;
		}
		cnt++;
	}
	int ans = 0;
	for(int c = 1; c <= 1000007; c++) {
		int can = m, res = 0;
		deque<pair<int, int>> owo;//v, w
		for(int i = 0; i < line[c].size(); i++) {
			int len = line[c][i].second - line[c][i].first;
			if(i) {
				int r = line[c][i].first - line[c][i - 1].second;
				owo.back().second += r;
				can -= r;
				//res += r;
				//cout << can << ' ' << r << ' ' << res << ' ' << c << '\n';
			}
			while(can < 0) {
				res -= owo.front().first;
				can += owo.front().second;
				owo.pop_front();
			}
			owo.push_back({len, 0});
			//cout << i << ' ' << c << ' ' << len << '\n';
			//cout << len << ' ' << c << ' ' << i << '\n';
			res += len;
			ans = max(ans, min(res + m, n));
		}
	}
	cout << ans << '\n';
} 
