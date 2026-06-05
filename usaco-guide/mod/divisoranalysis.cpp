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
const int MOD = 1e9+7;

int exp(int a, int b) {
    int ans = 1;
    while(b) {
        if(b&1) ans *= a;
        ans %= MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int sum = 1;
    int div = 1;
    int prod = 1;
    int div2 = 1;
    int x, k;
    while(n--) {
        cin >> x >> k;
        int f = exp(x, k+1)-1;
        f = (f * exp(x-1, MOD-2)) % MOD;
        sum = (sum * f) % MOD;

        prod = exp(prod, k+1);
        int expp = ((k*(k+1))/2) % (MOD-1);
        expp = (expp * div2) % (MOD-1);

        prod = (prod * exp(x, expp)) % MOD;
        div = (div * (k+1)) % MOD;
        div2 = (div2 * (k+1)) % (MOD-1);
    }

    cout << div << " " << sum << " " << prod << "\n";
    
}
