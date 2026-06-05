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
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        vector<int> a;
        int cur = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '0') {
                cur++;
            } else {
                if(cur != 0) a.push_back(cur);
                a.push_back(0);
                cur = 0;
            }
        }

        if(cur != 0) a.push_back(cur);

        int curam = 0;
        for(auto i: a) {
            if(i >= 0) curam += i / x;
        }

        DEBUG(curam);

        int maxi = 0;

        DEBUG(a);

        for(int i=1; i<a.size(); i++) {
            if(a[i] != 0) continue;

            int f = a[i-1] + 1 + a[i+1];
            DEBUG(i, f);
            if(f / x > a[i-1] / x + a[i+1] / x) {
                maxi = max(maxi, (f / x) - (a[i-1] / x + a[i+1] / x));
            }
        }

        cout << curam + maxi << "\n";
    }

}
