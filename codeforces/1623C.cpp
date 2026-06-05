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

bool check(int n, vector<long long> f, long long target) {
    vector<long long>h = f;
    for(int i=n-1; i>1; i--) {
        // DEBUG(i, h);
        long long amount = (h[i] - target) / 3;
        amount = min(amount, f[i] / 3);
        amount = max(amount, 0LL);
        h[i-2] += amount * 2;
        h[i-1] += amount;
        h[i] -= amount * 3;
    }

    // DEBUG(h);

    long long mina = h[0];
    for(auto x: h) {
        mina = min(mina, x);
    }

    return target <= mina;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> h(n);
        for(int i=0; i<n; i++) {
            cin >> h[i];
        }

        long long lb = 0;
        long long ub = 1e15;
        while(lb < ub) {
            long long m = lb + (ub - lb) / 2;
            // DEBUG(lb, ub, m);
            if(check(n, h, m)) {
                lb = m + 1;
            } else {
                ub = m;
            }
        }

        cout << lb - 1 << "\n";

    }

}
