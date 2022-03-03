#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node *head;
   
    LinkedList(){
        head = NULL;
    }

     void addNodeToEnd(int val){
         Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node *ptr = head;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }

    bool isEmpty(){
        return (head == NULL);
    }

    void merge(LinkedList list1, LinkedList list2){
        if(list1.isEmpty() && list2.isEmpty())
            return;

        if(list1.isEmpty()){
            Node *ptr = list2.head;
            while(ptr != NULL){
                this->addNodeToEnd(ptr->data);
                ptr = ptr->next;
            }
            return;
        }
         if(list2.isEmpty()){
            Node *ptr = list1.head;
            while(ptr != NULL){
                this->addNodeToEnd(ptr->data);
                ptr = ptr->next;
            }
            return;
        }

        Node *ptr1 = list1.head;
        Node *ptr2 = list2.head;
        while(ptr1 != NULL && ptr2 != NULL){
            this->addNodeToEnd(ptr1->data);
            this->addNodeToEnd(ptr2->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // add remaining list
        if(ptr1 == NULL){
            while(ptr1 != NULL){
                this->addNodeToEnd(ptr2->data);
                ptr2 = ptr2->next;
            }
        }
        // add remaining list
        if(ptr2 == NULL){
            while(ptr1 != NULL){
                this->addNodeToEnd(ptr1->data);
                ptr1 = ptr1->next;
            }
        }
    }

    void display(){
        Node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList list1;
    LinkedList list2;
    LinkedList list3;

    for(int i=1; i<=8; i++)
        list1.addNodeToEnd(i);
    for(int i=9; i<=12; i++)
        list2.addNodeToEnd(i);
    
    list3.merge(list1, list2);
    list3.display();
    return 0;
}