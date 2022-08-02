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

const int N = 1e5 + 25;
struct segtree {
    int arr[N << 1], n;
    int l[N << 1], r[N << 1];
    bool tag[N];
    void init(int _n) {
        n = _n;
        for(int i = 0; i < n; i++) {
            l[i + n] = i;
            r[i + n] = i + 1;
        }
        for(int i = n - 1; i; i--) {
            l[i] = min(l[i << 1], l[i << 1 | 1]);
            r[i] = max(r[i << 1], r[i << 1 | 1]);
        }
    }
    void upd(int p) {
        //cerr << "Here " << p << ' ' << arr[p] << ' ' << l[p] << ' ' << r[p] << '\n';
        arr[p] = r[p] - l[p] - arr[p];
        if(p < n)
            tag[p] = !tag[p];
    }
    void push(int p) {
        for(int h = __lg(p); ~h; h--) {
            int i = p >> h;
            if(tag[i >> 1]) {
                upd(i);
                upd(i ^ 1);
                tag[i >> 1] = false;
            }
        }
    }
    void pull(int p) {
        for(; p > 1; p >>= 1) {
            arr[p >> 1] = arr[p] + arr[p ^ 1];
            if(tag[p >> 1])
                arr[p >> 1] = r[p >> 1] - l[p >> 1] - arr[p >> 1];
        }
    }
    void edt(int p, int v) {
        for(arr[p += n] = v; p > 1; p >>= 1)
            arr[p >> 1] = arr[p] + arr[p ^ 1];
    }
    void flip(int l, int r) {
        int tl = l + n, tr = r + n - 1;
        push(tl);
        push(tr);
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1)
                upd(l++);
            if(r & 1)
                upd(--r);
        }
        pull(tl);
        pull(tr);
    }
    int que(int l, int r) {
        push(l + n); push(r + n - 1);
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1)
                res += arr[l++];
            if(r & 1)
                res += arr[--r];
        }
        return res;
    }
} tree;
signed main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    tree.init(n);
    for(int i = 0; i < n; i++)
        tree.edt(i, s[i] & 1);

    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if(t == 1) {
            tree.flip(l, r);
        }
        else {
            debug(tree.que(l, r));
            cout << 1LL * tree.que(l, r) * (r - l - tree.que(l, r)) << '\n';
        }
    }
}
