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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr != nullptr){
            ListNode* forwordNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forwordNode;
        }
        curr = head;
        while(prev != nullptr && curr != nullptr){
            ListNode* currForword = curr->next;
            ListNode* prevForword = prev->next;
            
            curr->next = prev;
            prev->next = currForword;
            curr = currForword;
            prev = prevForword;
        }
    }
};