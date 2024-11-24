// Works for some test casese but not all. Good effort and learning experience
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // find start
        // for every element,
        // check if current element is >= intervals[0][0], starting point
        // continue to check for ending point = current lement >= intervals[0][1]
        // if endign point isnt found in current row, pop current row
        // if ending point > intervals[0][1]
        // startng point  = intervals[0][1]
        // if ending point = intervals[0][1]
        // startng point  = ending point

        int startingPoint = -1; // used to stop looking for startingPoint
        int endingPoint = -1;
        int sRow;
        int sCol;
        // if intervals is empty add newInterval and return intervals
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }

        // is the first element in newIntervals larger than tha last element in intervals? Add newInterval to end and return intervals.
        if(intervals[intervals.size()-1][ intervals[0].size() - 1] < newInterval[0] ){
            intervals.push_back(newInterval);
            return intervals;
        }

        for(int i = 0; i < intervals.size(); i++){
            for(int j = 0; j < intervals[i].size(); j++){
                if(intervals[i][j] >= newInterval[0] && startingPoint == -1){
                    startingPoint = 1;
                    sRow = i;
                    sCol = j;
                    //intervals[i][j] = newInterval[0][0]; 
                } else if(intervals[i][j] >= newInterval[1] && endingPoint == -1){
                    endingPoint = 1;
                    if(intervals[i][j] == newInterval[1]){
                        //int temp = intervals[i][j+1]
                        intervals[sRow][sCol] = intervals[i][j+1];
                        intervals.erase(intervals.begin() + i);
                    } else {
                        intervals[sRow][sCol] = newInterval[1];
                    }
                }

                // Are we at the end of array and not found endingPoint?  Make last memeber endingPoint
                if(i == intervals.size() - 1 && j == intervals[0].size() -1 && endingPoint == -1){
                    intervals[i][j] = std::max(newInterval[1], intervals[i][j]);
                }
            }
            // we found a starting point but the current row doesnt have endingPoint, pop it
            if(startingPoint != -1 && endingPoint == -1 ){
                if(sRow != i){
                    intervals.erase(intervals.begin() + i);
                    i--;
                }
            }
        }
        
        return intervals;

    }
};


// Best solution I've found so far. 
// Instead of 1 forloop, it uses a counter to go through the vector and while loops to enter and exit conditions
class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // Add all intervals ending before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Merge all overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // Add all intervals starting after newInterval ends
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};