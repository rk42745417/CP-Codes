// 100/100
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
const ll LINF     = 2e18;
const int MOD     = 1e9+7;
static int Lamy_is_cute = []() {
	EmiliaMyWife
	return 48763;
}();
/*--------------------------------------------------------------------------------------*/

const int M = 9e4 + 25;
vector<ll> cal(vector<ll> arr) {
	vector<ll> prv(M * 2 + 1, LINF), cur(M * 2 + 1);
	prv[M] = 0;
	int m = arr.size() / 2;
	for(int i = 0; i < m; i++) {
		if(!arr[i])
			continue;
		ll c = m - i;
		vector<deque<int>> mx(c);
		for(int j = M * 2; ~j; j--) {
			auto &owo = mx[j % c];
			while(!owo.empty() && (owo.front() - j) / c > arr[i])
				owo.pop_front();
			while(!owo.empty() && prv[owo.back()] + (owo.back() - j) / c >= prv[j])
				owo.pop_back();
			owo.push_back(j);
			cur[j] = prv[owo.front()] + (owo.front() - j) / c;
		}
		swap(cur, prv);
	}
	for(int i = m + 1; i <= m * 2; i++) {
		if(!arr[i])
			continue;
		ll c = i - m;
		vector<deque<int>> mx(c);
		for(int j = 0; j <= M * 2; j++) {
			auto &owo = mx[j % c];
			while(!owo.empty() && (j - owo.front()) / c > arr[i])
				owo.pop_front();
			while(!owo.empty() && prv[owo.back()] + (j - owo.back()) / c >= prv[j])
				owo.pop_back();
			owo.push_back(j);
			cur[j] = prv[owo.front()] + (j - owo.front()) / c;
		}
		swap(cur, prv);
	}
	return prv;
}
vector<ll> cal2(vector<ll> arr) {
	vector<ll> prv(M * 2 + 1, -LINF), cur(M * 2 + 1);
	prv[M] = 0;
	int m = arr.size() / 2;
	for(int i = 0; i < m; i++) {
		if(!arr[i])
			continue;
		ll c = m - i;
		vector<deque<int>> mx(c);
		for(int j = M * 2; ~j; j--) {
			auto &owo = mx[j % c];
			while(!owo.empty() && (owo.front() - j) / c > arr[i])
				owo.pop_front();
			while(!owo.empty() && prv[owo.back()] + (owo.back() - j) / c <= prv[j])
				owo.pop_back();
			owo.push_back(j);
			cur[j] = prv[owo.front()] + (owo.front() - j) / c;
		}
		swap(cur, prv);
	}
	for(int i = m + 1; i <= m * 2; i++) {
		if(!arr[i])
			continue;
		ll c = i - m;
		vector<deque<int>> mx(c);
		for(int j = 0; j <= M * 2; j++) {
			auto &owo = mx[j % c];
			while(!owo.empty() && (j - owo.front()) / c > arr[i])
				owo.pop_front();
			while(!owo.empty() && prv[owo.back()] + (j - owo.back()) / c <= prv[j])
				owo.pop_back();
			owo.push_back(j);
			cur[j] = prv[owo.front()] + (j - owo.front()) / c;
		}
		swap(cur, prv);
	}
	return prv;
}
signed main() {
	int m;
	ll l;
	cin >> m >> l;

	ll tot = 0;
	vector<ll> has(m * 2 + 1), can(m * 2 + 1);
	for(int i = 0; i < m * 2 + 1; i++) {
		cin >> can[i];
		tot += can[i] * (i - m);
	}
	swap(can[m], has[m]);
	ll cur = 0;
	if(tot < l) {
		l = -l;
		for(int i = 0; i < m; i++)
			swap(can[i], can[m * 2 - i]);
		tot = -tot;
	}

	for(int i = 0; i < m; i++) {
		cur += can[i] * (i - m);
		swap(has[i], can[i]);
	}
	for(int i = m + 1; i <= m * 2; i++) {
		ll g = min(can[i], (l - cur) / (i - m));
		cur += (i - m) * g;
		has[i] = g;
		can[i] -= g;
	}

	ll owo = l - cur;
	auto dp1 = cal(has), dp2 = cal2(can);
	ll ans = -LINF;
	ll res = 0;
	for(ll a : has)
		res += a;

	for(int i = 0; i + owo < dp1.size(); i++) {
		ans = max(ans, res - dp1[i] + dp2[i + owo]);
	}
	if(ans < 0)
		cout << "impossible\n";
	else
		cout << ans << '\n';
}
