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


void insertAtTail(NODE* &head, int val) {
	NODE* newNode = new NODE(val);

	if(head==NULL) {
		head=newNode;
		return;
	}

	NODE* temp = head;
	
	while(temp->next!=NULL) {
		temp = temp->next;
	}
	temp->next = newNode;

}

void insertAtHead(NODE* &head, int val) {

	NODE* newNode = new NODE(val);

	if(head==NULL) {
		head = newNode;
		return;
	}

	newNode->next = head;
	head = newNode;

}

void display(NODE* head) {
		
	while(head->next!=NULL) {
		cout << head->data << "->";
		head = head->next;
	}
	cout << head->data;
}


bool search(NODE* temp,int key) {
	while(temp->next!=NULL) {
		if(temp->data==key) {
			return true;
		}
		temp=temp->next;
	}
	// for last element
	if(temp->data==key) {
		return true;
	}
	return false;
}



// cornercase deleteathead
void deleteAtHead(NODE* &head) {
	NODE* toDelete = head;
	head=head->next;
	delete toDelete;
}

void deletion(NODE* &head, int key) {
	// deletion is special case
	NODE* temp = head;

	while (temp->next->data!=key) {
		temp=temp->next;
	}
	NODE* toDelete=temp->next;
	temp->next=temp->next->next;
	delete toDelete;
}

// reversing a linked list (itertive method)
NODE* reverse(NODE* &head) {
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
	// prevptr is our new head so return new head
	return prevptr;
}

// reversing a linked list (itertive method)
NODE* reverseRecursive(NODE* &head) {
	// basecase
	if(head->next==NULL) {
		return head;
	}

	NODE* newHead=reverseRecursive(head->next);

	head->next->next=head;
	head->next=NULL;

	return newHead;
}

int main() {
	NODE* head = new NODE(4);
	
	insertAtTail(head,6);
	insertAtTail(head,7);
	insertAtTail(head,8);
	insertAtTail(head,9);
	insertAtTail(head,10);
	insertAtTail(head,11);

	insertAtHead(head,3);


	deletion(head,10);

	display(head);
	NODE* reversedLLhead = reverse(head);
	cout<<endl;
	display(reversedLLhead);

	NODE* againreversedLLhead = reverseRecursive(reversedLLhead);
	cout<<endl;
	display(againreversedLLhead);

	cout <<endl<< search(head, 11);
	return 0;
}
