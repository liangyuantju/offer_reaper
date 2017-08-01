//输入一个链表，从尾到头打印链表每个节点的值。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    //ListNode(int x) : val(x),next(NULL) {}
//};
//
/* 创建一个单链表 */
struct ListNode{
    int val;
    ListNode* next;
};

void createList(ListNode* pHead){
    ListNode* p = pHead;
    for (int i = 1; i < 10; ++i) {
        ListNode* pNewNode = new ListNode;
        pNewNode->val = i; // 将新节点的值赋值为i
        pNewNode->next = NULL;
        p->next = pNewNode; // 上一个节点指向这个新建立的节点
        p = pNewNode; // p节点指向这个新的节点
    }
}

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> value;
        if (head != NULL) {
            value.insert(value.begin(), head->val);
            if (head->next != NULL) {
                vector<int> tempVec = printListFromTailToHead(head->next);
                if (tempVec.size() > 0)
                    value.insert(value.begin(), tempVec.begin(), tempVec.end());
            }
        }
        return value;
    }
};

int main(){
    ListNode* head = NULL;
    head = new ListNode;
    head->val = 0;
    head->next = NULL;
    createList(head);
    Solution test;
    vector<int> res = test.printListFromTailToHead(head->next);
    ListNode* tmp = head->next;
    while(tmp != NULL) {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;

    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}