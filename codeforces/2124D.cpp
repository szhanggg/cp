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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        if(k <= 2) {
            cout << "YES\n";
            continue;
        }

        vector<int> b(n);
        for(int i=0; i<n; i++) b[i] = a[i];
        sort(b.begin(), b.end());
        int maxe = b[k-2];
        vector<int> c;
        for(int i=0; i<n; i++) {
            if(a[i] <= maxe) c.push_back(a[i]);
        }
        bool pali = true;
        for(int i=0; i<=(c.size()-1)/2; i++) {
            if(c[i] != c[c.size()-1-i]) pali = false;
        }
        if(pali) {
            cout << "YES\n";
            continue;
        }
        vector<int> d;
        for(auto x: c) {
            if(x != maxe) d.push_back(x);
        }

        pali = true;

        for(int i=0; i<=(d.size()-1)/2; i++) {
            if(d[i] != d[d.size()-1-i]) pali = false;
        }

        if(!pali) {
            cout << "NO\n";
            continue;
        }

        DEBUG(c);
        DEBUG(d);

        int l = -1;
        int r = -1;

        int ammax = 0;

        if(d.size() % 2 == 1) {
            int ti = d.size()/2;
            int j = -1;
            for(int i=0; i<c.size(); i++) {
                if(c[i] != maxe) j++;
                if(ti == j) {
                    l = i;
                    r = i;
                    break;
                }
            }
        } else {
            int ti = d.size()/2;
            int j = -1;
            DEBUG(ti);
            for(int i=0; i<c.size(); i++) {
                if(c[i] != maxe) j++;
                if(l == -1 && j == ti-1) l = i;
                if(j == ti) {
                    r = i;
                    ammax += r - l - 1;
                    break;
                }
            }
        }
        
        int lnew = l-1;
        int rnew = r+1;
        while(lnew > -1 && rnew < c.size()) {
            DEBUG(lnew, rnew);
            while(c[lnew] == maxe) {
                lnew--;
                if(lnew == -1) break;
            }
            while(c[rnew] == maxe) {
                rnew++;
                if(rnew == c.size()) break;
            }


            DEBUG(lnew, rnew);

            int lmaxe = l - lnew - 1;
            int rmaxe = rnew - r - 1;
            ammax += 2 * min(lmaxe, rmaxe);
            l = lnew;
            r = rnew;
            lnew--;
            rnew++;
        }

        DEBUG(ammax);

        if(ammax + d.size() >= k-1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    
}
