// 9/100
#include "hexagon.h"

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

int dx[] = {0, 0, 1, 1, 0, -1, -1}, dy[] = {1, 0, -1, -1, 0, 1};
int draw_territory(int N, int A, int B, vector<int> D, vector<int> L) {
	assert(N == 3);
	assert(L[0] == L[1] && L[1] == L[2]);
	ll g = L[0];
	ll x = (g + 1) * g / 2 % MOD;
	ll y = g * (g + 1) / 2;
	if(y % 3 == 0)
		y = y / 3 % MOD * (2 * g + 1) % MOD;
	else
		y = y % MOD * ((2 * g + 1) / 3) % MOD;
	return (x * A + (y - x + MOD) * B) % MOD;
}
