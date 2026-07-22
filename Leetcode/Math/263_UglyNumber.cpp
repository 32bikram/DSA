//if a number is divisible by anything other than 2,3,5 then while keep divising with 2,3,5 there will be a time when it will not be divisble by 2,3,5 we use this concept
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false; //cause ugly is +ve
        if(n==1) return true; //1 has no prime factor
        bool divisible = true;
        while(divisible && n!=0){
            if(n==1) break; //vag hoite hoite sudhu 1 roye geche
            //jemon 6/3 = 2; 2/2 = 1; now 1 mane ar divisible na
            //atodur obdhi sudhu 2,3,5 diye vag hoyei 1 hoiche tai ugly
            if(n%5==0) n/=5;
            else if(n%3==0) n/=3;
            else if(n%2==0) n/=2;
            else divisible = false;
        }
        if(divisible == false) return false;
        //divisible = false, tokhoni hobe jokhon 2,3,5 charao onno kichu diye vag jabe
        return true;
    }
};
