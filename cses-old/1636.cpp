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

const int MOD = 1e9 + 7;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<int> c(n);

    for(int i=0; i<n; i++) cin >> c[i];

    vector<int> dp(x+1);
    // dp[i][j] represents the number of ways to make j w/ only coins 0 to i

    vector<int> prev(x+1);
    vector<int> next(x+1);
    for(int j=0; j<=x; j+=c[0]) prev[j] = 1;

    for(int i=1; i<n; i++) {
        fill(next.begin(), next.end(), 0);
        next[0]=1;
        for(int j=0; j<=x; j++) {
            int am = 0;
            am += prev[j];
            am %= MOD;
            if(j - c[i] >= 0) am += next[j - c[i]];
            am %= MOD;
            next[j] = am;
        }
        prev = next;
    }

    // DEBUG(dp);

    cout << prev[x] << "\n";
    
}
