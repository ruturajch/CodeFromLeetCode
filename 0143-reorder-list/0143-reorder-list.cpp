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
        
        //find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr){
            if(fast->next == nullptr){
                slow = slow->next;
                break;
            }
            fast = fast->next;
            slow = slow->next;
            fast = fast->next;
        }
        
        //reverse the linkedlist
        ListNode* prev = nullptr;
        while(slow != nullptr){
            //cout << slow->val << endl;
            ListNode* cur = slow->next;
            slow->next = prev;
            prev = slow;
            slow = cur;
        }
        ListNode* itr = head;
        while(prev != nullptr){
            ListNode* curprev = prev->next;
            ListNode* curitr = itr->next;
            cout << prev->val << " " << itr->val << endl;
            itr->next = prev;
            prev->next = curitr;
            itr = curitr;
            prev = curprev;
        }
        itr->next = nullptr;
    }
};