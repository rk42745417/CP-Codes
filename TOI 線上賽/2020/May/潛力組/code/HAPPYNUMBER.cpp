/*
HAPPYNUMBER
0/100
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, N = 1<<9;

int dp[10][1001][N][10];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for(int q = 1; q <= 9; q++) {
		dp[q][1][1<<(q-1)][q] = 1;
		for(int i = 1; i < 1000; i++) {
			for(int j = 0; j < N; j++) {
				for(int k = 1; k <= 9; k++) {
					if((j>>(k-1))&1^1)
						continue;
					for(int w = k-2; w <= k+2; w++) {
						if(w && w < 10) {
							dp[q][i+1][j|(1<<(w-1))][w] = (dp[q][i+1][j|(1<<(w-1))][w] + dp[q][i][j][k]) % MOD;
						}
					}
				}
			}
		}
	}

	int t;
	cin >> t;
	while(t--) {
		int n, q;
		cin >> n >> q;
		int ans = 0;
		for(int i = 1; i <= 9; i++) {
			ans = (ans + dp[q][n][N-1][i]) %MOD;
		}
		cout << ans << '\n';
	}

	return 0;
}
