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
const int MOD = 998244353;

void solve() {
    
    int n, x; cin >> n >> x;
    // number of xor 0 strictly before x

    int b0 = (x / 4 + 1) % MOD;
    if(b0 < 0) b0 += MOD;

    // number of xor 0 strictly after including x

    int a0 = (((n + 1) / 4) - b0 + 1) % MOD;
    if(a0 < 0) a0 += MOD;
    DEBUG(b0, a0);

    int ans = a0 * b0;
    ans %= MOD;
    if(ans < 0) ans += MOD;

    // number of xor 1 strictly before x

    int b1 = ((x + 2) / 4) % MOD;
    if(b1 < 0) b1 += MOD;

    // number of xor 1 strictly after including x

    int a1 = (((n + 3) / 4) - b1) % MOD;
    if(a1 < 0) a1 += MOD;

    ans += (a1 * b1) % MOD;
    if(ans < 0) ans += MOD;
    DEBUG(b1, a1);

    cout << ans % MOD << "\n";
    

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;

    int cur = 0;

    for(int i=0; i<20; i++) {
        cur ^= i;
        DEBUG(i, cur);
    }

    while(t--) {
        solve();
    }
}
