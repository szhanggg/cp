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
        
        vector<pair<int, int>> ran;
        for(int i=0; i<n; i++) {
            int l, r;
            cin >> l >> r;
            ran.push_back(make_pair(l, r));
        }

        vector<array<int, 3>> ans;
        
        queue<pair<int, int>> q;
        q.push(make_pair(1, n));
        while(!q.empty()) {
            pair<int, int> next = q.front(); q.pop();
            auto [l, r] = next;
            auto tempf = find(ran.begin(), ran.end(), next);
            if(tempf == ran.end()) {
                continue;
            }
            ran.erase(tempf);
            if(l == r) {
                ans.push_back({l, r, l});
                continue;
            }

            unordered_set<int> ls;
            unordered_set<int> rs;

            int numa = -1;

            for(int i=0; i<ran.size(); i++) {
                auto [ln, rn] = ran[i];
                DEBUG(ln, rn);
                if(ln == l && rn == r) continue;
                if(ln == l) {
                    ls.insert(rn + 1);
                    if(rs.count(rn + 1)) {
                        numa = rn + 1;
                        break;
                    }
                }
                if(rn == r) {
                    rs.insert(ln - 1);
                    if(ls.count(ln - 1)) {
                        numa = ln - 1;
                        break;
                    }
                }
            }

            DEBUG(numa);
            if(numa == -1) {
                auto temp = find(ran.begin(), ran.end(), make_pair(l, r-1));
                if(temp != ran.end()) {
                    ans.push_back({l, r, r});
                    q.push({l, r-1});
                } else {
                    ans.push_back({l, r, l});
                    q.push({l+1, r});
                }
                continue;
            }

            ans.push_back({l, r, numa});
            q.push({l, numa - 1});
            q.push({numa + 1, r});

        }

        for(auto x: ans) {
            auto [l, r, a] = x;
            cout << l << " " << r << " " << a << "\n";
        }

        cout << "\n";
    }

}
