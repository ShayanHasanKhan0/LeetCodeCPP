#include <iostream>

using namespace std;
// This implementation has a problem that when you dequeue a full queue and then enque it still shows queue is full, we have a concept of circular queue to counter this problem

class Queue {
    int* arr;
    int front;
    int back;
    int size;

    public:
        Queue(int size) {
            arr = new int[size];
            front=-1;
            back=-1;
            this->size=size;
        }
    // add element to front of queue 
    // enqueue
    void enqueue(int x) {
        if(back==size-1) {
            cout << "queue is full!"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if (front==-1) {
            front++;
        }
    }
    // dequeue
    void dequeue() {
        if(front==-1 || front>back) {
            cout <<"Queue is empty dequeue";
            return;
        }
        front++;
    }
    // peek (returns first element)
    int peek() {
        if(front==-1 || front>back) {
            cout <<"Queue is empty";
            return -1;
        }
        
        return arr[front];
    }
    // empty
    bool isEmpty() {
        return (front==-1 || front>back);
    }
};

int main() {
    Queue queue1(5);

    cout<<queue1.peek()<<endl;
    queue1.enqueue(1);
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