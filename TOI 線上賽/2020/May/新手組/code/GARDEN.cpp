/*
GARDEN
100/100
00:16:25
*/
#include <bits/stdc++.h>
using namespace std;

bool can[27];
int arr[27];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i], cnt += (arr[i]==1);
	for(int i = 1, cur = 0; i <= n; i++) {
		cur += (arr[i]==1);
		if(cur && cur < cnt)
			can[i] = true;
	}

	for(int i = 1; i <= n; i++) {
		if(arr[i] == 1)
			can[i] = false;
		if(arr[i] == 9) {
			for(int k = i-1; k <= i+1; k++)
				can[k] = false;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += can[i];
	cout << ans;

	return 0;
}
