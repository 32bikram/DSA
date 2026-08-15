class Solution {
public:
    void fun(int a, int b, vector<int>& stones){
        if(a>b){
            a = a-b;
            stones.push_back(a);
            push_heap(stones.begin(), stones.end());
        }

        if(stones.size()==1 || stones.size()==0) return;
        pop_heap(stones.begin(), stones.end());
        a = stones[stones.size()-1];
        stones.pop_back();
        pop_heap(stones.begin(), stones.end());
        b = stones[stones.size()-1];
        stones.pop_back();

        fun(a,b,stones);
    }
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        make_heap(stones.begin(), stones.end());
        pop_heap(stones.begin(), stones.end());
        int a = stones[stones.size()-1];
        stones.pop_back();
        pop_heap(stones.begin(), stones.end());
        int b = stones[stones.size()-1];
        stones.pop_back();
        fun(a,b,stones);
        if(stones.size()>0) return stones.front();
        return 0;
    }
};
