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

int bitflip(int x, int k) {
    x = ~x;
    x &= (1 << k) - 1;
    return x;
}
 
void solve() {

    int l, r; cin >> l >> r;
    int n = r-l+1;

    int k = 0;
    int rx = r;
    while(rx > 0) {
        rx /= 2;
        k++;
    }

    vector<int> a(n);
    iota(a.begin(), a.end(), l);
    DEBUG(a);
    vector<int> b(n);
    int j = 0;
    r = n-1;
    for(int i=r; i>=l; i--) {
        if(i == 0) continue;
        if(b[i-l]) continue;
        int pi = bitflip(i, k);
        DEBUG(i, pi);
        if(pi <= r && pi >= l) {
            if(b[pi-l] == 0) {
                b[i-l] = pi;
                b[pi - l] = i;
                continue;
            }
        } else if(pi < l) {
            while(b[j] != 0) {
                j++;
            }
            b[i-l] = j+l;
            b[j] = i;
        } else {
            while(b[r-1] != 0) {
                r--;
            }
            b[i-l] = r+l;
            b[r] = i;
        }
    }

    DEBUG(b);

    int sum = 0;

    for(int i=0; i<n; i++) {
        sum += b[i] | a[i];
    }

    cout << sum << "\n";
    for(auto x: b) {
        cout << x << " ";
    }
    cout << "\n";
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}

