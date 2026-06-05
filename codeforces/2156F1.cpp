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
    vector<int> p(n);
    for(int i=0; i<n; i++) cin >> p[i];

    vector<int> ans(n);
    set<int> prev;

    for(int i=0; i<n; i++) {
        int newv = p[i] % 2;
        if(newv == 0) newv = 2;
        for(int j=newv; j<=n; j+=2) {
            if(!prev.count(j)) {
                newv = j;
                break;
            }
        }
        for(int j=i+1; j<n; j++) {
            if(p[j] < p[i] && p[j] >= newv) p[j]++;
        }
        ans[i] = newv;
        DEBUG(newv, p);
        prev.insert(newv);
    }

    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
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
