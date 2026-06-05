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

const int MAXN = 2e5 + 123;

vector<int> p(MAXN);
vector<int> perm(MAXN);
vector<int> weights(MAXN);
vector<int> adj[MAXN];
bool no = false;

int get(int v) {
    if(v!=p[v]) {
        p[v] = get(p[v]);
    }
    return p[v];
}

int dfs(int v, int w) {
    // DEBUG(v);
    weights[v] = w;
    // DEBUG(weights[v]);
    int i = 1;
    for(auto adjN: adj[v]) {
        if(perm[adjN] < perm[v]) no = true;
        i += dfs(adjN, i);
    }
    return i;
}

bool cmp(int a, int b) {
    return perm[a] < perm[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        p.clear();
        perm.clear();
        fill(weights.begin(), weights.end(), -1);
        no = false;
        int n;
        cin >> n;

        for(int i=1; i<n+1; i++) {
            cin >> p[i];
            adj[i].clear();
        }
        for(int i=1; i<n+1; i++) {
            cin >> perm[i];
        }

        for(int i=1; i<n+1; i++) {
            if(i!=p[i]) adj[p[i]].push_back(i);
        }

        for(int i=1; i<n+1; i++) {
            sort(adj[i].begin(), adj[i].end(), cmp);
            // DEBUG(adj[i]);
        }

        int root = get(1);        

        dfs(root, 0);

        if(no) {
            cout << "-1\n";
            continue;
        }

        for(int i=1; i<n+1; i++) {
            cout << weights[i] << " ";
        }

        cout << "\n";

    }

}
