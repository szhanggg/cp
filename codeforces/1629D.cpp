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
        vector<string> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        bool pre = false;
        for(auto x: a) {
            if(x.size() == 1) pre = true;
            if(x.size() == 2) {
                if(x[0] == x[1]) pre = true;
            }
            if(x.size() == 3) {
                if(x[0] == x[2]) pre = true;
            }
        }
        if(pre) {
            cout << "YES\n";
            continue;
        }

        bool table1[26][26][2]; //Third value is 0 if length 2, 1 if length 3
        bool table2[26][26][26];
        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                table1[i][j][0] = false;
                table1[i][j][1] = false;
                for(int k=0; k<26; k++) {
                    table2[i][j][k] = false;
                }
            }
        }

        bool found = false;
            
        for(auto x: a) {
            int i = x[0] - 'a';
            int j = x[1] - 'a';
            if(x.size() == 2) {
                // DEBUG(i, j);
                if(table1[j][i][0] || table1[j][i][1]) {
                    found = true;
                    break;
                }
                table1[i][j][0] = true;
            } else {
                int k = x[2] - 'a';
                // DEBUG(i, j, k);
                if(table2[k][j][i] || table1[k][j][0]) {
                    found = true;
                    break;
                }
                table2[i][j][k] = true;
                table1[i][j][1] = true;
            }
        }

        if(found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

}
