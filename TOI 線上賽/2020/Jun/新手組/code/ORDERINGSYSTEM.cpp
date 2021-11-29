/*
 OrderingSystem
 100/100
*/
#include <bits/stdc++.h>
using namespace std;

string item[2][10] = {
	{"Medium Wac", "WChicken Nugget", "Geez Burger", "ButtMilk Crispy Chicken", "Plastic Toy"},
	{"German Fries", "Durian Slices", "WcFurry", "Chocolate Sunday"}
};
int cost[2][10] = {
	{4, 8, 7, 6, 3},
	{2, 3, 5, 7}
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, tot=0;
	while(cin >> n, n) {
		int a;
		cin >> a;
		n--;
		cout << item[n][a-1] << ' ' << cost[n][a-1] << '\n';
		tot += cost[n][a-1];
	}
	cout << "Total: " << tot;
}
