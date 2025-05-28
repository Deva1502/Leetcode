class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        for (int i = 1; i < k; ++i) {
            first = first->next;
        }

        ListNode* fast = first->next;
        // for (int i = 0; i < k; ++i) {
        //     fast = fast->next;
        // }

        ListNode* second = head;
        while (fast != nullptr) {
            fast = fast->next;
            second = second->next;
        }

        swap(first->val, second->val);
        return head;
    }
};
