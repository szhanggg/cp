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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> a(n);

    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> b(2*n);
    for(int i=0; i<n; i++) {
        b[i] = a[i];
        b[i+n] = a[i];
    }

    vector<int> pre(2*n+1);
    for(int i=0; i<2*n; i++) {
        pre[i+1] = pre[i] + b[i];
    }

    int cur = 0;

    while(q--) {
        int x; cin >> x;
        if(x == 1) {
            int c; cin >> c;
            cur += c;
            cur %= n;
        } else {
            int l, r; cin >> l >> r;
            l += cur;
            r += cur;

            cout << pre[r] - pre[l-1] << "\n";
        }
    }
    
}
