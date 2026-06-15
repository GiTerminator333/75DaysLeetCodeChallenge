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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return head->next;
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow == fast){
            //2 nodes
            head->next = NULL;
            return head;
        }
        if(fast->next){
            //even nodeCount -> del (n/2 + 1)th
            slow = slow->next;
        }
        ListNode* ptr = head;
        while(ptr->next != slow) ptr = ptr->next;

        ptr->next = slow->next;
        slow->next = NULL;

        return head;
    }
};