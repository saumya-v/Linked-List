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
Node* insert(Node *head,int i,int data){
    if(head==NULL){
        if(i==0){
            Node *newnode=new Node(data);
            return newnode;
        }

        return head;
    }
    Node *newnode=new Node(data);
    if(i==0){
        newnode->next=head;
        head=newnode;
        return head;
    }
    head->next=insert(head->next,i-1,data);
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
    int i,data;
    cin>>i>>data;
    head=insert(head,i,data);
    print(head);
}

