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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int exp(int x, int e) {
    int res = 1;
    while(e > 0) {
        if(e % 2 == 1) res *= x;
        x *= x;
        e /= 2;
    }
    return res;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> maxp(1e6+1);

    for(int p=2; p<=1e6; p++) {
        if(maxp[p] == 0) for(int i=p; i<=1e6; i+=p) maxp[i] = p;
    }

    vector<int> primes;

    for(int p=2; p<= 1e6; p++) {
        if(maxp[p] != p) continue;
        primes.push_back(p);
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int curgc = gcd(a[0], a[1]);
        for(int i=2; i<n; i++) curgc =gcd(curgc, a[i]);
        for(int i=0; i<n; i++) a[i] /= curgc;

        // loop through and find the prime factorization differences

        int x = 1;

        DEBUG(a);

        for(int i=1; i<n; i++) {
            if(a[i] % a[i-1] == 0) continue;
            int am = 1;
            if(a[i-1] <= 1e6) {
                int temp = a[i-1];
                int temp2 = a[i];
                while(temp > 1) {
                    int p = maxp[temp];
                    int pam = 0;
                    while(temp % p == 0) {
                        pam++;
                        temp /= p;
                    }
                    int pam2 = 0;
                    while(temp2 % p == 0) {
                        pam2++;
                        temp2 /= p;
                        if(pam2 == pam) break;
                    }
                    DEBUG(p, pam, pam2);
                    am *= exp(p, pam - pam2);
                }
            } else {
                int temp = a[i-1];
                int temp2 = a[i];
                for(int i=0; i<primes.size(); i++) {
                    int p = primes[i];
                    if(temp % p != 0) continue;
                    int pam = 0;
                    while(temp % p == 0) {
                        pam++;
                        temp /= p;
                    }
                    int pam2 = 0;
                    while(temp2 % p == 0) {
                        pam2++;
                        temp2 /= p;
                        if(pam2 == pam) break;
                    }
                    DEBUG(p, pam, pam2);
                    am *= exp(p, pam - pam2);
                    if(temp == 1) break;
                }
            }

            DEBUG(am);

            x /= gcd(x, am);
            x *= am;
        }

        cout << x << "\n";
        
    }
    
}
