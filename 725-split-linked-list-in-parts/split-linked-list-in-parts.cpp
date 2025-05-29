class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int c = 0;
        ListNode *tmp = head;
        while (tmp) {
            tmp = tmp->next;
            c++;
        }

        int vl1 = c / k;
        int vl2 = c % k;

        vector<ListNode*> ans;
        tmp = head;

        for (int i = 0; i < k; ++i) {
            ListNode* partHead = tmp;
            int vl = vl1 + (i < vl2 ? 1 : 0);
            //traversing ll
            for (int j = 0; j < vl - 1; ++j) {
                if (tmp) tmp = tmp->next;
            }
            // aage agr tmp h to break krna hoga jisme tmp ke next ko kahi store krke aage de denge reversal ki tarah
            if (tmp) {
                ListNode* nextPart = tmp->next;
                tmp->next = nullptr;
                tmp = nextPart;
            }
            //ans me start vale node ko push karenge
            ans.push_back(partHead);
        }

        return ans;
    }
};
