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
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
Node *deleted(Node *head,int i){
    if(head==NULL){
        return head;
    }
    if(i==0){
        head=head->next;
        return head;
    }
    head->next=deleted(head->next,i-1);
    return head;
}
void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    Node *head=takeinput();
    print(head);
    int i;
    cin>>i;
    head=deleted(head,i);
    print(head);
}
