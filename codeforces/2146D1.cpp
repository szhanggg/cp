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
    vector<int> b(n);
    for(int i=r; i>=l; i--) {
        if(b[i]) continue;
        int bi = bitflip(i, k);
        if(l <= bi && bi <= l) {
            b[i-l] = bi;
            b[bi-l] = i;
        }
    }

    int left = 0;
    int right = n-1;

    DEBUG(b);

    for(int i=r; i>=l; i--) {
        if(b[i]) continue;
        int bi = bitflip(i, k);

        while(b[left] != 0) left++;
        while(b[right] != 0) right--;

        int lam = i | (left+l);
        int ram = i | (right+l);

        DEBUG(i, left, right);
        DEBUG(lam, ram);

        if(lam > ram) {
            b[left] = i;
            b[i-l] = left+l;
        } else {
            b[right] = i;
            b[i-l] = right+l;
        }

    }


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
