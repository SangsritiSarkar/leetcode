class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0, h=n*m-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(x==matrix[mid/m][mid%m]) return true;
            else if(x>matrix[mid/m][mid%m]) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};