class Solution {
public:
typedef pair<int,int> ppi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<ppi> maxh;
        for(auto it:arr){
            maxh.push({abs(it-x),it});
            if(maxh.size()>k) maxh.pop();
        }
        while(maxh.size()){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};