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
    int countTreeDepth(TreeNode* root){
        if( root == nullptr){
            return 0;
        }

        int leftDepth =  countTreeDepth(root->left);
        int rightDepth =  countTreeDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) {
        // for every node
        // check left and right nodepointers
        // if either is true then +1 to the count and call function again on left and right nodes to repeate ( recursion )
        // compare count of leftnode to count of rightnode, if it is more than 1, it is not balanced.
        if( root == nullptr){
            return true;
        }

        int leftCounter = 0, rightCounter = 0;

        leftCounter = countTreeDepth(root->left);
        rightCounter = countTreeDepth(root->right);

        if (std::abs(leftCounter - rightCounter) > 1){
            return false;
        } 
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// Better solution A
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If the tree is empty, we can say it’s balanced...
        if (root == NULL)  return true;
        // Height Function will return -1, when it’s an unbalanced tree...
        if (Height(root) == -1)  return false;
        return true;
    }
    // Create a function to return the “height” of a current subtree using recursion...
    int Height(TreeNode* root) {
        // Base case...
        if (root == NULL)  return 0;
        // Height of left subtree...
        int leftHeight = Height(root->left);
        // Height of height subtree...
        int rightHight = Height(root->right);
        // In case of left subtree or right subtree unbalanced or their heights differ by more than ‘1’, return -1...
        if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)  return -1;
        // Otherwise, return the height of this subtree as max(leftHeight, rightHight) + 1...
        return max(leftHeight, rightHight) + 1;
    }
};

// Better solution B
class Solution {
    private:
    int checkHeight(TreeNode* node) {
        if(node == NULL){
            return 0;
        }
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Left subtree is not balanced
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Right subtree is not balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight); 
    }
public:
    bool isBalanced(TreeNode* root) {
        if(checkHeight(root) != -1) return true;
        else return false;
    }
};