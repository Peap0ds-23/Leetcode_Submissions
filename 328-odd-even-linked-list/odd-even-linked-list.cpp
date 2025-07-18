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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return head;
        }
        ListNode* odd=head;
        ListNode* odd2=head;
        ListNode* even=head->next;
        ListNode* even2=head->next;
        while(odd && even){
            if(even){
                odd->next=even->next;
                odd=odd->next;
            }
            
            if(odd){
                even->next=odd->next;
                even=even->next;
            } 
        }
        odd=odd2;
        while(odd->next){
            odd=odd->next;
        }
        odd->next=even2;
        return odd2;
    }
};