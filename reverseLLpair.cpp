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
class Pair{
public:
    Node *head;
    Node *tail;
};
Pair reversal(Node *head){
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallans=reversal(head->next);
    smallans.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallans.head;
    ans.tail=head;
    return ans;
}
Node *recursive(Node *head){
    return reversal(head).head;
}
int main(){
    Node *head=takeinput();
    Node *l=recursive(head);
    print(l);
}

