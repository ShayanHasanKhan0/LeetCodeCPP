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

class Stack{
    public:
    Node *head;
   
    Stack(){
        head = NULL;
    }

    void push(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    int pop(){
        int val = head->data;
        Node *ptr = head;
        head = head->next;
        delete ptr;
        return val;
    }

    bool isEmpty(){
        return (head == NULL);
    }

    void display(){
        Node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void addStacks(Stack stk1, Stack stk2){
        if(stk1.isEmpty() && stk2.isEmpty())
            return;

        if(stk1.isEmpty()){
            Node *ptr = stk2.head;
            while(ptr != NULL){
                this->push(ptr->data);
                ptr = ptr->next;
            }
        }

        if(stk2.isEmpty()){
            Node *ptr = stk1.head;
            while(ptr != NULL){
                this->push(ptr->data);
                ptr = ptr->next;
            }
        }

        while(!stk1.isEmpty() && !stk2.isEmpty()){
            bool carry = false;
            int sum = stk1.pop() + stk2.pop(); //Pop the elements at the top and add them
            if(carry == true) //If we have a carry from a previous addition, add that in
                sum++;
            if(sum > 9){    //Set carry flag and push only unit part of the sum, not the tens
                sum = sum - 10;
                carry = true;
            }
            this->push(sum);
        }

        if(stk1.isEmpty()){
            while(!stk2.isEmpty()){
                this->push(stk2.pop());
            }
        }

        if(stk2.isEmpty()){
            while(!stk1.isEmpty()){
                this->push(stk1.pop());
            }
        }
    }
};

int main(){
    Stack stk1, stk2, stk3;
    string num1, num2;
    cout << "Enter two numbers separated by a space: ";
    cin >> num1 >> num2;

    //Number string needs to be pushed in reverse order so that corresponding elements are 
    //always at the top of the stack
    for(int i=0; i<num1.length(); i++)
         stk1.push(num1[i]-'0');
    
    //Number strings are pushed to the stack char by char (the char is converted to int)
    //before pushing
    for(int i=0; i<num2.length(); i++)
       stk2.push(num2[i]-'0');
    
    stk3.addStacks(stk1, stk2);
    cout << "Sum of the two numbers: ";
    stk3.display();
    
    return 0;
}