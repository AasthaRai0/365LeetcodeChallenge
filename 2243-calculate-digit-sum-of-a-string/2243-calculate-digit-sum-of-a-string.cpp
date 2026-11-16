class Solution {
public:
    string digitSum(string s, int m) {
        
        while(s.length()>m){
            int k= s.length();
            string temp="";
            for(int i=0;i<s.length();i+=m){
                int sum = 0;
                for (int j = i; j < i + m && j < s.length(); ++j) {
                    sum += s[j] - '0';
                }
                temp += to_string(sum);

            }
            s=temp;
        }
        return s;
        
    }
};