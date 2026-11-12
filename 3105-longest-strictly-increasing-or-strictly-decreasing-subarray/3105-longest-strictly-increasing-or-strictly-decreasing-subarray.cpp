class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;

        int inc=1;
        int dec=1;
        int res=1;
        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]){
                inc++;
                dec=1;
            }
            else if(nums[i-1]>nums[i]){
                dec++;
                inc=1;
            }
            else{
                inc=1;
                dec=1;
            }
            res= max({res, inc, dec});
        }
        return res;
    }
};