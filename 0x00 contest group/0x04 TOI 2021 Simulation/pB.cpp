#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;

signed main() { EMT
	int n;
	cin >> n;
	vector<string> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(arr[i][j] != arr[j][i])
				return cout << "-1\n", 0;
	vector<vector<bool>> inv(n, vector<bool>(n));
	int ans = 0;
	for(int k = n - 1; ~k; k--) {
		for(int i = 0; i + k < n; i++) {
			int j = i + k;
			if(arr[i][j] == '1' ^ inv[i][j]) {
				ans++;
				inv[i][j] = inv[i][j] ^ 1;
			}
			if(k) {
				inv[i + 1][j] = inv[i][j] ^ inv[i + 1][j];
				inv[i][j - 1] = inv[i][j] ^ inv[i][j - 1];
			}
			if(k > 1)
				inv[i + 1][j - 1] = inv[i][j] ^ inv[i + 1][j - 1];
		}
	}
	cout << ans << '\n';
}
