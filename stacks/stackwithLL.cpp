#include <iostream>

using namespace std;

class NODE {
    public:
        int data;
        NODE* next;

        NODE(int val) {
            data=val;
            next=NULL;
        }
};
class stackusingLL {

    NODE* top;

    public:
    stackusingLL() {
        top=NULL;
    }
    // we call INSERT AT HEAD OF NORMAL LL as PUSH
    void push(int x) {
        NODE* newNode= new NODE(x);
        newNode->next=top;
        top = newNode;
    }
    // delete at head
    void pop() {
        if (top==NULL) {
            cout<< "stack is empty";
            return;
        }
        NODE* toDelete = top;
        top = top->next;
        delete toDelete;
    }
    // top
    int Top() {
        cout<<top->data<<endl;
        return top->data;
    }
    // display
    void display() {
        NODE* temp = top;
        while (temp->next!=NULL) {
            cout<< temp->data << "->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main() {

    stackusingLL stack1;

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    stack1.push(7);

    stack1.Top();

    stack1.pop();
    stack1.pop();

    stack1.display();


    return 0;
}

