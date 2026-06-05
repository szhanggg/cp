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
        int n, k;
        long long x;
        cin >> n >> k >> x;
        vector<char> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        vector<long long> lists;

        long long total = (a[0] == '*'? k + 1 : 1);


        for(int i=1; i<n; i++) {
            if(a[i] == '*') {
                total += k;
            } else {
                lists.push_back(total);
                total = 1;
            }
        }

        if(a[n-1] == '*') {lists.push_back(total);}
 

        reverse(lists.begin(), lists.end());

        DEBUG(lists);

        vector<long long> ans;

        for(int i=0; i<lists.size(); i++) {
            DEBUG(x, lists[i]);
            if(x == 0) {
                ans.push_back(0);
                continue;
            }
            if(x % lists[i] != 0) {
                ans.push_back(x % lists[i] - 1);
            } else {
                ans.push_back(lists[i] - 1);
            }
            if(x % lists[i] != 0) {
                x /= lists[i];
                x++;
            } else {
                x /= lists[i];
            }
        }

        DEBUG(ans);
        reverse(ans.begin(), ans.end());

        vector<char> news;
        int counter = 0;

        for(int i=0; i<n; i++) {
            if(a[i] == 'a') {
                if(counter > 0) news.push_back('*');
                counter = 0;
                news.push_back('a');
            } else {
                counter++;
            }
        }

        if(a[n-1] == '*') news.push_back('*');

        DEBUG(news);

        counter = 0;

        for(char i: news) {
            if(i == 'a') {
                cout << 'a';
            } else {
                string stuff(ans[counter], 'b');
                cout << stuff;

                counter++;

            }
        }

        cout << "\n";

    }   

}
