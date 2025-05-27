#include <utility>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    constexpr static auto next_of = [](auto node) { return node ? node->next : nullptr; };
    constexpr static auto val_of = [](auto node) { return node ? node->val : 0; };

    template<typename Func>
    ListNode* zip_list(ListNode* l1, ListNode* l2, Func F, int carry)  {
        if(l1 == nullptr && l2 == nullptr && carry == 0) return nullptr;

        const auto [digit, carry_new] = F(l1, l2, carry);

        return new ListNode(digit, zip_list(
            next_of(l1),
            next_of(l2),
            F,
            carry_new
        ));
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto F = [](ListNode* l1, ListNode* l2, int c) -> std::pair<int, int> {
            int sum = val_of(l1) + val_of(l2) + c;
            return {sum % 10, sum / 10};
        };

        return zip_list(l1, l2, F, 0);
    }
};