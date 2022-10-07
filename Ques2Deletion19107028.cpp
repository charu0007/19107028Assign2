// //19107028 - CHARU MODI

// b) Create a doubly linked list. Perform Deletion of an element (given by the user at run time)

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev; 
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
 


//DELETION OF NODE FUNCTION
void deleteNode(Node *head, int data){

    if(head == NULL){
        return;
    }
    if(head->data == data){
        Node *temp = head->prev;
        temp->next = head->next;
        if(head->next)
        { 
            head->next->prev = temp;
        }
        return;
    }
    deleteNode(head->next, data);

}

Node *insert(){

    Node* prev = NULL;
    Node* head = NULL;
  
    int data;
    cin>>data;
    while(data!= -1){

        Node * nn = new Node(data);
        if(head == NULL){
            nn->prev = NULL;
            nn->next = NULL;
            head = nn;
            prev = nn;
        }
        else{
            prev->next = nn; 
            nn->prev = prev;
            prev = nn;
        }
        
        cin>>data;

    }
    return head;

}


void printNodes(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
 

int main()
{

    cout<<"Please enter the linked list";
    
    Node* head = insert();
    cout<<"Enter the node for deletion";
    int data;
    cin>>data; 
    if(head!=NULL && head->data==data) head=head->next;
    else deleteNode(head, data);

    cout << "New Linked list ";
    printNodes(head);
 
    return 0;
}

