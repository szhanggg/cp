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

#define int long long

double solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<double> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    double ans = 0;
    double min = INT_MAX;
    for(auto num: a) if(num < min) min = num;

    priority_queue<double> pq;

    for(auto num: a) {
        pq.push(num);
    }

    int op = 0;

    while(pq.top() > min) {
        double f = pq.top();
        pq.pop();
        pq.push(f / 2.0);
        pq.push(f / 2.0);
        op++;
        if(k == op) {
            while(--x) {
                pq.pop();
            }
            return pq.top();
        }
    }

    k -= op;

    vector<double> newa;
    while(!pq.empty()) {
        newa.push_back(pq.top());
        pq.pop();
    }
    n = newa.size();

    DEBUG(newa);
    DEBUG(k, op);

    double stage = 1;
    int csum = 0;

    while(k >= 0) {
        csum += stage*n;
        k -= csum;
        stage*=2;
    }
    k += csum;

    stage /= 2;

    int left = k / stage;
    vector<double> newwa;
    for(int i=0; i<left; i++) {
        newwa.push_back(newa[i] / 2.0);
        newwa.push_back(newa[i] / 2.0);
    }
    for(int i=left; i<n; i++) newwa.push_back(newa[i]);
    sort(newwa.begin(), newwa.end(), greater<double>());

    DEBUG(stage);
    DEBUG(newwa);

    for(auto num: newwa) {
        x -= stage;
        if(x <= 0) return (num / stage);
    }

    return 0;

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        cout << solve() << setprecision(9) << "\n";
    }
    
}
