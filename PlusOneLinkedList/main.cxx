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
    ListNode* plusOne(ListNode* head) {
        int c = add(head);
        if (c == 0 ){
            return head;
        }
        return new ListNode(1,head);

    }
    private:
    int add(ListNode* head){
        if (head->next == nullptr) {
            head->val +=1;
            if (head->val >=10){
                head->val -=10;
                return 1;
            }
            return 0;
        }
        head->val +=add(head->next);
        if (head->val >=10){
            head->val -=10;
            return 1;
        }
        return 0;

    }
};
