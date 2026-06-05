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

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int solve() {

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n; i++) {
        if(i == n-1) return -1;
        if(a[i] > a[i+1]) break;
    }
    vector<pair<int, int>> b(n);
    for(int i=0; i<n; i++) b[i] = {a[i], i};
    sort(b.begin(), b.end());

    DSU ds(n);
    int lb = b[0].first;
    int ub = b[n-1].first;
    int ans = ub - lb;
    priority_queue<pair<int, int>> edges;
    for(int i=0; i<n; i++) {
        int dist = max(b[i].first - lb, ub - b[i].first);
        edges.push({dist, b[i].second});
    }
    DEBUG(b);

    for(int i=0; i<n; i++) {
        DEBUG(i, b[i].second);
        while(!ds.same(i, b[i].second)) {
            auto nexte = edges.top(); edges.pop();
            DEBUG(nexte);
            ds.unite(b[0].second, nexte.second);
            ans = nexte.first;
        }
    }

    return ans;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
}
