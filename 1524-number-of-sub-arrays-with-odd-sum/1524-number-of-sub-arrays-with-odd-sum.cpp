class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0; 
        int odd = 0; 
        int even = 0;
        for (auto x: arr) {
            even = even + 1;
            if (x % 2){
                swap(odd, even);
            }
            ans = (ans + odd) % 1000000007;
        }
        return ans;
    }
};