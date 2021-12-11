// 35/100
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

signed main() {
	int n;
	cin >> n;
	if(n <= 5000) {
		vector<bool> has(n), undo_ty(n);
		vector<int> undo(n), level(n);
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if(x > 0) {
				has[i] = true;
				undo[i] = x;
			}
			else {
				level[i] = -x;
				undo_ty[i] = true;
				has[i] = true;
				for(int j = i; ~j; j--) {
					if(has[j] && level[j] < level[i]) {
						undo[i] = j;
						break;
					}
				}
				int x = i;
				while(undo_ty[x]) {
					//cerr << x << '\n';
					x = undo[x];
					has[x] = !has[x];
				}
			}
			int g = -1;
			for(int j = i; ~j; j--)
				if(!undo_ty[j] && has[j])
					g = max(g, j);
			cout << (~g ? undo[g] : 0) << '\n';
		}
		return 0;
	}
	stack<int> has;
	has.push(0);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x < 0) {
			has.pop();
		}
		else
			has.push(x);
		cout << has.top() << '\n';
	}
}
