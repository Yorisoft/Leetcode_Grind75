// Start from the back of the row
// move to empty slot if not designate current element as empty slot.

// to rotate 90 degrees
// vector[i][j] needs to be vector[j][vector.size() - 1 - i]
// the old vector is loaded starting from the last row moving up the column and to the next row

class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& box) {
        // Make the stones fall to the right
        for (int i = 0; i < box.size(); i++) {
            int emptySpot = box[i].size() - 1;
            for (int j = box[i].size() - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    std::swap(box[i][j], box[i][emptySpot--]);
                } else if (box[i][j] == '*') {
                    emptySpot = j - 1;
                }
            }
        }

        // Initialize newBox with transposed dimensions
        std::vector<std::vector<char>> newBox(box[0].size(), std::vector<char>(box.size()));

        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < box.size(); i++) {
            for (int j = 0; j < box[i].size(); j++) {
                newBox[j][box.size() - 1 - i] = box[i][j];
            }
        }

        return newBox;
    }
};