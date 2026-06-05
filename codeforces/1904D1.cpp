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


/**
 * Description: Performs range queries and point updates.
 * Source: http://codeforces.com/blog/entry/18051
 * Verification: https://www.spoj.com/problems/FENTREE/
 * Time: O(n) build, O(log n) query and update
 * --IMPORTANT--
 * 0-indexed, update is [l, r]
 * T is type, id should be manually set to the starting values
 */

using T = int;

template <typename T>
struct SegmentTreeMin {
    int n;
    const T id = LLONG_MAX;
    vector<T> st;

    T merge(const T &a, const T &b) {
        return min(a, b);
    }

    SegmentTreeMin(int _n) : n(_n), st(2 * n, id) {}

    SegmentTreeMin(const vector<T> &a) : n((int) a.size()), st(2 * n) {
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = merge(st[i<<1], st[i<<1|1]);
    }

    T query(int l, int r) {
        T ls = id, rs = id;
        for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
            if (l&1) ls = merge(ls, st[l++]);
            if (r&1) rs = merge(st[--r], rs);
        }
        return merge(ls, rs);
    }

    void update(int p, T val) {
        for (st[p+=n]=val, p>>=1; p>0; p>>=1)
            st[p] = merge(st[p<<1], st[p<<1|1]);
    }
};

template <typename T>
struct SegmentTreeMax {
    int n;
    const T id = 0;
    vector<T> st;

    T merge(const T &a, const T &b) {
        return max(a, b);
    }

    SegmentTreeMax(int _n) : n(_n), st(2 * n, id) {}

    SegmentTreeMax(const vector<T> &a) : n((int) a.size()), st(2 * n) {
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = merge(st[i<<1], st[i<<1|1]);
    }

    T query(int l, int r) {
        T ls = id, rs = id;
        for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
            if (l&1) ls = merge(ls, st[l++]);
            if (r&1) rs = merge(st[--r], rs);
        }
        return merge(ls, rs);
    }

    void update(int p, T val) {
        for (st[p+=n]=val, p>>=1; p>0; p>>=1)
            st[p] = merge(st[p<<1], st[p<<1|1]);
    }
};
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        // Map of all values in a to their indices
        map<int, vector<int>> aMap;
        for(int i=0; i<n; i++) {
            aMap[a[i]].push_back(i);
        }

        bool ok = true;
        SegmentTreeMin<int> stMin(b);
        SegmentTreeMax<int> stMax(a);

        // Loop through all elements of b
        for(int ib=0; ib<n; ib++) {
            int x = b[ib];

            //Find the closest two indices to i in a that are equal to x
            int l = -1;
            int r = -1;
            auto it = lower_bound(aMap[x].begin(), aMap[x].end(), ib);
            if(it != aMap[x].end()) {
                r = *it;
            }
            if(it != aMap[x].begin()) {
                l = *(--it);
            }

            // If both are -1, then we can't set this value
            if(l == -1 && r == -1) {
                ok = false;
                break;
            }
            // If one is -1, we can see if we can set it to the other
            // i.e. if the minimum of that range in b is x and if the maximum of that range in a is x
            if(l == -1) {
                if(stMin.query(ib, r) != x || stMax.query(ib, r) != x) {
                    ok = false;
                    break;
                }
            } else if(r == -1) {
                if(stMin.query(l, ib) != x || stMax.query(l, ib) != x) {
                    ok = false;
                    break;
                }
            } else {
                // If both are not -1, we can see if we can set it to either
                // i.e. if the minimum of that range in b is x and if the maximum of that range in a is x
                if(stMin.query(l, ib) != x || stMax.query(l, ib) != x) {
                    if(stMin.query(ib, r) != x || stMax.query(ib, r) != x) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';

    }
    
}
