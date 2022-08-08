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
void printI(Node *head,int i){
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
        if(l==i){
            cout<<head->data;
        }
    }
}
int main(){
    Node *head=takeinput();
    int pos;
    cin>>pos;
    printI(head,pos);
    cout<<endl;
}
