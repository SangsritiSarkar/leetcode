class Solution {
public:
    void dfs(int r, int c, int color, int nr, int nc, vector<vector<int>>& image, int ori){
        if(r<0 or r>=nr or c<0 or c>=nc or image[r][c]!=ori or image[r][c]==color) return;
        image[r][c]=color;
        dfs(r+1,c,color,nr,nc,image,ori);
        dfs(r-1,c,color,nr,nc,image,ori);
        dfs(r,c+1,color,nr,nc,image,ori);
        dfs(r,c-1,color,nr,nc,image,ori);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int nr=image.size();
        int nc=image[0].size();
        if(image[sr][sc]==color) return image;
        int ori=image[sr][sc];
        dfs(sr,sc,color,nr,nc,image,ori);
        return image;
    }
};