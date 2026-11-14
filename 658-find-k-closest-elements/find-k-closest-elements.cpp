class Solution {
public:
typedef pair<int,int> ppi;
template <typename T>

struct comp{
    bool operator()(T a, T b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
};

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<ppi, vector<ppi>, comp<ppi>> maxh;
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