class Solution {
//set of elements independently x vabe, and other set of elements independently y vabe organise kora gele akstahe duita mile X x Y vabe organise kora jabe.
//r number of elements n position a order same raikhe nCr vabe organise kora jabe

public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    vector<vector<ll>> PT;
    int dfs(vector<int> nums){
        if(nums.size()<3) return 1;
        vector<int> left, right; int root = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]<root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        ll x = dfs(left) % MOD;
        ll y = dfs(right) % MOD;
        ll z = PT[nums.size()-1][left.size()];

        return ((x * y) % MOD * z )% MOD;
    }
    int numOfWays(vector<int>& nums) {
        PT.resize(nums.size());
        for(int i = 0; i<nums.size(); i++){
            PT[i] = vector<ll>(i+1, 1);
            for(int j = 1; j<i; j++){ //last and first index isn't used
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1]) % MOD;
            }
        }
        return (dfs(nums) - 1) % MOD;
    }
};
For intution - https://youtu.be/YMe9Q2yZvBo
