//Given a binary tree and a sum, 
//find all root-to-leaf paths where each path's sum equals the given sum.
// 
//For example:
//Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//return:
//[
//   [5,4,11,2],
//   [5,8,4,5]
//]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> allPath;
        vector<int> singlePath;
        findPath(root, sum, allPath, singlePath);
        return allPath;
    }

    void findPath(TreeNode* node, int sum, vector<vector<int>> &paths, vector<int> &path)
    {
        if (!node) return;
        path.push_back(node->val);
        if (sum == node->val && node->left == NULL && node->right == NULL)
        {
            paths.push_back(path);
        }
        findPath(node->left, sum - node->val, paths, path);
        findPath(node->right, sum - node->val, paths, path);
        path.pop_back();
    }
};