#include <iostream>
using namespace std;

const int MAX = 3;

/*
CODE BY AREEB SHIEKH
TESTED AND CORRECTED BY ALI AHMED
*/
class queue 
{

	private:
		int que[MAX];
		int front = -1,rear=-1;

    public:

        queue()
        {
            front = rear = -1;
        }

		void enqueue(int ele) 
        {
			if((rear+1)%MAX == front) 
            {
				cout<<"Queue is full "<<endl; 

			} 
            else 
            {
				rear=(rear+1)%MAX;
				que[rear]=ele;
				if(front==-1)
				{
					front=0;
				}
			}
		}
	
		void dequeue() 
        {
			if(front==-1 || rear==-1) 
            {
				cout<<"queue is empty "<<endl;
		    }
            else 
            {
                if(front == rear)
                {
                    front = rear = -1;
                }
				front=(front+1)%MAX;
			}
		}
		
		void display() 
        {
	 
            if(rear != -1)
            {
                for(int i=front ; i!=rear ; i=(i+1)%MAX) 
                {
                    cout<<que[i]<<" ";
                }
                cout<<que[rear]<<endl;
            }
        }
            

};

int main()
{
    //MAX is 3, 
    queue test;
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    test.display();
    test.dequeue();
    test.dequeue();
    test.enqueue(4);
    test.display();
    test.dequeue();
    test.dequeue();
    //test.dequeue();
    //test.display();

}