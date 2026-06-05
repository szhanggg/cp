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

int conv(int i, int j, int w) {
    return i*w + j;
}

int solve() {
    int h, w; cin >> h >> w;
    int n = h*w;
    vector<string> s(h);
    for(int i=0; i<h; i++) {
        cin >> s[i];
    }

    int bam = 0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(s[i][j] == '#') bam++;
        }
    }
    if(bam >= 46) return 9;

    int ans = 0;
    unordered_set<int> us;

    for(int am=0; am<=min(8, bam); am++) {
        string bitmask(am, 1);
        bitmask.resize(n, 0);

        do {
            bool all_black = true;
            for(int i=0; i<n; i++) {
                if(bitmask[i] && s[i/w][i % w] == '.') {
                    all_black = false;
                    break;
                }
                if(bitmask[i]) us.insert(i);
            }
            if(!all_black) continue;

            bool skip = false;

            for(int i=0; i<h; i++) {
                for(int j=0; j<w; j++) {
                    int ind = i*w + j;
                    if(s[i][j] == '.') continue;
                    if(us.count(ind)) continue;
                    int mimj = us.count(conv(i-1, j-1, w));
                    int miej = us.count(conv(i-1, j, w));
                    int mipj = us.count(conv(i-1, j+1, w));
                    int eimj = us.count(conv(i, j-1, w));
                    int eipj = us.count(conv(i, j+1, w));
                    int pimj = us.count(conv(i+1, j-1, w));
                    int piej = us.count(conv(i+1, j, w));
                    int pipj = us.count(conv(i+1, j+1, w));
                    if(i > 0 && j > 0) {
                        if(s[i-1][j] == '#' && s[i-1][j-1] == '#' && s[i][j-1] == '#') {
                            if(miej == 0 && mimj == 0 && eimj == 0) {
                                skip = true;
                                break;
                            }
                        }
                    }
                    if(i < h-1 && j < w - 1) {
                        if(s[i+1][j] == '#' && s[i+1][j+1] == '#' && s[i][j+1] == '#') {
                            if(piej == 0 && pipj == 0 && eipj == 0) {
                                skip = true;
                                break;
                            }
                        }
                    }
                    if(i > 0 && j < w - 1) {
                        if(s[i-1][j] == '#' && s[i-1][j+1] == '#' && s[i][j+1] == '#') {
                            if(miej == 0 && mipj == 0 && eipj == 0) {
                                skip = true;
                                break;
                            }
                        }
                    }
                    if(i < h-1 && j > 0) {
                        if(s[i+1][j] == '#' && s[i+1][j-1] == '#' && s[i][j-1] == '#') {
                            if(piej == 0 && pimj == 0 && eimj == 0) {
                                skip = true;
                                break;
                            }
                        }
                    }
                }
                if(skip) break;
            }
            if(skip) continue;
            return am;
        } while(prev_permutation(bitmask.begin(), bitmask.end()));
    }

    return 9;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }

}
