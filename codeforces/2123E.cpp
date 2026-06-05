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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int cur = a[0];
        vector<int> b;
        for(auto x: a) {
            if(x - cur > 1) break;
            b.push_back(x);
            cur = x;
        }
        int leftover = n - b.size();
        int leftover2 = 0;
        int n2 = b.size();
        cur = a[0];
        int cursz = 1;
        vector<int> accu(n+3);
        DEBUG(a);
        DEBUG(b);
        for(int i=1; i<n2; i++) {
            if(b[i] == cur) {
                cursz++;
            } else {
                // in order for the MEX to be b[i]
                // k can be anywhere from cursz to n - i + cursz
                accu[cursz]++;
                accu[n - i + cursz + 1 + leftover2]--;


                leftover2 += cursz - 1;

                cur = b[i];
                cursz = 1;
            }
        }
        accu[cursz]++;
        accu[n - n2 + cursz + 1 + leftover2]--;
        leftover2 += cursz - 1;
        accu[leftover + leftover2 + 1]--;
        accu[0]++;

        int accum = 0;
        for(int i=0; i<=n; i++) {
            accum += accu[i];
            if(a[0] == 0) cout << accum << " ";
            else cout << 1 << " ";
        }
        cout << "\n";
    }
    
}
