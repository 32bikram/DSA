class Solution {
public:
    int bfs(string beginword, string endword, unordered_set<string> &st){
        int ans = 0;
        queue<string> q;
        q.push(beginword);
        int q_size = 0;

        while(!q.empty()){
            int q_size = q.size(); //for keeping the count of level

            while(q_size--){ //one level at a time
                string word = q.front();
                if(word == endword) return ans+1; //+1 since for cat->bat->bag->sag there is 3 level to go but 4 words, these bithes count number of words not steps dont ask me why, and for cat->cat they take 1 not 2 fuck it...
                q.pop();

                for(int i = 0; i<word.size(); i++){
                    string temp = word;
                    for(int j = 0; j<26; j++){
                        temp[i] = 'a' + j;
                        if(st.contains(temp)){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
            ans++;
        }
        if(q.empty()) return 0; //incase there is no way to achive end word
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(string w : wordList){
            st.insert(w);
        }
        return bfs(beginWord, endWord, st);
    }
};
