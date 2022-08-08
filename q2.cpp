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
Node *reversal(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *ans=reversal(head->next);

    Node *tail=head->next;
    tail->next=head;
    head->next=NULL;
    return ans;

}
int main(){
    Node *head=takeinput();
    head=reversal(head);
    print(head);
}
