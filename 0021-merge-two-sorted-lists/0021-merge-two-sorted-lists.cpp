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
private:
    static bool compare(ListNode* list1, ListNode* list2){
        return list1->val < list2->val;
    }
public:
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        vector<ListNode*> helperVector;
        while(list1 != nullptr){
            helperVector.push_back(list1);
            list1 = list1->next;
        }
        while(list2 != nullptr){
            helperVector.push_back(list2);
            list2 = list2->next;
        }
        
        sort(helperVector.begin(), helperVector.end(), [](ListNode* list1, ListNode* list2) {
            return list1->val < list2->val;
        });

        for(int i = 1; i < helperVector.size(); i++){
            helperVector[i-1]->next = helperVector[i];
        }
        
        if(helperVector.size() == 0)
            return nullptr;
        else{
            helperVector[helperVector.size()-1]->next = nullptr;
            return helperVector[0];
        }
    }
};