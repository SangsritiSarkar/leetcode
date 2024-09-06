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
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* temp=dummy;
        
        while(dummy->next!=nullptr)
        {
            if(st.count(dummy->next->val)>0)
            {
                ListNode* delNode=dummy->next;
                dummy->next=dummy->next->next;
                delete delNode;
            }
            else dummy=dummy->next;
        }
        return temp->next;
        
    }
};
