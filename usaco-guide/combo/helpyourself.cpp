// AC
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

    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);

    vector<long long> pow;

    long long cur = 1;

    for(int i=0; i<100007; i++) {
        pow.push_back(cur);
        cur *= 2;
        cur %= MOD;
    }

    int n; cin >> n;
    vector<int> am(2*n+2);
    vector<int> a(2*n+2);
    vector<int> l(n);
    vector<int> r(n);

    for(int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
        am[l[i]]++; am[r[i]]--;
    }

    cur = 0;
    for(int i=0; i<2*n+1; i++) {
        cur += am[i];
        a[i] = cur;
    }

    long long ans = 0;

    for(int i=0; i<n; i++) {
        int g = n - a[l[i]-1] - 1;
        ans += pow[g];
        ans %= MOD;
    }

    cout << ans << "\n";
    
}
