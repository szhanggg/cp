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

struct segtree {

    int size;
    vector<long long> mins;

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        mins.assign(2 * size, LONG_LONG_MAX);
    }

    void build(vector<long long> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                mins[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    }

    void build(vector<long long> &a) {
        build(a, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {   
        if (lx >= rx || l >= rx) return 0;
        if (lx >= l && rx <= r) return mins[x];
        if (x >= size || lx >= r) return 0;
        int m = (lx + rx) / 2;
        long long s1 = query(l, r, 2 * x + 1, lx, m);
        long long s2 = query(l, r, 2 * x + 2, m, rx);
        return min(s1, s2);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, s;
        cin >> n >> s;

        segtree st;
        st.init(n);

        vector<int> a(n);
        vector<long long> prefix(n);

        long long total = 0;

        for(int i=0; i<n; i++) {
            cin >> a[i];
            total += (long long) a[i];
            prefix[i] = total;
        }

        DEBUG(a);
        DEBUG(prefix);

        st.build(prefix);

        DEBUG(st.mins);
        
        int l = 0;
        int ans = -1;
        int la = -1;
        int ra = -1;

        for(int r=0; r<n; r++) {
            
            while(l<=r) {
                DEBUG(l);
                DEBUG(r);
                long long pre = (l == 0 ? 0 : prefix[l-1]);
                DEBUG(pre);
                DEBUG(st.query(l, r+1));
                if(s + (st.query(l, r+1) - pre) >= 0) {
                    break;
                } else {
                    l++;
                }
            }

            if(r-l > ans) {
                ans = r-l;
                la = l;
                ra = r;
            }
        }

        if(ans == -1) {
            cout << "-1\n";
            continue;
        }

        cout << la + 1 << " " << ra + 1 << "\n";

    }

}
