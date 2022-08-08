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
Node *recursive(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *ans=recursive(head->next);
    Node *tail=head->next;
    tail->next=head;
    head->next=NULL;
    return ans;
}
int main(){
    Node *head=takeinput();
    Node *l=recursive(head);
    print(l);
}

