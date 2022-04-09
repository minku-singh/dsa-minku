#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = *head_ref;
    (*head_ref )= newNode;
}

void insertAfter(Node* prev, int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = prev -> next;
    prev -> next = newNode;
}

void append(Node* head, int data){
    Node* temp = head;
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
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

    head = new Node();
    second = new Node();
    third = new Node();

    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = NULL;
    
    push(&head, 100);
    insertAfter(second, 3000);
    append(head, 232);
    printList(head);
}