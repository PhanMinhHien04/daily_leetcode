class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int actualSum = 0;
        for(int num : nums){
            actualSum += num;
        }
        return sum - actualSum;
    }
};