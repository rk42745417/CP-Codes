/*
JSON
0/100
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 65540;
vector<int> son[N];
int t = 1, it = 0;
string key[N], s, s2;
pair<int, int> val[N];
void build(int u) {
	val[u].first = it;
	if(s[it] != '{' && s[it] != '[') {
		int r;
		if(s[it] == '\"') {
			r = it + 1;
			while(s[r] != '\"')
				r++;
			val[u].second = r + 1;
		}
		else {
			r = it + 1;
			while(s[r] <= '9' && s[r] >= '0')
				r++;
			r--;
			val[u].second = r + 1;
		}
		it = r;
	}
	else if(s[it] == '{') {
		it++;
		while(s[it] != '}') {
			son[u].push_back(t);
			int r = it + 1;
			while(s[r] != '\"')
				r++;
			key[t] = s.substr(it, r - it + 1);
			it = r + 2;
			build(t++);
			it++;
			if(s[it] == ',')
				it++;
		}
		val[u].second = it+1;
	}
	else {//s[it] == '['
		it++;
		int c = 0;
		while(s[it] != ']') {
			son[u].push_back(t);
			key[t] = to_string(c++);
			build(t++);
			it ++;
			if(s[it] == ',')
				it++;
		}
		val[u].second = it+1;
	}
}
void debugdfs(int u) {
	cout << "cur at " << u << '\n';
	cout << "key: " << key[u] << '\n';
	cout << "val: " << s.substr(val[u].first, val[u].second - val[u].first) << '\n';
	cout << "size: " << son[u].size() << '\n';
	for(int v : son[u])
		debugdfs(v);
}
void dfs(int u) {
	if(it == s2.size()) {
		cout << s.substr(val[u].first, val[u].second - val[u].first) << '\n';
		return;
	}
	int r = it + 1;
	string nd;
	if(s2[r] == '\"') {
		r++;
		while(s2[r] != '\"')
			r++;
	}
	else {
		while(s2[r] <= '9' && s2[r] >= '0')
			r++;
		r--;
	}
	nd = s2.substr(it + 1, r - it);
	it = r + 2;
	for(int v : son[u]) {
		if(key[v] == nd)
			dfs(v);
	}
}

signed main() { ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	build(0);
	it = 3;
	cin >> s2;
	//debugdfs(0);
	dfs(0);
}
