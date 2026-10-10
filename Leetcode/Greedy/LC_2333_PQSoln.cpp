class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<int> pq;
        for(int i = 0; i<nums1.size(); i++){
            pq.push(abs(nums1[i]-nums2[i]));
        }
        int total_k = k1+k2, remove = 0;
        while(total_k>0 && pq.top()>0){
            int top = pq.top(); pq.pop();
            if(!pq.empty()){
                int top2 = pq.top(); 
                remove = top - top2;
            }
            if(remove!=0){
                top -= remove;
                total_k -= remove;
                pq.push(top);
            }
            else{
                top--;
                pq.push(top);
                total_k--;
            }
        }
        long long ans = 0;
        while(!pq.empty()){
            long long t = pq.top();
            ans += t*t;
            pq.pop();
        }
        return ans;
    }
};
