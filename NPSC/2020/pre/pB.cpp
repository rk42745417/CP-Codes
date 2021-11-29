#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define YukinonMyWife   ios::sync_with_stdio(0); cin.tie(NULL);
#define size(v)         (long long)(v).size()
#define mem(whr, stf)   memset(whr, stf, sizeof(whr));
typedef int64_t   ll;
typedef uint64_t ull;
const double EPS   =        1e-8;
const  int   INF   =      0x3F3F3F3F;
const   ll   LINF  =  0x3F3F3F3F3F3F3F3F;
const  int   MOD   =        1e9+7;
const  int   dx[4] = {  1, -1,  0,  0  };
const  int   dy[4] = {  0,  0,  1, -1  };


#define int ll
#define endl '\n'
#define V vector
#define pb push_back
#define pii pair<int, int> 
#define x first
#define y second


int arr[200000];
__int128 ans = 0;


signed main() {
  YukinonMyWife
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    ans += arr[i] * (n - 2 * i - 1);
  }

  if (ans < 0) ans *= -1;

  int pr = ans;

  cout << pr << endl;
  
  return 0;
}
