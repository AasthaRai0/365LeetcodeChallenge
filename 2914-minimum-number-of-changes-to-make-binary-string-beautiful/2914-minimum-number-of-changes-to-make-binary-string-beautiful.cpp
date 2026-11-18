class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0; i<n; i=i+2){
            char st=s[i];
            char end= s[i+1];

            if(st != end){
                ans++;
            }
        }
        return ans;
    }
};