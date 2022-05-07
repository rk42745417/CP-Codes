// 5/100
/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"
#define print(x) emilia_mata_tenshi(#x, begin(x), end(x))
template<typename T> void emilia_mata_tenshi(const char *s, T l, T r) {
	cerr << "\e[1;33m" << s << " = [";
	while(l != r) {
		cerr << *l;
		cerr << (++l == r ? ']' : ',');
	}
	cerr << "\e[0m\n";
}

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
static int Lamy_is_cute = []() {
	EmiliaMyWife
	return 48763;
}();
/*--------------------------------------------------------------------------------------*/

const int N = 1e6 + 1e3, O = N / 2;
int a[N], b[N];
signed main() {
	int m; ll l;
	cin >> m >> l;
	vector<ll> arr(m * 2 + 1);
	for(auto &x : arr)
		cin >> x;
	if(m > 100 || *max_element(arr.begin(), arr.end()) > 100)
		return 0;

	int *prv = a, *nxt = b;
	for(int i = 0; i < N; i++)
		prv[i] = -INF;
	prv[O] = 0;
	for(int i = 0; i < m; i++) {
		int c = m - i;
		vector<deque<int>> mx(c);
		for(int j = N - 1; ~j; j--) {
			int r = j % c;
			while(!mx[r].empty() && (mx[r].front() - j) / c > arr[i])
				mx[r].pop_front();
			while(!mx[r].empty() && prv[mx[r].back()] + (mx[r].back() - j) / c < prv[j])
				mx[r].pop_back();
			mx[r].push_back(j);
			nxt[j] = prv[mx[r].front()] + (mx[r].front() - j) / c;
		}
		swap(nxt, prv);
	}
	for(int i = m + 1; i < m * 2 + 1; i++) {
		int c = i - m;
		vector<deque<int>> mx(c);
		for(int j = 0; j < N; j++) {
			int r = j % c;
			while(!mx[r].empty() && (j - mx[r].front()) / c > arr[i])
				mx[r].pop_front();
			while(!mx[r].empty() && prv[mx[r].back()] + (j - mx[r].back()) / c < prv[j])
				mx[r].pop_back();
			mx[r].push_back(j);
			nxt[j] = prv[mx[r].front()] + (j - mx[r].front()) / c;
		}
		swap(nxt, prv);
	}

	if(l + O > N || l + O < 0 || prv[l + O] < 0)
		cout << "impossible\n";
	else
		cout << prv[l + O] + arr[m] << '\n';
}
