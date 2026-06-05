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

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        vector<unordered_map<int, int>> dp(n);

        vector<int> ans(n+1);

        for(int i=0; i<n; i++) {
            dp[i].insert(make_pair(a[i], 1));
            ans[1] = max(ans[1], a[i]);
            if(i == 0) continue;
            for(auto &it : dp[i-1]) {
                int f = gcd(it.first, a[i]);
                if(dp[i][f]) dp[i][f] = max(dp[i][f], it.second+1);
                else dp[i][f] = it.second+1;
                ans[it.second+1] = max(ans[it.second+1], f);
            }
        }

        for(int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

    }
    
}
