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

const int CONTI = 1, SINGLE = 2;
bool solve() {
	int n, m;
	cin >> n >> m;
	vector<int> stat(n + 2);
	vector<int> ope1, ope2;
	stat[0] = stat[n + 1] = CONTI;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		stat[x] = SINGLE;
	}
	for(int i = 1; i <= n; i++) {
		if(stat[i] && (stat[i - 1] || stat[i + 1]))
			stat[i] = CONTI;
	}
	for(int i = 1, l = 1; i <= n + 1; i++) {
		if(stat[i] != CONTI)
			continue;
		if(l == i) {
			l = i + 1;
			continue;
		}
		vector<int> arr, owo, split, init;
		for(int j = l, it = j; j <= i; j++) {
			if(j == i) {
				arr.push_back(j - it);
				owo.push_back((j + it) / 2);
				break;
			}
			if(stat[j] == SINGLE) {
				arr.push_back(j - it);
				split.push_back(j);
				owo.push_back((j + it) / 2);
				it = j + 1;
			}
		}
		if(arr.size() == 1)
			return false;
		int x = 0;
		for(int a : arr)
			x ^= (a & 1);
		if(x)
			return false;
		init = arr;
		//cout << "start\n";
		for(int i = 0; i + 1 < arr.size(); i++) {
			if(init[i] <= 2) {
				if(arr[i + 1] < arr[i])
					return false;
				while(arr[i]) {
					ope2.push_back(split[i]);
					arr[i]--;
					arr[i + 1]--;
				}
			}
			else {
				if(arr[i] & 1) {
					ope2.push_back(split[i]);
					arr[i]--;
					arr[i + 1]--;
				}
				if(init[i + 1] <= 2 && arr[i] >= 2 && arr[i + 1] % 2 == arr[i] % 2) {
					while(arr[i + 1]) {
						ope2.push_back(split[i]);
						arr[i]--;
						arr[i + 1]--;
					}
				}
				if(init[i] == arr[i]) {
					if(arr[i + 1] < 2)
						return false;
					ope2.push_back(split[i]);
					arr[i]--;
					arr[i + 1]--;
					ope2.push_back(split[i]);
					arr[i]--;
					arr[i + 1]--;
				}
			}
		}
		for(int i = 0; i < arr.size(); i++) {
			if(arr[i]) {
				if(arr[i] % 2 || init[i] <= 2 || arr[i] == init[i])
					return false;
				while(arr[i]) {
					ope1.push_back(owo[i]);
					arr[i] -= 2;
				}
			}
		}
		l = i + 1;
	}
	for(int a : ope2)
		ope1.push_back(a);
	cout << ope1.size() << '\n';
	for(int i = 0; i < ope1.size(); i++)
		cout << ope1[i] << " \n"[i + 1 == ope1.size()];
	return true;
}
signed main() {
	int t;
	cin >> t;
	while(t--)
		if(!solve())
			cout << "-1\n";
}
