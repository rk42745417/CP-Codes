/*
 Detector
 100/100
*/
#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0}, dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n+2, vector<int>(m+2, -1));
	int a=0, b=0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> arr[i][j], b+=(arr[i][j]==1);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {			
			if(arr[i][j] == 5) {
				bool ok = true;
				for(int k = 0; k < 8; k++)
					if(arr[i+dx[k]][j+dy[k]] == arr[i][j])
						ok = false;
				if(ok)
					for(int k = 0; k < 8; k++)
						if(arr[i+dx[k]][j+dy[k]] == 1)
							arr[i+dx[k]][j+dy[k]] = 0;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(arr[i][j] == 1)
				b--, a++;
	cout << b << ' ' << a << '\n';

	return 0;
}
