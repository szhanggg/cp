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

bool solve(vector<int>&a, vector<int>&b, int x, int asum, int bsum, int req) {
    for(int i=0; i<a.size(); i++) {
        for(int j=0; j<b.size(); j++) {
            if(a[i]*bsum + b[j]*asum - a[i]*b[j] == req) return true;
        }
    }
    return false;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m , q; cin >> n >> m >> q;

    vector<int> a(n);
    vector<int> b(m);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    int asum = 0;
    int bsum = 0;

    for(int i=0; i<n; i++) asum += a[i];
    for(int i=0; i<m; i++) bsum += b[i];

    int tot = asum * bsum;
    
    while(q--) {
        int x;
        cin >> x;

        int req = tot - x;
        if(solve(a, b, x, asum, bsum, req)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    
}
