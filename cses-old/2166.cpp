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

const long long INF = 1e14 + 7;

struct SegmentTree {
    int n;
    vector<long long> a, st, lazy;

    SegmentTree(int _n) : n(_n), st(4*n), lazy(4*n) {}

    SegmentTree(const vector<long long> &_a) : n((int) _a.size()), a(_a), st(4*n), lazy(4*n) {
        fill(st.begin(), st.end(), INF);
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p] = min(st[2*p], st[2*p+1]);
    }

    void push(int p, int l, int r) {
        if (lazy[p]) {
            st[p] += lazy[p];
            if (l != r) {
                lazy[2*p] += lazy[p];
                lazy[2*p+1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }

    long long query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (i > r || j < l)
            return INF;
        if (i <= l && r <= j)
            return st[p];
        int m = (l + r) / 2;
        return min(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
    }

    long long query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }

    void update(int p, int l, int r, int i, int j, int val) {
        push(p, l, r);
        if (i > r || j < l)
            return;
        if (i <= l && r <= j) {
            st[p] += val;
            if (l != r) {
                lazy[2*p] += val;
                lazy[2*p+1] += val;
            }
            return;
        }
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, val);
        update(2*p+1, m+1, r, i, j, val);
        st[p] = min(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int val) {
        update(1, 0, n-1, i, j, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    vector<long long> prefix(n);
    long long total = 0;

    for(int i=0; i<n; i++) {
        cin >> a[i];
        total += a[i];
        prefix[i] = total;
    }

    SegmentTree segt(prefix);

    DEBUG(prefix);
    DEBUG(segt.st);

    while(q--) {
        int op;
        long long a, b;
        cin >> op >> a >> b;
        if(op == 1) {
            long long change = b - segt.st[n+a-1];
            DEBUG(segt.st[n+a-1]);
            segt.update(a, n, change);
            DEBUG(segt.st);
        } else {
            cout << segt.query(a, b) << "\n";
        }
    }

}
