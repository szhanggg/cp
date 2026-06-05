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

int solve() {

    int n; cin >> n;
    string s; cin >> s;

    vector<int> groups;
    int cur = 0;
    int ans = 0;
    for(auto c: s) if(c == '1') ans++;
    for(int i=1; i<n; i++) {
        if(s[i] == '1') {
            s[i-1] = '2';
        }
    }
    for(int i=n-2; i>=0; i--) {
        if(s[i] == '1') {
            s[i+1] = '2';
        }
    }
    for(auto c: s) {
        if(c == '1' || c == '2') {
            groups.push_back(cur);
            cur = 0;
        } else {
            cur++;
        }
    }
    groups.push_back(cur);
    DEBUG(groups);
    DEBUG(s);
    for(auto x: groups) {
        ans += (x+2) / 3;
    }
    return ans;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
}
