// 26/100
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
	int n;
	cin >> n;
	if(n == 0) {
		cout << "0\n";
		return 0;
	}
	n = 1 << n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	map<vector<int>, int> has;
	has[arr] = 0;
	queue<vector<int>> bfs;
	bfs.push(arr);
	while(!bfs.empty()) {
		auto a = bfs.front();
		bfs.pop();
		auto b = a;
		for(int i = 0; i < n; i++) {
			if(i & 1)
				b[i / 2 + n / 2] = a[i];
			else
				b[i / 2] = a[i];
		}
		for(int i = 0; i < n / 2; i++)
			swap(a[i], a[i + n / 2]);
		if(!has.count(b)) {
			has[b] = 2;
			bfs.push(b);
		}
		if(!has.count(a)) {
			has[a] = 1;
			bfs.push(a);
		}
	}
	auto rev = [&](const vector<int> &arr) {
		int res = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < i; j++)
				res += arr[j] > arr[i];
		return res;
	};
	vector<int> ans;
	int w = INF;
	for(const auto &[a, b] : has) {
		int x = rev(a);
		if(x < w)
			w = x, ans = a;
	}

	cout << w << '\n';
	string s;
	vector<int> tmp(n);
	while(has[ans]) {
		//for(int x : ans)
		//cout << x << ' ';
		//cout << '\n';
		if(has[ans] == 1) {
			for(int i = 0; i < n / 2; i++)
				swap(ans[i], ans[i + n / 2]);
			s += '1';
		}
		else {
			for(int i = 0; i < n; i += 2)
				tmp[i] = ans[i / 2];
			for(int i = 1; i < n; i += 2)
				tmp[i] = ans[i / 2 + n / 2];
			ans = tmp;
			s += '2';
		}
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
}
