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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    vector<int> p(n);

    vector<vector<int>> adj(n);

    for(int i=1; i<=n-1; i++) {
        cin >> p[i]; p[i]--;
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }

    vector<pair<int, int>> st;
    vector<int> fi(n, -1);

    DEBUG(adj);

    auto dfs = [&] (auto self, int i, int pa, int depth) -> void {
    
        DEBUG(i);

        if(fi[i] == -1) fi[i] = st.size();

        st.push_back(make_pair(depth, i));

        for(auto x: adj[i]) {
            if(x != pa && x != i) {
                self(self, x, i, depth + 1);
                st.push_back(make_pair(depth, i));
            }
        }
        
    };

    dfs(dfs, 0, -1, 1);

    DEBUG(st);
    DEBUG(fi);
    
    int g = st.size();

    int f = __lg(g);

    vector<vector<pair<int, int>>> spt(g, vector<pair<int, int>>(f+1));

    for(int po=0; po<=f; po++) {
        int pow = (1 << po);
        for(int i=0; i<g; i++) {
            if(i + pow > g) break;
            if(po == 0) spt[i][0] = st[i];
            else {
                spt[i][po] = min(spt[i][po-1], spt[i+(pow >> 1)][po-1]);
            }
        }
    }

    for(int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b; a--; b--;

        a = fi[a];
        b = fi[b];

        if(a > b) swap(a, b);

        int lg = __lg(b - a + 1);
        DEBUG(lg);

        cout << min(spt[a][lg], spt[b - (1 << lg) + 1][lg]).second + 1 << "\n";

    }

}
