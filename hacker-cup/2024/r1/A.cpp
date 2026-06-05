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

double solve() {
    int n; cin >> n;
    vector<double> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];

    double maxspd = 1e9;

    for(int i=1; i<=n; i++) {
        maxspd = min(maxspd, b[i-1] / ((double) i));
    }

    for(int i=1; i<n; i++) {
        if(maxspd * i < a[i-1]) return -1;
    }

    return (double) 1.0 / maxspd;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("subsonic_subway_input.txt", "r", stdin);
    freopen("aout.txt", "w", stdout);

    int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
        cout << "Case #" << i << ": ";
        cout << solve() << "\n";
    }
    
}
