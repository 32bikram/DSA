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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* temp = head; ListNode* prev = NULL;
        ListNode* ans = temp->next;
        while(temp!=NULL && temp->next!=NULL){
            ListNode* temp3 = temp->next->next;
            ListNode* temp2 = temp->next;

            if(prev!=NULL) prev->next = temp2;
            temp2->next = temp;
            temp->next = temp3;

            prev = temp;
            temp = temp3;
        }
        return ans;
    }
};
