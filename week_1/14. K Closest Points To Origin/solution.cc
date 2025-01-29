#include<map>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // calculate euclidean distance 
        // add to sorted datatype. 
        // key is distance, point is value.
        // for k, add points from sorted datatype to response
        // return response
        // Map ? sort by key
        std::multimap<double, pair<int,int>> k_points;
        std::vector<std::vector<int>> response;
        
        for (std::vector<int>& point : points){
            double distance = euclideanDistance(0,point[0], 0, point[1]);
            std::cout << "Point: [" << point[0] << ',' << point[1] << "] , " 
            << "distance: " << distance << std::endl;

            k_points.insert({distance, {point[0], point[1]}});
        }

        int counter = 0;
        for (auto& new_points : k_points){
            if(counter == k)
                break;
            std::vector<int> temp = {new_points.second.first, new_points.second.second};
            response.emplace_back(temp);
            counter++;
        }
        return response;
    }


    double euclideanDistance(int x1, int x2, int y1, int y2){
        double result;
        result = std::sqrt(std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2));
        return result;
    }
};