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
 
void solve() {

    int n; cin >> n;
    vector<int> r(n+1);

    for(int i=1; i<=n; i++) cin >> r[i];

    vector<int> indeg(n+1, 0);
    for(int i=1; i<=n; i++) {
        indeg[r[i]]++;
    }
    int ans = 0;

    // Find all the cycles
    vector<bool> isCycle(n+1, false);
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, -1);
    for(int i=1; i<=n; i++) {
        if(visited[i]) continue;
        if(indeg[i] != 0) continue;
        int slow = i; int fast = i;
        int steps = 0;

        vector<int> path;

        while(true) {
            path.push_back(slow);
            slow = r[slow];
            fast = r[r[fast]];
            steps++;
            if(distance[slow] != -1) break;
            if(slow == fast) break;
        }

        if(distance[slow] != -1) {
            int distToCycle = distance[slow];
            for(int j=path.size()-1; j>=0; j--) {
                distToCycle++;
                distance[path[j]] = distToCycle;
            }
            ans = max(ans, distToCycle);
            continue;
        }

        // cur is now the start of a cycle
        // Find all the elements in the cycle

        int cur = slow;
        do {
            isCycle[cur] = true;
            visited[cur] = true;
            distance[cur] = 0;
            cur = r[cur];
        } while(cur != slow);

        // See how long it takes to get to a cycle from i
        cur = i;
        path.clear();
        while(distance[cur] == -1 && !isCycle[cur]) {
            path.push_back(cur);
            cur = r[cur];
        }
        int distToCycle = isCycle[cur] ? 0 : distance[cur];
        for(int j=path.size()-1; j>=0; j--) {
            distToCycle++;
            distance[path[j]] = distToCycle;
        }
 
        ans = max(ans, distToCycle);
    }
 
    cout << ans + 2 << "\n";

}
 
signed main() {
    // freopen("tsetcase.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
