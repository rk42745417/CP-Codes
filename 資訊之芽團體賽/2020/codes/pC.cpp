#include <bits/stdc++.h>
using namespace std;

signed main() {
     ios::sync_with_stdio(0); cin.tie(0);

     const int MODS[5] = {1e9+7, 1e5+7, 1e6+7, 1e7+7, 1e8+7};
     int t=1;
     cin >> t;
     string s;
     getline(cin, s);
     while(t--) {
        long long x = 0, y = 0, z = 0, tmp = 0;
        long long x[5] = {0}, y[5] = {0}, z[5] = {0};
        char w;
        //string s;
        //getline(cin, s);
        getline(cin, s, 'X');
        for(char &w : s) {
            for(int i = 0; i < 5; i++)
                x[i] = (x[i]*10 + w-'0')%MODS[i];
        }
        //cout << s << '\n';
        getline(cin, s, '=');
        for(char &w : s) {
            for(int i  = 0; i < 5; i++)
                y[i] = (y[i]*10 + w-'0')%MODS[i];
        }
        //cout << s << '\n';
        getline(cin, s);
        //cout << s << '\n';
        for(char &w : s) {
            tmp = (tmp*10)%MOD;
            if(w=='?')
                tmp = 1, w = '0';
            for(int i = 0; i < 5; i++)
                z[i] = (z[i]*10 + w-'0')%MODS[i];
        }
        //cout << x << ' ' << y << ' ' << tmp << '\n';
        int ans;
        for(int j = 0; j < 10; j++) {
            int w = 1;
            for(int i = 0; i < 5; i ++) {
                long long a = (z[i]+i*tmp)%MODS[i];
                if(x[i]*y[i]%MODS[i] != a) {
                    q = false;
                    break;
                }
            }
            if(w) {
                ans = j;
                break;
            }
        }
        cout << ans << '\n';
     }
}
/*
3
2X3=?
111X111=123?1
7X143=?001

*/
