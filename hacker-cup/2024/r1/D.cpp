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

const int MOD = 998244353;

pair<string, int> solve() {
    string s; cin >> s;
    int k; cin >> k; k--;
    int n = s.size();

    pair<string, int> fans;
    int am = 0;
    for(int i=0; i<n-2; i++) {
        if(s[i] == '?') {
            if(i != n-1) {
                if(s[i+1] - '0' <= 6) am++;
                else if(s[i+1] == '?') {
                    am++;
                } else {
                    s[i] = '1';
                }
            }
        }
    }

    int last = s[n-1] - '0';
    int slast = s[n-2] - '0';
    int sub = k;

    if(last == 15 && slast == 15) {
        // Values can range from 11 to 26 excluding 20
        // 15 possible values

        int rem = k % 15;
        sub = k / 15;
        int leftover = 26 - rem;
        if(leftover <= 20) leftover--;
        s[n-1] = '0' + (leftover % 10);
        s[n-2] = '0' + (leftover / 10);
    } else if(slast == 15) {
        if(last <= 6) am++;
        else {
            s[n-2] = '1';
        }
    } else if(last == 15) {
        if(slast != 2) {
            // last number can range from 1 to 9
            int rem = k % 9;
            sub = k / 9;
            int leftover = 9 - rem;
            s[n-1] = '0' + (leftover % 10);
        } else {
            // last number can range from 1 to 6
            int rem = k % 6;
            sub = k / 6;
            int leftover = 6 - rem;
            s[n-1] = '0' + (leftover % 10);
        }
    }

    int curbits = (1 << (am + 1)) - 1 - sub;
    int curbit = 0;

    for(int i=n-1; i>=0; i--) {
        if(s[i] == '?') {
            if(curbits & (1 << curbit)) {
                s[i] = '2';
            } else {
                s[i] = '1';
            }
            curbit++;
        }
    }

    fans.first = s;

    if(n == 1) {
        fans.second = 1;
        return fans;
    }

    // Count the number of possible answers

    vector<int> dp(n, 0);
    // dp[i] is the number of possible answers if we're only allowed to use the first i characters
    dp[0] = 1;

    // dp[i] = dp[i-1] + dp[i-2] but you can only adc dp[i-2] if you can combine characters i and i-1
    // The two characters are combinable if i-1 is 1 OR i-1 is 1 and i is 0-6
    // We can only add dp[i-1] if i is not 0

    int cur = s[1] - '0';
    int prev = s[0] - '0';
    int ans = 0;
    if(cur != 0) ans++;
    if(prev == 1) ans++;
    if(prev == 2 && (cur >= 0 && cur <= 6)) ans++;
    dp[1] = ans;

    for(int i=2; i<n; i++) {
        cur = s[i] - '0';
        prev = s[i-1] - '0';
        ans = 0;
        if(cur != 0) ans += dp[i-1];
        if(prev == 1) ans += dp[i-2];
        if(prev == 2 && (cur >= 0 && cur <= 6)) ans += dp[i-2];
        dp[i] = ans;
    }


    fans.second = dp[n-1];

    return fans;

}
 
signed main() {
    DEBUG('?' - '0');
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("substitution_cipher_input.txt", "r", stdin);
    // freopen("dout.txt", "w", stdout);

    int t; cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case #" << i << ": ";
        pair<string, int> ans = solve();
        cout << ans.first << " " << ans.second << "\n";
    }
    
}
