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

template<typename T>
struct Matrix {
    int n, m;
    vector<vector<T>> mat;

    Matrix(int _n, int _m) : n(_n), m(_m), mat(n, vector<T>(m)) {}

    Matrix(const vector<vector<T>> &_mat) : n((int) _mat.size()), m((int) _mat[0].size()), mat(_mat) {}

    Matrix& operator += (const Matrix &other) {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                mat[i][j] += other.mat[i][j];
        return *this;
    }

    Matrix& operator -= (const Matrix &other) {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                mat[i][j] -= other.mat[i][j];
        return *this;
    }

    Matrix operator * (const Matrix &other) const {
        Matrix ret(n, other.m);
        for (int i=0; i<n; i++)
            for (int k=0; k<m; k++)
                for (int j=0; j<other.m; j++)
                    ret.mat[i][j] += mat[i][k] * other.mat[k][j];
        return ret;
    }

    friend Matrix operator + (Matrix a, const Matrix &b) {
        return a += b;
    }

    friend Matrix operator - (Matrix a, const Matrix &b) {
        return a -= b;
    }

    Matrix& operator *= (const Matrix &other) {
        return *this = *this * other;
    }

    vector<T>& operator [] (int i) {
        return mat[i];
    }

    friend Matrix power(Matrix a, long long b) {
        Matrix ret(a.n, a.m);
        for (int i=0; i<a.n; i++)
            ret[i][i] = 1;
        while (b > 0) {
            if (b & 1)
                ret *= a;
            a *= a;
            b >>= 1;
        }
        return ret;
    }

    friend ostream& operator << (ostream &os, const Matrix &a) {
        return os << a.mat;
    }
};

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
 
const int MOD = 1e9+7;

#define mi ModInt<MOD>

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<vector<mi>> a(n, vector<mi>(n));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> a[i][j];

    Matrix<mi> m(a);

    Matrix<mi> m2 = power(m, k);

    mi ans = 0;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) ans += m2[i][j];

    cout << ans << "\n";
    
}
