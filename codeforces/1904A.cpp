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

    int t;
    cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        int xk, yk; cin >> xk >> yk;
        int xq, yq; cin >> xq >> yq;

        vector<pair<int, int>> combos = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        set<pair<int, int>> points;
        for(auto x: combos) {
            for(auto y: combos) {
                if(xk + x.first*a + y.first*b == xq && yk + x.second*b + y.second*a == yq) points.insert(make_pair(xk+x.first*a, yk+x.second*b));
                if(xk + x.first*a + y.first*a == xq && yk + x.second*b + y.second*b == yq) points.insert(make_pair(xk+x.first*a, yk+x.second*a));
                if(xk + x.first*b + y.first*a == xq && yk + x.second*a + y.second*b == yq) points.insert(make_pair(xk+x.first*b, yk+x.second*a));
                if(xk + x.first*b + y.first*b == xq && yk + x.second*a + y.second*a == yq) points.insert(make_pair(xk+x.first*b, yk+x.second*b));
            }
        }

        cout << points.size() << "\n";
    }
    
}
