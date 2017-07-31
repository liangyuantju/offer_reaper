#include<iostream>
using namespace std;

class Solution {
public:
    bool IsBalanced(TreeNode *root, int &dep) {
        if(root == NULL) {
            return true;
        }
        int left = 0;
        int right = 0;
        if(IsBalanced(root->left, left) && IsBalanced(root->right, right)) {
            int dif = left - right;
            if(dif < -1 || dif > 1)
                return false;
            dep = (left > right ? left : right) + 1;
            return true;
        }
        return false;
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return  IsBalanced(pRoot, dep);
    }
};



class Solution {
public:
    bool IsBalancedValue = true;

    int IsBalanced(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        int left = IsBalanced(root->left);
        int right = IsBalanced(root->right);
        if((left - right) > 1 || (left - right) < -1)
            IsBalancedValue = false;
         return (left > right ? left : right) + 1;
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        IsBalanced(pRoot);
        return IsBalancedValue;
    }
};