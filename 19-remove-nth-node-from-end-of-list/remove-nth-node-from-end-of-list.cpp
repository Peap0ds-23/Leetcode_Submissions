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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        if(count==n){
            head=temp->next;
            delete(temp);
            return head;
        }
        
        count-=(n+1);
        while(count>0){
            temp=temp->next;
            count--;
        }
        ListNode* temp1=temp->next;
        if(n==1){
            if(count<0){
                delete(head);
                return NULL;
            }
            temp->next=NULL;
            delete(temp1);
            return head;
        }
        temp->next=temp->next->next;
        delete(temp1);
        return head;
    }
};