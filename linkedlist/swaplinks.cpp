#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void swapNode(Node** head_ref, int x, int y){
    
    Node* px = NULL;
    Node* cx = *head_ref;
    Node* py = NULL;
    Node* cy = *head_ref;

    while(cx && cx -> data != x){
        px = cx;
        cx = cx -> next;
    }

    while(cy && cy -> data != y){
        py = cy;
        cy = cy -> next;
    }

    if(cx == py){
        return;
    }

    if(cx == NULL || cy == NULL){
        return;
    }

    if(px != NULL){
        px -> next = cy;
    }else{
        *head_ref = cy;
    }

    if(py != NULL){
        py -> next = cx;
    }else{
        *head_ref = cx;
    }

    Node* temp = cy -> next;
    cy -> next = cx -> next;
    cx -> next = temp;

}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;
    Node* sixth = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();

    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = fourth;

    fourth -> data = 4;
    fourth -> next = fifth;

    fifth -> data = 5;
    fifth -> next = sixth;

    sixth -> data = 6;
    sixth -> next = NULL;

    printList(head);
    swapNode(&head, 2,5);
    printList(head);
}