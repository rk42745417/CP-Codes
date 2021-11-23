// 30/100
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

const int CONTI = 1, SINGLE = 2;
bool solve() {
	int n, m;
	cin >> n >> m;
	vector<int> stat(n + 2);
	vector<int> ope1, ope2;
	stat[0] = stat[n + 1] = CONTI;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		stat[x] = SINGLE;
	}
	for(int i = 1; i <= n; i++) {
		if(stat[i] && (stat[i - 1] || stat[i + 1]))
			stat[i] = CONTI;
	}
	for(int i = 1, l = 1; i <= n + 1; i++) {
		if(stat[i] != CONTI)
			continue;
		if(l == i) {
			l = i + 1;
			continue;
		}
		vector<int> arr, owo, split;
		for(int j = l, it = j; j <= i; j++) {
			if(j == i) {
				arr.push_back(j - it);
				owo.push_back((j + it) / 2);
				break;
			}
			if(stat[j] == SINGLE) {
				arr.push_back(j - it);
				split.push_back(j);
				owo.push_back((j + it) / 2);
				it = j + 1;
			}
		}
		if(arr.size() == 1)
			return false;
		vector<vector<int>> dp(arr.size(), vector<int>(3, -1));
		dp[0][arr[0] % 2 + 2 * (arr[0] > 1)] = 0;
		for(int i = 0; i < arr.size(); i++) {
			if(arr[i] >= 3 && ~dp[i][2]) {
				dp[i][0] = INF;
			}
			if(i + 1 == arr.size())
				break;
			for(int j = 0; j < 3; j++) {
				if(dp[i][j] == -1)
					continue;
				int g = arr[i + 1] - j;
			}
		}
		if(arr.back()[0] == -1)
			return false;
		int a = arr.size() - 1, b = 0;
		l = i + 1;
	}
	for(int a : ope2)
		ope1.push_back(a);
	cout << ope1.size() << '\n';
	for(int i = 0; i < ope1.size(); i++)
		cout << ope1[i] << " \n"[i + 1 == ope1.size()];
	return true;
}
signed main() {
	int t;
	cin >> t;
	while(t--)
		if(!solve())
			cout << "-1\n";
}
