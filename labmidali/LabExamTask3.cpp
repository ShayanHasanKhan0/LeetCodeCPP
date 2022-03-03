#include<iostream>

using namespace std;

class Node{
	
	friend class list;
	Node* next;
	int coeficient;
	char base;
	int exponent;
	public: 
		Node(int coeficient,char base,int exponent){
		this->next=NULL;
		this->coeficient=coeficient;
		this->base=base;
		this->exponent=exponent;
			
		}
};

class list{
	Node* head;
	public: 
		list(){
			head=NULL;
		}
	
	void insert_at_head(int coeficient,char base,int exponent){
		Node* new_node=new Node(coeficient,base,exponent);
		if(head==0)
			head=new_node;
		else{
			new_node->next=head;
			head=new_node;
		}
	}
	
	void print(){
		Node* curr=head;
		while(curr!=0){
			cout<<curr->coeficient;
			cout<<curr->base;
			cout<<curr->exponent;
			curr=curr->next;
		}
		cout<<endl;
	}
	
	void add_list(list& L1,list& L2){	
	
	Node* curr=L1.head;
	Node* temp=L2.head;
	list L3;
		while(curr!=0){
			
			while(temp!=0){
			
			if(curr->exponent==temp->exponent && curr->base==temp->base){
				
				L3.insert_at_head((curr->coeficient)+(temp->coeficient), curr->base, curr->exponent);
									
			}
			else{
				L3.insert_at_head((curr->coeficient), curr->base, curr->exponent);				
			}
			temp=temp->next;					
			}
			curr=curr->next;
		}
		L3.print();
	}
	
};


int main(){
	list L1;
	list L2;
	L1.insert_at_head(-2,'X',8);
	L2.insert_at_head(+3,'X',8);
	L1.print();
	L1.add_list( L1,L2);
}
