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

bool solve(int n, int k, vector<int>& a) {

    vector<int> pre(n); // the number of numbers <= k that are in 0...i
    int cur = 0;
    for(int i=0; i<n; i++) {
        if(a[i] <= k) cur++;
        else cur--;
        pre[i] = cur;
    }


    // if pre[i] >= i -> subarray counts

    vector<int> post(n); // the number of numbers <= k ) * 2 that are in i...n
    cur = 0;
    for(int i=n-1; i>-1; i--) {
        if(a[i] <= k) cur++;
        else cur--;
        post[i] = cur;
    }

    vector<int> mpre(n); mpre[0] = pre[0];
    for(int i=1; i<n; i++) mpre[i] = min(mpre[i-1], pre[i]);
    vector<int> mpost(n); mpost[n-1] = post[n-1];
    for(int i=n-2; i>=0; i--) mpost[i] = min(mpost[i+1], post[i]);

    DEBUG(pre, post, mpre, mpost);

    // Check if first and second
    for(int l=1; l<n-1; l++) {
        DEBUG(l);
        if(pre[l] >= 0 && mpost[l+1] - pre[l] >= 0) return true;
    }

    for(int l=1; l<n-1; l++) {
        DEBUG(l);
        if(pre[l] >= 0 && pre[n-1] - mpost[l+1] >= 0) return true;
    }

    for(int r=1; r<n; r++) {
        DEBUG(r);
        if(post[r] >= 0 && mpre[r-1] - post[r] >= 0) return true;
    }

    return false;


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n); for(int i=0; i<n; i++) cin >> a[i];
        if(solve(n, k, a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}
