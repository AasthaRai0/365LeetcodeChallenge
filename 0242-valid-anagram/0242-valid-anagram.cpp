class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> f;
        unordered_map<char, int> m;

        for(int i=0; i<s.length(); i++){
            f[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            m[t[i]]++;
        }
        
        if(s.length() != t.length()){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            if(s.length() == t.length() && f[s[i]] != m[s[i]]){
                return false;
            }
        }
        return true;
    }
};