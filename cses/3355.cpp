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

    vector<int> vals(1e7+1, -1);

    for(int i=0; i<3163; i++) {
        for(int j=i; j<3163; j++) {
            int x = i*i+j*j;
            if(x >= 1e7) continue;
            vals[i*i+j*j] = i;
        }
    }

    vector<int> pos;
    for(int i=0; i<1e7+1; i++) if(vals[i] >= 0) pos.push_back(i);

    while(t--) {
        int n; cin >> n;
        vector<int> ans(4);
        DEBUG(n);
        for(int i: pos) {
            if(vals[n-i] >= 0) {
                ans[0] = vals[i];
                ans[1] = sqrt(i - vals[i]*vals[i]);
                ans[2] = vals[n-i];
                ans[3] = sqrt(n-i - ans[2]*ans[2]);
                break;
            }
        }
        for(int i=0; i<4; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
