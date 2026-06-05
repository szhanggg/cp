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

bool cmpdist(int x1, int y1, int x2, int y2, int r) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dist = dx * dx + dy * dy;
    return dist <= r*r;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r; cin >> n >> r;
    vector<pair<int, int>> p(n);
    for(int i=0; i<n; i++) cin >> p[i].first >> p[i].second;

    int gridsize = 2*r;
    int ox = 0; int oy = 0;

    int allowedmiss = (int) (0.11 * (double) n);

    set<pair<int, int>> tested;

    auto test = [&] (int ox, int oy) {
        tested.insert({ox, oy});
        int curmiss = 0;
        set<pair<int, int>> m;

        for(auto x: p) {
            int gx = (x.first + ox) / gridsize;
            int gy = (x.second + oy) / gridsize;

            int cx = gx * gridsize + ox;
            int cy = gy * gridsize + oy;

            if(cmpdist(x.first, x.second, cx, cy, r)) {
                m.insert({cx, cy});
            } else {
                curmiss++;
                if(curmiss > allowedmiss) return;
            }
        }

        cout << m.size() << "\n";
        for(auto c: m) {
            cout << c.first << " " << c.second << "\n";
        }
        exit(0);

    };
    // default_random_engine generator;
    uniform_int_distribution<int> distribution(0, gridsize-1);

    while(1) {
        test(ox, oy);
        while(tested.contains({ox, oy})) {
            ox = distribution(rng);
            oy = distribution(rng);
        }
    }

}
