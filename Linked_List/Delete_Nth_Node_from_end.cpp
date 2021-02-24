/*Name: Utkarsh Kumar
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
    void delete_Node(ListNode *ptr)
    {
        ListNode *temp = ptr->next;
        ptr->val = temp->val;
        ptr->next = temp->next;
        delete (temp);
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr || n == 0)
            return head;
        if (head->next == nullptr)
        {
            if (n == 1)
                return nullptr;
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        ListNode *prev = head;
        while (fast != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (slow->next == nullptr)
        {
            prev->next = nullptr;
            delete (slow);
        }
        else
            delete_Node(slow);
        return head;
    }
};