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

    cout << fixed << setprecision(12);

    int n; cin >> n;
    vector<int> a(3);

    for(int i=0; i<n; i++) {
        int x; cin >> x; x--;
        a[x]++;
    }
    vector<vector<vector<double>>> dp(301, vector<vector<double>>(301, vector<double>(301)));

    auto calc = [&] (auto self, int x, int y, int z) -> double {
        if(x + y + z == 0) return 0;
        if(dp[x][y][z]) return dp[x][y][z];
        double ans = 0;
        double rem = (double) (x+y+z);
        if(x > 0) ans += (x / rem) * self(self, x-1, y, z);
        if(y > 0) ans += (y / rem) * self(self, x+1, y-1, z);
        if(z > 0) ans += (z / rem) * self(self, x, y+1, z-1);
        ans += n / rem;
        dp[x][y][z] = ans;
        return ans;
    };

    cout << calc(calc, a[0], a[1], a[2]) << "\n";
    
}
