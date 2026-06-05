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
const int MOD = 676767677;

int solve() {

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) a[i]--;

    vector<int> b(n);
    for(int i=0; i<n; i++) b[i] = a[i];
    vector<int> c(n);
    for(int i=0; i<n; i++) c[i] = b[i];

    if(n == 1) {
        if(a[0] == 0) {
            return 2;
        } else {
            return 0;
        }
    }

    int ans = 0;

    vector<int> aor(n); // 1 means right

    // sps a[0] is left
    int left = 1;
    for(int i=1; i<n; i++) {
        a[i] -= left;
        // a[i] is now the number of right

        int id = a[i-1] - a[i];
        if(id == 1) {
            //a[i] must be right
            aor[i] = 1;
        } else {
            left++;
        }
    }

    left = 0;
    vector<int> bor(n);
    bor[0] = 1;

    for(int i=1; i<n; i++) {
        b[i] -= left;
        int id = b[i-1] - b[i];
        if(id == 1) {
            bor[i] = 1;
        } else {
            left++;
        }
    }


    // now we actually check if both of these arrays work
    vector<int> apre(n+1);
    for(int i=0; i<n; i++) apre[i+1] = apre[i] + aor[i];
    vector<int> bpre(n+1);
    for(int i=0; i<n; i++) bpre[i+1] = bpre[i] + bor[i];

    // apre[i+1] = number of rights from 0.. i

    int avalid = true;
    int bvalid = true;

    for(int i=0; i<n; i++) {
        int amt = 0;
        // count number of lefts from 0..i-1
        if(i > 0) amt += i - apre[i];
        if(i < n-1) {
            amt += apre[n];
            amt -= apre[i+1];
        }
        if(amt != c[i]) avalid = false;
    }
    if(avalid) ans++;
     for(int i=0; i<n; i++) {
        int amt = 0;
        // count number of lefts from 0..i-1
        if(i > 0) amt += i - bpre[i];
        if(i < n-1) {
            amt += bpre[n];
            amt -= bpre[i+1];
        }
        if(amt != c[i]) bvalid = false;
    }
    if(bvalid) ans++;
 
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
