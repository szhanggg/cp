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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> h(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) cin >> h[i][j];

        vector<int> a(n); vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        vector<array<bool, 3>> diffs(n, {false, false, false}); //first if needs to change, second is if changing will mess with next row, third is if changing i+1 will mess with prev row
        
        bool impos = false;
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(h[i][j] == h[i-1][j]) diffs[i-1][0] = true;
                if(h[i][j] == h[i-1][j]+1) diffs[i-1][1] = true;
                if(h[i][j] == h[i-1][j]-1) diffs[i-1][2] = true;
            }
            if(diffs[i][0] && diffs[i][1] && diffs[i][2]) impos = true;
        }

        if(impos) {
            cout << "-1\n";
            continue;
        }

        int ans = 0;

        vector<array<int, 2>> dp(n, {LLONG_MAX, LLONG_MAX}); // dp[i] represents the minimum ans of 0..i if i is changed or unchanged

        dp[0] = {0, a[0]};

        for(int i=1; i<n; i++) {
            // first calculate dp[i][0]
            if(!diffs[i-1][0]) {
                if(dp[i-1][0] != LLONG_MAX) dp[i][0] = min(dp[i][0], dp[i-1][0]);
                // see if we can change both rows
                if(dp[i-1][1] != LLONG_MAX) dp[i][1] = min(dp[i][1], a[i] + dp[i-1][1]);
            }
            // if it will not mess things up to change prev row, try it out
            if(dp[i-1][1] != LLONG_MAX) if(!diffs[i-1][1]) dp[i][0] = min(dp[i][0], dp[i-1][1]);
            // if we can change current row, try it out
            if(dp[i-1][0] != LLONG_MAX) if(!diffs[i-1][2]) dp[i][1] = min(dp[i][1], a[i] + dp[i-1][0]);
        }

        DEBUG(dp);

        ans += min(dp[n-1][0], dp[n-1][1]);
        if(ans == LLONG_MAX) {
            cout << "-1\n";
            continue;
        }
        

        for(int i=0; i<n; i++) diffs[i] = {false, false, false};
        
        impos = false;
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(h[j][i] == h[j][i-1]) diffs[i-1][0] = true;
                if(h[j][i] == h[j][i-1]+1) diffs[i-1][1] = true;
                if(h[j][i] == h[j][i-1]-1) diffs[i-1][2] = true;
            }
            if(diffs[i][0] && diffs[i][1] && diffs[i][2]) impos = true;
        }

        if(impos) {
            cout << "-1\n";
            continue;
        }

        for(int i=0; i<n; i++) dp[i] = {LLONG_MAX, LLONG_MAX};

        dp[0] = {0, b[0]};

        for(int i=1; i<n; i++) {
            // first calculate dp[i][0]
            if(!diffs[i-1][0]) {
                if(dp[i-1][0] != LLONG_MAX) dp[i][0] = min(dp[i][0], dp[i-1][0]);
                // see if we can change both rows
                if(dp[i-1][1] != LLONG_MAX) dp[i][1] = min(dp[i][1], b[i] + dp[i-1][1]);
            }
            // if it will not mess things up to change prev row, try it out
            if(dp[i-1][1] != LLONG_MAX) if(!diffs[i-1][1]) dp[i][0] = min(dp[i][0], dp[i-1][1]);
            // if we can change current row, try it out
            if(dp[i-1][0] != LLONG_MAX) if(!diffs[i-1][2]) dp[i][1] = min(dp[i][1], b[i] + dp[i-1][0]);
        }
        if(min(dp[n-1][0], dp[n-1][1]) == LLONG_MAX) {
            cout << "-1\n";
            continue;
        }

        DEBUG(dp);

        ans += min(dp[n-1][0], dp[n-1][1]);

        cout << ans << "\n";

    }
    
}
