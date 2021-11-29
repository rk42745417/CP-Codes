/*
0/100
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct point {
	ll x, y;
};

ll cross(point a, point b, point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

signed main() {
	int n;
	cin >> n;
	vector<point> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;
	int l = arr[0].y, r = arr[n - 1].y;
	sort(arr.begin(), arr.end(), [&] (auto a, auto b) { return a.x == b.x ? a.y < b.y : a.x < b.x; });
	vector<point> line;
	for(int i = 0; i < n; i++) {
		if(arr[i].y < l || arr[i].y > r)
			continue;
		while(line.size() > 1 && cross(line[line.size() - 2], line.back(), arr[i]) < 0)
			line.pop_back();
		line.push_back(arr[i]);
	}
	for(auto w : line)
		cout << w.x << ' ' << w.y << '\n';
}
