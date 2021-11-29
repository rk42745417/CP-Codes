#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    #define int long long
    const int INF = 1e15;

    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> arr(n+1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i].first;
    for(int i = 1; i <= n; i++)
        cin >> arr[i].second;
    sort(arr.begin(), arr.end());
    arr[0].first = -INF;
    vector<int> dp(n+1);
    for(int i = 1, it = 0; i <= n; i++) {
        while(arr[i].first-arr[it].first>=x)
            it++;
        dp[i] = max(dp[i-1], dp[it-1]+arr[i].second);
    }
    cout << dp[n] << '\n';
}
/*
10  10
6  16  2  16  15  1  11  16  5  13
2  1  3  1  8  7  9  7  2  7

13  12
15  22  4  22  10  14  9  1  21  18  17  26  22
8  3  8  8  19  6  11  1  2  9  3  17  9

*/
