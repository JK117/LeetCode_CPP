//Given a binary tree, return all root-to-leaf paths.
// 
//For example, given the following binary tree:
//   1
// /   \
//2     3
// \
//  5
//All root-to-leaf paths are:
//["1->2->5", "1->3"]

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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> paths;
        vector<int> path;
        createPaths(root, path, paths);
        return paths;
    }
    void createPaths(TreeNode* root, vector<int>& path, vector<string>& paths)
    {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            convertPath(path, paths);
        }
        createPaths(root->left, path, paths);
        createPaths(root->right, path, paths);
        path.pop_back();
    }
    void convertPath(vector<int>& intPath, vector<string>& stringPath)
    {
        string singlePath;
        stringstream buffPath;
        int n = intPath.size();
        for (int i = 0; i < n; ++i)
        {
            if (i != n-1)
            {
                buffPath << intPath[i];
                buffPath << "->";
                singlePath += buffPath.str();
                buffPath.str("");
            }
            else
            {
                buffPath << intPath[i];
                singlePath += buffPath.str();
                buffPath.str("");
            }
        }
        stringPath.push_back(singlePath);
    }
};

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> result;
        
        if(!root) return result;
        
        binaryTreePathshelper(root, result, to_string(root->val));
        
        return result;
    }
    
    void binaryTreePathshelper(TreeNode* root, vector<string>& result, string t)
    {
        if(!root->left && !root->right)
        {
            result.push_back(t);
            return;
        }
        
        if(root->left)
        {
            binaryTreePathshelper(root->left,result, t + "->" + to_string(root->left->val));
        }
        
        if(root->right)
        {
            binaryTreePathshelper(root->right,result, t + "->" + to_string(root->right->val));
        }
        
    }
};