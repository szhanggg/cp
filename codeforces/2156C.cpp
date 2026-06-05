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
 
void solve() {

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> div(n+1);
    vector<int> cnt(n+1);
    for(int i=0; i<n; i++) cnt[a[i]]++;

    vector<int> pre(n+2);
    for(int i=0; i<=n; i++) pre[i+1] = pre[i] + cnt[i];

    for(int i=1; i<=n; i++) {
        div[i] += pre[n+1] - pre[min(i*4, n+1)];
    }

    for(int i=0; i<n; i++) {
        for(int j=1; j*j<= a[i]; j++) {
            if(a[i] % j == 0) {
                if(a[i] < 4*j) div[j]++;
                if(a[i] / j != j) 
                    if(a[i] < 4*(a[i]/j)) div[a[i]/j]++;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
        if(div[i] >= n-k) ans = i;
    cout << ans << "\n";

    DEBUG(div);

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
