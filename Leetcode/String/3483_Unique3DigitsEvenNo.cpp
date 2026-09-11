class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;

        vector<int> freq(10,0);
        for(int i=0; i<digits.size(); i++){
            freq[digits[i]]++;
        }
        vector<int> temp = freq;
        for(int i = 100; i<999; i+=2){
            string s = to_string(i);
            temp = freq;
            for(int j = 0; j<s.size(); j++){
                if(temp[ s[j]-'0' ] == 0) break;
                else temp[ s[j]-'0' ] -= 1;
                if(j==s.size()-1) count++;                
            }
        }
        return count;
    }
};
