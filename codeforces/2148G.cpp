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
 
void solve() {

    int n; cin >> n;
    vector<int> a(n);

    int maxe = 0;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) maxe = max(maxe, a[i]);

    vector<int> div(n+1);
    vector<int> nums;
    vector<int> newnums;

    int ans = 0;

    for(int i=0; i<n; i++) {
        newnums.clear();
        for(int j=1; j*j<=maxe; j++) {
            if(j*j > a[i]) continue;
            if(a[i] % j == 0) {
                div[j]++;
                if(j*j != a[i]) {
                    div[a[i]/j]++;
                    if(div[a[i]/j] != i+1) ans = max(ans, div[a[i]/j]);
                    else newnums.push_back(a[i]/j);
                }
            }
            if(j > 1 && div[j] != i+1) ans = max(ans, div[j]);
            if(div[j] == i+1) newnums.push_back(j);
        }

        for(auto x: nums) if(div[x] != i+1) ans = max(ans, div[x]);
        nums = newnums;
        newnums.clear();
        
        cout << ans << " ";
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
