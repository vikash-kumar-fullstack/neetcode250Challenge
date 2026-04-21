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

// class Solution {
//    public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* temp1 = list1;
//         ListNode* temp2 = list2;
//         ListNode* head = NULL;
//         ListNode* tail = NULL;
//         while (temp1 && temp2) {
//             if (temp1->val < temp2->val) {
//                 if (!head) {
//                     head = tail = temp1;
//                 } else {
//                     tail->next = temp1;
//                     tail = temp1;
//                 }
//                 temp1=temp1->next;
//             } else {
//                 if (!head) {
//                     head = tail = temp2;
//                 } else {
//                     tail->next = temp2;
//                     tail = temp2;
//                 }
//                 temp2=temp2->next;
//             }
//         }
//         while (temp1) {
//             if (!head) {
//                 head = tail = temp1;
//             } else {
//                 tail->next = temp1;
//                 tail = temp1;
//             }
//             temp1=temp1->next;
//         }
//         while (temp2) {
//             if (!head) {
//                 head = tail = temp2;
//             } else {
//                 tail->next = temp2;
//                 tail = temp2;
//             }
//             temp2=temp2->next;
//         }
//         if (tail) tail->next = NULL;
//         return head;
//     }
// };
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = (list1) ? list1 : list2;

        return dummy->next;
    }
};
