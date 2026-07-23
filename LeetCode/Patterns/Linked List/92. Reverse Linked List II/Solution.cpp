
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == nullptr || left == right)
           return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        for(int i = 1; i < left; i++){
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* prevNode = nullptr;

        for(int i = 0; i <= right - left; i++){
            ListNode* next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
        }
        ListNode* tail = prev->next;
        prev->next = prevNode;
        tail->next = curr;

        return dummy->next;
        
    }
};