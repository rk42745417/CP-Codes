/*
Verification
100/100
00:10:56
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
	string s, t;
	cin >> s;
	t = s;
	sort(t.begin(), t.end());
	int x =  (t.back()-'0')*(t.back()-'0')+(t[t.size()-2]-'0')*(t[t.size()-2]-'0');
	int w = 0;
	for(int i = s.size()-3; i < s.size(); i++)
		w*=10, w += s[i]-'0';
	if(x == w) {
		cout << "Good Morning!";
	}
	else
		cout << "SPY!";
}
