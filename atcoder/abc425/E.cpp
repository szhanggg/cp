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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, m;
    cin >> t >> m;


    while(t--) {
        int n; cin >> n;
        vector<int> c(n);

        for(int i=0; i<n; i++) cin >> c[i];

        int sum = 0;
        for(int i=0; i<n; i++) sum += c[i];

        vector<int> a(sum+1);
        iota(a.begin(), a.end(), 0);

        int cur = 1;
        int ans = 1;

        for(auto x: c) {
            for(int i=x; i>= 2; i--) {
                int k = i;
                for(int j=cur; j<cur+x; j++) {
                    int g = gcd(k, a[j]);
                    a[j] /= g;
                    k /= g;
                    if(k == 1) break;
                }
            }
            cur = cur+x;
        }


        for(int i=1; i<=sum; i++) {
            ans *= a[i];
            ans %= m;
        }


        cout << ans << "\n";

    }
    
}
