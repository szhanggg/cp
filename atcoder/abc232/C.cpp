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

bool taka[9][9];
bool aoki[9][9];

bool check_permutation(vector<int> perm) {
    for(int i=1; i<=perm.size(); i++) {
        for(int j=i+1; j<=perm.size(); j++) {
            if(taka[i][j] != aoki[perm[i-1]][perm[j-1]]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        taka[a][b] = true;
        taka[b][a] = true;
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        aoki[a][b] = true;
        aoki[b][a] = true;
    }

    vector<int> perm(n);
    for(int i=1; i<=n; i++) {
        perm[i-1] = i;
    }

    if(check_permutation(perm)) {
        cout << "Yes\n";
        return 0;
    }

    while(next_permutation(perm.begin(), perm.end())) {
        DEBUG(perm);
        if(check_permutation(perm)) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

}
