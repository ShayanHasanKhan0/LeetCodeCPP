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

int main() {
    NODE car;
    NODE* ptr=car;
    cout<<ptr;
    return 0;
}