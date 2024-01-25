class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> mat_t(matrix[0].size(),vector<int>(matrix.size()));
      
        for(int i =0;i<mat_t.size();i++) {
            for(int j=0;j<matrix.size();j++) {
                mat_t[i][j] = matrix[j][i];
            }
        }
        return mat_t;
    }
};