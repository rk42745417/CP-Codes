/*
LOTTERY
100/100
00:10:21
*/
#include<bits/stdc++.h>
using namespace std;

int a[5], b[5];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int x, y, c;
	cin >> x >> y >> c;
	for(int i = 0; i < 5; i++)
		cin >> a[i];
	for(int i = 0; i < 5; i++)
		cin >> b[i];
	long long ans = 0;
	int owo = 2;
	for(int i = 0; i < 5; i++) {
		if(a[i] == x || a[i]==y)
			ans += b[i];
		if(a[i] == c)
			ans -= b[i], owo = 1;
	}
	cout << max(ans, 0LL)*owo;

	return 0;
}
