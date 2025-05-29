class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* current = head;
        while (current && current->next) {
            swap(current->val, current->next->val);
            current = current->next->next;
        }
        return head;
    }
};
