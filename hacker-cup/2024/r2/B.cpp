#include <bits/stdc++.h>
using namespace std;

#define int long long
 
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

int a, b, m;
int ans;

void genNextInc(int k, int i, int cur, int num) {
    if(i > 2*k-1) return;
    if(num > b) return;
    if(i == 2*k-1) {
        if(num % m == 0 && num >= a) {
            ans++;
        }
    }
    // cur is the current digit
    if(i < k) {
        // Generate all possible non-monotonically next numbers
        for(int j=cur; j<=9; j++) {
            if(j == cur && i == k-1) continue;
            genNextInc(k, i+1, j, num + j * pow(10, (2*k-2 - i)));
        }
    } else {
        // Generate all possible monotonically non-increasing numbers
        for(int j=cur; j>=1; j--) {
            if(j == cur && i == k) continue;
            genNextInc(k, i+1, j, num + j * pow(10, (2*k-2 - i)));
        }
    }

}

int solve() {
    cin >> a >> b >> m;
    ans = 0;
    for(int k=1; k<=9; k++) {
        // 2k-1 is the length of the number
        // Loop through all combinations of first k+1 digits
        // They  have to be monotonically non-decreasing
        for(int i=1; i<=9; i++) {
            genNextInc(k, 1, i, i * pow(10, 2*k-2));
        }
    }

    return ans;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("B.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int test=1; test<=t; test++) {
        int ans = solve();
        cout << "Case #" << test << ": " << ans << "\n";
    }
    
}

