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
    int pairSum(ListNode* head) {
        int nodeCount = 0;
        ListNode* temp = head;

        stack<int> st;
        while(temp){
            st.push(temp->val);
            nodeCount++;
            temp = temp->next;
        }

        temp = head;

        int maxi = 0;
        while(st.size() > nodeCount/2){
            maxi = max(maxi, st.top() + temp->val);
            st.pop();
            temp = temp->next;
        }

        return maxi;
    }
};