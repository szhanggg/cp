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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        int base = n;
        for(int i=1; i<n; i++) {
            if(s[i] != s[i-1]) base++;
        }
        if(s[0] == '1') base++;

        int ans = base;

        bool seen0 = false;
        bool seen1 = false;

        int cur0 = 0;
        int cur1 = 0;

        
        if(s[0] == '0') {
            seen0 = true;
            cur1--;
        } else {
            seen1 = true;
            cur0++;
        }

        for(int i=1; i<n; i++) {
            int cur = 0;
            DEBUG(i, cur0, cur1);
            if(s[i] == '0') {
                if(!seen1) continue;
                cur = cur0;
                if(i < n-1) {
                    if(s[i+1] == '0') cur--;
                    else cur++;
                }
                ans = min(ans, base - cur);
            } else {
                if(seen0) {
                    cur = cur1;
                    if(i < n-1) {
                        if(s[i+1] == '1') cur--;
                        else cur++;
                    }
                    else cur++;
                    ans = min(ans, base - cur);
                }
            }
            if(s[i] == '0') {
                seen0 = true;
                if(s[i-1] == '1') cur1 = 1;
            } else {
                seen1 = true;
                if(s[i-1] == '0') cur0 = 1;
            }
            DEBUG(ans);
        }

        cout << ans << "\n";


    }
    
}
