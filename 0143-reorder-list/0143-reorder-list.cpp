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
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr != NULL){
            ListNode* forwordNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forwordNode;
        }
        curr = head;
        while(prev != NULL && curr != NULL){
            cout << curr->val << endl;
            cout << prev->val << endl;
            cout << "dasd"<< endl;
            ListNode* currForword = nullptr;
            ListNode* prevForword = nullptr;
            if(curr->next != nullptr)
                currForword = curr->next;
            if(prev->next != nullptr)
                prevForword = prev->next;
            cout << "dasd1"<< endl;
            curr->next = prev;
            prev->next = currForword;
            cout << "dasd2"<< endl;
            curr = currForword;
            prev = prevForword;
            cout << "dasd3"<< endl;
        }
    }
};