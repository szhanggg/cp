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

    int n, m, k; cin >> n >> m >> k;
    vector<int> x(k); vector<int> y(k);
    for(int i=0; i<k; i++) cin >> x[i] >> y[i];

    int maxy = 0;
    for(int i=0; i<k; i++) {
        maxy = max(maxy, y[i]);
    }

    if(maxy == 1) {
        return false;
    }

    if(n == 1) {
        int p = 0;
        for(int i=0; i<k; i++) {
            if(y[i] == 2) p++;
        }
        if(p % 2 == 1) {
            return true;
        } else {
            return false;
        }
    }


    sort(y.begin(), y.end());

    int prev = 0; // prev is 1 if mimo win

    int start = 0;
    while(y[start] == 1) start++;

    int cnt = 1;

    for(int i=start+1; i<k; i++) {
        if(y[i] == y[i-1]) {
            cnt++;
        } else {
            if(cnt % 2 == 1) {
                prev = 1;
            }
            cnt = 1;
        }
    }

    if(cnt % 2 == 1) prev = 1;

    return prev == 1;
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        if(solve()) {
            cout << "Mimo\n";
        } else {
            cout << "Yuyu\n";
        }
    }
}
