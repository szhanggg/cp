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

int solve() {

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    map<int, int> f;
    set<int> unseen;
    for(int i=0; i<n; i++) unseen.insert(i);

    for(int i=0; i<k; i++) {
        f[a[i]]++;
        unseen.erase(a[i]);
    }
    int rmax = k-1;
    int mmax = *unseen.begin();

    // for(int i=k; i<n; i++) {
    //     f[a[i]]++;
    //     f[a[i-k]]--;
    //     if(f[a[i-k]] == 0) {
    //         f.erase(a[i-k]);
    //     }
    //     if(*unseen.begin() > mmax) {
    //         rmax = i;
    //         mmax = *unseen.begin();
    //     }
    // }

    set<int> in;

    for(int i=0; i<n; i++) {
        in.insert(a[i]);
    }

    DEBUG(in);

    for(int i=0; i<=k-2; i++) {
        if(!in.count(i)) return i;
    }

    return k-1;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
}
