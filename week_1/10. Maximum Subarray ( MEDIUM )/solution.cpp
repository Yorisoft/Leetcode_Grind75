class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // start at the begining of list.
        // make currentSum = nums[0], and maxSum = currentSum;
        // for every element in nums, add to currentSum. currentSum = nums[i]
        // if currentSum is < 0, discard the currentSum and set it to 0.
        // otherwise, add nums[i] to currentSum. 
        // if currentSum is > maxSum, maxSum = currentSum. 
        // return maxSum

        int currentSum = nums[0];
        int maxSum = currentSum;
        for(int i = 1; i < nums.size(); i++){
            if(currentSum < 0 )
                currentSum = 0;
            currentSum += nums[i];
            if (currentSum > maxSum){
                maxSum = currentSum;
            }
        }
        return maxSum;
    }
};