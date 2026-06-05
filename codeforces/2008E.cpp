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

int solve(vector<int> a, int n, int c1, int c2) {
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a(n);
        vector<bool> used(26, false);
        int totalused = 0;
        for(int i=0; i<n; i++) a[i] = s[i] - 'a';
        for(int i=0; i<n; i++) used[a[i]] = true;
        for(int i=0; i<n; i++) if(used[a[i]]) totalused++;
        int Aans = INT_MAX;
        vector<vector<int>> e(n+1, vector<int>(26, 0));
        vector<vector<int>> o(n+1, vector<int>(26, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<26; j++) {
                e[i+1][j] = e[i][j];
                o[i+1][j] = o[i][j];
            }
            if(i % 2 == 0) {
                e[i+1][a[i]]++;
            } else {
                o[i+1][a[i]]++;
            }
        }

        if(n % 2 == 1) {
            for(int j=0; j<26; j++) {
                for(int i=0; i<n; i++) {
                    // See how good swapping is at this point assuming 
        }
    }
    
}
