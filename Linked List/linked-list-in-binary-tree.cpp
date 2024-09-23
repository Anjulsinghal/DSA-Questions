// Leetcode. 1367 /linked-list-in-binary-tree
// https://leetcode.com/problems/linked-list-in-binary-tree/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkPath(ListNode* head, TreeNode* root) 
    {
        if(!head) return true;
        if(!root or head->val != root->val) return false;
        return checkPath(head->next, root->left) or checkPath(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if(!root) return false;
        return (head->val == root->val && checkPath(head, root)) or 
               isSubPath(head, root->left) or
               isSubPath(head, root->right);
    }
};