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
 
bool solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> neww(n+1);

    for(int i=0; i<n; i++) {
        if(s[i] == '1') neww[i+1] = i+1;
    }

    if(s[0] == '0' && s[1] == '1') return false;
    if(s[n-1] == '0' && s[n-2] == '1') return false;

    for(int i=1; i<n-1; i++) {
        if(s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') return false;
    }

    int i=0;
    while(i < n) {
        while(s[i] == '1') {
            i++;
            if(i == n) break;
        }
        DEBUG(i);
        if(i == n) break;
        int j = i+1;
        if(j == n) break;
        while(s[j] == '0') {
            j++;
            if(j == n) break;
        }
        DEBUG(j);
        for(int k=i; k<j-1; k++) {
            DEBUG(k+1, k+2);
            neww[k+1] = k+2;
        }
        neww[j] = i+1;
        i = j+1;
    }

    cout << "YES\n";
    for(int j=1; j<=n; j++) {
        cout << neww[j] << " ";
    }
    cout << "\n";

    return true;

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        if(!solve()) {
            cout << "NO\n";
        };
    }
}
