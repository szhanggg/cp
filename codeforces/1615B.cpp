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

vector<int> query(int x) {
    vector<int> a(32, 0);
    int i = 0;
    while((1 << i) <= x) {

        bool k = 0;

        int change = 1 << i;

        for(int j=0; j<=x; j++) {

            a[i] += k;

            if(change == 1) {

                k = !k;
                change = 1 << i;

            } else {
                change--;
            }
        }

        i++;

    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;

        vector<int> a = query(l - 1);
        vector<int> b = query(r);

        int ans = 0;

        DEBUG(a);
        DEBUG(b);

        for(int i=0; i<32; i++) {
            ans = max(ans, b[i] - a[i]);
        }

        cout << r - l + 1 - ans << "\n";

    }

}
