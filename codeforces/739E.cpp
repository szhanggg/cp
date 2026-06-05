#include <bits/stdc++.h>
using namespace std;

#define double long double
 
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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b; cin >> n >> a >> b;
    vector<double> p(n); vector<double> q(n);
    for(int i=0; i<n; i++) cin >> p[i];
    for(int i=0; i<n; i++) cin >> q[i];

    // for(int i=0; i<n; i++) p[i] += 1 / ((double)(rng() % 1000000));
    // for(int i=0; i<n; i++) q[i] += 1 / ((double)(rng() % 1000000));

    DEBUG(p);
    DEBUG(q);

    double lpa = 0; double upa = 1; double pa, lpb, upb, pb, ev;
    int ca, cb;

    while(upa - lpa > 1e-8) {
        pa = (upa + lpa) / 2;

        lpb = 0; upb = 1;
        
        while(upb - lpb > 1e-8) {
            pb = (upb + lpb) / 2;
            cb = 0; ca = 0;
            ev = 0;

            // DEBUG(pa, pb);

            for(int i=0; i<n; i++) {
                // 4 cases
                vector<pair<double, int>> cases;
                cases.push_back({0, 0});
                cases.push_back({p[i] - pa, 2});
                cases.push_back({q[i] - pb, 1});
                cases.push_back({p[i] + q[i] - p[i]*q[i] - pa - pb, 3});
                sort(cases.begin(), cases.end());
                // DEBUG(cases);
                int opt = cases[3].second;
                if(opt == 2) {
                    ca++;
                    ev += p[i];
                }
                if(opt == 1) {
                    cb++;
                    ev += q[i];
                }
                if(opt == 3) {
                    ca++; cb++;
                    ev += p[i] + q[i] - p[i]*q[i];
                }
            }

            if(cb < b) {
                upb = pb;
            } else if(cb > b) {
                lpb = pb;
            } else {
                break;
            }
        }

        if(ca < a) {
            upa = pa;
        } else if(ca > a) {
            lpa = pa;
        } else {
            break;
        }
    }

    DEBUG(ca, cb);
    DEBUG(pa, pb);

    cout << ev << "\n";
    
}
