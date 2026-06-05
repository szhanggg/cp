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

#define int long long

// 32 + 16 + 1
//

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, d, u; cin >> l >> r >> d >> u;
    int mx = max(abs(l), max(abs(r), max(abs(d), abs(u))));

    int ans = 0;

    for(int i=0; i<=mx; i+=2) {
        DEBUG(i, ans);
        if(i == 0) {
            if(l <= 0 && 0 <= r && d <= 0 && 0 <= u) ans++;
            continue;
        }
        // check each of the 4 sides
        int top = min(u, i);
        int bot = max(d, -i);
        int left = max(l, -i);
        int right = min(r, i);
        if(right < left || top < bot) continue;
        DEBUG(bot, top, left, right);
        if(l <= -i && r >= -i) ans += top-bot+1;
        if(r >= i && l <= i) ans += top-bot+1;
        if(d <= -i && u >= -i) ans += right-left+1;
        if(u >= i && d <= i) ans += right-left+1;
        // check the 4 corners
        if(l <= i && i <= r && d <= i && i <= u) ans--;
        if(l <= -i && -i <= r && d <= i && i <= u) ans--;
        if(l <= i && i <= r && d <= -i && -i <= u) ans--;
        if(l <= -i && -i <= r && d <= -i && -i <= u) ans--;
    }

    cout << ans << "\n";

}
