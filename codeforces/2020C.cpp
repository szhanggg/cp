#include <bits/stdc++.h>
using namespace std;
#define int long long
 
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

signed solve(int a, int b, int c) {
    int ans = 0;
    int shiftam = -1;
    while(a != 0 || b != 0 || c != 0) {
        int cura = a & 1;
        int curb = b & 1;
        int curc = c & 1;
        a >>= 1;
        b >>= 1;
        c >>= 1;
        shiftam++;
        if(cura == 1 && curb == 0) {
            if(curc == 0) return -1;
            continue;
        }
        if(cura == 0 && curb == 1) {
            if(curc == 1) return -1;
            continue;
        }
        if(cura == 0) {
            if(curc == 1) {
                ans += (1LL << shiftam);
            }
        } else {
            if(curc == 0) {
                ans += (1LL << shiftam);
            }
        }
    }
    return ans;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int b, c, d; cin >> b >> c >> d;
        cout << solve(b, c, d) << '\n';
    }
}
