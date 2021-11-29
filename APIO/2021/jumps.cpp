// 37/100
#include "jumps.h"

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

const int N = 2e5 + 25, LGN = 18;
int n, l[LGN][N], r[LGN][N];
vector<vector<int>> edge;
vector<int> dis;
void init(int N, std::vector<int> H) {
	n = N;
	edge.resize(n);
	dis.resize(n);
	vector<int> st;
	for(int &a : H)
		a = n - a + 1;
	for(int i = 0; i < n; i++) {
		while(!st.empty() && H[st.back()] < H[i]) {
			r[0][st.back()] = i;
			//edge[st.back()].push_back(i);
			st.pop_back();
		}
		if(!st.empty())
			r[0][i] = st.back();
			//edge[i].push_back(st.back());
		else
			l[0][i] = -1;
		st.push_back(i);
	}
	for(int a : st)
		r[0][a] = INF;

	//debug("here");
	for(int i = 1; i < LGN; i++) {
		for(int j = 0; j < n; j++) {
			if(l[i - 1][j] == -1)
				l[i][j] = -1;
			else
				l[i][j] = l[i - 1][l[i - 1][j]];
			if(r[i - 1][j] == INF)
				r[i][j] = INF;
			else
				r[i][j] = r[i - 1][r[i - 1][j]];
		}
	}
}

int minimum_jumps(int A, int B, int C, int D) {
	swap(A, C);
	swap(B, D);
	assert(A == B);
	int st = A, w = INF, g = 0;
	
	for(int i = LGN - 1; ~i; i--)
		if(l[i][st] > D)
			g += 1 << i, st = l[i][st];
	if(C <= l[0][st] && l[0][st] <= D)
		w = min(w, g + 1);

	g = 1;
	st = A;
	for(int i = LGN - 1; ~i; i--)
		if(r[i][st] != INF && l[0][r[i][st]] > D)
			g += 1 << i, st = r[i][st];
	if(r[0][st] != INF && C <= l[0][r[0][st]] && l[0][r[0][st]] <= D)
		w = min(w, g + 1);

	return (w == INF ? -1 : w);
}
