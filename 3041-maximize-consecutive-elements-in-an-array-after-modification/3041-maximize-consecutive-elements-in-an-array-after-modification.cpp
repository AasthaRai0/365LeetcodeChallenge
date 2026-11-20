class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int a1=1;
        int a2=1;
        int prev = nums[0];
        int ans=1;

        for(int i=1; i<n; i++){
            int curr = nums[i];
            int diff = curr - prev;
            prev = curr;

            if(diff==0){
                a2 = a1 + 1;
            }else if(diff == 1){
                a1 = a1+1;
                a2 = a2+1;
            }else if(diff == 2){
                a1 = a2 + 1;
                a2 = 1;
            }else{
                a1 = 1;
                a2 = 1;
            }
            if(a1 > ans){
                ans = a1;
            }
            if(a2 > ans){
                ans = a2;
            }
        }
        return ans;
    }
};