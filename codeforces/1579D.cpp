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
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            pq.push(make_pair(a[i], i));
        }

        int ans = 0;

        vector<pair<int, int>> pairs;

        while(true) {
            auto [p1, p1i] = pq.top(); pq.pop();
            auto [p2, p2i] = pq.top(); pq.pop();
            if(p1 == 0 || p2 == 0) break;
            ans++;

            pq.push(make_pair(p1-1, p1i));
            pq.push(make_pair(p2-1, p2i));

            pairs.push_back(make_pair(p1i, p2i));

        }

        cout << ans << "\n";

        for(auto x: pairs) {
            cout << x.first + 1 << " " << x.second + 1 << "\n";
        }

    }

}
