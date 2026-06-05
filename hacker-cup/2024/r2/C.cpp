#include <bits/stdc++.h>
using namespace std;

#define int long long
 
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

vector<vector<int>> origa(6, vector<int>(7, 0));

pair<int, int> eoriga(0, 0);

bool Cwin = false;
bool Fwin = false;

set<pair<long long, long long>> seen;

vector<vector<int>> decode(pair<int, int> ab) {
    vector<vector<int>> ans(6, vector<int>(7, -1));
    // a represents the encode of 0, b represents the encode of 1
    int a = ab.first;
    int b = ab.second;
    for(int i=0; i<6; i++) {
        for(int j=0; j<7; j++)  {
            if((a & (1LL << (6*j + i))) != 0) ans[i][j] = 0;
            if((b & (1LL << (6*j + i))) != 0) ans[i][j] = 1;
        }
    }
    return ans;
}

bool isValidSeq(pair<int, int> a, vector<pair<int, int>> seq, int b) {
    bool ok = true;
    vector<vector<int>> na = decode(a);
    for(auto p : seq) {
        ok &= na[p.first][p.second] == b;
    }
    return ok;
}

long long encode(vector<vector<int>> a, int b) {
    long long ans = 0;
    for(int i=0; i<6; i++) {
        for(int j=0; j<7; j++) {
            ans += (a[i][j] == b) * (1LL << (6*j + i));
        }
    }

    return ans;
}


bool checkState(pair<int, int> a, int b) {
    // Check all horizontals
    for(int i=0; i<6; i++) {
        for(int j=0; j<4; j++) {
            vector<pair<int, int>> seq = {{i, j}, {i, j+1}, {i, j+2}, {i, j+3}};
            if(isValidSeq(a, seq, b)) return true;
        }
    }
    // Check all verticals
    for(int i=0; i<3; i++) {
        for(int j=0; j<7; j++) {
            vector<pair<int, int>> seq = {{i, j}, {i+1, j}, {i+2, j}, {i+3, j}};
            if(isValidSeq(a, seq, b)) return true;
        }
    }
    // Check all diagonals
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            vector<pair<int, int>> seq = {{i, j}, {i+1, j+1}, {i+2, j+2}, {i+3, j+3}};
            if(isValidSeq(a, seq, b)) return true;
        }
        for(int j=3; j<7; j++) {
            vector<pair<int, int>> seq = {{i, j}, {i+1, j-1}, {i+2, j-2}, {i+3, j-3}};
            if(isValidSeq(a, seq, b)) return true;
        }
    }

    return false;
}

void print(vector<vector<int>> a) {
    for(int i=0; i<6; i++) {
        for(int j=0; j<7; j++) {
            if(a[i][j] == 0) cout << "C";
            else if(a[i][j] == 1) cout << "F";
            else cout << ".";
        }
        cout << "\n";
    }
}

// Brute force all possible moves
void solve(pair<int, int> ab, int b) {
    // a is the current state
    // b is the player to play

    if(Cwin && Fwin) return;
    if(checkState(ab, 0) || checkState(ab, 1)) return;

    if(seen.find(ab) != seen.end()) return;

    seen.insert(ab);

    vector<vector<int>> a = decode(ab);

    // Loop through every column
    for(int i=0; i<7; i++) {
        // Find the first -1 in the column
        int j = 0;
        while(j < 6 && a[j][i] != -1) j++;
        if(j == 6) continue;

        // Check if it's a valid move
        if(origa[j][i] != b) continue;

        // Make a copy of the current state
        vector<vector<int>> na(a);

        na[j][i] = b;

        pair<int, int> nab = make_pair(encode(na, 0), encode(na, 1));
     
        // Check if the state is valid
        if(checkState(nab, b)) {
            if(b == 0) {
                Cwin = true;
                return;
            } else {
                Fwin = true;
                return;
            }
        }

        // If it's not valid, keep recursing
        solve(nab, 1-b);
    }
}

int solve() {
    vector<string> orig(6);
    for(int i=0; i<6; i++) cin >> orig[i];

    for(int i=0; i<6; i++) {
        for(int j=0; j<7; j++) {
            origa[5-i][j] = orig[i][j] == 'F';
        }
    }

    eoriga = make_pair(encode(origa, 0), encode(origa, 1));

    bool cC = checkState(eoriga, 0);
    bool cF = checkState(eoriga, 1);

    if(!cC && !cF) return -1;
    if(cC && !cF) return 0;
    if(!cC && cF) return 1;


    vector<vector<int>> na(origa);
    fill(na.begin(), na.end(), vector<int>(7, -1));

    Cwin = false;
    Fwin = false;

    seen.clear();

    solve(make_pair(0, 0), 0);

    if(Cwin && Fwin) {
        return 2;
    } else if(Cwin) {
        return 0;
    } else if(Fwin) {
        return 1;
    } else {
        return -1;
    }

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("C.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for(int test=1; test<=t; test++) {
        int ans = solve();
        DEBUG(ans);
        if(ans == -1) {
            cout << "Case #" << test << ": 0\n";
        } else if(ans == 0) {
            cout << "Case #" << test << ": C\n";
        } else if(ans == 1) {
            cout << "Case #" << test << ": F\n";
        } else {
            cout << "Case #" << test << ": ?\n";
        }
    }

}
