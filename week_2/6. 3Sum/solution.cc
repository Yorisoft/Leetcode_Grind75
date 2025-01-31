// My solution. Not fully working solution.
// for every num in nums
// currentSum =  num + num+1
// for num in nums+2
// if currentSum + num = 0
// add i, j, and k result vector

// return result vector


// THINK BINARY SEARCH
class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size() - 1; j++){
                for(int k = j + 1; k < nums.size(); k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        triplets.emplace_back(std::vector<int>{nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return triplets;
    }
};




/*
Your implementation is incorrect because:

It doesn't handle duplicate triplets properly.

Example: [-1, -1, 2] is missing from the output because duplicates are not handled correctly.
The output order is incorrect.

The triplets are added in an arbitrary order.
*/
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        std::sort(nums.begin(), nums.end()); // Sorting helps with two-pointer technique

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate values for i

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;  // Move left to increase the sum
                } else {
                    right--; // Move right to decrease the sum
                }
            }
        }

        return triplets;
    }
};
