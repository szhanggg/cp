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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, inp;
        cin >> n;
        int count0 = 0;
        int count1 = 0;
        vector<bool> a(n);
        for(int i=0; i<n; i++) {
            cin >> inp;
            if(inp % 2 == 0) {
                count0++;
                a[i] = false;
            } else {
                count1++;
                a[i] = true;
            }
        }

        // DEBUG(a);

        vector<bool>b = a;

        if(abs(count0 - count1) > 1) {
            cout << "-1\n";
            continue;
        }

        long long ans[2];
        ans[0] = LONG_LONG_MAX; ans[1] = LONG_LONG_MAX;

        //start 0
        
        if(count0 >= count1) {
            ans[0] = 0;
            for(int i=0; i<n; i++) {
                // DEBUG(i);
                bool look = i % 2;
                if(a[i] == look) continue;
                int ix;
                for(int j=i+1; j<n; j++) {
                    if(a[j] == look) {
                        ix = j;
                        break;
                    }
                }
                // DEBUG(ix);
                swap(a[i], a[ix]);
                ans[0] += ix - i;
            }
        }

        

        if(count1 >= count0) {
            ans[1] = 0;
            for(int i=0; i<n; i++) {
                // DEBUG(i);
                bool look = !(i % 2);
                if(b[i] == look) continue;
                int ix;
                for(int j=i+1; j<n; j++) {
                    if(b[j] == look) {
                        ix = j;
                        break;
                    }
                }
                // DEBUG(ix);
                swap(b[i], b[ix]);
                ans[1] += ix - i;
            }
        }

        cout << min(ans[0], ans[1]) << "\n";   

    }

}
