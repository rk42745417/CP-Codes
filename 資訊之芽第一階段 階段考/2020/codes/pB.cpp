/*
pB
60/100
14:46:09
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		vector<int> arr(n), brr(n);
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		for(int i = 0; i < n; i++)
			cin >> brr[i];

		deque<int> line;
		set<int> mx;
		int it = 0, ans = 1;
		for(int i = 0; i < n; i++) {
			//cout << line.size() << ' ' << it << '\n';
			while(line.size() && !mx.count(line.back()))
				line.pop_back();
			while(line.size() && !mx.count(line.front()))
				line.pop_front();

			if(line.size()) {
				if(x && line.front() == brr[i]) {
					mx.erase(line.front());
					line.pop_front();
					x--;
					continue;
				}
				if(y && line.back() == brr[i]) {
					mx.erase(line.back());
					line.pop_back();
					y--;
					continue;
				}
			}

			if(z && mx.size() && *mx.rbegin() == brr[i]) {
				mx.erase(brr[i]);
				z--;
				continue;
			}

			bool can = 0;
			while(it < n) {
				mx.insert(arr[it]);
				line.push_back(arr[it]);
				it++;
				//cout << line.back() << ' ' << brr[i] << ' ' << *mx.rbegin() << '\n';
				if(line.back() == brr[i]) {
					if(y) {
						line.pop_back();
						mx.erase(arr[it-1]);
						can = 1;
						y--;
						break;
					}
					else if(x && line.size() == 1) {
						line.pop_front();
						mx.erase(arr[it-1]);
						can = 1;
						x--;
						break;
					}
					else if(z && *mx.rbegin() == arr[it-1]) {
						line.pop_back();
						mx.erase(arr[it-1]);
						can = 1;
						z--;
						break;
					}
				}
			}
			ans &= can;
		}
		cout << (ans?"Yes":"No") << '\n';
	}
}
/*
5
4  4  0  0
1  2  3  4
1  2  3  4
3  0  3  0
3  2  1
1  3  2
5  0  0  5
5  1  3  4  2
5  4  3  1  2
6  1  5  0
3  6  1  5  2  4
6  5  3  1  4  2
8  1  3  4
4  8  7  3  6  2  5  1
3  5  6  1  8  2  4  7

*/
