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

    int t;
    cin >> t;
    while(t--) {
        int n, inp, inp2, ind;
        cin >> n;
        vector<int> p(n+1, -1);
        cout << "? 1" << endl;
        cin >> inp;
        cout << "? " << 1 << endl;
        cin >> inp;
        p[1] = inp;
        ind = 1;
        for(int query=1; query<=2*n; query++) {
            if(p[inp] != -1) {
                for(int i=1; i<=n; i++) {
                    inp++;
                    if(inp == n+1) inp = 1;
                    if(p[inp] != -1) {
                        break;
                    }
                }
                break;
            }
            cout << "? " << inp << endl;
            cin >> inp2;
            
            if(inp == inp2) {

            } else {

            }
            

        }
    }

}
