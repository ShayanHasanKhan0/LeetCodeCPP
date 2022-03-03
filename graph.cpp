#include<iostream>
#include<queue>
#include<stack>
#include<list>

using namespace std;

class graph{
	int size;
	list<int> *adjmatrix;
	
	public:
		graph(int size){
			this->size=size;
			adjmatrix = new list<int>[size]; 
		}
		
		add_node(int u,int v){
			adjmatrix[u].push_back(v);
		}
		
	void BFS(int x){
		queue<int> q;
		bool *visited = new bool[size];
        // initizlise pointer array visited as all false
		for(int i=0;i<size;i++){
			visited[i] = false;
		}
		// starting noed push and then visited true
		q.push(x);
		visited[x]= true;
		// list<int> :: iterator i;
		list<int> :: iterator i;
	while(!q.empty()){	
        //until empty while loop temp front then pop print loop for adjecent if not visites then push and visit
        int s = q.front();
        q.pop();
        cout<<s<<" ";
        
            
            for(i = adjmatrix[s].begin(); i!= adjmatrix[s].end() ; i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    q.push(*i);
                }
            }
    }
}	
			
	void DFS(int x){
		stack<int> s;
		bool *visited2 = new bool[size];
		for(int i=0;i<size;i++){
			visited2[i] = false;
		}
		
		s.push(x);
		visited2[x]= true;
		
		list<int> :: iterator i;
	while(!s.empty()){
	
	int e = s.top();
	s.pop();
	cout<<e<<" ";
	
		
		for(i = adjmatrix[e].begin(); i!= adjmatrix[e].end() ; i++){
			if(!visited2[*i]){
				visited2[*i] = true;
				s.push(*i);
			}
		}
    }
}
		
};

int main(){
	graph g(4);
	
	
	g.add_node(0,1);
	g.add_node(1,2);
	g.add_node(0,2);
	g.add_node(2,0);
	g.add_node(3,3);
	g.add_node(2,3);
	
	
	cout << "Following is Breadth First Traversal "<< "(starting from vertex 2) \n";
    g.BFS(2);
    
	cout <<endl<< "Following is Depth First Traversal "<< "(starting from vertex 2) \n";
    g.DFS(2);
	return 0;
}