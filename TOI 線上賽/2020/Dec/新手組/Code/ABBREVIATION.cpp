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

signed main() { EmiliaMyWife
	map<string, char> owo;
	owo["for"] = '4';
	owo["to"] = '2';
	owo["and"] = 'n';
	owo["you"] = 'u';
	string s;
	while(cin >> s) {
		string t = s;
		for(char &c : t)
			c = tolower(c);
		if(owo.count(t))
			cout << owo[t];
		else
			cout << char(toupper(s[0]));
	}
}
