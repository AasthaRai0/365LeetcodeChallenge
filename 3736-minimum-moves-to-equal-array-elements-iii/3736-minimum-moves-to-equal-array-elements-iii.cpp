class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            ans = ans + nums[n-1] - nums[i];
        }
        return ans;
    }
};