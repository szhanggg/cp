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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin >> t[i];

    sort(t.begin(), t.end());

    vector<vector<int>> dp(50, vector<int>(x+5001)); // unfinished groups, penalty
    vector<vector<int>> prev(50, vector<int>(x+5001));
    prev[0][0] = 1;

    for(int i=0; i<n; i++) {
        // 4 options
        // Add i to group by itself
        // Add i to an already unfinished group
        // Finish a group with i
        // Start a new unfinished group with i
        for(int j=0; j<50; j++) {
            for(int k=5000; k<=x+5000; k++) {
                dp[j][k] += prev[j][k];
                dp[j][k] %= MOD;
                dp[j][k] += j*prev[j][k];
                dp[j][k] %= MOD;
                if(j > 0) dp[j-1][k+t[i]] += j*prev[j][k];
                if(j < 49) dp[j+1][k-t[i]] += prev[j][k];
                dp[j][k] %= MOD;
            }
        }
        prev.assign(dp.begin(), dp.end());
        for(int j=0; j<50; j++)
            for(int k=0; k<=x+5000; k++) dp[j][k] = 0;
    }

    int tot = 0;
    for(int i=0; i<=x; i++) {
        tot += prev[0][i+5000];
        tot %= MOD;
    }

    cout << tot << "\n";
    
}
