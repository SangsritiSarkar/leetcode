class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==target) return mid;
            else if(arr[mid]>=arr[l]){
                if(arr[l]<=target and target<arr[mid]) h=mid-1;
                else l=mid+1;
            }
            else
            {
                if(arr[mid]<target and target<=arr[h]) l=mid+1;
                else h=mid-1;
            }
        }
        return -1;
    }
};