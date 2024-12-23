#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;

    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = createList(vector<int>{2, 4, 3});
    ListNode* l2 = createList(vector<int>{5, 6, 4});

    printList(l1);
    printList(l2);

    ListNode* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}
