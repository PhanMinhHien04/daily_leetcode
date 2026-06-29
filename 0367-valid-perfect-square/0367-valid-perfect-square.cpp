class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1) return true;

        int start = 1;
        int end = num;

        while(start <= end){
            long long mid = start + (end - start) / 2;
            long long sqr = mid * mid;
            if(sqr == num) return true;
            else if(sqr > num) end = mid - 1;
            else start = mid + 1;

        }
        return false;
    }
};