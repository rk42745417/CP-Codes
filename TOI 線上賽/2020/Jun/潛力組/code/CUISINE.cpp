/*
 Cuisine
 100/100
*/
#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const int N = 2e5+25;
ll bit[N];
int a, n;
void mod(int pos, int val) {
	for(; pos < N; pos+=pos&-pos)
		bit[pos] += val;
}
ll que(int pos) {
	ll res = 0;
	for(; pos; pos-=pos&-pos)
		res += bit[pos];
	return res;
}
int solve() {
	int L = 0, ans = 0;
	while(L < n) {
		//cerr << L << ' ' << n << '\n';
		ans++;
		if(que(n)-que(L) <= a)
			break;
		int l = L+1, r = n;
		while(l < r) {
			int m = (l+r)/2;
			if(que(m)-que(L) <= a)
				l = m+1;
			else
				r = m;
		}
		L = l-1;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> n >> q >> a;
	for(int i = 1, a; i <= n; i++)
		cin >> a, mod(i, a);
	while(q--) {
		int c, i, d;
		cin >> c;
		if(c) {
			cin >> i >> d;
			if(c==2)
				d *= -1;
			mod(i, d);
		}
		else
			cout << solve() << '\n';
	}

	return 0;
}
