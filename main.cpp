// Copyright @2019
// Shivani Bajaj

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(int element, Node** head, int *listCount) {
    Node *tempLoc = new Node();
    tempLoc->data = element;
    tempLoc->next = *head;
    *head = tempLoc;
    *listCount = *listCount + 1;
}

void insertAtPosition(int position, int element, Node** head, int *listCount) {
    Node *newNode = new Node();
    newNode->data = element;
    
    if ((position == 1) || (head == NULL)) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    int tempPos = 1;
    Node *ptr;
    ptr = *head;
    while (tempPos != position - 1) {
        ptr = ptr->next;
        tempPos += 1;
    } 
    newNode->next = ptr->next;
    ptr->next = newNode;
    *listCount += 1;
}

void deleteAtPosition(int position, Node** head, int *listCount) {
    Node *ptr, *ptr1;
    ptr = *head;
    ptr1 = NULL;
    
    if (position == 1) {
        *head = ptr->next;
        free(ptr);
        return;
    }
    
    int tempPos = 1;
    
    while (tempPos != position) {
        ptr1 = ptr;
        ptr = ptr->next;
        tempPos += 1;
    }
    ptr1->next = ptr->next;
    free(ptr);
}

void reverse(Node **head) {
    Node *pre, *current, *next;
    current = *head;
    pre = NULL;
    next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    *head = pre;
}

void reverseByRecursion(Node* p, Node **head) {
    if (p->next == NULL) {
        *head = p;
        return;
    }
    reverseByRecursion(p->next, head);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

void printList(Node** head) {
    Node *ptr = *head;
    cout<<"List is\n";
    while (ptr != NULL) {
        cout<<ptr->data<<"\n";
        ptr = ptr->next;
    }
}

int main()
{
    Node *head = NULL;
    int n, listCount = 0, pos;
    cout<<"Enter number of elements";
    cin>>n;
    
    for(int i=0; i<n; i++) {
        int ele;
        cout<<"Enter element";
        cin>>ele;
        insertAtBeginning(ele, &head, &listCount);
    }
    
    printList(&head);
    
    
    // Un-comment to insert element at specific position
    // cout<<"Enter position to insert at";
    // cin>>pos;
    // if (pos <= listCount + 1) {
    //     int ele;
    //     cout<<"Enter element";
    //     cin>>ele;
    //     insertAtPosition(pos, ele, &head, &listCount);
    //     printList(&head);
    // } else {
    //     cout<<"Invalid position to insert";
    // }
    
    // Un-comment to delete element at specific position
    // cout<<"Enter position to delete element";
    // cin>>pos;
    // if (pos <= listCount) {
    //     deleteAtPosition(pos, &head, &listCount);
    //     printList(&head);
    // } else {
    //     cout<<"Invalid position to delete";
    // }
    
    //Reverse elements by iteraion
    // reverse(&head);
    
    // Reverse elements by reverse by recurion
    reverseByRecursion(head, &head);
    
    cout<<"Reversed linked list is::";
    printList(&head);
    return 0;
}




