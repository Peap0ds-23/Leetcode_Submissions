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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp=new ListNode(-1,head);
        unordered_set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        ListNode *curr=head,*prev=temp;
        while(curr){
            if(s.find(curr->val)!=s.end()){
                prev->next=curr->next;
                // delete curr;
                curr=prev->next;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        // for()
        return temp->next;
    }
};