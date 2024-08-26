class Solution {
public:
    bool isPalin(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++; end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        auto expand_from_center=[&](int left, int right){
            while(left>=0 and right<s.size() and s[left]==s[right]){
                left--;right++;
            }
            return s.substr(left+1, right-left-1);
        };
        string maxi="";
        maxi+=s[0];
        for(int i=0;i<s.size();i++){
            string odd=expand_from_center(i,i);
            string even=expand_from_center(i,i+1);

            if(odd.size()>maxi.size()) maxi=odd;
            if(even.size()>maxi.size()) maxi=even;
        }
        return maxi;
    }
};