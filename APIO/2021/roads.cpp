// 36/100
#include "roads.h"
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
/*--------------------------------------------------------------------------------------*/

vector<long long> ans;
vector<vector<pair<int, int>>> edge;
vector<int> dfs(int u, int p) {
	int deg  = edge[u].size();
	
	vector<int> cost(deg, 1);
	for(const auto &[v, c] : edge[u]) {
		if(v == p)
			continue;
		auto x = dfs(v, u);
		for(int a : x) {
			if(a >= 0)
				cost[min(deg - 1, a)]--;
			else
				cost[min(deg - 1, -a)]++;
		}
	}
	for(int i = deg - 2; ~i; i--)
		cost[i] += cost[i + 1];
	vector<int> x;
	bool cur = 0;
	for(int i = deg - 1; ~i; i--) {
		if(cost[i] > 0) {
			if(!cur)
				x.push_back(i);
			cur = 1;
		}
		else {
			if(cur)
				x.push_back(-i);
			cur = 0;
		}
	}

	for(int i = 0; i < deg; i++)
		ans[i] += cost[i];
	return x;
}
vector<long long> minimum_closure_costs(int N, vector<int> U, vector<int> V, vector<int> W) {
	int n = N;
	edge.resize(n);
	ans.resize(n);
	for(int i = 0; i < N - 1; i++)
		edge[U[i]].push_back({V[i], W[i]}), edge[V[i]].push_back({U[i], W[i]});
	dfs(0, 0);
	return ans;
}
