#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void deleteNode(Node** head_ref){
    Node* temp = *head_ref;
    (*head_ref) = temp -> next;
    delete temp;
}

void deletePos(Node* head, int pos){
    Node* temp = head;

    for(int i = 1; i < pos-1; i++){
        temp = temp -> next;
    }

    Node* garbage = temp -> next;
    temp -> next = garbage -> next;
    delete garbage;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = fourth;

    fourth -> data = 4;
    fourth -> next = NULL;

    // deleteNode(&head);
    deletePos(head, 4);
    printList(head);
}