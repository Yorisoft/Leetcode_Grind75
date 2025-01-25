class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> myMat(mat.size(), vector<int>(mat[0].size(), -1));
        int rowDirection[] = {-1, 1, 0, 0};
        int colDirection[] = {0, 0, 1, -1};

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    myMat[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + rowDirection[i];
                int ncol = c + colDirection[i];
                if(nrow >= 0 && ncol >= 0 && nrow < myMat.size() && ncol < myMat[nrow].size() && myMat[nrow][ncol] == -1){
                    myMat[nrow][ncol] = myMat[r][c] + 1;
                    q.push({nrow, ncol}); 
                }
            }
        }
        return myMat;
    }
};