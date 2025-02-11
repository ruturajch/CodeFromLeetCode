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
    bool isPalindrome(ListNode* head) {
        ListNode* rightNode = head;
        vector<int> v;
        while(rightNode != NULL){
            v.push_back(rightNode->val);
            rightNode = rightNode->next;
        }
        for(int i = 0; i < v.size() / 2; i++){                
            if(v[i] != v[v.size() - i - 1]){                    
                return false;                    
            }                
        }            
        return true;
    }
};