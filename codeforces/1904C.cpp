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
 
long long findSmallestDifference(vector<int>A, vector<int>B,
                           int m, int n)
{
    sort(A.begin(), A.end());
 
    int a = 0, b = 0;
 
    int result = abs(A[0]-B[0]);
 
    while (a < m && b < n)
    {
        if (abs(A[a] - B[b]) < result)
            result = abs(A[a] - B[b]);
 
        if (A[a] < B[b])
            a++;
 
        else
            b++;
        if(result == 0) return result;
    }
 
    return result; 
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
 
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int ans = a[0];
        for(int i=0; i<n; i++) ans = min(ans, a[i]);

        sort(a.begin(), a.end());
 
        if(k >= 3) {
            cout << "0\n";
            continue;
        }
 
        if(k == 1) {
            for(int i=0; i<n; i++) {
                for(int j=i+1; j<n; j++) {
                    if(i == j) continue;
                    ans = min(ans, abs(a[i]-a[j]));
                }
            }
            cout << ans << "\n";
            continue;
        } else if(k == 2) {
            for(int i=0; i<n; i++) {
                for(int j=i+1; j<n; j++) {
                    if(i == j) continue;
                    int diff = abs(a[i]-a[j]);
                    ans = min(ans, diff);
                    // Find the smallest difference between diff and the sorted array a
                    if(diff > a[n-1]) {
                        ans = min(ans, diff-a[n-1]);
                    } else if(diff < a[0]) {
                        ans = min(ans, a[0]-diff);
                    } else {
                        int idx = lower_bound(a.begin(), a.end(), diff)-a.begin();
                        ans = min(ans, min(abs(a[idx]-diff), abs(a[idx-1]-diff)));
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    
}

