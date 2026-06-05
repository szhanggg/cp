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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, d, k; cin >> n >> d >> k;
        vector<int> start(n);
        vector<int> end(n);
        for(int i=0; i<k; i++) {
            int x, y; cin >> x >> y;
            x--; y--;
            start[x]++;
            end[y]++;
        }

        int maxv = 0;
        int minv = INT_MAX;
        int maxvi = -1;
        int minvi = -1;

        int cur = 0;
        // Sum up the first d days
        for(int i=0; i<d; i++) {
            cur += start[i];
            if(i > 0) cur -= end[i-1];
        }
        if(cur >= maxv) {
            maxv = cur;
            maxvi = 0;
        }
        if(cur <= minv) {
            minv = cur;
            minvi = 0;
        }
        for(int r=d; r<n; r++) {
            int l = r - d + 1;
            cur += start[r];
            cur -= end[l-1];
            if(cur > maxv) {
                maxv = cur;
                maxvi = l;
            }
            if(cur < minv) {
                minv = cur;
                minvi = l;
            }
        }

        cout << maxvi + 1 << " " << minvi + 1 << "\n";
    }
    
}
