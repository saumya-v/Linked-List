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
Node *takeinput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *iterative(Node *head){
    Node *curr=head;
    Node *prev=NULL;
    Node *n=NULL;
    while(curr!=NULL){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    return prev;
}
int main(){
    Node *head=takeinput();
    Node *l=iterative(head);
    print(l);
}


