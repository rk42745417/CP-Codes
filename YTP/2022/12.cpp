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

signed main() {
    int n;
    cin >> n;
    vector<pair<ld, ld>> arr(n);
    for(auto &[a, b] : arr)
        cin >> a >> b;

    if(n <= 3) {
        while(arr.size() <= 2)
            arr.push_back({0, 0});
        for(int i = 0; i < n; i++) {
            cout << arr[i].first << ' ' << arr[i].second << " 0\n";
        }
        for(int i = 0; i < 3 - n; i++)
            cout << "0 0 0\n";
        for(int i = 0; i < n; i++)
            cout << i + 1;
        cout << '\n';
        return 0;
    }

    auto [x1, y1] = arr[0];
    auto [x2, y2] = arr[1];
    auto [x3, y3] = arr[2];

    ld d1 = x2 * x2 + y2 * y2 - (x1 * x1 + y1 * y1);
    ld d2 = (x3 * x3 + y3 * y3) - (x2 * x2 + y2 * y2);
    ld k = 2 * ((y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2));

    ld x = ((y3 - y2) * d1 - (y2 - y1) * d2) / k;
    ld y = ((x2 - x1) * d2 - (x3 - x2) * d1) / k;
    cout << fixed << setprecision(15) << x << ' ' << y << ' ' << sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)) << '\n';
    cout << "0 0 0\n";
    cout << "0 0 0\n";
    cout << string(n, '1') << '\n';
}
