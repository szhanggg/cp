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
    vector<int> sz(n);
    vector<vector<int>> a(n);

    int maxk = 0;

    for(int i=0; i<n; i++) {
        int k; cin >> k;
        sz[i] = k;
        maxk = max(maxk, k);
        for(int j=0; j<k; j++) {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }

    vector<bool> valid(n, true);
    vector<int> ans;

    vector<int> vind;
    for(int j=0; j<n; j++) vind.push_back(j);

    for(int i=0; i<maxk; i++) {
        DEBUG(i, vind);
        int mv = INT_MAX;
        vector<int> newind;
        for(int j : vind) {
            if(i >= a[j].size()) {
                valid[j] = false;
            } else {
                if(i < a[j].size() - 1) newind.push_back(j);
            }
            if(!valid[j]) continue;
            mv = min(mv, a[j][i]);
        }

        bool last = false;

        DEBUG(valid);

        for(int j : vind) {
            if(!valid[j]) continue;
            if(a[j][i] == mv) {
                if(i == a[j].size()-1) last = true;
            } else {
                valid[j] = false;
            }
        }


        if(last) {
            for(int j : newind) {
                valid[j] = true;
            }
        }

        ans.push_back(mv);
        vind = newind;
    }

    for(auto x: ans) cout << x << " ";
    cout << "\n";
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
