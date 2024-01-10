#include <iostream>
#define Max 20
using namespace std;

void s(int arr[],int size){
	int lb=0,ub=size-1;
	for(int i=lb;i<=ub;i++){
		for(int j=i+1;j<=ub;j++){
			
			if(arr[i]>arr[j]){
		
			int temp;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
			
			}
		}
	}
}

int main() {
	int size;
	cout<<"Enter size of the array."<<endl;
	cin>>size;
	int arr[Max];
	cout<<"Enter elements of array."<<endl;
	for(int i=0;i<size;i++){
		cout<<"Enter element "<<i;
		cin>>arr[i];
	}
	
	s(arr,size);
	for(int i=0;i<size;i++){
		cout<<"array is: "<<arr[i]<<endl;
	}
	return 0;
}
