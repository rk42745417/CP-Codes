// 15/100
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
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

vector<int> findSequence(int n) {
	assert(n <= 10);
	int g = n * 3 / 4 + 1, cnt = 0;
	///*
	for(int i = 1; i <= n; i++) {
		if(!isSubsequence(vector<int>(i, 0))) {
			cnt = n - i + 1;
			break;
		}
		if(!isSubsequence(vector<int>(i, 1))) {
			cnt = i - 1;
			break;
		}
	}
	//*/
	for(int i = 0; i < (1 << n); i++) {
		vector<int> arr(n);
		if(__builtin_popcount(i) != cnt)
			continue;
		for(int j = 0; j < n; j++)
			if(i >> j & 1)
				arr[j]++;
		bool ok = 1;
		for(int j = 0; j + g <= n; j++) {
			vector<int> w(g);
			for(int k = 0; k < g; k++)
				w[k] = arr[j + k];
			ok &= isSubsequence(w);
		}
		///*
		if(n <= 8) {
			for(int j = 0; j < (1 << n); j++) {
				if(__builtin_popcount(j) > g)
					continue;
				vector<int> w;
				for(int k = 0; k < n; k++)
					if(j >> k & 1)
						w.push_back(arr[k]);
				ok &= isSubsequence(w);
			}
		}
		//*/
		if(ok)
			return arr;
	}
	assert(false);
}
