#include<bits/stdc++.h>
class Solution {
public:
    int op(int n1, int n2, string opt)
    {
        if(opt=="+") return n1+n2;
        else if(opt=="-") return n1-n2;
        else if(opt=="/") return n1/n2;
        else return n1*n2;
    }
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            //if(tokens[i].size()==1 && tokens[i][0]<48)
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int x2=st.top();
                st.pop();
                int x1=st.top();
                st.pop();
                st.push(op(x1,x2,tokens[i]));
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();      
    }
};