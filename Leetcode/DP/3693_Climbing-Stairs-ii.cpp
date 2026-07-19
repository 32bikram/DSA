class Solution {
public:
    int dfs(int curr, int n, vector<int>& costs, vector<int> &visited){
        if(curr==n) return 0;
        if(curr!=0 && visited[curr]!=-1) return visited[curr];

        int cost1 = INT_MAX, cost2 = INT_MAX, cost3 = INT_MAX;
        int i = curr;

        int result = INT_MAX;
        int j = i+1;
        if(j-1<costs.size()){
            cost1 = costs[j-1]+(j-i)*(j-i);
            result = min(result, cost1 + dfs(i+1, n, costs, visited));
        }
        j = i+2;
        if(j-1<costs.size()){
            cost2 = costs[j-1]+(j-i)*(j-i);
            result = min(result, cost2 + dfs(i+2, n, costs, visited));
        }
        j = i+3;
        if(j-1<costs.size()){
            cost3 = costs[j-1]+(j-i)*(j-i);
            result = min(result, cost3 + dfs(i+3, n, costs, visited));
        } 

        visited[i] = result;
        return result;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> visited(n+1, -1);
        return dfs(0, n, costs, visited);
    }
};
