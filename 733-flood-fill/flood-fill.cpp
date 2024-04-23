class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int nr=image.size();
        int nc =image[0].size();
        int origin=image[sr][sc];
        if(origin==color) return image;
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int r[]={-1,0,1,0};
            int c[]={0,-1,0,1};
            for(int i=0;i<4;i++)
            {
                int delrow=row+r[i];
                int delcol=col+c[i];
                if(delrow>=0 and delrow<nr and delcol>=0 and delcol<nc and  image[delrow][delcol]==origin)
                {
                    q.push({delrow,delcol});
                    image[delrow][delcol]=color;
                }
            }
        }
        return image;
    }
};