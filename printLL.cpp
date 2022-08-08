#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int n){
        data=n;
        next=NULL;
    }
};
void print(Node* head){
      Node *temp=head;
      while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node *n1=new Node(3);
    Node *n2=new Node(4);
    Node *n3=new Node(1);
    Node *n4=new Node(5);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    Node* head=n1;
    print(head);
}
