class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col = grid[0].size();
        int ans =0;
        for(int i =0;i<row;i++) {
            for(int j =0; j<col;j++){
                if(grid[i][j]==1) {
                    ans+=4;
                    if(i>0&&grid[i-1][j]==1) ans-=2;
                    if(j>0&&grid[i][j-1]==1) ans-=2;
                }

            }
        }
        return ans; 
    }
    int dfs(vector<vector<int>>& grid,int i,int j) {
        int count = 0;
        if(grid[i][j]==0) {
            if(i-1>0) count += dfs(grid,i-1,j);
            if(j-1>0) count += dfs(grid,i,j-1);
            if(i+1<grid.size()) count += dfs(grid,i+1,j);
            if(j+1<grid[0].size()) count += dfs(grid,i,j+1);
        }
        else{
            if(i-1<0) count++;
            else {
                if(grid[i-1][j] == 0) count++;
                else {
                    if(grid[i-1][j]!=2) {
                        grid[i-1][j]=2;
                        count += dfs(grid,i-1,j);
                    }
                }
            }
            if(j-1<0) count++;
            else {
                if(grid[i][j-1] == 0) count++;
                else {
                    if(grid[i][j-1]!=2) {
                        grid[i][j-1]=2;
                        count += dfs(grid,i,j-1);
                    }
                }
            }
            if(i+1>grid.size()) count++;
            else {
                if(grid[i+1][j] == 0) count++;
                else {
                    if(grid[i+1][j]!=2) {
                        grid[i+1][j]=2;
                        count += dfs(grid,i+1,j);
                    }
                }
            }
            if(j+1>grid[0].size()) count++;
            else {
                if(grid[i][j+1] == 0) count++;
                else {
                    if(grid[i][j+1]!=2){
                        grid[i][j+1]=2;
                        count += dfs(grid,i,j+1);
                    } 
                }
            }

        }
        
        return count;
    }
};