#include <iostream>

using namespace std;

class stack {
  int* arr;
  int top;
  int size;

  public:
    stack(int n) {
        arr = new int[n];
        top=-1;
        size=n;
    }
    void push(int x) {
        if (top==size-1) {
            cout<< "Stack overflow!";
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop() {
        if(top==-1) {
            cout<<"Stack underflow!"<<endl;
            return;
        }
        top--;
    }

    int Top() {
        if (top==-1) {
            cout<<"no element in stack"<<endl;
            return -1;
        }
        return arr[top]; 
    }

    bool empty() {
        return top==-1;
    }

};

int main() {
    stack stack1(6);

    stack1.pop();
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);

    cout<<stack1.Top()<<endl;
    stack1.push(6);
    stack1.push(7);
    return 0;
}