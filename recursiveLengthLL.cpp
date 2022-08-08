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
int length(Node *head){
    if(head==NULL){
        return 0;
    }
    return 1+length(head->next);
}
int main(){
    Node *head=takeinput();
    cout<<length(head)<<endl;
}
