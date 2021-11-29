/*
Slime
100/100
00:06:10
*/
#include <bits/stdc++.h>
using namespace std;
signed main() {
	int n, t;
	cin >> n >> t;
	int g = __gcd(n, t);
	n /= g; t /= g;
	cout << __lg(n+t);
}
