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
#define ll long long
const int MOD = 1e9 + 7;

int binexp(int a, int b) {
    int ans = 1; int cur = a;
    cur %= MOD;
    while(b) {
        if(b&1) ans *= cur;
        ans %= MOD;
        cur *= cur; cur %= MOD;
        b /= 2;
    }
    return ans;
}

	/** The extended Euclidean algorithm used to find the inverse */
void ext(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1, y = 0;
	} else {
		ext(b, a % b, x, y);
		ll tem = x;
		x = y;
		y = tem - (a / b) * y;
	}
}

/** @return the modular inverse of a mod m */
ll inv(ll a, ll m) {
	ll x = 0, y = 0;
	ext(a, m, x, y);
	return (x + m) % m;
}

 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    int a, b; cin >> a >> b;
    b %= MOD-1;

    int ans = 1;

    for(int p=2; p*p<=a; p++) {
        if(a % p != 0) continue;
        int cur = 0;
        while(a % p == 0) {
            a /= p;
            cur++;
        }

        cur *= b; cur %= MOD-1;
        cur = cur + MOD % MOD;
        ans *= binexp(p, cur+1)-1;
        ans %= MOD;
        ans *= inv(p-1 + MOD, MOD);
        ans %= MOD;

    }

    if (a > 1 && ((a - 1) % MOD) != 0) {
        // if a is greater than 1 and a - 1 is not divisible by 10^9 + 7
        // find the value of d - 1 and (d^k - 1) modulo (10^9 + 7).
        ll d_1 = inv((a - 1 + MOD) % MOD, MOD);
        ll dk_1 = (binexp(a, b + 1) - 1 + MOD) % MOD;
        ans = (ans * ((d_1 * dk_1) % MOD)) % MOD;
    } else if (a > 1) {
        /*
         * if a - 1 is divisible by 10^9 + 7,
         * a is a prime of the form k * (10^9 + 7) + 1.
         * this means the sum of a^i modulo (10^9 + 7), where i goes from 0 to b
         * is (b + 1), so we multiply by (b + 1).
         */
        ans = (ans * ((b + 1) % MOD)) % MOD;
    }

    cout << ans << "\n";
    
}
