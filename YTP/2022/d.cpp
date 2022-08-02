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
#define pii pair<ll, ll>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
#define pb push_back
#define sz(x) ((int)(x.size))
#define all(x) x.begin(),x.end()
/*--------------------------------------------------------------------------------------*/
#define int ll
pair<pii,pii> ar[1005];
int n,m;

signed main() {
    cin>>n>>m;
    F(n)cin>>ar[i].X.X>>ar[i].X.Y>>ar[i].Y.X>>ar[i].Y.Y;
    Fi(j,m){
        __int128 x,y,r,ans=0;
        {
            int a, b, c;
            cin >> a >> b >> c;
            x = a;
            y = b;
            r = c;
        }
        F(n){
            bool tag=0;
            __int128 l1=ar[i].X.X-x,l2=ar[i].X.Y-y,l3=ar[i].Y.X-x,l4=ar[i].Y.Y-y;
            l1=l1*l1,l2=l2*l2,l3=l3*l3,l4=l4*l4;
            tag=(l1<=r*r-l2||l1<=r*r-l4||l3<=r*r-l2||l3<=r*r-l4);
            if(ar[i].X.X<=x&&ar[i].Y.X>=x&&(l2<=r*r||l4<=r*r))tag=1;
            if(ar[i].X.Y<=y&&ar[i].Y.Y>=y&&(l1<=r*r||l3<=r*r))tag=1;
            if(ar[i].X.X<=x&&ar[i].Y.X>=x&&ar[i].X.Y<=y&&ar[i].Y.Y>=y)tag=1;
            ans+=tag;
        }
        cout<<ll(ans)<<endl;
    }
}
