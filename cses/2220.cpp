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

    int a, b; cin >> a >> b;

    auto solve = [&] (auto self, int x) -> int {
        if(x == -1) return 0;
        if(x == 0) return 1;
        DEBUG(x);

        int y = x;
        vector<int> dig;
        while(x) {
            dig.push_back(x % 10);
            x /= 10;
        }
        reverse(dig.begin(), dig.end());
        DEBUG(dig);
        int n = dig.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(10, vector<int>(2)));
        int ans = 0;
        for(int i=1; i<dig[0]; i++) dp[0][i][1] = 1;
        dp[0][dig[0]][0] = 1;

        for(int i=1; i<n; i++) {
            for(int d=0; d<10; d++) {
                for(int d2=0; d2<10; d2++) {
                    // d is the new one, d2 is the prev
                    if(d == d2) continue;
                    dp[i][d][1] += dp[i-1][d2][1];
                    if(d < dig[i]) {
                        dp[i][d][1] += dp[i-1][d2][0];
                    } else if(d == dig[i]) {
                        dp[i][d][0] += dp[i-1][d2][0];
                    }
                }
            }
        }

        for(int i=0; i<10; i++) {
            ans += dp[n-1][i][0] + dp[n-1][i][1];
        }
        
        int c = 1;
        int r = y / dig[0];
        while(r - c > c) {
            c *= 10;
        }
        ans += self(self, c-1);
        DEBUG(ans);
        return ans;
    };
    cout << solve(solve, b) - solve(solve, a-1) << "\n";

    
}
