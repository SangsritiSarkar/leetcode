class Solution {
public:
    int M=1e9+7;
    #define ll long long

    vector<int> getNSL(vector<int>&arr, int n)
    {
        vector<int> result(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()) result[i]=-1;
            else
            {
                while(!st.empty() && arr[i]<=arr[st.top()])
                  st.pop();
                result[i]=(st.empty())?-1:st.top();  
            }
            st.push(i);
            
        }
        return result;
        
    }
     
    vector<int> getNSR(vector<int>&arr, int n)
    {
        vector<int> result(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()) result[i]=n;
            else
            {
                while(!st.empty() && arr[i]<arr[st.top()])
                  st.pop();
                result[i]=(st.empty())?n:st.top();  
            }
            st.push(i);
            
        }
        return result;
        
    } 

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> NSL=getNSL(arr,n);
        vector<int> NSR=getNSR(arr,n);
        ll sum=0;
        for(int i=0;i<n;i++)
        {

            ll ls=i-NSL[i];
            ll rs=NSR[i]-i;
            ll tot=arr[i]*ls*rs;
            
            sum=(sum+tot)%M;

        }
        return sum;
    }
};