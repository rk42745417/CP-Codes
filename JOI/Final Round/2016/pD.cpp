// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(4e18) + ll(2e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return make_pair(a.first + b.first, a.second + b.second);
}

pair<int, int> get_direction(char c) {
	if(c == 'E')
		return {1, 0};
	if(c == 'W')
		return {-1, 0};
	if(c == 'N')
		return {0, 1};
	if(c == 'S')
		return {0, -1};
	return {0, 0};
}
pair<int, int> get_vector(const string &s) {
	pair<int, int> res = {0, 0};
	for(char c : s)
		res = res + get_direction(c);
	return res;
}
pair<int, int> simplify(string &s) {
	auto [a, b] = get_vector(s);
	if(a == 0) {
		for(char &c : s) {
			if(c == 'E')
				c = 'N';
			else if(c == 'W')
				c = 'S';
			else if(c == 'N')
				c = 'E';
			else // c == 'S'
				c = 'W';
		}
		swap(a, b);
	}
	if(a < 0) {
		for(char &c : s) {
			if(c == 'E')
				c = 'W';
			else if(c == 'W')
				c = 'E';
		}
		a = -a;
	}
	if(b < 0) {
		for(char &c : s) {
			if(c == 'S')
				c = 'N';
			else if(c == 'N')
				c = 'S';
		}
		b = -b;
	}
	return {a, b};
}
int get_ans(const string &s) {
	set<pair<int, int>> has;
	pair<int, int> res = {0, 0};
	has.insert(res);
	for(char c : s) {
		res = res + get_direction(c);
		has.insert(res);
	}
	int ans = 0;
	for(const auto &[a, b] : has)
		ans += has.count({a, b + 1}) && has.count({a + 1, b}) && has.count({a + 1, b + 1});
	return ans;
}

struct dat {
	int p, q, l, r;
	bool operator<(dat other) {
		auto a = make_pair(p, q), b = make_pair(other.p, other.q);
		if(a == b)
			return l < other.l;
		return a < b;
	}
	dat() { }
	dat(int a, int b, int c, int d): p(a), q(b), l(c), r(d) { }
};

signed main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	auto [a, b] = simplify(s);
	if(a == 0)
		return cout << get_ans(s) << '\n', 0;

	vector<dat> arr;
	pair<int, int> res = {0, 0};
	arr.push_back({0, 0, 0, 0});
	arr.push_back({a, b, -1, -1});

	for(char c : s) {
		res = res + get_direction(c);

		auto [x, y] = res;
		int w = (x > 0) ? x / a : (x - a + 1) / a;
		arr.push_back({x - a * w, y - b * w, w, w + k - 1});
		if(x - a * w == 0) {
			w--;
			arr.push_back({x - a * w, y - b * w, w, w + k - 1});
		}
	}
	sort(arr.begin(), arr.end());

	ll ans = 0;
	res = {-INF, -INF};
	for(const auto &[x, y, _, __] : arr) {
		if(make_pair(x, y) == res)
			continue;
		res = {x, y};

		pair<int, int> pos[4] = {res, res + make_pair(0, 1), res + make_pair(1, 0), res + make_pair(1, 1)};
		int it[4], mx[4] = {-INF, -INF, -INF, -INF};

		auto check = [&](int p, int id) {
			return p >= 0 && p < arr.size() && make_pair(arr[p].p, arr[p].q) == pos[id];
		};

		for(int i = 0; i < 4; i++)
			it[i] = lower_bound(arr.begin(), arr.end(), dat(pos[i].first, pos[i].second, -INF, -INF)) - arr.begin();

		auto update = [&](int val) {
			for(int i = 0; i < 4; i++) {
				while(check(it[i], i) && arr[it[i]].l <= val) {
					mx[i] = max(mx[i], arr[it[i]].r);
					it[i]++;
				}
			}
		};

		int prv = -INF;
		while(check(it[0], 0) || check(it[1], 1) || check(it[2], 2) || check(it[3], 3)) {
			int l = INF;
			for(int i = 0; i < 4; i++)
				if(check(it[i], i))
					l = min(l, arr[it[i]].l);
			l = max(prv, l);
			update(l);
			int r = INF;
			for(int i = 0; i < 4; i++)
				r = min(r, mx[i]);
			if(l <= r) {
				ans += (r - l + 1);
				prv = r + 1;
			}
		}
	}
	cout << ans << '\n';
}
