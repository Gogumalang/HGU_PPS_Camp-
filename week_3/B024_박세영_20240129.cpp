class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> rank = score; 
        vector<string> ans;
        sort(rank.rbegin(),rank.rend());
        int left;
        int right;
        int p_index;
        for(int i =0;i<score.size();i++) {
            left = 0;
            right = score.size()-1;
            p_index = rank.size()/2; 
            while(left<right) {
                if(rank[p_index] == score[i]) break;
                else if(rank[p_index] < score[i]){
                    right = p_index -1;
                }
                else {
                    left = p_index +1;
                }
                p_index = (right+left)/2;
            }
            if(p_index == 0 ) ans.push_back("Gold Medal");
            else if (p_index == 1)ans.push_back("Silver Medal");
            else if (p_index == 2)ans.push_back("Bronze Medal");
            else ans.push_back(to_string(p_index+1));
        }
        return ans;
    }
};