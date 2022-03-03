#include <iostream>

using namespace std;

class NODE{
	public:
	int data;
	NODE* next;
	
	NODE(int val) {
		data =val;
		next = NULL;
	}
};

class singlylinkedlist {

    NODE* head;

    public:
    
    singlylinkedlist() {
        head = NULL;
    }
    // insertAtTail
    void insertAtTail(int val) {
        
        NODE* newNode = new NODE(val);
        
        if(head==NULL) {
            head=newNode;
            return;
        }

        NODE* temp = head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
         
        temp->next=newNode;
    }
    // insertAtHead(notneccessary)
    // deleteAtHead
    void deleteAtHead() {
        NODE* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    // delete
    void deletion(int key) {
        NODE* temp = head;

        while (temp->next->data!=key){
            temp = temp->next;
        }
        NODE* toDelete = temp->next;
        temp->next=temp->next->next;
        delete toDelete;

    }
    // search
    void search(int key) {
        NODE* temp=head;
        while (temp->next!=NULL) {
            temp = temp->next;
            if (temp->data==key) {
                cout<<"value found";
                return;
            }
        }
        cout<<"cannot find value";
    }
    void display() {
		NODE* temp = head;
        while(temp->next!=NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data;
    }
    // reversing a linked list (itertive method)
    void reverse() {
        NODE* prevptr=NULL;
        NODE* currptr=head;
        NODE* nextptr;

        while(currptr!=NULL) {
            nextptr=currptr->next;
            // changing link
            currptr->next = prevptr;
            
            // traverse
            prevptr=currptr;		
            currptr=nextptr;
        }
        // prevptr is our new head
        head = prevptr;
    }

};

// reversing a linked list (itertive method)
NODE* reverseRecursive(NODE* head) {
    // basecase
    if(head->next==NULL) {
        return head;
    }

    NODE* newHead=reverseRecursive(head->next);

    head->next->next=head;
    head->next=NULL;

    return newHead;
}
void display1(NODE* head) {
		
	while(head->next!=NULL) {
		cout << head->data << "->";
		head = head->next;
	}
	cout << head->data;
}
int main() {
    singlylinkedlist list1;
    
    list1.insertAtTail(6);
	list1.insertAtTail(7);
	list1.insertAtTail(8);
	list1.insertAtTail(9);
	list1.insertAtTail(10);
	list1.insertAtTail(11);
    list1.insertAtTail(12);

	list1.deletion(11);

	list1.display();
    
	list1.reverse();
    cout<<endl;
    list1.display();
    cout<<endl;

	list1.search(11);

    return 0;
}