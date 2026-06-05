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

vector<int> potwo = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

array<int, 3> findW(const vector<int> &a, int x, int y, int n) {
    auto xi = lower_bound(a.begin(), a.end(), x);
    auto yi = upper_bound(a.begin(), a.end(), y);
    int xii = xi - a.begin();
    int yii = a.end() - yi;
    if(yi != a.end()) yii++;

    int mii = n - xii - yii;

    return {xii, mii, yii};

}

int clotwo(int i) {
    if(i == 0) return 1;
    if(i == 1) return 0;
    auto fi = lower_bound(potwo.begin(), potwo.end(), i);
    int fii = *fi;


    return fii - i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    DEBUG(clotwo(2));

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long minA = INT_MAX;

    }

}
