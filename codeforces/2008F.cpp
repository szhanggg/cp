#include <bits/stdc++.h>
using namespace std;
#define int __int128
 
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

int findProductSum(vector<long long>A, int n, int mod)
{ 
    // calculating array sum (a1 + a2  ... + an) 
    int array_sum = 0; 
    for (int i = 0; i < n; i++) 
        array_sum = (array_sum + A[i]) % mod;
  
    // calculating square of array sum 
    // (a1 + a2 + ... + an)^2 
    int array_sum_square = array_sum * array_sum; 
    array_sum_square = array_sum_square % mod;
  
    // calculating a1^2 + a2^2 + ... + an^2 
    int individual_square_sum = 0; 
    for (int i = 0; i < n; i++) 
        individual_square_sum += (A[i]*A[i]) % mod;
  
    // required sum is (array_sum_square - 
    // individual_square_sum) / 2 
    return ((array_sum_square - individual_square_sum)/2) % mod;
}

long long binExpo(int a, int b, int mod) 
{ 
    int ans = 1; 
    while (b > 0) { 
        if (b & 1) 
            ans = (ans * a) % mod; 
        a = (a * a) % mod; 
        b = b >> 1; 
    } 
    return ans % mod;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int mod = 1e9 + 7;

    DEBUG(binExpo(3, mod-2, mod));

    long long t; cin >> t;
    while(t--) {
        long long n; cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int ans = 0;
        ans = findProductSum(a, n, mod);
        DEBUG((long long)ans);
        // Find q^-1 mod 1^9 + 7
        int q = binExpo((n*(n-1))/2, mod-2, mod);
        cout << (long long) ((ans * q) % mod) << "\n";

    }
    
}
