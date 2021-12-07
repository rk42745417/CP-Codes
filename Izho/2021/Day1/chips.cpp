// 7/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const ll LINF = 4e18;

signed main() { EmiliaMyWife
	int n, t;
	cin >> n >> t;
	vector<char> arr(n);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}
	vector<char> brr(n);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		brr[i] = x;
	}
	set<vector<char>> has;
	map<vector<char>, pair<int, int>> owo;
	has.insert(arr);
	queue<vector<char>> bfs;
	bfs.push(arr);
	while(!bfs.empty()) {
		auto x = bfs.front();
		//cout << "here ";
		//for(int a : x)
			//cout << a << ' ';
		//cout << '\n';
		bfs.pop();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i == j)
					continue;
				int a = 0, b = 0;
				if(i < j) {
					for(int k = i + 1; k <= j; k++) {
						if(x[k] > x[i])
							a++;
						else
							b++;
					}
				}
				else {
					for(int k = i - 1; k >= j; k--) {
						if(x[k] > x[i])
							a++;
						else
							b++;
					}
				}
				if(a == b) {
					auto r = x;
					int w = r[i];
					if(i < j) {
						for(int k = i + 1; k <= j; k++)
							r[k - 1] = r[k];
					}
					else {
						for(int k = i - 1; k >= j; k--)
							r[k + 1] = r[k];
					}
					r[j] = w;
					if(!has.count(r)) {
						has.insert(r);
						bfs.push(r);
						owo[r] = {i + 1, j - i};
					}
				}
			}
		}
	}
	if(has.count(brr)) {
		cout << "YES\n";
		vector<pair<int, int>> ans;
		///*
		while(brr != arr) {
			assert(owo.count(brr));
			auto [a, b] = owo[brr];
			ans.push_back({a, b});
			//cerr << a << ' ' << b << '\n';
			if(b > 0) {
				int x = brr[a + b - 1];
				for(int i = 0; i < b; i++) {
					brr[a + b - 1 - i] = brr[a + b - i - 2];
				}
				brr[a - 1] = x;
			}
			else {
				int x = brr[a + b - 1];
				for(int i = 0; i < -b; i++) {
					brr[a + b - 1 + i] = brr[a + b + i];
				}
				brr[a - 1] = x;
			}
		}
		//*/
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for(auto [a, b] : ans)
			cout << a << ' ' << b << '\n';
	}
	else
		cout << "NO\n";
}
