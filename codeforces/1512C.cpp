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
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int n = s.size();
        int f = (n % 2 == 0 ? n / 2 : n / 2 + 1);

        int a1 = 0; int b1 = 0;
        
        bool found = false;

        for(int i=0; i<n; i++) {
            if(s[i] == '0') {
                a1++;
            }
            if(s[i] == '1') {
                b1++;
            }
        }

        for(int i=0; i<f; i++) {
            char counter = s[n-1-i];
            if(i == (n / 2)) {
                if(s[i] == '?') {
                    if(a1 < a) {
                        s[i] = '0';
                        a1++;
                    } else {
                        s[i] = '1';
                        b1++;
                    }
                }
            } else if(s[i] == '?') {
                if(counter == '?') {
                    if(a1 < a - 1) {
                        s[i] = '0';
                        s[n-1-i] = '0';
                        a1+=2;
                    } else {
                        s[i] = '1';
                        s[n-1-i] = '1';
                        b1+=2;
                    }
                } else {
                    s[i] = counter;
                    if(s[i] == '0') {
                        a1++;
                    } else {
                        b1++;
                    }
                }
            } else {
                if(s[i] != counter && counter != '?') found = true;
                if(counter == '?') {
                    s[n-1-i] = s[i];
                    if(s[i] == '0') {
                        a1++;
                    } else {
                        b1++;
                    }
                }
            }
        }

        DEBUG(s, a1, b1);

        if(a1 != a || b1 != b) found = true;
        if(found) {
            cout << "-1\n";
            continue;
        }

        cout << s << "\n";

    }

}
