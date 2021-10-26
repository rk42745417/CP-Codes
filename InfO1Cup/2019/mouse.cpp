// 34/100
#include "grader.h"
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;

//int query(vector<int>);

void solve(int n) {
	vector<int> arr(n);
	vector<bool> fixed(n);
	for(int i = 0; i < n; i++)
		arr[i] = i + 1;
	for(int i = 0; i < n; i++) {
		if(fixed[i])
			continue;
		int w = query(arr);
		if(w == n)
			return;
		bool ok = 0;

		int tot = 0, neg = 0;
		int a = -1, b = -1;

		for(int j = 0; j < n; j++) {
			if(i == j)
				continue;
			swap(arr[i], arr[j]);
			int x = query(arr);
			swap(arr[i], arr[j]);
			if(x == n)
				return;

			if(fixed[j]) {
				if(x - w == -2) {
					fixed[i] = true;
					ok = 1;
					break;
				}
				continue;
			}
			tot++;

			if(x - w == 2) {
				swap(arr[i], arr[j]);
				fixed[i] = fixed[j] = true;
				ok = 1;
				break;
			}
			if(x - w == 1) {
				if(a == -1)
					a = j;
				else if(b == -1)
					b = j;
				else
					assert(false);
			}
			if(x - w == -1) {
				neg++;
			}
			if(x - w == -2) {
				fixed[i] = fixed[j] = true;
				ok = 1;
				break;
			}
		}
		if(ok)
			continue;
		if(tot == neg)
			fixed[i] = true;
		assert(b != -1);
		swap(arr[i], arr[a]);
		swap(arr[i], arr[b]);
		int x = query(arr);
		if(x == n)
			return;
		if(x - w >= 2) {
			fixed[i] = fixed[a] = true;
			if(x - w == 3)
				fixed[b] = true;
		}
		else {
			swap(arr[i], arr[b]);
			swap(arr[i], arr[a]);
			swap(arr[i], arr[b]);
			swap(arr[i], arr[a]);
			fixed[i] = fixed[b] = true;
			if(x - w == 1)
				fixed[a] = true;
		}
		//cout << "owo " << a << ' ' << b << '\n';;
	}
	query(arr);
}

/*
vector<int> arr;
int query(vector<int> g) {
	int w = 0;
	for(int i = 0; i < g.size(); i++)
		w += arr[i] == g[i];
	cout << "query: ";
	for(int a : g)
		cout << a << ' ';
	cout << '\n';
	cout << "Answer: " << w << '\n';
	return w;
}
signed main() {
	int n;
	cin >> n;
	arr.resize(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	solve(n);
}
*/
