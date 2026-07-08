class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for(int i = digits.size()-1; i>=0; i--){
            if(carry == 0) return digits;
            int t = (digits[i]+carry) % 10;
            carry = (digits[i]+carry) / 10;
            digits[i] = t;
        }
        if(carry!=0){
	    digits.reverse(digits.begin(), digits.end());
	    digits.push_back(carry);
	    digits.reverse(digits.begin(), digits.end());
	    //reverse is inplace unlike insert methode where the vector is copied in new space
	}
        return digits;
    }
};

