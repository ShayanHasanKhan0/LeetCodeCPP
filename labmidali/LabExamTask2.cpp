#include<iostream>

using namespace std;

void display_path(int arr[][3],int n,int count){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	cout<<"Count = "<<count<<endl;	
}

int count_path(int count){
	
	count=count+1;
}

bool is_safe(int arr[][3],int x,int y){
	
	if(x>=0 && x<3 && y>=0 && y<3 && arr[x][y]==1)	
			return true;
			
	return false;		
}



bool solve_grid(int arr[][3],int x,int y,int n){
	
	int count=0;
	if(x==n-1 && y==n-1 && arr[x][y]==1){
		count++;
		display_path(arr,3,count);
		return true;
	}
	
	if(is_safe(arr,x,y)){
			
			
		count++;
		
		if(solve_grid(arr,x+1,y,n))
			return true;
			
		if(solve_grid(arr,x,y+1,n))	
			return true;

		count--;
		return false;
	}
	
	return false;	
}


int main(){
	
	int arr[3][3]={{1,1,1},
				   {1,0,1},
				   {1,1,1}};

	int count;

	solve_grid(arr,0,0,3);
	solve_grid(arr,0,0,3);
	
}
