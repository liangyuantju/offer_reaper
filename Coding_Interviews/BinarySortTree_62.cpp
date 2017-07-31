//给定一颗二叉树，请找出其中的第k大的结点。
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL)
//    {
//    }
};

void creatBiTree(TreeNode *pHead)
{
    char ch;
    ch = getchar();
    if (ch == '#') {
        pHead = NULL;
    } else {
        if(!(pHead = (TreeNode*)malloc(sizeof(TreeNode))))
            cout << "error" << endl;
        pHead->val = ch;
        pHead->left = creatBiTree(pHead->left);
        pHead->right = creatBiTree(pHead->right);
    }

    return pHead;
}

//二叉搜索树中序遍历的变形
class Solution1 {
public:
    int count = 0;
    TreeNode* kthNode(TreeNode* pRoot, int k)
    {
        if (pRoot) {
            TreeNode *ret = kthNode(pRoot->left, k);
            if (ret) return ret;
            if (++count == k) return pRoot;
            ret = kthNode(pRoot->right, k);
            if (ret) return ret;
        }
        return NULL;
    }
}

//二叉搜索树按照中序遍历的顺序打印出来正好就是排序好顺序
class Solution2 {
    void visitMid(TreeNode *pHead)
    {
        if (pHead != NULL) {
            visitMid(pHead->left);
            cout<<pHead->val;
            visitMid(pHead->right);
        }
    }
}