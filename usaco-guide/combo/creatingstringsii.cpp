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

const int MOD = 1e9 + 7;

long long binexp(long long a, long long b) {
    long long cur = a;
    long long ans = 1;
    while(b) {
        if(b & 1) ans *= cur;
        ans %= MOD;
        b /= 2;
        cur *= cur;
        cur %= MOD;
    }
    return ans;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    int n = s.size();
    
    vector<int> cnt(26);

    for(int i=0; i<n; i++) {
        cnt[s[i] - 'a']++;
    }

    long long cur = 1;
    vector<int> fact;
    for(int i=1; i<n+2; i++) {
        fact.push_back(cur);
        cur *= i;
        cur %= MOD;
    }

    long long ans = fact[n];
    for(auto x: cnt) {
        ans *= binexp(fact[x], MOD-2);
        ans %= MOD;
    }

    cout << ans << "\n";

}
