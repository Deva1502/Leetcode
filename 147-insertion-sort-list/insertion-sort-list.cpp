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
    ListNode* insertionSortList(ListNode* head) {
        vector<int>a;
        ListNode *tmp = head;
        while(tmp!=nullptr){
            a.push_back(tmp->val);
            tmp = tmp->next;
        }
        sort(a.begin(),a.end());
        tmp = head;
        int i=0;
        while(tmp!=nullptr){
            tmp->val = a[i];i++;
            tmp = tmp->next;
        }
        return head;
    }
};