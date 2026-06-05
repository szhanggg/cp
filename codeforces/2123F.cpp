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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("test.in", "r", stdin);

    vector<int> maxp(1e5 + 1);
    for(int i=2; i<=1e5; i++)
        if(maxp[i] == 0)
            for(int j=i; j<=1e5; j+=i) maxp[j] = i;

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n+1);
        vector<bool> placed(n+1, false);
        a[1] = 1;
        placed[1] = true;

        for(int i=n; i>1; i--) {
            if(maxp[i] == i) {
                for(int j=i; j<=n; j+=i) {
                    if(placed[j]) continue;
                    for(int k=2*j; k<=n; k+=i) {
                        if(a[k] == 0) {
                            a[k] = j;
                            placed[j] = true;
                            break;
                        }
                    }
                    if(placed[j]) continue;
                    for(int k=i; k<j; k+=i) {
                        if(a[k] == 0) {
                            a[k] = j;
                            placed[j] = true;
                            break;
                        }
                    }
                    if(placed[j]) continue;
                    a[j] = j;
                }
            }
        }


        int tfp = 1;
        for(int i=2; i<=n; i++)
            if(maxp[i] == i && 2*i > n) tfp++;

        for(int i=2; i<=n; i++) {
            if(a[i] != i) continue;
            if(maxp[i] == i && 2*i > n) continue;
            bool fixed = false;
            int p = maxp[i];
            int cur = a[i];
            while(!fixed) {
                for(int j=p; j<=n; j+=p) {
                    if(j == i) continue;
                    if(a[j] != i && gcd(a[j], i) > 1) {
                        a[i] = a[j];
                        a[j] = i;
                        fixed = true;
                        break;
                    }
                }
                while(maxp[cur] != p) cur /= p;
                p = maxp[cur];
            }
        }

        for(int i=1; i<=n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        int cnt = 0;
        for(int i=1; i<=n; i++) if(a[i] == i) cnt++;
        DEBUG(cnt, tfp);
    }
    
}
