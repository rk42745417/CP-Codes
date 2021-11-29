#include <bits/stdc++.h>
using namespace std;

signed main() {
     ios::sync_with_stdio(0); cin.tie(0);

     string a, b;
     int m;
     cin >> a >> b >> m;
     long long x = 0, y = 0;
     for(int i = a.size()-1, tmp = 1; ~i; i--) {
        x = (x+(a[i]-'0')*tmp)%m;
        tmp = tmp*10%m;
     }
     for(int i = b.size()-1, tmp = 1; ~i; i--) {
        y = (y+(b[i]-'0')*tmp)%m;
        tmp = tmp*10%m;
     }
     cout << (x*y)%m%2 << '\n';
}
