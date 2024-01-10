#include<iostream>
#include<conio.h>
using namespace std;
const int MAX=20;
class stack
{
	private:
	  int st[MAX];
      int top;
    public:
	   stack();
       void push(int x);
       int pop();
       void display();
};
stack::stack()
{
	top=- 1;
}
void stack::push(int x)
{
if (top== MAX- 1)
{
	cout<<"\n stack is full!";
	return;
}
else
{
	top++ ;
	st[top] =x;
}
}
int stack::pop()
{
	if (top==-1)
{
	cout << "\n stack is empty";
	return NULL;
}
else
{
	int item = st[top];
	top--;
	return item;

}
}
void stack::display()
{
	int temp = top;
	while (temp!=- 1)
	{
		cout << "\n" << st[temp];
		temp=temp-1;
		//cout<<"temp is "<<temp;
		
	}
	
	
}
int main()
{
	stack s;
	int n;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.display();
	n=s.pop();
	cout <<"\n Popped item:"<< n ;
	n=s.pop();
	cout <<"\n Popped item:"<< n ;
	s.display();
	getch();
	return 0;
}
