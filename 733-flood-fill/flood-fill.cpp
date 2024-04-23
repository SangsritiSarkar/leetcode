class Solution {
public:
    void dfs(vector<vector<int>> &image, int row, int col, int color, int origin, int nr, int nc)
    {
        if(row<0 or row>=nr or col<0 or col>=nc or image[row][col]==color or image[row][col]!=origin) return;
        image[row][col]=color;
        dfs(image,row-1,col,color,origin,nr,nc);
        dfs(image,row+1,col,color,origin,nr,nc);
        dfs(image,row,col-1,color,origin,nr,nc);
        dfs(image,row,col+1,color,origin,nr,nc);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int nr=image.size();
        int nc =image[0].size();
        int origin=image[sr][sc];
        dfs(image,sr,sc,color,origin,nr,nc);
        return image;
    }
};