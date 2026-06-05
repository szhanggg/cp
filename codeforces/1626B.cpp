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
        string s;
        cin >> s;
        //check 2;

        bool found = false;

        for(int i=s.size()-1; i>0; i--) {
            int f = (s[i] - '0') + (s[i-1] - '0');
            if(f >= 10) {
                s[i] = '0' + f % 10;
                s[i-1] = '1';
                found = true;
                break;
            }
        }
        if(found) {
            cout << s << "\n";
            continue;
        }

        //check 1;
        for(int i=0; i<s.size()-1; i++) {
            int f = (s[i] - '0') + (s[i+1] - '0');
            if(f >= (s[i] - '0')) {
                s[i] = '0' + f;
                s[i+1] = 'N';
                found = true;
                break;
            }
        }

        if(!found) {
            int f = (s[s.size()-2] - '0') + (s[s.size()-1] - '0');
            s[s.size()-2] = '0' + f;
            s[s.size()-1] = 'N';
        }

        for(auto x: s) {
            if(x != 'N') cout << x;
        }
        cout << "\n";
        continue;
    }

}
