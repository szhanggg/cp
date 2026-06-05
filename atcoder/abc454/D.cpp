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
    string a, b; cin >> a >> b;

    vector<bool> ain(a.size(), true);
    vector<bool> bin(b.size(), true);
    int n = a.size(); int m = b.size();

    DEBUG(n, m);

    for(int i=1; i<n-2; i++) {
        if(a[i-1] == '(' && a[i] == 'x' && a[i+1] == 'x' && a[i+2] == ')') {
            DEBUG(i);
            int ii = i-1;
            int jj = i+2;
            while(ii >= 0 && jj < n && a[ii] == '(' && a[jj] == ')') {
                ain[ii] = false; ain[jj] = false;
                ii--; jj++;
            }
            i = jj;
        }
    }
    for(int i=1; i<m-2; i++) {
        if(b[i-1] == '(' && b[i] == 'x' && b[i+1] == 'x' && b[i+2] == ')') {
            DEBUG(i);
            int ii = i-1;
            int jj = i+2;
            while(ii >= 0 && jj < m && b[ii] == '(' && b[jj] == ')') {
                bin[ii] = false; bin[jj] = false;
                ii--; jj++;
            }
            i = jj;
        }
    }

    DEBUG(ain, bin);

    int i=0;
    int j=0;

    while(true) {
        while(i < n && !ain[i]) i++;
        while(j < m && !bin[j]) j++;
        if(i == n && j == m) return true;
        if(i == n || j == m) return false;
        if(a[i] != b[j]) return false;
        i++; j++;
    }
    return false;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        if(solve()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}
