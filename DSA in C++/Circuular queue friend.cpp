#include <iostream>
#define MAX 5
using namespace std;

class queue{
	string q[MAX];
	int front, rear;
	public:
	queue(){
		front=-1;
		rear=-1;
	}
	void enqueue(string x){
		if((front==0 &&rear==MAX-1)||(front==rear+1)){
			cout<<"Queue is full"<<endl;
		}
		else{
			if(front==-1)
				front=0;
			rear = (rear+1)%MAX;
			q[rear]=x;
		}
	}
	string dequeue(){
		if(front==-1){
			cout<<"Queue is empty."<<endl;
		}
		else{
			string x=q[front];
//			front++;
			if(front==rear){
				front=-1;
				rear=-1;
			}
			else{
				front = (front + 1) % MAX;
			}
			return x;
		}
	}
	void display(){
		int temp=front;
		for(int i = front; i != rear; i = (i + 1) % MAX){
//			cout<<que[temp];
			cout<<q[i]<<endl;
//		 	temp++;
		}
	}
};

int main(int argc, char** argv) {
	
	queue Q;
	Q.enqueue("X");
	Q.enqueue("Y");
	Q.enqueue("Z");
	Q.enqueue("S");
	Q.enqueue("M");
	Q.display();
	
	cout<<"AFTER REMOVED."<<endl;
	Q.dequeue();
	Q.dequeue();
	Q.display();
	
	cout<<"AGAIN INSERTION."<<endl;
	Q.enqueue("a");
	Q.enqueue("b");
	Q.display();

	
	return 0;
}
