
#include <bits/stdc++.h>
using namespace std;


#define int long long
const int INF = 1e15;
int n, tot;
vector<vector<pair<int,int>>> edge;
vector<int> ans;
vector<int> sum;
vector<int>   v;

void dfs1(int now, int pa) {
    sum[now] += ans[now];
    for(auto &a : edge[now]) {
        if(pa==a.first)
            continue;
        dfs1(a.first, now);
        sum[now] += sum[a.first];
        v[now] += v[a.first]+(sum[a.first])*a.second;
    }
}
void dfs2(int now, int pa) {
    for(auto &a : edge[now]) {
        if(pa == a.first)
            continue;
        v[a.first] += v[now]-v[a.first]+(tot-sum[a.first]*2)*a.second;
        dfs2(a.first, now);
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    edge.resize(n+1);
    ans.resize(n+1);
    sum.resize(n+1);
    v.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> ans[i], tot+=ans[i];
    for(int i = 1, a, b, c; i <= n-1; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    dfs1(1, 1);
    dfs2(1, 1);
    int mx = 1e18;
    for(int i = 1; i <= n; i++)
        mx = min(mx, v[i]);
    cout << mx << '\n';
}
/*
4
5
3
2
4
4 3 3
4 2 4
2 1 4

*/
