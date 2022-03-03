#include <iostream>

using namespace std;

class NODE {
    int data;
    NODE* next;
    NODE* prev;

    NODE(int val) {
        data=val;
        next=NULL;
        prev=NULL;
    }
}

class doublylinkedlist{

    NODE* head;

    doublylinkedlist() {
        head = NULL;    
    }

    void insertAtTail(int val) {
        NODE* newNode = new NODE(val);

        if(head==NULL) {
            head = newNode;
            return;
        }

        NODE* temp = head;
        while (temp->next!=NULL) {
            temp = temp->;
        }

        newNode->prev = temp;
        temp->next = newNode;
        
    }
}


void main() {


}
