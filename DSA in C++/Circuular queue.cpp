#include<iostream>
#define MAX 5
using namespace std;
class friendqueue{
int rear;
int front;
char arr[MAX];
public:
friendqueue(){
front=-1;
rear=-1;
}
void enqueue(int x){
if((front==0 && rear==MAX-1)||front==rear+1){
cout<<"\nQueue is Full:: ";
   return;
}
if(front==-1){
	front=0;
	rear=0;
}
else{
if(rear=MAX-1){
	rear=0;
}
else{
	rear++;
}
arr[rear]=x;
}
}
int dequeue(){
if(front==-1){
cout<<"\nQueue is empty ";
}
else{

int temp=arr[front];
if (front == rear) {
   front = -1;
   rear = -1;
}
else{
   if (front == MAX- 1)
   front = 0;
   else
   front = front + 1;
}
return temp;
}
}

void display(){
int i;
for(i=front;i!=rear;i=(i+1)%MAX)
{
cout<<"\n i is "<<i<<endl;
cout<<"\nThe Displayed Element is "<<arr[i]<<" index is "<<front<<endl;
}
cout<<"\ni is "<<i<<endl;
cout<<"\nThe Displayed Element is "<<arr[i]<<" index is "<<front<<endl;}
};
int main(){
friendqueue q;
q.enqueue('s');
q.enqueue('a');
q.enqueue('m');
q.enqueue('i');
q.enqueue('j');

q.display();

q.dequeue();
q.dequeue();
q.dequeue();
q.enqueue('a');
q.enqueue('b');

q.display();
return 0;
}

