class Solution {
public:
    int search(vector<int>& nums, int target) {
        // create two pointer, one pointing to beginning and other pointing to end of vector.
        // while start is less or equal to end pointer
            // check the middle element and compare it to the target
            // if the target is higher than the middle element, then the start pointer is the middle of the vector + 1 ( + 1 becuse we just compared the middle element and dont need to compare again).
            // if it is lower, the end pointer is the middle element of vector - 1.
            // continue untill target is found
            // return -1 if no target is found

        bool found_target = false;
        int start_pointer = 0, end_pointer = nums.size()-1;
        
        while(start_pointer <= end_pointer){
            int mid = start_pointer + (end_pointer - start_pointer)/2 ;

            if(nums[mid] == target)
                return mid;
            
            if (nums[mid] > target){
                end_pointer = --mid;
            }
            else if (nums[mid] < target){
                start_pointer = ++mid;
            }              
        }
        return -1;
    }
};

// Not enough accepted submissions to show better solution