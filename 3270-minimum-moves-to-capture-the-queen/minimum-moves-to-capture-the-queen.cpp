class Solution {
public:
   
    
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // if(a==e || b==f)
        // {
        //     if(a==e && a==c && (d-b)*(d-f)<0) return 2;
        //     if(b==f && b==d && (c-a)*(c-e)<0) return 2;
        //     return 1;
        // }
        // if(abs(c-e)==abs(d-f) && abs(c-a)==abs(d-b) && abs(a-e)==abs(b-f) && ((b-d)*(b-f)<0)) return 1;
        // return 2;

        if(a == e || b == f) {
            if(a == e && a == c && ((d-b) * (d-f) < 0)) return 2;
            if(b == f && b == d && ((c-a) * (c-e) < 0)) return 2;
            return 1;
        }
        if(abs(c - e) == abs(d - f)) {
            if(abs(c - a) == abs(d - b) && abs(e - a) == abs(f - b) && ((b-f) * (b-d) < 0))  return 2;
            return 1;
        }
        return 2;
    }
};