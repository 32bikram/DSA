class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> prev = {0,0,0};
        for(int i = 0; i<triplets.size(); i++){
            int count = 0;
            for(int j = 0; j<3; j++){
                if(triplets[i][j]>target[j]) break;
                count++;
            }
            if(count == 3){
                triplets[i][0] = max(triplets[i][0], prev[0]);
                triplets[i][1] = max(triplets[i][1], prev[1]);
                triplets[i][2] = max(triplets[i][2], prev[2]);
                prev = triplets[i];
            }
        }
        if(prev==target) return true;
        return false;
    }
};
