class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        int cnt=1;
        unordered_set<int> s(nums.begin(), nums.end());
        if(n==0){
            return 0;
        }

        for(int i : s){
            if(s.count(i-1)==0){
                int curr = i;
                int len=1;
                while(s.count(curr + 1) > 0){
                    curr++;
                    len++;               
                }
                cnt = max(cnt, len);
            }
        }
        return cnt;
    }
};