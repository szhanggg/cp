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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        vector<int> b = a;
        sort(b.begin(), b.end());

        vector<array<int, 3>> moves;


        for(int i=0; i<n; i++) {
            DEBUG(b[i]);
            auto it = find(a.begin() + i, a.end(), b[i]);
            int index = it - a.begin();
            DEBUG(index);
            if(i == index) continue;
            int old = a[i];
            for(int j=i+1; j<=index; j++) {
                DEBUG(j);
                DEBUG(old);
                int oold = old;
                old = a[j];
                a[j] = oold;
            }
            a[i] = b[i];
            DEBUG(a);
            moves.push_back({i+1, index+1, index-i});
        }

        cout << moves.size() << "\n";

        for(auto i: moves) {
            cout << i[0] << " " << i[1] << " " << i[2] << "\n";
        }

    }

}
