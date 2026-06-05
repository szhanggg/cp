#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

#define int long long
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

map<pair<int, int>, int> mp;

vector<int> a1, a2;

int solve(int n, int m) {
    // n represents a1, m represents a2
    // 4 cases:
    if(n == -1 && m == -1) return 0;
    if(n < 0 || m < 0) return -1000000;
    if(mp.count(make_pair(n, m))) return mp[make_pair(n, m)];
    int ans = 0;
    if(n == m) {
        if(n > 0) {
            int cur = (a1[n] + a2[m] + a1[n-1]) >= 2;
            ans = max(ans, solve(n-2, m-1) + cur);
        }
        if(m > 0) {
            int cur = (a1[n] + a2[m] + a2[m-1]) >= 2;
            ans = max(ans, solve(n-1, m-2) + cur);
        }

        int cur = (a1[n] + a1[n-1] + a1[n-2]) >= 2;
        cur += (a2[m] + a2[m-1] + a2[m-2]) >= 2;
        ans = max(ans, solve(n-3, m-3) + cur);
    } else if (n - 1 == m) {
        int cur = (a1[n] + a2[m] + a1[n-1]) >= 2;
        ans = max(ans, solve(n-2, m-1) + cur);

        cur = (a1[n] + a1[n-1] + a1[n-2]) >= 2;
        cur += (a2[m] + a2[m-1] + a2[m-2]) >= 2;
        ans = max(ans, solve(n-3, m-3) + cur);
    } else if (m - 1 == n) {
        int cur = (a1[n] + a2[m] + a2[m-1]) >= 2;
        ans = max(ans, solve(n-1, m-2) + cur);

        cur = (a1[n] + a1[n-1] + a1[n-2]) >= 2;
        cur += (a2[m] + a2[m-1] + a2[m-2]) >= 2;
        ans = max(ans, solve(n-3, m-3) + cur);
    }

    mp[make_pair(n, m)] = ans;
    DEBUG(n, m, ans);
    DEBUG(mp);
    return ans;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        mp.clear();
        int n; cin >> n;
        string s1, s2; cin >> s1 >> s2;
        a1.resize(n);
        a2.resize(n);
        for(int i = 0; i < n; i++) {
            a1[i] = s1[i] == 'A';
            a2[i] = s2[i] == 'A';
        }

        DEBUG(n, a1, a2);

        cout << solve(n-1, n-1) << '\n';
    }
    
}
