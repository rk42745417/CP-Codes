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

pii a1,a2,b1,b2;

void solve(){
    int n,m;
    cin>>n>>m>>a1.X>>a1.Y>>a2.X>>a2.Y>>b1.X>>b1.Y>>b2.X>>b2.Y;
    if(a1.Y>a2.Y)swap(a1,a2);
    if(b1.Y>b2.Y)swap(b1,b2);
    if(a2.Y<b1.Y||b2.Y<a1.Y){
        cout<<"0"<<endl;
        return;
    }
    if(a1.X>a2.X)swap(a1,a2);
    if(b1.X>b2.X)swap(b1,b2);
    if(a2.X<b1.X||b2.X<a1.X){
        cout<<"0"<<endl;
        return;
    }
    if(a1.X<b1.X)a1.X=b1.X;
    else b1.X=a1.X;
    if(a2.X>b2.X)a2.X=b2.X;
    else b2.X=a2.X;
    bool t1=0,t2=0;
    if(a1.Y>a2.Y)t1=1;
    if(b1.Y>b2.Y)t2=1;
    if(t1^t2){
        if(t1){
            if(a1.Y>b2.Y)a1.Y=b2.Y;
            else b2.Y=a1.Y;
            if(a2.Y<b1.Y)a2.Y=b1.Y;
            else b1.Y=a2.Y;
        }
        else{
            if(a1.Y<b2.Y)a1.Y=b2.Y;
            else b2.Y=a1.Y;
            if(a2.Y>b1.Y)a2.Y=b1.Y;
            else b1.Y=a2.Y;
        }
        cout<<max(abs(a1.X-a2.X),abs(a1.Y-a2.Y)) + 1<<endl;
        return;
    }
    else{
        if(t1){
            if(a1.Y>b1.Y)a1.Y=b1.Y;
            else b1.Y=a1.Y;
            if(a2.Y<b2.Y)a2.Y=b2.Y;
            else b2.Y=a2.Y;
        }
        else{
            if(a1.Y<b1.Y)a1.Y=b1.Y;
            else b1.Y=a1.Y;
            if(a2.Y>b2.Y)a2.Y=b2.Y;
            else b2.Y=a2.Y;
        }
        cout<<abs(a1.X-a2.X)+abs(a1.Y-a2.Y)+1<<endl;
        return;
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
