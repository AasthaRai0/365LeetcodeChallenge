class Solution {
public:
    int maxLength(vector<int>& nums) 
    {
        int n = nums.size();
        int maxlen = 0;
        for (int i = 0; i < n; ++i) 
        {
            int curr_gcd = nums[i];
            int curr_lcm = nums[i];
            double res = 1.0/nums[i];
            
            for (int j = i; j < n; ++j){
                if (j > i){
                    curr_gcd = gcd(curr_gcd, nums[j]);
                    curr_lcm = lcm(curr_lcm,nums[j]); 
                    res /= nums[j];
                }
                if (curr_gcd * curr_lcm * res>0.99999999){ 
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};


