class Solution {
public:
    //restrat
    int dfs(int num, vector<int> &visited){
        int temp = 0;
        if(visited[num]!=-1){
            return visited[num];
        }
        temp += dfs(num-1,visited);
        temp += dfs(num-2,visited);
        visited[num] = temp;
        return temp;
    }
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int> visited(n+1,-1);
        visited[1] = 1;
        visited[2] = 2; //it wont be a valid position if n = 1 so size only 1
        dfs(n, visited);
        return visited[n];
    }
};
