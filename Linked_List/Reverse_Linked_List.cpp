/* Name: Utkarsh Kumar
Institution: NIT Meghalaya
*/

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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *third = head->next->next;
        second->next = first;
        first->next = nullptr;
        first = second;
        second = third;
        while (third != nullptr)
        {
            third = third->next;
            second->next = first;
            first = second;
            second = third;
        }
        return first;
    }
};