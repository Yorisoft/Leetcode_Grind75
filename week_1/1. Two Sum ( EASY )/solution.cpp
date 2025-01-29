class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Are the numbers in nums array in order? NO
        // Is there always going to be a valid answer?

        // Add nums[0] to nums_table map
        // loop/itterate through each number in nums starting at nums[1]
        // second loop/itteration check if nums[x] matches w. number in table to meet target.
        // if nums[x] + nums_table[y] == target, return this as solution. 
        // if nums[x] does not match with any key/value in table, add nums[x] to table.
        // Continue adding key/values to table and itterating through the outter loop to find target. 
        std::vector<int>* solution = new std::vector<int>();
        std::map<int, int>* myTable = new std::map<int, int>();

        for (int i = 0; i < nums.size(); i++){
            if ( i == 0 ){
                myTable->insert({i, nums[i]});
                continue;
            }
            for ( const auto& [key, value] : *myTable ){
                if(nums[i] + value == target ){
                    solution->push_back(key);
                    solution->push_back(i);
                    return *solution;
                }
            }
            myTable->insert({i, nums[i]});
        }
        return *solution;
    }
};

// Slightly better solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        int n = nums.size();
        int i;
        for( i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    sol.push_back(i);
                    sol.push_back(j);
                }
            }
        }
      return sol;  
    }
};

// Best solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> m;
     
       
        for(int i=0;i<nums.size();i++)
        {
            int complement=target-nums[i];
            if(m.find(complement) != m.end())
            {
                return {m[complement], i};
            }
            m[nums[i]]=i;
        }
        return{-1,-1};
    }
};