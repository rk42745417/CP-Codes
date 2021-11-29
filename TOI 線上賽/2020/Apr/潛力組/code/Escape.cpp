/*
Escape
100/100
01:30:00
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,bool>>> edge;
vector<int> cnt;

int toInt(const string &s) {
	int res = 0;
	for(int i = 0; i < s.size(); i++)
		res *= 10, res += s[i]-'0';
	//cerr << res << '\n';
	return res;
}

bool dfs(int now, int stat) {
	if(~cnt[now])
		return (stat==cnt[now]);
	cnt[now] = stat;
	bool res = true;
	for(auto &a: edge[now]) {
		res &= dfs(a.first, stat^a.second);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, t;
	cin >> n >> t;
	edge.resize(2*n);
	cnt.resize(2*n, -1);
	string x, y, z;
	for(int i = 0; i < t; i++) {
		cin >> x >> y >> z;
		int a = toInt(x.substr(0, x.size()-1))-1, b = (x[1]=='R'), c = toInt(y.substr(0, y.size()-1))-1, d = (y[1]=='R');
		edge[2*a+b].push_back({2*c+d, (z[0]=='D')});
		edge[2*c+d].push_back({2*a+b, (z[0]=='D')});
	}
	for(int i = 0; i < n; i++) {
		edge[2*i].push_back({2*i+1, 1});
		edge[2*i+1].push_back({2*i, 1});
	}
	bool res = true;
	for(int i = 0; i < n*2; i++) {
		if(cnt[i] < 0)
			res &= dfs(i, 0);
	}
	cout << (res?"Easy Peasy":"Impossible");
}
