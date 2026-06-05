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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, calc;
    cin >> n >> q;
    int prefix[n][n];
    char inp;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> inp;
            calc = 0;
            if(inp == '*') calc = 1;
            if(i > 0) calc += prefix[i-1][j];
            if(j > 0) calc += prefix[i][j-1];
            if(i > 0 && j > 0) calc -= prefix[i-1][j-1];
            prefix[i][j] = calc;
            DEBUG(i);
            DEBUG(j);
            DEBUG(calc);
        }
    }

    while(q--) {
        int x1, y1, x2, y2, ans;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;x1--;y2--;x2--;
        ans = prefix[y2][x2];
        if(x1 > 0) ans -= prefix[y2][x1-1];
        if(y1 > 0) ans -= prefix[y1-1][x2];
        if(x1 > 0 && y1 > 0) ans += prefix[y1-1][x1-1];
        cout << ans << "\n";
    }

}
