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
        ListNode *back; 
        ListNode *cur; 
        ListNode *next; 
        back = nullptr; 
        cur = head;
        while(cur !=nullptr) {
            next = cur->next;
            cur->next = back;
            back = cur;
            cur = next;
        }
        head = back;
        return head;
    }
};