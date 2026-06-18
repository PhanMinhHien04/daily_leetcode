class Solution {
public:
    int mySqrt(int x) {
        int high = 46340;
        int low = 1;
        int ans = high;
        if(x==0) return 0;

        while(low<=high){
            int mid = (high+low)/2;

            if(mid*mid == x) return mid;
            else if(mid*mid<x){
              low = mid+1;
              ans = mid;
            } 
            else high = mid-1;
        }
        return ans;
    }
};