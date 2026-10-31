class Solution {
    const int MOD = 1e9 + 7;
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int dir) {
        int n = grid.size(); 
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m){
            return 0;
        }
        if(i == n - 1 && j == m - 1){
            return 1;
        }
        if(dp[i][j][dir] != -1){
            return dp[i][j][dir];
        }
        int right = 0;
        int down = 0;

        if(grid[i][j] == 1) {
            if(dir == 1) {
                down = solve(i + 1, j, grid, dp, 0);
            }
            else {
                right = solve(i, j + 1, grid, dp, 1);
            }
            return  dp[i][j][dir] = (right + down) % MOD;
        }
        right = solve(i, j + 1, grid, dp, 1);
        down = solve(i + 1, j, grid, dp, 0);
        return dp[i][j][dir] = (right + down) % MOD;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2,-1)));
        return solve(0, 0, grid, dp, 0);
    }
};