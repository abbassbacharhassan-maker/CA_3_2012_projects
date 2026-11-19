
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the required node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummy.next;
    }
};

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution obj;

    head = obj.removeNthFromEnd(head, n);

    cout << "Output: ";

    ListNode* current = head;

    while (current != nullptr) {
        cout << current->val << " ";

        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    cout << endl;

    return 0;
}
