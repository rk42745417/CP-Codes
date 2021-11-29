/*
Homework
100/100
00:03:50
*/
#include <bits/stdc++.h>
using namespace std;
signed main() {
	int n, r;
	cin >> n >> r;
	if(n==r)
		r -= 3;
	cout << min(r, n-r) << "+" << max(r, n-r) << "=" << n;
}
