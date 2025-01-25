class Solution {
public:
    void dsf(vector<vector<int>>& image, int sr, int sc, int color, int oldColor){
        if(sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0){
            // if current cell is out of bounds or is already color, return
            return;
        } else if (image[sr][sc] == color || image[sr][sc] != oldColor ){
            // if it is equal to color, it means change was already made
            // if it is not equal to oldColor, it means its not to be changed.
            return;
        }
    
        // change the current cell / element of the matrix
        image[sr][sc] = color;

        // call this function recusively to go down 1
        dsf(image, sr-1, sc, color, oldColor);
        // call this function recusively to go up 1
        dsf(image, sr+1, sc, color, oldColor);
        // call this function recusively to go left 1
        dsf(image, sr, sc-1, color, oldColor);
        // call this function recusively to go right 1
        dsf(image, sr, sc+1, color, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        // perform depth search first
        dsf(image,sr,sc,color,oldColor);

        return image;
    }
};