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
//O(n)
int findMex(const vector<int> &a, int l, int r, int n) {
    vector<bool> vis(n+1, false);
    int mex = 0;
    for(int i=l; i<r; i++) {
        vis[a[i]] = true;
        while(vis[mex]) {
            mex++;
        }
    }
    return mex;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        vector<int> b;
        int id = 0;

        vector<int> cnt(n+1, 0);

        for(auto x: a) {
            cnt[x]++;
        }

        while(id < n) {
            DEBUG(id);
            int curmex = 0;
            while(cnt[curmex] > 0) curmex++;
            if(curmex == 0) {
                b.push_back(0);
                id++;
                continue;
            }
            DEBUG(curmex);
            vector<bool> vis(n+1, false);
            int mex = 0;
            int i=id;
            while(mex < curmex) {
                vis[a[i]] = true;
                cnt[a[i]]--;
                i++;
                while(vis[mex]) mex++;
            }

            id = i;
            b.push_back(curmex);
            
        }

        cout << b.size() << "\n";
        for(auto x: b) {
            cout << x << " ";
        }
        cout << "\n";

    }

}
