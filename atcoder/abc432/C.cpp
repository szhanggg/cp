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

#define int long long

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b%a, a);
}

int lcm(int a, int b) {
    return (a / gcd(a, b))*b;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int lc = lcm(x, y);
    int xdiff = lc / x;
    int ydiff = lc / y;
    int diff = xdiff - ydiff;

    sort(a.begin(), a.end());
    int prev = a[0];
    for(int i=0; i<n; i++) a[i] = a[i] - prev;
    bool pos = true;
    int ans = prev;

    DEBUG(a);
    DEBUG(diff);

    for(int i=1; i<n; i++) {
        if(a[i] % diff != 0) pos = false;
        int cd = a[i] - a[i-1];
        int am = cd / diff;
        prev -= am * ydiff;
        if(prev < 0) pos = false;
        DEBUG(prev);
        ans += prev;
    }

    if(!pos) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    
}
