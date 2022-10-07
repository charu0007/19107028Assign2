//19107028 - CHARU MODI

// a) Create a singly linked list. Perform Insertion of an element after a Specified Value
// (given by the user at run time)

#include <bits/stdc++.h>
using namespace std;

class Node{ 
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this-> next = NULL;
        }
};
// CODE FOR INPUT THE LINKED LIST
Node *takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *nextNode = new Node(data);
        if(head == NULL){
            head = nextNode;
            tail = nextNode;

        }
        else{
            tail->next = nextNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

void printLL(Node* head){
    Node* temporary = head;
    while(temporary != NULL){ // print the node till temporary is not null
        cout<<temporary->data<<" ";
        temporary = temporary->next;
    }
    cout<<endl;
}

Node* insert(Node* head, int i, int data){
    Node* newNode = new Node(data); 
    if(head==NULL){
        if(i==0){
            Node* nn = new Node(data);
            return nn;
        }
        return head;
    }
    if(i==0){
        newNode->next = head; 
        head = newNode;
        return head;
    }
    
   head->next = insert(head->next, i-1, data); // call the function
   return head;
}

int main(){
    Node* head = takeInput(); // ask LL from user
    int position;//ask user  position of node
    int data;
    cin>>position>>data;
    head = insert(head, position, data); 
    printLL(head);
}