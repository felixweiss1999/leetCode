#include <memory>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* const new_list_head = new ListNode();
        ListNode* new_list_node = new_list_head;
        int sum = 0;
        int carryover = 0;
        while(l1 != nullptr && l2 != nullptr){
            sum = l1->val + l2->val + carryover;
            carryover = 0; //reset
            if(sum >= 10){
                carryover = 1;
                sum -= 10;
            }
            new_list_node->next = new ListNode(sum);
            new_list_node = new_list_node->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* remainder_list = l1 != nullptr ? l1 : l2;
        while(remainder_list != nullptr){
            sum = remainder_list->val + carryover;
            carryover = 0;
            if(sum >= 10){
                carryover = 1;
                sum -= 10;
            }
            new_list_node->next = new ListNode(sum);
            new_list_node = new_list_node->next;
            remainder_list = remainder_list->next;
        }
        if(carryover == 1){
            new_list_node->next = new ListNode(1);
        }
        return new_list_head->next;
    }

    void test(){

    }
};


int main(){

    return 0;
}