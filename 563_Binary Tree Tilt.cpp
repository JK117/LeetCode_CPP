//Given two arrays, write a function to compute their intersection.
// 
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
// 
//Note:
//1.Each element in the result must be unique.
//2.The result can be in any order.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int findTilt(TreeNode* root)
    {
        postOrder(root);
        return sum;
    }
    int postOrder(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        int valL = postOrder(root->left);
        int valR = postOrder(root->right);
        sum = sum + abs(valL - valR);
        return root->val + valL + valR;
    }

private:
    int sum = 0;
};