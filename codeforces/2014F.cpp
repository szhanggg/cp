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

class LazyTreeEulerTour {
    int n;  // Number of nodes
    vector<int> values;  // Original values of nodes
    vector<int> enter, exit, euler_tour, bit;  // Arrays for Euler Tour and BIT
    vector<vector<int>> tree;  // Adjacency list of the tree
    vector<int> degree;  // Array to store the degree of each node
    int time = 0;  // Time counter for Euler Tour

public:
    // Constructor to initialize the tree with 'n' nodes
    LazyTreeEulerTour(int n) : n(n), values(n), enter(n), exit(n), tree(n), bit(2 * n + 2, 0), degree(n, 0) {}

    // Add an edge to the tree
    void add_edge(int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // Get the number of neighbors (degree) of a node
    int get_neighbors_count(int node) {
        return degree[node];
    }

    // DFS to perform the Euler Tour and set enter/exit times for each node
    void dfs(int node, int parent) {
        enter[node] = time++;
        euler_tour.push_back(node);
        for (int neighbor : tree[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node);
            }
        }
        exit[node] = time++;
        euler_tour.push_back(node);
    }

    // Initialize the Euler tour starting from the root
    void build_euler_tour(int root = 0) {
        euler_tour.reserve(2 * n);  // Reserve space for Euler Tour
        dfs(root, -1);
    }

    // BIT utility to perform point updates (delta) at index `idx`
    void bit_update(int idx, int delta) {
        for (; idx < bit.size(); idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    // BIT utility to query the prefix sum up to index `idx`
    int bit_query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    // Range update to apply a delta (e.g. subtract c) to all nodes between [l, r] in the Euler tour
    void range_update(int l, int r, int delta) {
        bit_update(l + 1, delta);  // BIT is 1-based
        bit_update(r + 2, -delta);  // End range update
    }

    // Subtract a given value `c` from all neighbors of a node lazily
    void update_neighbors(int node, int c) {
        range_update(enter[node], exit[node], -c);
    }

    // Set the value of a node directly
    void set_value(int node, int value) {
        values[node] = value;
    }

    // Get the value of a node, applying any pending lazy updates from the BIT
    int get_value(int node) {
        int delta = bit_query(enter[node] + 1);  // Get any pending lazy updates
        return values[node] + delta;  // Return the actual value with the updates applied
    }
};
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, c; cin >> n >> c;
        LazyTreeEulerTour tree(n);
        for(int i=0; i<n; i++) {
            int val; cin >> val;
            tree.set_value(i, val);
        }
        for(int i=0; i<n-1; i++) {
            int u, v; cin >> u >> v; u--; v--;
            tree.add_edge(u, v);
        }
        tree.build_euler_tour();
        int ans = 0;
        // Loop through every node
        vector<pair<int, int>> ivals(n);
        for(int i=0; i<n; i++) ivals[i] = {tree.get_value(i), i};
        sort(ivals.begin(), ivals.end(), greater<pair<int, int>>());
        for(auto [_, i] : ivals) {
            // See if the value at the node is 
            int val = tree.get_value(i);
            DEBUG(i, val);
            if(tree.get_neighbors_count(i) * c < val) {
                DEBUG(i, val);
                tree.update_neighbors(i, c);
                ans += val;
            }
        }

        cout << ans << "\n";
    }
}
