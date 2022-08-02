#include <bits/stdc++.h>
using namespace std;

#ifdef EMT
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"
#define print(x) emilia_mata_tenshi(#x, begin(x), end(x))
template<typename T, typename T2> ostream& operator<<(ostream &os, const pair<T, T2> &obj) {
    return os << '{' << obj.first << ',' << obj.second << '}';
}
template<class TupType, size_t... I> void lamy_kawaii(ostream& os, const TupType& _tup, index_sequence<I...>) {
    // source: https://stackoverflow.com/a/41171552
    os << '{';
    (..., (cerr << (I == 0? "" : ",") << get<I>(_tup)));
    os << '}';
}
template<class... T> ostream& operator<<(ostream &os, const tuple<T...>& _tup) {
    lamy_kawaii(os, _tup, make_index_sequence<sizeof...(T)>());
    return os;
}
template<typename T> void emilia_mata_tenshi(const char *s, T l, T r) {
    cerr << "\e[1;33m" << s << " = [";
    while(l != r) {
        cerr << *l;
        cerr << (++l == r ? ']' : ',');
    }
    cerr << "\e[0m\n";
}
#else
#define debug(x) 48763
#define print(x) 48763
#endif

template<typename T, typename T2> istream& operator>>(istream &is, pair<T, T2> &obj) {
    is >> obj.first >> obj.second;
    return is;
}
template<typename T> istream& operator>>(istream &is, vector<T> &obj) {
    for(auto &x : obj)
        is >> x;
    return is;
}

#define YN(x) ((x) ? "YES" : "NO")
#define Yn(x) ((x) ? "Yes" : "No")
#define yn(x) ((x) ? "yes" : "no")
#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
static int Lamy_is_cute = []() {
    EmiliaMyWife
    return 48763;
}();
#define X first
#define Y second
#define pii pair<int,int>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
#define pb push_back
#define sz(x) ((int)(x.size))
#define all(x) x.begin(),x.end()
/*--------------------------------------------------------------------------------------*/

const int N = 2e5 + 25;
struct disjoint_set {
    int sz[N], mn[N], pa[N];
    int fnd(int x) { return pa[x] == x ? x : x = fnd(pa[x]); }
    void uni(int a, int b) {
        if((a = fnd(a)) == (b = fnd(b)))
            return;
        if(sz[a] > sz[b])
            swap(a, b);
        sz[b] += sz[a];
        mn[b] = min(mn[b], mn[a]);
        pa[a] = b;
    }
    ll value(int p) {
        p = fnd(p);
        return 1LL * sz[p] * mn[p];
    }
} dsu;
signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<pair<int, int>> owo;
    cin >> arr;
    for(int i = 0; i < n; i++)
        owo.push_back({arr[i], i});
    sort(owo.begin(),owo.end());
    reverse(owo.begin(), owo.end());

    vector<bool> has(n);
    ll ans = 0, res = 0;
    for(const auto &[x, i] : owo) {
        dsu.sz[i] = 1;
        dsu.mn[i] = x;
        dsu.pa[i] = i;

        has[i] = true;
        if(i > 0 && has[i - 1]) {
            res -= dsu.value(i - 1);
            dsu.uni(i - 1, i);
        }
        if(i + 1 < n && has[i + 1]) {
            res -= dsu.value(i + 1);
            dsu.uni(i, i + 1);
        }
        res += dsu.value(i);
        ans = max(ans, res);
    }
    cout << ans << '\n';
}
