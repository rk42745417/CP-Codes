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
const double EPS = 1e-8;
const ll LINF = ll(2e18) + ll(1e15);
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	vector<int> arr;
	{
		int x;
		while(cin >> x, x)
			arr.push_back(x);
	}
	int n;
	cin >> n;
	while(n--) {
		vector<int> tmp = arr;
		for(int i = 0; i < arr.size(); i++) {
			if(i == 0)
				tmp[i + 1] += arr[i] * 10 / 100 * (arr[i] > arr[i + 1]);
			else if(i + 1 == arr.size())
				tmp[i - 1] += arr[i] * 10 / 100 * (arr[i] > arr[i - 1]);
			else
				for(int k = i - 1; k <= i + 1; k += 2)
					tmp[k] += arr[i] * 5 / 100 * (arr[i] > arr[k]);
		}
		arr = tmp;
	}
	for(int a : arr)
		cout << a << ' ';
	cout << '\n';
}
