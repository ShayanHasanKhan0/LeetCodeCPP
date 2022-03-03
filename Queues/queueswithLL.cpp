#include <iostream>

using namespace std;

class NODE {
    public:
    int data;
    NODE* next;
    NODE(int val) {
        data = val;
        next=NULL;
    }
}; 

class Queue {
    NODE* front;
    NODE* back;

    public:
    Queue(int x) {
        front=NULL;
        back=NULL;
    }
    void enqueue(int x) {
        NODE* newNode=new NODE(x);

        if(front==NULL) {
            front=newNode;
            back=newNode;
        }

        back->next=newNode;
        back=newNode;
    }

    void dequeue() {

        if (front==NULL){
            cout<<"stack is empty"<<endl;
            return;
        }
        
        NODE* toDelete=front;

        front=front->next;

        delete toDelete;
    }

    int peek() {
        if (front==NULL){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return (front->data);
    }

    bool isEmpty() {
        return (front==NULL);
    }


};


int main() {
    Queue queue1(5);

    cout<<queue1.peek()<<endl;
    queue1.enqueue(4);
    cout<<queue1.peek()<<endl;
    queue1.enqueue(2);
    cout<<queue1.peek()<<endl;
    queue1.enqueue(3);
    cout<<queue1.peek()<<endl;
    queue1.enqueue(4);
    cout<<queue1.peek()<<endl;
    queue1.enqueue(5);
    cout<<queue1.peek()<<endl;
    queue1.enqueue(6);
    cout<<queue1.peek()<<endl;
    
    queue1.dequeue();

    queue1.enqueue(6);
}