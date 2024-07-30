class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nr=matrix.size();
        int nc=matrix[0].size();
        int l=0,h=nc*nr-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int mr=(mid/nc);
            int mc=(mid%nc);
            if(target==matrix[mr][mc]) return true;
            if(target>matrix[mr][mc]) l=mid+1;
            else h=mid-1;

        }
        return false;
    }
};