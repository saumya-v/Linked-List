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
int main(){
    Node n1(6);
    Node* head=&n1;
    Node n2(5);
    n1.next=&n2;
    cout<<n1.data<<" "<<n2.data<<endl;
}

