#include <iostream>

using namespace std;
void bubble(int arr[],int size){
	int flag=1;
	if(flag==1){
		for(int i=0;i<size;i++){
			for(int j=0;j<size-1;j++){
				if(arr[j]>arr[j+1]){
					int temp;
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
	}
	for(int i=0;i<size;i++){
		cout<<"array elements are: "<<arr[i]<<endl;
	}

}
int main(){
	int size;
	cout<<"Enter array size."<<endl;
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++){
		cout<<"Enter array element: "<<i<<endl;
		cin>>arr[i];
	}
	bubble(arr,size);
	
}
