class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        unordered_map<int,int> ngemp;
        vector<int> nge;
        stack<int> st;
        for(int i=n2-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=nums2[i]) st.pop();
            if(st.empty()) ngemp[nums2[i]]=-1;
            else ngemp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<n1;++i) nge.push_back(ngemp[nums1[i]]);
        return nge;
    }
};