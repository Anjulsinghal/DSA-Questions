// Leetcode 143. reorder-list
// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* ptr1 = head;
        while(ptr1)
        {
            st.push(ptr1);
            ptr1 = ptr1->next;

        }
        int n = ((st.size() - 1) / 2) ;
        ptr1 = head;
        while(n--)
        {
            ListNode* next = ptr1->next;
            ptr1->next = st.top();
            st.pop();
            ptr1->next->next = next;
            ptr1 = ptr1->next->next;
            st.top()->next = nullptr;

        } 
    }
};