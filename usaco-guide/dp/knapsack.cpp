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

    int s, n; cin >> s >> n;
    vector<int> v(n), w(n), k(n);
    for(int i=0; i<n; i++) cin >> v[i] >> w[i] >> k[i];

    vector<vector<pair<int, int>>> vals(s+1);

    for(int i=0; i<n; i++) {
        vals[w[i]].push_back(make_pair(v[i], k[i]));
    }

    for(int i=0; i<=s; i++) sort(vals[i].begin(), vals[i].end(), greater<>());

    vector<pair<int, int>> tot;
    
    for(int i=0; i<=s; i++) {
        int cnt = 0;
        for(auto pi: vals[i]) {
            for(int j=0; j<pi.second; j++) {
                tot.push_back(make_pair(i, pi.first));
                cnt++;
                if(cnt >= s/i) break;
            }
            if(cnt >= s/i) break;
        }
    }

    vector<int> dp(s+1); // max amount with i weight
    for(auto pi: tot) {
        for(int i=s; i>=pi.first; i--) {
            dp[i] = max(dp[i], pi.second + dp[i-pi.first]);
        }
    }

    cout << dp[s] << "\n";

}
