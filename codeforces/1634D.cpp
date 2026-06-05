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
        int n;
        cin >> n;

        vector<int> a(n + 1, INT_MAX);
        vector<int> ans;

        for(int i=2; i<=n-1; i++) {
            cout << "? " << i-1 << " " << i << " " << i + 1 << endl;
            cin >> a[i];
        }

        DEBUG(a);

        //Skip i

        for(int i=2; i<=n-2; i++) {
            int inp;
            cout << "? " << i-1 << " " << i+1 << " " << i+2 << endl;
            cin >> inp;
            DEBUG(inp, a[i-1], a[i], a[i+1]);
            if(inp <= a[i-1] && inp <= a[i] && inp <= a[i+1]) {
                ans.push_back(i);
            }
        }

        int inp;
        cout << "? " << n-3 << " " << n-2 << " " << n << endl;
        cin >> inp;

        if(inp <= a[n-2] && inp <= a[n-1]) {
            ans.push_back(n-1);
        }

        if(ans.size() == 0) {
            cout << "! 1 " << n << endl;
        } else {
            if(ans.size() > 1) {
                cout << "! " << ans[0] << " " << ans[1] << endl;
            } else {
                cout << "! " << ans[0] << " " << ans[0] + 1 << endl;
            }
        }

    }

}
