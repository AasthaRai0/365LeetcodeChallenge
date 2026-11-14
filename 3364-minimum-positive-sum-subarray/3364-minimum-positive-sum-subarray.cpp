class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int ans=-1;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum = sum + nums[j];
                int len = j-i+1;
                if(len>=l && sum>0 && len<=r){
                    if (ans == -1 || sum < ans) {
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};