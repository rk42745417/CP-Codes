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

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*--------------------------------------------------------------------------------------*/

const int N = 1025;
bool has[N * 3][N * 3];

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int ans;

inline bool ok(int x, int y) { return x >= 0 && x < N * 3 && y >= 0 && y < N * 3; }

pair<int, int> get(int x, int y) {
	vector<pair<int, int>> no;
	for(int i = 0; i < 4; i++)
		if(ok(x + dx[i], y + dy[i]) && !has[x + dx[i]][y + dy[i]])
			no.push_back({x + dx[i], y + dy[i]});
	if(no.size() == 1)
		return no.back();
	return make_pair(-1, -1);
}

void add(int x, int y) {
	if(has[x][y])
		return;
	//cout << "at " << x << ' ' << y << '\n';
	has[x][y] = 1;
	ans++;

	auto w = get(x, y);
	if(~w.first)
		add(w.first, w.second);
	for(int i = 0; i < 4; i++) {
		if(!ok(x + dx[i], y + dy[i]) || !has[x + dx[i]][y + dy[i]])
			continue;
		auto w = get(x + dx[i], y + dy[i]);
		if(~w.first)
			add(w.first, w.second);
	}
}
/*
void upd(int x, int y) {
	//cout << "checking " << x << ' ' << y << '\n';
	vector<pair<int, int>> no;
	for(int i = 0; i < 4; i++)
		if(!ok(x + dx[i], y + dy[i]) || !has[x + dx[i]][y + dy[i]])
			no.push_back({x + dx[i], y + dy[i]});
	if(no.size() == 1) {
		ans++;
		auto [a, b] = no.front();
		if(!ok(a, b))
			return;
		has[a][b] = 1;
		//cout << "adding " << a << ' ' << b << '\n';
		upd(a, b);
		for(int i = 0; i < 4; i++)
			if(ok(a + dx[i], b + dy[i]))
				upd(a + dx[i], b + dy[i]);
	}
}
*/
set<pair<int, int>> inp;

signed main() { EmiliaMyWife
	int q;
	cin >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		x += N, y += N;
		
		ans--;
		add(x, y);
		cout << ans << '\n';
	}
}
