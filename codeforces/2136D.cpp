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

const int k = 1e9;
 
signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> x(n), y(n);
        int s;
        for(int i=0; i<n; i++) cin >> x[i] >> y[i];

        // X + 2e9 - ur[x] + Y + 2e9 - ur[y] = X + Y + 4e9 - ur[x] - ur[y]
        // bottom left
        // X + 2e9 - lr[x] - (Y - 2e9 - lr[y]) = X - Y + 4e9 - lr[x] + lr[y]

        cout << "? U " << k << endl; cin >> s;
        cout << "? U " << k << endl; cin >> s;
        cout << "? R " << k << endl; cin >> s;
        cout << "? R " << k << endl; cin >> s;
        DEBUG(s);
        
        int urx, ury, lrx, lry;
        int curur = 0; int curlr = 4*k;

        for(int i=0; i<n; i++) {
            int urd = x[i] + y[i];
            if(urd >= curur) {
                curur = urd;
                urx = x[i];
                ury = y[i];
            }
            int lrd = abs(k - x[i]) + abs(-1*k - y[i]);
            if(lrd <= curlr) {
                curlr = lrd;
                lrx = x[i];
                lry = y[i];
            }
        }

        int sum = s - 4*k + urx + ury;
        DEBUG(sum);
        cout << "? D " << k << endl; cin >> s;
        cout << "? D " << k << endl; cin >> s;
        cout << "? D " << k << endl; cin >> s;
        cout << "? D " << k << endl; cin >> s;

        int diff = s - 4*k + lrx - lry;
        DEBUG(diff);

        int xv = (sum + diff) / 2;
        int yv = (sum - diff) / 2;

        cout << "! " << xv << " " << yv << endl;
    }
    
}
