class Solution {
public:
    bool checkvflag(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    bool checkcflag(char c){
        if(checkvflag(c) == false && ((c - 'a' >= 0 && 'z' - c >= 0) || (c - 'A' >= 0 && 'Z' - c >= 0))) return true;
        return false;
    }
    bool checkvalidity(char c){
        if(((c - 'a' >= 0 && 'z' - c >= 0) || (c - 'A' >= 0 && 'Z' - c >= 0)) || (c-'0' >= 0 && '9'-c>=0)) return true;
        return false;
    }
    bool isValid(string word) {
        bool vflag = false, cflag = false;
        if(word.size()<3) return false;
        for(int i = 0; i<word.size(); i++){
            if(vflag == false) vflag = checkvflag(word[i]);
            if(cflag == false) cflag = checkcflag(word[i]);
            if(!checkvalidity(word[i])) return false;
        }
        if(!cflag || !vflag) return false;
        return true;
    }
};
