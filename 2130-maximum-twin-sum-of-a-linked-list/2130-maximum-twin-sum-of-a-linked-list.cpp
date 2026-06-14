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
        vector <int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }

        int i = 0;
        int n = nums.size();
        //twin sum
        int sum = -1;    //since val of node is alway > -1
        while(i <= ((n/2) -1)){
            int a = nums[i] + nums[n - 1 - i];
            sum = max(sum,a);
            i++;
        }
        return sum;
    }
};