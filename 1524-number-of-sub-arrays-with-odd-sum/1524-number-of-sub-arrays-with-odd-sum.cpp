class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int res = 0, odd = 0, even = 0;
        for (auto x: arr) {
            even = even + 1;
            if (x % 2){
                swap(odd, even);
            }
            res = (res + odd) % 1000000007;
        }
        return res;
    }
};