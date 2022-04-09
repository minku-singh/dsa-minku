#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
}

int length(Node* head){
    Node* temp = head;
    int ans;
    while(temp != NULL){
        ans++;
        temp = temp -> next;
    }
    return ans;
}

int lengthRecursive(Node* head){
    if(head == NULL){
        return 0;
    }

    return 1+lengthRecursive(head -> next);
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

    printList(head);
    cout << length(head);
    cout << lengthRecursive(head);
}