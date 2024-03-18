class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            int x=nums[i][0];
            int y=nums[i][1];
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end(), [](const pair<int,int> &a, const pair<int,int>&b){
            if(a.first==b.first)
              return a.second<b.second;
            else return a.first<b.first;
        });
        int l=v[n-1].first,c=1;
        for(int i=n-2;i>=0;i--)
        {
            if(l>=v[i].first and l<=v[i].second) continue;
            else {l=v[i].first; c++;}

        }
        return c;
    }
};