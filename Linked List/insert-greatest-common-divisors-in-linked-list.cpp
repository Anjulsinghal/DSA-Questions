/** Leetcode 2807. insert-greatest-common-divisors-in-linked-list
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* temp = head->next;

        while(temp != NULL){
            int gcD = gcd(prev->val, temp->val);
            ListNode* newNode = new ListNode(gcD);

            prev->next = newNode;
            newNode->next = temp;

            temp = temp->next;
            prev = prev->next->next;

        }

        return head;
    }
};