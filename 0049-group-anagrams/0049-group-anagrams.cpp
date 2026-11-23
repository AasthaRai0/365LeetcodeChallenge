class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();

        unordered_map<string, vector<string>> m;  
        vector<vector<string>> ans;  

        for(int i=0; i<n; i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(strs[i]);
        }
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};