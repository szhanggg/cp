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

const int MAXA = 2e5 + 7;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    vector<int> maxp(MAXA);
    for(int i=2; i<MAXA; i++)
        if(maxp[i] == 0)
            for(int j=i; j<MAXA; j+=i) maxp[j] = i;

    vector<int> primes;
    for(int i=2; i<MAXA; i++) if(maxp[i] == i && i <= mx) primes.push_back(i);

    int ans = 1;
    for(auto p: primes) {
        int zcnt = 0;
        vector<int> tcnt;
        for(auto x: a) {
            if(zcnt >= 2) break;
            int cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt++;
            }
            if(cnt == 0) zcnt++;
            tcnt.push_back(cnt);
        }
        DEBUG(p, tcnt);
        if(zcnt >= 2) continue;
        int mn = *min_element(tcnt.begin(), tcnt.end());
        int smn = INT_MAX;
        int mncnt = 0;
        for(auto x: tcnt) {
            if(x == mn) {
                mncnt++;
            } else {
                smn = min(smn, x);
            }
        }
        int power = mncnt == 1 ? smn : mn;
        ans *= pow(p, power);
    }

    cout << ans << "\n";
    
}
