#include <bits/stdc++.h>
using namespace std;
  
signed main() {

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> len(n+1);

        vector<int> path;

        int maxlen = 0;

        for(int i=1; i<=n; i++) {
            cout << "? " << i << " " << n << " ";
            for(int i=1; i<n; i++) {
                cout << i << " ";
            }
            cout << n << endl;

            int x; cin >> x;
            if(x == -1) return 0;
            maxlen = max(maxlen, x);

            len[x].push_back(i);
        }

        path.push_back(len[maxlen][0]);

        for(int length=maxlen-1; length>=1; length--) {
            int prev = path.back();
            for(auto pos: len[length]) {
                cout << "? " << prev << " 2 " << prev << " " << pos << endl;
                int x; cin >> x;
                if(x == -1) return 0;

                if(x == 2) {
                    path.push_back(pos);
                    break;
                }
            }
        }

        cout << "! ";
        cout << path.size() << " ";
        for(auto x: path) {
            cout << x << " ";
        }
        cout << endl;
    }
    
}
