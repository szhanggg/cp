#include <bits/stdc++.h>
using namespace std;
#define int long long
 
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

int solve() {
    int n, m, h; cin >> n >> m >> h;
    vector<bool> a(n);
    for(int i=0; i<h; i++) {
        int x; cin >> x;
        a[x-1] = true;
    }

    vector<vector<pair<int, int>>> adj(n);
    for(int i=0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Run Dijkstra from node 0
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    if(a[0]) pq.push({0, 0, 1});
    else pq.push({0, 0, 0});
    // First index is the node, second is the distance, third is if they have mounteda horse

    vector<int> dist(n, LONG_MAX);
    vector<int> disth(n, LONG_MAX);
    dist[0] = 0;
    if(a[0]) disth[0] = 0;
    while(!pq.empty()) {
        auto [u, d, horse] = pq.top();
        DEBUG(u, d, horse);
        pq.pop();
        if(horse) {
            // Do regular Dijstrka but with disth
            if(disth[u] != d) continue;
            for(auto [v, w] : adj[u]) {
                if(disth[v] > d + (w / 2)) {
                    disth[v] = d + (w / 2);
                    pq.push({v, d + (w / 2), 1});
                }
            }
        } else {
            if(dist[u] != d) continue;
            for(auto [v, w] : adj[u]) {
                int newHorse = horse;
                if(a[v]) newHorse = 1;
                if(newHorse) {
                    if(disth[v] > d + w) {
                        disth[v] = d + w;
                        pq.push({v, d + w, newHorse});
                    }
                } else {
                    if(dist[v] > d + w) {
                        dist[v] = d + w;
                        pq.push({v, d + w, newHorse});
                    }
                }
            }
        }
    }

    DEBUG(dist, disth);

    if(dist[n-1] == LONG_MAX && disth[n-1] == LONG_MAX) return -1;

    // Same thing but with n - 1
    vector<int> dist2(n, LONG_MAX);
    vector<int> disth2(n, LONG_MAX);
    dist2[n-1] = 0;
    if(a[n-1]) pq.push({n-1, 0, 1});
    else pq.push({n-1, 0, 0});
    if(a[n-1]) disth2[n-1] = 0;
    while(!pq.empty()) {
        auto [u, d, horse] = pq.top();
        DEBUG(u, d, horse);
        pq.pop();
        if(horse) {
            // Do regular Dijstrka but with disth
            if(disth2[u] != d) continue;
            for(auto [v, w] : adj[u]) {
                if(disth2[v] > d + (w / 2)) {
                    disth2[v] = d + (w / 2);
                    pq.push({v, d + (w / 2), 1});
                }
            }
        } else {
            if(dist2[u] != d) continue;
            for(auto [v, w] : adj[u]) {
                int newHorse = horse;
                if(a[v]) newHorse = 1;
                if(newHorse) {
                if(disth2[v] > d + w) {
                    disth2[v] = d + w;
                    pq.push({v, d + w, newHorse});
                }
                } else {
                    if(dist2[v] > d + w) {
                        dist2[v] = d + w;
                        pq.push({v, d + w, newHorse});
                    }
                }
            }
        }
    }

    vector<int> distf(n, LONG_MAX);
    vector<int> distf2(n, LONG_MAX);
    for(int i=0; i<n; i++) {
        distf[i] = min(dist[i], disth[i]);
        distf2[i] = min(dist2[i], disth2[i]);
    }

    int ans = LONG_MAX;
    for(int i=0; i<n; i++) {
        ans = min(ans, max(distf[i], distf2[i]));
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
