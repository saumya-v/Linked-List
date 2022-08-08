#include<iostream>
using namespace std;
class Node{
public:
    Node *next;
    int data;
    Node(int n){
        data=n;
        next=NULL;
    }
};
Node *startingPoint(Node *head){
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast !=slow) {
        if (fast == NULL ||fast->next==NULL){
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
int main()
{
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    Node* res = startingPoint(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->data;

}
