// NOT A WORKING SOLUTION. BUT IT WAS BEST I COULD DO FIRST TIME AROUND
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // find the p and q
    // std::max( 1 ,2)
    // std::maximum(array.begin(), array.end())
    TreeNode* bsf(TreeNode* root, TreeNode* x){
        if(root == nullptr){
            return nullptr;
        }
        if(root->left->val == x->val){
            return root;
        }
        if(root->right->val == x->val){
            return root;
        }  
 
        TreeNode lcaR = bsf(root->right, x);
        TreeNode lcaL = bsf(root->left, x);

        if( lcaR == lcaL ) {
            return lcaR;
        }
        else if (lcaR == nullptr ){
            return &lcaL;
        }

        return &lcaR;
    }

    // calculate the LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* pLCA = new TreeNode(0), qLCA = new TreeNode(0) , lca = new TreeNode(0);

        pLCA = bsf(root, p);
        qLCA = bsf(root, q);

        // pLCA and qLCA are the same, if so, either can be returned as LCA
        // 
        if ( pLCA == qLCA){
            lca = pLCA;
        } else if ( pLCA <  qLCA){
            lca = pLCA;
        } else {
            lca = qLCA;
        }

        return lca;

    }
};



//
// Good solid  Solution
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // find the p and q
    // std::max( 1 ,2)
    // std::maximum(array.begin(), array.end())

    // Calculate the LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *currentNode = root; 

        while(currentNode){
            if(currentNode->val < p->val && currentNode->val < q->val ){
                currentNode = root->right;            
            } else if (currentNode->val > p->val && currentNode->val > q->val){
                currentNode = root->left;
            } else {
                break;
            }
        }
        return currentNode;
    }
};


// Best and simples solution. recursively call the function
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // find the p and q
    // std::max( 1 ,2)
    // std::maximum(array.begin(), array.end())

    // Calculate the LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root->val < p->val && root->val < q->val ){
                return lowestCommonAncestor(root->right, p, q);            
            } else if (root->val > p->val && root->val > q->val){
                return lowestCommonAncestor(root->left, p, q);
            } 
        return root;
    }
};