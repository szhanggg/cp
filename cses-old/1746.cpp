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

    int n, m; cin >> n >> m;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];

    vector<int> prev(m+1);
    vector<int> next(m+1);
    int sum = 0;

    if(x[0] == 0) {
        fill(prev.begin(), prev.end(), 1);
        prev[0] = 0;
        sum = m;
    } else {
        prev[x[0]] = 1;
        sum = 1;
    }

    // DEBUG(0, prev);

    for(int i=1; i<n; i++) {
        fill(next.begin(), next.end(), 0);
        if(x[i] != 0) {
            next[x[i]] = prev[x[i]] + prev[x[i]-1];
            if(x[i]<m) next[x[i]] += prev[x[i]+1];
            next[x[i]] %= MOD;
            prev = next;
            sum = next[x[i]];
            // DEBUG(i, next);
            continue;
        }
        sum = 0;
        for(int j=1; j<=m; j++) {
            int am = prev[j];
            if(j > 0) am+=prev[j-1];
            if(j < m) am+=prev[j+1];
            am %= MOD;
            next[j] = am;
            sum += am;
            sum %= MOD;
        }
        // DEBUG(i, next);
        prev = next;
    }

    cout << sum << "\n";
    
}
