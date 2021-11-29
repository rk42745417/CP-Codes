// 100/100
#include <iostream>

using namespace std;

#define MAX_N 500

/********************************************/
#include <bits/stdc++.h>

int p;
const int N = 500;
bool dp[N][N][2]; // (cop pos, rob pos, whether rob takes turn)
int fr[N][N];
int cnt[N][N];
vector<int> edge[N];
int start(int n, bool a[N][N]) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j])
				edge[i].push_back(j);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cnt[i][j] = edge[j].size();
	queue<tuple<int, int, int>> bfs;
	for(int i = 0; i < n; i++) {
		dp[i][i][1] = 1;
		bfs.push({i, i, 1});
	}


	while(!bfs.empty()) {
		auto [a, b, c] = bfs.front();
		bfs.pop();

		if(c) {
			if(!dp[a][b][0]) {
				fr[a][b] = a;
				dp[a][b][0] = true;
				bfs.push({a, b, 0});
			}
			for(int k : edge[a]) {
				if(!dp[k][b][0]) {
					fr[k][b] = a;
					dp[k][b][0] = true;
					bfs.push({k, b, 0});
				}
			}
		}
		else {
			for(int k : edge[b]) {
				if(dp[a][k][1])
					continue;
				cnt[a][k]--;
				if(cnt[a][k] == 0) {
					dp[a][k][1] = true;
					bfs.push({a, k, 1});
				}
			}
		}
	}

	int x = 0, y = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			x ++, y += dp[i][j][0];
	bool ok = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ok &= dp[i][j][0];
		}
	}
	return ok ? 0 : -1;
}
int nextMove(int r) {
	return p = fr[p][r];
}
/*********************************************/

// don't modify the main function
int main() {
    int N;
    cin >> N;
    bool A[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    int P = start(N,A);
    cout << P << endl;
    int R;
    cin >> R;
    while (true) {
        if (P == R) break;
        P = nextMove(R);
        cout << P << endl;
        if (P == R) break;
        cin >> R;
    }
}
