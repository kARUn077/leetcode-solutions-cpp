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
    ListNode* reverseKGroup(ListNode* head, int k){
        //base call
        if(head == NULL)return NULL;

        // check if at least k nodes exist
        ListNode* temp = head;
        for(int i = 0; i < k; i++) {
            if(temp == NULL) return head; // not enough nodes, return original head
            temp = temp->next;
        }

        //step1: reverse first k nodes 
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt=0;

        while(curr && cnt<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        //step2: recursion dekhlega aage ka
        if(next){
            head -> next = reverseKGroup(next ,k);
        }

        //step3: return head of reversed list
        return prev;
    }
};