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

    deque<int> d;

    while(t--) {
        int n;
        cin >> n;
        while(!d.empty()) {
            d.pop_front();
        }
        vector<int> a(n);
        a.clear();

        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        if(a[0]!=n && a[n-1]!=n) {
            cout << "-1\n";
            continue;
        }

        int i = 0;
        int j = n-1;


        while(i!=j) {
            // DEBUG(i);
            // DEBUG(j);
            if(a[i] > a[j]) {
                d.push_front(a[i]);
                i++;
            } else {
                d.push_back(a[j]);
                j--;
            }
        }

        d.push_front(a[i]);
        
        while(!d.empty()) {
            int next = d.front(); d.pop_front();
            cout << next << " ";
        }
        cout << "\n";
    }

}
