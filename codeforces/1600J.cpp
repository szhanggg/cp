#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 7
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "" << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=1, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 1) {cerr << "" << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int MAXARR = 1e6 + 123;
bool vis [MAXARR];
vector<int> adj [MAXARR];

vector<int> sizes;
int countSize;

void dfs(int i) {
    vis[i] = true;
    countSize++;

    for(int adjN: adj[i]) {
        if(!vis[adjN]) {
            DEBUG(adjN);
            dfs(adjN);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a;

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a;
            string binT = bitset<4>(a).to_string();
            int index1 = m * i + j;
            if(binT[0] == '0' && i > 0) {
                adj[index1].push_back(index1 - m);
            }
            if(binT[1] == '0' && j < m - 1) {
                adj[index1].push_back(index1 + 1);
            }
            if(binT[2] == '0' && i < n - 1) {
                adj[index1].push_back(index1 + m);
            }
            if(binT[3] == '0' && j > 0) {
                adj[index1].push_back(index1 - 1);
            }
        }
    }

    for(int i=0; i<n*m; i++) {
        if(!vis[i]) {
            countSize = 0;
            DEBUG(i);
            dfs(i);
            sizes.push_back(countSize);
        }
    }

    sort(sizes.begin(), sizes.end(), greater<int>());

    for(int sizeN: sizes) {
        cout << sizeN << " ";
    }

    cout << endl;

}
