/*
Treasure
100/100
00:19:31
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

bool solve(int now, int a, int b, int c) {
	if(now == arr.size())
		return (a==b && b==c);
	return (solve(now+1, a+arr[now], b, c) | solve(now+1, a, b+arr[now], c) | solve(now+1, a, b, c+arr[now]));
}

signed main() {
	int n;
	cin >> n;
	arr.resize(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << (solve(0, 0, 0, 0)?"YES":"NO");
}
