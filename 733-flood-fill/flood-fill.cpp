class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int col=image[sr][sc];
        if(col==color) return image;
        image[sr][sc]=color;
        q.push({sr,sc});
        vector<int> r={-1,0,0,1};
        vector<int> c={0,-1,1,0};
        int nr=image.size();
        int nc=image[0].size();

        while(!q.empty()){
            auto node=q.front();
            int tr=node.first;
            int tc=node.second;
            q.pop();
            for(int i=0;i<4;++i){
                int delrow=tr+r[i];
                int delcol=tc+c[i];
                if(delrow>=0 and delrow<nr and delcol>=0 and delcol<nc and image[delrow][delcol]==col){
                    image[delrow][delcol]=color;
                    q.push({delrow,delcol});
                }
            }
        }
        return image;
    }
};