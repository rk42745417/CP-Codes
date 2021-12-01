// 100/100
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

int t = 1;

/*
 * arr: The constraints
 * can_have_zero: Can solve() return 0?
 */
ll solve(vector<int> arr, bool can_have_zero) {
	if(!accumulate(arr.begin(), arr.end(), 0))
		return !can_have_zero;
	if(arr.size() == 1) {
		if(arr[0] == 1)
			return 10;
		int w = 0;
		for(int i = 1; i < 10; i++) {
			if(arr[0] >> i & 1) {
				w = w * 10 + i;
			}
			if(w > 0 && (arr[0] & 1)) {
				w *= 10;
				arr[0] ^= 1;
			}
		}
		return w;
	}
	ll res = LINF;
	for(int i = 0; i < 10; i++) {
		vector<int> brr;
		bool r = can_have_zero || i; // If i != 0, then solve() will not return zero. So the next solve can return zero.
		for(int j = 0, cur = 0; j < arr.size(); j++) {
			int w = (i + j) % 10;
			int k = arr[j];
			if(k >> w & 1) {
				k ^= 1 << w;
				if(w == 0 && brr.empty()) // IF 0 is used to satisfy the constraint, and it is at the first term, then the next solve() can not return zero.
					r = 0;
			}
			cur |= k; // Merge the constraints

			if(w == 9 || j + 1 == arr.size()) {
				brr.push_back(cur);
				cur = 0;
			}
		}
		if(i == 9 && arr.size() == 2 && arr == brr) {
			continue; // Prevent infinite loop
		}
		res = min(res, solve(brr, r) * 10 + i);
	}
	return res;
}

signed main() {
	int k;
	cin >> k;
	vector<int> arr(k);
	for(int i = 0; i < k; i++)
		cin >> arr[i], arr[i] = 1 << arr[i];
	cout << solve(arr, 0) << '\n';
}
