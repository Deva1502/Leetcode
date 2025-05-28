/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr)return nullptr;
        int i = 0;
        ListNode *cur = head, *p = head, *q = head->next, *r = q;
        while (q != nullptr and q->next!=nullptr) {

            p->next = p->next->next;
            p = p->next;

            q->next = q->next->next;
            q=q->next;
        }
        p->next = r;
        return head;
    }
};