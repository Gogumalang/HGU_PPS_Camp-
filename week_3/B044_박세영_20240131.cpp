class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if((m*n != r*c) || (m==r && n==c)) return mat;
        vector<int> oneD_mat; 
        vector<int> row(c);
        vector<vector<int>> ans;
        for(int i=0;i<r;i++) {
            ans.push_back(row);
        } 
        for(int i =0;i<m;i++) {
            for(int j =0;j<n;j++) {
                oneD_mat.push_back(mat[i][j]);
            }
        }

        for(int i =0;i<oneD_mat.size();i++) {
            ans[i/c][i%c] = oneD_mat[i];
        }
        return ans;

    }
};