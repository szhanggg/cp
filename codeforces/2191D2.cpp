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

const int MOD = 998244353;

template<int MOD>
struct ModInt {
    long long v;
    ModInt(long long _v = 0) {v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD;}
    ModInt& operator += (const ModInt &other) {v += other.v; if (v >= MOD) v -= MOD; return *this;}
    ModInt& operator -= (const ModInt &other) {v -= other.v; if (v < 0) v += MOD; return *this;}
    ModInt& operator *= (const ModInt &other) {v = v * other.v % MOD; return *this;}
    ModInt& operator /= (const ModInt &other) {return *this *= inverse(other);}
    bool operator == (const ModInt &other) const {return v == other.v;}
    bool operator != (const ModInt &other) const {return v != other.v;}
    friend ModInt operator + (ModInt a, const ModInt &b) {return a += b;}
    friend ModInt operator - (ModInt a, const ModInt &b) {return a -= b;}
    friend ModInt operator * (ModInt a, const ModInt &b) {return a *= b;}
    friend ModInt operator / (ModInt a, const ModInt &b) {return a /= b;}
    friend ModInt operator - (const ModInt &a) {return 0 - a;}
    friend ModInt power(ModInt a, long long b) {ModInt ret(1); while (b > 0) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
    friend ModInt inverse(ModInt a) {return power(a, MOD - 2);}
    friend istream& operator >> (istream &is, ModInt &m) {is >> m.v; m.v = (-MOD < m.v && m.v < MOD) ? m.v : m.v % MOD; if (m.v < 0) m.v += MOD; return is;}
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};

#define mi ModInt<MOD>

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    // first is the count, second is the sum of lengths
    vector<pair<mi, mi>> dp(n+2);

    dp[0].first = 1;
    dp[0].second = 0;

    for(int i=0; i<n; i++) {
        vector<pair<mi, mi>> ndp = dp;
        for(int k=0; k<=n; k++) {
            if(dp[k].first == 0) continue;
            mi cnt = dp[k].first;
            mi sum = dp[k].second;
            if (s[i] == '(') {
                if(dp[k].first == 0) continue;
                ndp[k+1].first += cnt;
                ndp[k+1].second += sum + cnt;
            } else {
                if(k == 0) continue;
                ndp[k-1].first += cnt;
                ndp[k-1].second += sum + cnt;
            }
        }
        dp = ndp;
    }

    DEBUG(dp);

    mi ans = dp[0].second - 2*(dp[0].first - 1);

    // now find bad )((
    vector<vector<pair<mi, mi>>> dp2(n+2, vector<pair<mi, mi>>(3));
    // 0 is init ), 1 is )(, 2 is )((
    dp2[0][0] = {1, 0};
    for(int i=0; i<n; i++) {
        vector<vector<pair<mi, mi>>> ndp = dp2;
        for(int st=0; st<3; st++) {
            for(int k=0; k<=n; k++) {
                mi cnt = dp2[k][st].first;
                mi sum = dp2[k][st].second;
                if(s[i] == '(') {
                    if(st == 0) {
                        ndp[k+1][0].first += cnt;
                        ndp[k+1][0].second += cnt + sum;
                    } else if(st == 1) {
                        ndp[k+1][2].first += cnt;
                        ndp[k+1][2].second += cnt + sum;
                    }
                } else {
                    if(k == 0) continue;
                    int nst = st;
                    if(st == 0) nst = 1;

                    ndp[k-1][nst].first += cnt;
                    ndp[k-1][nst].second += cnt + sum;
                }
            }
        }
        dp2 = ndp;
    }

    ans -= dp2[0][1].second + dp2[0][2].second;
    ans += 2 * (dp2[0][1].first + dp2[0][2].first);

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
