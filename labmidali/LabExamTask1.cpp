#include<iostream>

using namespace std;

void bidi_bubbleSort(int a[], int n){
	
	for(int i=0; i<n; i++){
		if(i%2==0){
			for(int j=0; j<n-1; j++){
				if(a[j]>a[j+1]){
					swap(a[j],a[j+1]);
				}
			}
		}
		else{
			for(int j=n; j>=0; j--){
				if(a[j]<a[j-1]){
					swap(a[j],a[j-1]);
				}
			}
		}			
	}
}


void display(int a[], int n){
	for(int i=0; i<n; i++){
			cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	
	int arr[6]={5,3,58,9,2,44};
	display(arr,6);
	bidi_bubbleSort(arr,6);
	display(arr,6);
	
}
