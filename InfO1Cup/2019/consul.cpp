// 100/100
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

void solve(int n) {
	if(n <= 50) {
		map<int, int> cnt;
		for(int i = 0; i < n; i++) {
			cnt[kth(i + 1)]++;
		}
		for(const auto &[a, b] : cnt)
			if(b > n / 3)
				return say_answer(a), void();
		say_answer(-1);
		return;
	}
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		arr[i] = i + 1;
	shuffle(arr.begin(), arr.end(), mt19937(time(0)));
	set<int> has;
	int tmp = 0;
	for(int a : arr) {
		int x = kth(a);
		tmp++;
		if(tmp == 60)
			break;
		if(has.count(x))
			continue;
		has.insert(x);
		int w = cnt(x);
		tmp++;
		if(w > n / 3) {
			say_answer(x);
			return;
		}
		if(tmp == 60)
			break;
	}
	say_answer(-1);
}
