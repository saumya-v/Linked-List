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
Node *midpoint(Node *head){
    if(head==NULL){
        return head;
    }
    Node *fast=head;
    Node *slow=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node *merge(Node *head1,Node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node *fh=NULL;
    Node *ft=NULL;
    while(head1!=NULL && head2!=NULL){
     if(head1->data<head2->data){
        if(fh==NULL){
            fh=head1;
            ft=head1;
        }
        else{
            ft->next=head1;
            ft=head1;
        }
        head1=head1->next;
     }
     else {
        if(fh==NULL){
            fh=head2;
            ft=head2;
        }
        else{
            ft->next=head2;
            ft=head2;
        }
        head2=head2->next;
     }
    }
     if(head1!=NULL){
        ft->next=head1;
     }
     if(head2!=NULL){
        ft->next=head2;
     }
     return fh;
}
Node *mergesort(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *h1=head;
    Node *mid=midpoint(head);
    Node *h2=mid->next;
    mid->next=NULL;
    h1=mergesort(h1);
    h2=mergesort(h2);
    Node *final=merge(h1,h2);
    return final;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main(){
    Node *head=takeinput();
    head=mergesort(head);
    print(head);
}
