class Solution {
public:
typedef pair<int,vector<int>> ppi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<ppi> maxh;
        for(auto it:points){
            maxh.push({(it[0] * it[0]) + (it[1] * it[1]), it});
            if(maxh.size()>k) maxh.pop();
        }
        vector<vector<int>> ans;
        while(maxh.size()){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};