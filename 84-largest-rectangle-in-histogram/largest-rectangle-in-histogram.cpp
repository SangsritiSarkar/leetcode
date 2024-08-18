class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int area=0,nse,pse;
        for(int i=0;i<n;++i){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                int ele=heights[st.top()];
                st.pop();
                nse=i;
                pse=(st.empty())?-1:st.top();
                area=max(area, ele*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            int ele=heights[st.top()];
            st.pop();
            
            pse=(st.empty())?-1:st.top();
            area=max(area, ele*(nse-pse-1));
        }
        return area;

    }
};