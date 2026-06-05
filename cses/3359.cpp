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

    // freopen("test.in", "r", stdin);
    
    int n; cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++) cin >> s[i];

    vector<vector<int>> ord(n, vector<int>(n));

    vector<int> pi(n);
    
    for(int d=2*(n-1); d>=0; d--) {
        //d is length of diagonal
        int is = 0;
        if(d > n-1) is = d - (n-1);
        int im = n-1;
        if(d < n-1) im = d;
 
        int len = im-is+1;
 
        iota(pi.begin(), pi.begin() + len, is);
 
        sort(pi.begin(), pi.begin() + len, [&] (int a, int b) {
            int af = a;
            int as = d - a;
            int bf = b;
            int bs = d - b;
            if(s[af][as] == s[bf][bs]) {
                int ma = INT_MAX;
                int mb = INT_MAX;
                if(af < n-1) ma = min(ma, ord[af+1][as]);
                if(as < n-1) ma = min(ma, ord[af][as+1]);
                if(bf < n-1) mb = min(mb, ord[bf+1][bs]);
                if(bs < n-1) mb = min(mb, ord[bf][bs+1]);
                return ma < mb;
            }
            return s[af][as] < s[bf][bs];
        });
 
        for(int i=0; i<len; i++) {
            ord[pi[i]][d-pi[i]] = i;
        }
    }
    int i=0; int j=0;

    while(i != n-1 || j != n-1) {
        cout << s[i][j];
        if(i == n-1) {
            j++;
            continue;
        }
        if(j == n-1) {
            i++;
            continue;
        }

        if(ord[i+1][j] < ord[i][j+1]) {
            i++;
        } else {
            j++;
        }
    }

    cout << s[n-1][n-1] << "\n";

}
