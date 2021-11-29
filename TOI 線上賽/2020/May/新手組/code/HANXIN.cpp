/*
HANXIN
100/100
00:04:06
*/
#include <bits/stdc++.h>
using namespace std;

int a[3], b[3];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for(int i = 0; i < 3; i++)
		cin >> a[i] >> b[i];
	int ans = 1;
	while(true) {
		bool check = true;
		for(int i = 0; i < 3; i++)
			check &= (ans%a[i] == b[i]);
		if(check)
			break;
		ans++;
	}
	cout << ans;

	return 0;
}
