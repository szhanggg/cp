#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

#define int long long

// [0, n]
struct SegmentTree {
    int n;
    vector<int> st, a;

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int i, int tl, int tr) {
        if(tl == tr) {st[i] = a[tl]; return;}
        int mid = (tl + tr)/2;

        build(2*i, tl, mid);
        build(2*i+1, mid+1, tr);

        st[i] = st[2*i] + st[2*i+1];
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    int query(int i, int tl, int tr, int l, int r) {
        if(tl > r || tr < l) return 0;
        if(tl >= l && tr <= r) return st[i];
        if(tl == tr) return st[i];

        int mid = (tl + tr) / 2;
        int left = query(2*i, tl, mid, l, r);
        int right = query(2*i+1, mid+1, tr, l, r);

        return left + right;
    }

    void update(int i, int x) {
        update(1, 0, n-1, i, x);
    }

    void update(int i, int l, int r, int pos, int x) {
        if(l == r) st[i] = x;
        else {
            int mid = (l + r) / 2;
            if(pos <= mid) update(2*i, l, mid, pos, x);
            else update(2*i+1, mid+1, r, pos, x);
            st[i] = st[2*i] + st[2*i+1];
        }
    }
};
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    SegmentTree st(a);

    DEBUG(st.st);

    while(q--) {
        int k, a, b; cin >> k >> a >> b;
        if(k == 1) {
            st.update(a-1, b);
        } else {
            cout << st.query(a-1, b-1) << "\n";
        }
    }
    
}
