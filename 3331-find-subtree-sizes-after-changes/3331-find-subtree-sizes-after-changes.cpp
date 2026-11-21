
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n), newAdj(n);
        vector<int> newParent(n, -1);
        vector<int> ans(n, 0);
        vector<int> last(26, -1);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        function<void(int, int)> dfs = [&](int node, int par) {
            int ch = s[node] - 'a';
            int prev = last[ch];

            if (par != -1) {
                if (prev != -1)
                    newParent[node] = prev;
                else
                    newParent[node] = par;
            }
            last[ch] = node;

            for (int child : adj[node]) {
                dfs(child, node);
            }

            last[ch] = prev;
        };

        dfs(0, -1);
        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }
        function<int(int)> getSize = [&](int node) {
            int size = 1;

            for (int child : newAdj[node]) {
                size += getSize(child);
            }

            ans[node] = size;
            return size;
        };

        getSize(0);

        return ans;
    }
};
