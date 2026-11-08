class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> countrow(m, 0);
        vector<int> countcol(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    countrow[i]++;
                    countcol[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && (countrow[i] > 1 || countcol[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};