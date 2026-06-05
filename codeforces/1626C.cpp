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

long long findN(long long n) {
    if(n <= 0) return 0;
    return (n * (n+1)) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> k(n);
        vector<long long> h(n);
        long long ans = 0;
        for(int i=0; i<n; i++) {
            cin >> k[i];
        }
        for(int i=0; i<n; i++) {
            cin >> h[i];
        }

        long long slope = k[n-1] - h[n-1] + 1;
        long long maxV = k[n-1];

        vector<pair<long long, long long>> groups;

        for(int i=n-2; i>-1; i--) {
            if(k[i] < slope) {
                groups.push_back(make_pair(slope, maxV));
                slope = k[i] - h[i] + 1;
                maxV = k[i];
                continue;
            }
            long long islope = k[i] - h[i] + 1;
            if(islope < slope) {
                slope = islope;
            }
        }

        groups.push_back(make_pair(slope, maxV));

        DEBUG(groups);

        for(auto x: groups) {
            ans += findN(x.second - x.first + 1);
        }

        cout << ans << "\n";
    }

}
