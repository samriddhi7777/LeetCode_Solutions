
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
           return nullptr;
        Node* curr = head;
        while(curr != nullptr){
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }
        curr = head;
        while(curr != nullptr){
            if(curr->random != nullptr)
              curr->next->random = curr->random->next;
              curr = curr->next->next;
        }
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;

        curr = head;

        while(curr != nullptr){
            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;

            curr->next = curr->next->next;
            curr = curr->next;
        }
        return dummy->next;

        
    }
};