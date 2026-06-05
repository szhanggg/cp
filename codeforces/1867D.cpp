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
    
    int t;
    cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++) b[i]--;
        //you just need to find a cycle of length k in the array

        if(k == 1) {
            //Check if the array is in increasing order from 0 to n-1;
            bool ok = true;
            for(int i=0; i<n; i++) if(b[i] != i) ok = false;
            if(ok) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }

        vector<bool> vis(n, 0);
        bool ok = true;

        //Remove all the nodes that have nothing pointed to them
        vector<int> in(n, 0);

        for(int i=0; i<n; i++) {
            in[b[i]]++;
        }

        //Sort the nodes by their in-degree

        vector<pair<int, int>> nodes(n);

        for(int i=0; i<n; i++) {
            nodes[i] = make_pair(in[i], i);
        }

        sort(nodes.begin(), nodes.end());

        for(int i=0; i<n; i++) {
            if(in[nodes[i].second] == 0) {
                vis[nodes[i].second] = true;
                in[b[nodes[i].second]]--;
            }
        }

        DEBUG(vis);

        for(int i=0; i<n; i++) {
            if(vis[i]) continue;
            //Check the cycle length starting from i
            int cur = i;
            int len = 0;
            while(!vis[cur]) {
                vis[cur] = true;
                len++;
                cur = b[cur];
            }
            if(len != k) {
                ok = false;
                break;
            }
        }

        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
