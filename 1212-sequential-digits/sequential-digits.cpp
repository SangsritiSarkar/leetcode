class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        vector<int> pos={1,2,3,4,5,6,7,8,9,
                         12,23,34,45,56,67,78,89,
                         123,234,345,456,567,678,789,
                         1234,2345,3456,4567,5678,6789,
                         12345,23456,34567,45678,56789,
                         123456,234567,345678,456789,
                         1234567,2345678,3456789,
                         12345678,23456789,
                         123456789};
        int n=pos.size();    
        for(int i=0;i<n;i++) 
        {
            if(pos[i]>=low and pos[i]<=high) ans.push_back(pos[i]);
            else if(pos[i]>high) break;
        }             
        return ans;
    }
};