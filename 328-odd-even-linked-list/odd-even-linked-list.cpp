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
        ListNode* curr=head;
        ListNode* odd=new ListNode(1);
        ListNode* odd2=odd;
        ListNode* even=new ListNode(2);
        ListNode* even2=even;
        while(curr){
            if(curr){
                odd->next=curr;
                curr=curr->next;
                odd=odd->next;
            }
            if(curr){
                even->next=curr;
                curr=curr->next;
                even=even->next;
            }
        }
        even->next=NULL;
        if(odd && even2){
            odd->next=even2->next;
        }
        if(odd2){
            return odd2->next;
        }
        return NULL;
        
        // ListNode* odd=head;
        // ListNode* odd2=head;
        // ListNode* even=head->next;
        // ListNode* even2=head->next;
        // while(odd && even){
        //     if(even){
        //         odd->next=even->next;
        //         odd=odd->next;
        //     }
            
        //     if(odd){
        //         even->next=odd->next;
        //         even=even->next;
        //     } 
        // }
        // odd=odd2;
        // while(odd->next){
        //     odd=odd->next;
        // }
        // odd->next=even2;
        // return odd2;
    }
};