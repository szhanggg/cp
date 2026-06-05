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
        vector<int> p(n);
        for(int i=0; i<n; i++) {
            cin >> p[i];
        }
        deque<int> d;
        bool vis[n+1];
        int next = 1;
        memset(vis, false, sizeof(vis));

        stack<int> special;

        for(int i=n-1; i>-1; i--) {
            int proc = p[i];
            // DEBUG(i);
            // DEBUG(proc);
            // DEBUG(next);
            vis[proc] = true;
            if(proc == next) {
                special.push(proc);
                for(int j=proc; j<n+1; j++) {
                    if(!vis[j]) {
                        next = j;
                        // DEBUG(next);
                        break;
                    }
                }
            }
        }

        int i=0;
        while(i < n) {
            int proc = p[i];
            int topp = (special.size() > 0 ? special.top() : -1);
            DEBUG(proc);
            if(proc == topp) {
                DEBUG(proc);
                d.push_front(proc);
                special.pop();
            } else {
                d.push_back(proc);
            }
            i++;
        }

        DEBUG(d.size());

        while(!d.empty()) {
            int next = d.front(); d.pop_front();
            cout << next << " ";
        }
        cout << "\n";
    }

}
