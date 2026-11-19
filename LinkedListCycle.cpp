
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

class LinkedListCycle {

public:
    bool hasCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    ListNode* first = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    first->next = second;
    second->next = third;
    third->next = fourth;

    // Create cycle: last node connects to second node
    fourth->next = second;

    LinkedListCycle obj;

    if (obj.hasCycle(first)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Break cycle before deleting nodes
    fourth->next = nullptr;

    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
