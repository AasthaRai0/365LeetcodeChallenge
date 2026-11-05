class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int ans=0;
        int j=0;

        for(int i=0; i<arr1.size(); i++){
            while(j< arr2.size() && arr2[j] < arr1[i]-d){
                j++;
            }
            if(j== arr2.size() || arr2[j] > arr1[i]+d){
                ans++;
            }
        }
        return ans;
    }
};