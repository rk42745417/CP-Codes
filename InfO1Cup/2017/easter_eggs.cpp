// 100/100
#include <bits/stdc++.h>
#include "grader.h"
//#include "grader.cpp"
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const double EPS = 1e-9;

vector<vector<int>> edge;
vector<bool> can;
vector<bool> is;
int w;
vector<int> que;
void init(int n) {
	edge.clear();
	edge.resize(n + 1);
	can.clear();
	can.resize(n + 1, 1);
	is.clear();
	is.resize(n + 1);
	que.clear();
}

void dfs(int u, int p) {
	if(!w)
		return;
	que.push_back(u);
	is[u] = 1;
	if(can[u])
		w--;
	for(int v : edge[u])
		if(v != p)
			dfs(v, u);
}

int findEgg(int n, vector<pair<int, int>> edges) {
	init(n);

	for(const auto &[a, b] : edges)
		edge[a].push_back(b), edge[b].push_back(a);

	int has = n;
	while(has > 1) {
		int c = has / 2;
		w = has / 2;
		int x = 0;
		dfs(1, 1);

		if(!query(que)) {
			for(int a : que)
				can[a] = 0;
			has -= c;
		}
		else {
			has = c;
			for(int i = 1; i <= n; i++)
				if(!is[i])
					can[i] = 0;
		}
		for(int a : que)
			is[a] = 0;
		que.clear();
	}

	for(int i = 1; i <= n; i++)
		if(can[i])
			return i;
	assert(0);
	return 0;
}
