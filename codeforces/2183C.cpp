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

bool check(int n, int m, int k, int x) {

    DEBUG(n, m, k, x);

    if(x > n) return false;
    int need = x-1;
    int side = min(k-1, n-k);
    int small = min(side, need/2);
    int big = need-small;

    int ans = 0;
    ans += 2*big-1;
    ans += small;

    return ans <= m;

}

int solve() {

    int n, m, k; cin >> n >> m >> k;
    int lb = 1;
    int ub = n+1;
    while(lb < ub) {
        int mid = lb + (ub-lb)/2;
        if(check(n, m, k, mid)) {
            lb = mid + 1;
        } else {
            ub = mid;
        }
    }

    return lb - 1;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
}
