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

    int n; cin >> n;

    int maxb = -1;
    for(int i=0; i<32; i++) if(n & (1 << i)) maxb = i;

    vector<int> valid;
    for(int i=1; i<n; i++) valid.push_back(i);

    int ans = 0;

    int cnt = 0;

    for(int i=1; i<=n; i++) {
        if(i & 1) cnt++;
    }

 
    for(int b=0; b<=maxb; b++) {
        int zc = 0;
        int oc = 0;
        vector<int> z;
        vector<int> o;
        for(auto x: valid) {
            cout << "? " << x << " " << (1 << b) << endl;
            int r; cin >> r;
            if(r == 0) {
                zc++;
                z.push_back(x);
            } else {
                oc++;
                o.push_back(x);
            }
        }

        DEBUG(zc, oc, z, o);
        DEBUG(cnt);

        if(oc == cnt) {
            valid = z;
        } else {
            valid = o;
            ans += (1 << b);
        }
        cnt = 0;
        DEBUG(ans);
        for(int i=1; i<=n; i++) {
            int mask = (1 << (b+1)) -1;
            if((i & mask) == ans) {
                DEBUG(i);
                if(i & (1 << (b+1))) cnt++;
            }
        }

        DEBUG(cnt);
    }

    cout << "! " << ans << endl;
    
}
 
signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
