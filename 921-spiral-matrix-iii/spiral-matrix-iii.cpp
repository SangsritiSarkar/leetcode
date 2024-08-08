class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dirn={
            {0,1}, //E
            {1,0}, //S
            {0,-1}, //W
            {-1,0}  //N
        };
        vector<vector<int>> ans;
        int d=0,steps=0;
        ans.push_back({rStart,cStart});

        while(ans.size()<rows*cols){
            if(d==0 or d==2) steps++;
            for(int i=0;i<steps;++i)
            {
                rStart+=dirn[d][0];
                cStart+=dirn[d][1];
                if(rStart>=0 and rStart<rows and cStart>=0 and cStart<cols) 
                   ans.push_back({rStart,cStart});
            }
            d=(d+1)%4;
        }
        return ans;
    }
};