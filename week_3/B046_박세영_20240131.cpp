class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int s_color = image[sr][sc];
        if(s_color == color) return image;
        dfs(image,color,sr,sc,s_color);
        return image;
    }
    void dfs(vector<vector<int>>& image,int color,int i,int j,int oldcolor) {
        image[i][j] = color; 
        if(i+1<image.size()&&image[i+1][j]==oldcolor) dfs(image,color,i+1,j,oldcolor);
        if(i-1>=0&&image[i-1][j]==oldcolor)dfs(image,color,i-1,j,oldcolor);
        if(j-1>=0&&image[i][j-1]==oldcolor)dfs(image,color,i,j-1,oldcolor);
        if(j+1<image[0].size()&&image[i][j+1]==oldcolor)dfs(image,color,i,j+1,oldcolor);
    }
};