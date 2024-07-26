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
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL)return head;
        ListNode* temp =head;
        int c=0;
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        c=(c/2);
        cout<<c;
        while(c!=0){
            head=head->next;
            c--;
        }
        return head;
    }
};