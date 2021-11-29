
#include <bits/stdc++.h>
using namespace std;


#define int long long
const int INF = 1e15;
const int N = 1e5+25;
bitset<N> vis;
vector<pair<int,int>> edge[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
    }
    priority_queue<pair<int,int>> pq;
    for(auto &a : edge[s])
        pq.push(a);
    int ans;
    if(pq.size())
        ans = pq.top().first;
    else
        ans = 0;
    vis[s] = 1;
    while(pq.size()) {
        auto a = pq.top();
        pq.pop();
        if(vis[a.second]) {
            ans = min(ans, pq.top().first);
            continue;
        }
        vis[a.second] = 1;
        if(a.second == t)
            break;
        for(auto &x : edge[a.second]) {
            pq.push(x);
        }
        ans = min(ans, pq.top().first);
    }
    if(!vis[t])
        ans = 0;
    cout << ans << '\n';
}
/*
6  7  1  6
1  2  5
1  3  1
2  4  4
2  5  3
3  5  9
4  6  2
5  6  8

5  5  1  5
1  2  2
1  3  8
2  3  6
4  2  1
4  5  5

4  5  3  4
1  3  2
3  2  2
3  4  5
4  1  6
2  4  4

*/
