#include<bits/stdc++.h>
using namespace std;
class Reverse
{
public:
    struct Node
    {
        int val;
        Node *next;
        Node() : val(0), next(nullptr) {}
        Node(int x) : val(x), next(nullptr) {}
        Node(int x, Node *next) : val(x), next(next) {}
    };

    Node* head = nullptr;

    void insertLL(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr){
            head = newNode;
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = newNode;
    }

    void createLL(){
        int n;
        cout<<"Enter number of nodes: ";
        cin>>n;
        cout<<"\nEnter values: ";
        for(int i=0;i<n;i++){
            int data;
            cin>>data;
            insertLL(data);
        }
    }

    void displayLL(){
        if(head==nullptr){
            cout<<"Linked List is empty";
            return;
        }
        Node *cur=head;
        while(cur->next!=nullptr){
            cout<<cur->val<<"->";
            cur=cur->next;
        }
        cout<<cur->val;
    }

    void reverseLL()
    {
        if(head==nullptr)
            return;
        Node* back=nullptr, *cur=head, *front;
        while(cur!=nullptr)
        {
            front=cur->next;
            cur->next=back;
            back=cur;
            cur=front;
        }
        head=back;
    }
};
int main(){
    Reverse rl;
    rl.createLL();
    cout<<"\n\nThe linked list is:\n";
    rl.displayLL();
    rl.reverseLL();
    cout<<"\n\nThe reversed linked list is:\n";
    rl.displayLL();
}
