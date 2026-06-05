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
 
bool solve() {

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // pq + linked list
    priority_queue<pair<int, int>> pq;
    vector<int> next(n);
    vector<int> prev(n);
    vector<bool> del(n);
    for(int i=0; i<n; i++) {
        next[i] = i+1; prev[i] = i-1;
    }
    if(abs(a[1]-a[0]) == 1) pq.push({a[0], 0});
    if(abs(a[n-1]-a[n-2]) == 1) pq.push({a[n-1], n-1});
    for(int i=1; i<n-1; i++) {
        if(abs(a[i]-a[i-1]) == 1 || abs(a[i]-a[i+1]) == 1) pq.push({a[i], i});
    }
    int delam = 0;
    while(!pq.empty() && delam != n-1) {
        auto x = pq.top(); pq.pop();
        int u = x.first; int v = x.second;
        if(del[v]) continue;
        DEBUG(u, v);
        if(prev[v] == -1) {
            if(abs(u-a[next[v]]) != 1) continue;
        } else if(next[v] == n) {
            if(abs(u-a[prev[v]]) != 1) continue;
        } else {
            if(abs(u-a[prev[v]]) != 1 && abs(u-a[next[v]]) != 1) continue;
        }

        if(prev[v] != -1) next[prev[v]] = next[v];
        if(next[v] != n) prev[next[v]] = prev[v];
        if(prev[v] != -1 && next[v] != n) {
            if(abs(a[prev[v]]-a[next[v]]) == 1) {
                pq.push({a[prev[v]], prev[v]});
                pq.push({a[next[v]], next[v]});
            }
        }
        del[v] = true;
        delam++;
    }

    if(delam != n-1) return false;

    for(int i=0; i<n; i++)
        if(!del[i] && a[i] != 0) return false;

    return true;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        if(solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
