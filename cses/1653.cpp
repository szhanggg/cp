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

	int n, x; cin >> n >> x;
    vector<int> w(n);
    for(int i=0; i<n; i++) cin >> w[i];

    vector<pair<int, int>> dp(1<<n);
    dp[0] = {1, 0};

    for(int sbs = 1; sbs<(1<<n); sbs++) {
        pair<int, int> cur = {21, 0};
        for(int i=0; i<n; i++) {
            if((sbs & (1<<i)) == 0) continue;
            int psbs = sbs ^ (1 << i);
            pair<int, int> prev = dp[psbs];
            prev.second += w[i];
            if(prev.second > x) {
                prev.first++;
                prev.second = w[i];
            }
            if(prev.first < cur.first) {
                cur = prev;
            } else if(prev.first == cur.first) {
                cur.second = min(cur.second, prev.second);
            }
        }
        dp[sbs] = cur;
    }
    DEBUG(dp[(1<<n)-1]);

    cout << dp[(1<<n)-1].first << "\n";

}
