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

vector<int> primes;

long long solve() {
    int n; cin >> n;

    if(n <= 4) return 0;

    long long ans = 1;
    for(int i=1; i<n; i++) {
        long long p = primes[i];
        if(p > n) break;
        if(p - primes[i-1] == 2) ans++;
    }


    return ans;

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("prime_subtractorization_input.txt", "r", stdin);
    freopen("bout.txt", "w", stdout);

    // freopen("b.txt", "r", stdin);
    // freopen("bout.txt", "w", stdout);
    
    vector<bool> is_prime(1e7 + 7, true);
    is_prime[0] = is_prime[1] = false;

    for(int p=2; p*p<=1e7; p++) {
        if(is_prime[p])
            for(int i=p*p; i<=1e7; i+=p) is_prime[i] = false;
    }

    for(int i=2; i<=1e7; i++) if(is_prime[i]) primes.push_back(i);
 
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
        cout << "Case #" << i << ": ";
        cout << solve() << "\n";
    }
    
}

