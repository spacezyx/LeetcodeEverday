/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 思路：用hash表判断是否出现过最简单
        unordered_set<ListNode*> visited;
        while(head != nullptr) {
            if(visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head -> next;
        }
        return nullptr;
    }
};