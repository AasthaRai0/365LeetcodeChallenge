class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        if(n==3){
            return 0;
        }
        int n1 = nums[2];
        int n2 = nums[n-1];
        int ans=n2-n1;

        int n3 = nums[0];
        int n4 = nums[n-3];
        ans = min(ans, n4-n3);

        int n5 = nums[1];
        int n6 = nums[n-2];
        ans = min(ans, n6-n5);

        return ans;        
    }
};