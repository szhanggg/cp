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

const int MAXN = 1e5+7;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> maxp(MAXN, 0);
    for(int p=2; p<MAXN; p++) {
        if(maxp[p] != 0) continue;
        for(int j=p; j<MAXN; j+=p) maxp[j] = p;
    
    }

    int n; cin >> n;
    vector<int> primes;

    int x = n;
    while(x != 1) {
        int p = maxp[x];
        primes.push_back(p);
        while(x % p == 0) x /= p;
    } 
    vector<bool> vals(n, true);
    vals[0] = false;
    for(int p : primes) {
        for(int j=p; j<n; j+=p) vals[j] = false;
    }

    int ans = 1;
    for(int i=2; i<n; i++) {
        if(vals[i]) {
            ans *= i;
            ans %= n;
        }
    }
    if(ans != 1) vals[ans] = false;
    cout << count(vals.begin(), vals.end(), true) << "\n";
    for(int i=1; i<n; i++)
        if(vals[i])
            cout << i << " ";

    cout << "\n";
}
