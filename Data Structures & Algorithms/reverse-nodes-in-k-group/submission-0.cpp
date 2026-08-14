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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *curr = head;
        int count = 1;

        while(curr && count < k) {
            curr = curr->next;
            count++;
        }

        if(curr == nullptr)
            return head;

        ListNode* nextPart = curr->next;

        curr->next = nullptr;

        ListNode* newHead = reverseList(head);

        head->next = reverseKGroup(nextPart, k);

        return newHead;
    }
};
