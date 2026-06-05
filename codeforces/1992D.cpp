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

// const int MAXN = 1e5 + 7;
const int MAXN = 7;

vector<int> dp(MAXN);

bool solve(vector<char>&a, int n,int m,int k, int cur) {
    if(dp[cur] != -1) return dp[cur];
    if(cur == n) {
        for(int i=n-1; i>=n-m && i>=0; i--) {
            if(a[i] == 'L' && solve(a, n, m, k, i)) return true;
        }
        for(int i=n-1; i>=n-k && i>=0; i--) {
            if(a[i] == 'C') return false;
            if(a[i] == 'W') return true;
        }
    }
    if(a[cur] == 'C') {
        dp[cur] = 0;
        return false;
    }
    else {
        for(int i=cur-1; i>= 0 && i>=cur-m; i--) {
            if(a[i] == 'L' && solve(a, n, m, k, i)) {
                dp[cur] = true;
                return true;
            }
        }
        dp[cur] = false;
        return false;
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<char> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        fill(dp.begin(), dp.end(), -1);
        for(int i=0; i<m; i++) {
            if(a[i] == 'C') dp[i] = 0;
            else dp[i] = 1;
        }

        DEBUG(dp);

        if(solve(a, n, m , k, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    
}
