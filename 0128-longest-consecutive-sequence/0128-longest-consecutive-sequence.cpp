class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        
        int cnt=0;
        int curr=1;

        sort(nums.begin(), nums.end());
        if(n==0){
            return 0;
        }

        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                curr++;
            }else if(nums[i] != nums[i-1]){
                cnt = max(cnt, curr);
                curr=1;
            }
        }
        cnt = max(cnt, curr);
        return cnt;
    }
};