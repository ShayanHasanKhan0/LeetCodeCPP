#include <iostream>

using namespace std;


class NODE {
    public:
    int data;
    NODE* next;

    NODE(int val) {
        data = val;
        next = NULL;
    }
};


class linkedlist {

    public:

    NODE* head;

    linkedlist() {
        head=NULL;
    }

    void insertAtTail(int val) {
        NODE* newNode = new NODE(val);
        
        if (head==NULL) {
            head=newNode;
            return;
        }
        
        NODE* temp=head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    
    bool isEmpty() {
        return (head==NULL);
    }

    void merge(linkedlist list1, linkedlist list2) {
        // if both lists are empty
        if(list1.isEmpty() && list2.isEmpty()) {
            return;
        }
        // if list 1 is empty
        if(list1.isEmpty()) {
            NODE* ptr = list2.head;
            while (ptr!=NULL) {
                this->insertAtTail(ptr->data);
                ptr=ptr->next;
            } 
            return;
        }
        // if list 2 is empty
        if(list2.isEmpty()) {
            NODE* ptr = list1.head;
            while (ptr!=NULL) {
                this->insertAtTail(ptr->data);
                ptr=ptr->next;
            }
            return;
        }
        // if both have elements
        NODE* ptr1 = list1.head;
        NODE* ptr2 = list2.head;

        while(ptr1 != NULL && ptr2 != NULL){
            this->insertAtTail(ptr1->data);
            this->insertAtTail(ptr2->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        // add remaining list
        if(ptr1 == NULL){
            while(ptr1 != NULL){
                this->insertAtTail(ptr2->data);
                ptr2 = ptr2->next;
            }
        }
        // add remaining list
        if(ptr2 == NULL){
            while(ptr1 != NULL){
                this->insertAtTail(ptr1->data);
                ptr1 = ptr1->next;
            }
        }
    }
    void display(){
        NODE *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main(){
    linkedlist list1;
    linkedlist list2;
    linkedlist list3;

    for(int i=1; i<=8; i++)
        list1.insertAtTail(i);
    for(int i=9; i<=12; i++)
        list2.insertAtTail(i);

    list3.merge(list1, list2);
    list3.display();
    return 0;
}