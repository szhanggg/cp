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

void removeall(vector<vector<int>> &f, int ind) {
    DEBUG(f, ind);
    for(int i=0; i<f.size(); i++) {
        f[i].erase(remove(f[i].begin(), f[i].end(), ind), f[i].end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> f(n+1);
        for(int i=0; i<n; i++) {
            while(a[i] >= 1) {
                if(a[i] <= n) {
                    f[a[i]].push_back(i);
                }
                a[i] /= 2;
            }
        }

        vector<bool> finished(n+1, false);

        while(true) {
            bool changed = false;
            for(int i=1; i<=n; i++) {
                if(f[i].size() == 1 && !finished[i]) {
                    finished[i] = true;
                    removeall(f, f[i][0]);
                    changed = true;
                }
            }
            if(!changed) break;
        }

        DEBUG(finished);
        DEBUG(f);

        bool every = false;

        for(int i=1; i<=n; i++) {
            if(finished[i]) continue;
            if(f[i].size() != 0) {
                finished[i] = true;
                removeall(f, f[i][0]);
            } else {
                every = true;
            }
        }

        if(every) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        
    }

}
