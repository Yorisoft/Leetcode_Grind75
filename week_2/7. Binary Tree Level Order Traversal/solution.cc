// MY SOLUTION || NOT WORKING
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
vector<vector<int>> result;

public:
// recursion
// traverse left and right nodes untill root.left && root.right == nullptr
// return root.val 
// add roo.val from left, and root.val from right to tempVector
// add tempVector to final vectorVectorInt

    int recursiveFn(TreeNode* root){
        // condition
        if(root->left == nullptr && root->right == nullptr){
            return root->val;
        }

        // logic
        vector<int> temp;
        if(root->left)
           temp.emplace_back(recursiveFn(root->left));
        if(root->right)
           temp.emplace_back(recursiveFn(root->right));
        
        this->result.emplace_back(temp);

        return 0;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return result;
        }

        this->result.clear();
        vector<int> temp(1, recursiveFn(root));
        result.emplace_back(temp);

        for(vector<int> levels : result){
            for(int level : levels){
                cout << level;
            }
            cout << endl;
        }

        return result;
    }
};



// BETTER SOLUTION
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> q;

        if(!root){
            return levels;
        }
        
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();

                level.emplace_back(node->val);

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            levels.emplace_back(level);
        }
        return levels;
    }
};