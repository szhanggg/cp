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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<char>> g(n, vector<char>(n));
        int x1, x2, y1, y2;
        bool found = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> g[i][j];
                if(g[i][j] == '*') {
                    if(found) {
                        x2 = i;
                        y2 = j;
                    } else {
                        x1 = i;
                        y1 = j;
                        found = true;
                    }
                }
            }
        }

        DEBUG(x1, y1, x2, y2);
        
        if(x1 == x2) {
            if(x1 > 0) {
                g[x1-1][y1] = '*';
                g[x1-1][y2] = '*';
            } else {
                g[x1+1][y1] = '*';
                g[x1+1][y2] = '*';
            }
        } else if(y1 == y2) {
            if(y1 > 0) {
                g[x1][y1-1] = '*';
                g[x2][y1-1] = '*';
            } else {
                g[x1][y1+1] = '*';
                g[x2][y1+1] = '*';
            }
        } else {
            g[x1][y2] = '*';
            g[x2][y1] = '*';
        }

        for(auto x: g) {
            for(auto i: x) {
                cout << i;
            }
            cout << "\n";
        }

    }

}
