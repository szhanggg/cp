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

const int MAXN = 100007;
vector<bool> vis(MAXN, false);
vector<vector<int>> adj(MAXN);
vector<int> ans(MAXN);

void dfs(int i, int prevN, int prevV, const map<pair<int, int>, int> &um) {
    DEBUG(i, prevV);
    for(auto x: adj[i]) {
        if(x == prevN) continue;
        if(prevV == 2) {
            prevV = 3;
        } else {
            prevV = 2;
        }

        ans[um.find(make_pair(i, x))->second] = prevV;
        dfs(x, i, prevV, um);

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        fill(adj.begin(), adj.end(), vector<int>());
        fill(vis.begin(), vis.end(), false);
        fill(ans.begin(), ans.end(), 0);
        int n;
        cin >> n;

        map<pair<int, int>, int> um;

        for(int i=0; i<n-1; i++) {
            int a, b;
            cin >> a >> b;
            um[make_pair(a, b)] = i;
            um[make_pair(b, a)] = i;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        DEBUG(um);

        bool f = false;

        int startN = -1;

        for(int i=1; i<=n; i++) {
            if(adj[i].size() > 2) {
                f = true;
                break;
            }
            if(adj[i].size() == 1) startN = i;
        }

        if(f) {
            cout << "-1\n";
            continue;
        }

        DEBUG(startN);

        dfs(startN, -1, 3, um);

        for(int i=0; i<n-1; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        
    }

}
