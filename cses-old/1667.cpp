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

const int MAXN = 1e5 + 123;
vector<int> adj[MAXN];
vector<int> dist(MAXN);
vector<int> pointers(MAXN);

bool vis[MAXN];

stack<int> path;

int get(int n) {
    path.push(n);
    DEBUG(n);
    if(n!=pointers[n]) {
        pointers[n] = get(pointers[n]);
    }
    return pointers[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;
    dist[1] = 0;
    pointers[1] = 1;

    while(!q.empty()) {
        int next = q.front(); q.pop();

        // cout << "Processing: " << next << "\n";

        for(int adjN: adj[next]) {
            if(vis[adjN]) continue;
            dist[adjN] = dist[next] + 1;
            vis[adjN] = true;
            pointers[adjN] = next;
            q.push(adjN);
        }
    }

    // for(int i=1; i<n+1; i++) {
    //     cout << i << ": " << dist[i] << " " << pointers[i] << "\n";
    // }

    // DEBUG(pointers);
    // DEBUG(dist);

    if(dist[n] == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n] + 1 << "\n";
        get(n);
        while(!path.empty()) {
            int next = path.top(); path.pop();
            cout << next << " ";
        }
        cout << "\n";
    }

}
