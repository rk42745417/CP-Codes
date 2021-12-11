// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EMiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EMiliaMyWife
	return 48763;
}();

const int N = 350;
ll dp[10][N][12][12]; // (current score, score needed next shot, score needed two next shot)

signed main() {
	int tc;
	cin >> tc;
	while(tc--) {
		memset(dp, 0, sizeof dp);
		dp[0][0][11][11] = 1;
		string s;
		int n;
		cin >> n >> s;
		vector<int> arr(n);
		for(int i = 0; i < n; i++)
			cin >> arr[i];

		auto mat = [&](const string &a, string b) {
			for(int i = 0; i < a.size(); i++)
				if(a[i] != '?' && a[i] != b[i])
					return false;
			return true;
		};

		for(int i = 0; i < n - 1; i++) {
			const int sc = arr[i];
			const string cur_round = string(1, s[2 * i]) + s[2 * i + 1];
			for(int j = 0; j < N; j++) {
				for(int k = 0; k <= 11; k++) {
					for(int w = 0; w <= 11; w++) {
						if(dp[i][j][k][w] == 0)
							continue;
						const ll cur = dp[i][j][k][w];
						for(int a = 0; a <= 10; a++) {
							if(k != 11 && k != a)
								continue;
							if(a == 10) {
								if(!mat(cur_round, string("x-")))
									continue;
								for(int t = 0; t <= 10; t++)
									for(int r = 0; r <= 10; r++)
										if((sc == -1 || sc == j + 10 + t + r) && (w == 11 || t == w))
											dp[i + 1][j + 10 + t + r][t][r] += cur;
								continue;
							}
							string x(1, a + '0');
							for(int b = 0; a + b <= 10; b++) {
								if(w != 11 && w != b)
									continue;
								if(a + b == 10) {
									if(!mat(cur_round, x + "/"))
										continue;
									for(int t = 0; t <= 10; t++)
										if(sc == -1 || sc == j + 10 + t)
											dp[i + 1][j + 10 + t][t][11] += cur;
									continue;
								}
								if(!mat(cur_round, x + char(b + '0')))
									continue;
								if(sc == -1 || j + a + b == sc)
									dp[i + 1][j + a + b][11][11] += cur;
							}
						}
					}
				}
			}
		}
		ll ans = 0;
		const string cur_round = s.substr(s.size() - 3, 3);
		const int sc = arr.back();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j <= 11; j++) {
				for(int k = 0; k <= 11; k++) {
					const ll cur = dp[n - 1][i][j][k];
					if(cur == 0)
						continue;
					for(int a = 0; a <= 10; a++) {
						if(j != 11 && j != a)
							continue;
						string t;
						if(a == 10)
							t += 'x';
						else
							t += char(a + '0');
						for(int b = 0; b <= 10; b++) {
							if(k != 11 && k != b)
								continue;
							if(a != 10 && b + a > 10)
								continue;
							if(a + b < 10) {
								if(!mat(cur_round, t + char(b + '0') + "-"))
									continue;
								if((sc == -1 || a + b + i == sc))
									ans += cur;
								continue;
							}
							if(a == 10) {
								if(b == 10)
									t.push_back('x');
								else
									t.push_back(b + '0');
							}
							else
								t.push_back('/');
							for(int c = 0; c <= 10; c++) {
								if(a == 10 && b != 10 && b + c > 10)
									continue;
								if(a == 10 && b != 10 && b + c == 10)
									t.push_back('/');
								else if(c == 10)
									t.push_back('x');
								else
									t.push_back(c + '0');
								if(mat(cur_round, t) && (sc == -1 || sc == i + a + b + c))
									ans += cur;
								t.pop_back();
							}
							t.pop_back();
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
}
