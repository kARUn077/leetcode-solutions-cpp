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
    ListNode* rotateRight(ListNode* head, int k){
        //calcluate length
        if(head==NULL || head->next == NULL || k==0) return head;

        int cnt=1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp -> next;
            cnt ++;
        }

        k = k%cnt;
        k = cnt - k;

        temp ->next = head;

        for(int i=0;i<k;i++){   
            temp = temp -> next;
        }

        head = temp -> next;
        temp -> next = NULL; 
        return head;        
    }
};