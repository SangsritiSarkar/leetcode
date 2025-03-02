class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i=0,j=0, id1,v1, id2, v2, n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> ans;
        while(i<n1 and j<n2){
            id1=nums1[i][0]; v1=nums1[i][1];
            id2=nums2[j][0]; v2=nums2[j][1];

            if(id1<id2){
                ans.push_back({id1,v1}); ++i;
            } 
            else if(id1>id2){
                ans.push_back({id2,v2}); ++j;
            } 
            else{
                ans.push_back({id1, v1+v2}); ++i; ++j;
            }
        }

        while(i<n1) {ans.push_back({nums1[i][0],nums1[i][1]}); ++i;}
        while(j<n2) {ans.push_back({nums2[j][0],nums2[j][1]}); ++j;}

        return ans;
    }
};