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
Node *takeinput(){
    int n;
    cin>>n;
    Node *head=NULL;
    Node *tail=NULL;
    while(n!=-1){
        Node *newNode=new Node(n);
        if(head==NULL){
           head=newNode;
           tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>n;
    }
    return head;
}
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node *delLL(Node *head,int n){
    if(head==NULL){
        return NULL;
    }
    if(head->data==n && head->next==head){
        delete[] head;
        head=NULL;
        return NULL;
    }
    Node *prev=head;
    Node *curr=head;
    while(prev->next!=head){
            prev=prev->next;
        }
    if(curr->data==n){
            if(curr->next!=NULL){
                prev->next=curr->next;
            }
            else{
                prev->next=NULL;
            }
            if(curr==head){
                head=prev->next;
            }
            free(curr);
            if(prev!=NULL){
                curr=prev->next;
            }
            else{
                curr=NULL;
            }
            prev=curr;
            curr=curr->next;
    }
    return head;

}
int main(){
    Node *n1=new Node(6);
    Node *n2=new Node(1);
    Node *n3=new Node(4);
    Node *n4=new Node(2);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n1;
    Node *head=n1;
    print(head);
    head=delLL(head,4);
    print(head);
}

