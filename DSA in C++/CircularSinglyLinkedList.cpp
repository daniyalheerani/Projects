#include <iostream>
#include <string>
using namespace std;

struct node
{
	string numberPlate;
	node *next;
};

class circularParkingLot
{
	private:
		node *head;
		node *tail;
		int numberOfCars;
		
	public:
		
		circularParkingLot()
		{
			head = tail = NULL;
			numberOfCars = 0;
		}
		
		// a) Write a createList() function which creates 8 nodes of circular linked list.
		void createList()
		{
			head = new node;
			head->next = NULL;
			head->numberPlate = "NA";
			node *temp = head;
			for(int i = 1; i < 8; i++)
			{
				node *newNode = new node;
				newNode->next = NULL;
				newNode->numberPlate = "NA";
				temp->next = newNode;
				temp = newNode;
			}
			tail = temp;
			tail->next = head;
			numberOfCars = 8;
		}

		// b) Write a method to insert a new car in the list at the intermediate position.
		void insertAtPosition(int position, string numPlate)
		{
			if(position > 1 && position < numberOfCars)
			{
				node* temp = head;
				for(int i = 1; i < position-1; i++)
				{
					temp = temp->next;
				}
				node *newNode = new node;
				newNode->next = temp->next;
				newNode->numberPlate = numPlate;
				temp->next = newNode;
				numberOfCars++;
			}
			else
			{
				cout << "Invalid position\n";  
			}
		}

		// c) Write a method to delete data of a specific car when it leaves the parking lot.

		void deleteSpecificCar(string numPlate)
		{
			// uses the function e) isCarInside
			isCarInside(numPlate, true);
			
		}

		// d) Write a method to Check if the parking lot is empty

		bool isEmpty()
		{
			if(head == NULL)
			{
				cout << "Parking Lot is empty\n";
				return true;
			}
			return false;
		}

		// e) Write a method to check that a particular car is still parked in parking lot or not.

		bool isCarInside(string numPlate, bool remove = false)
		{
			if(!isEmpty())
			{
				if(head->numberPlate == numPlate)
				{
					if(remove)
					{
						deleteFromBegining();
						cout << "Car Removed Successfully\n";
					}
					return true;
				}
				else
				{
					node *temp = head;
					while(true)
					{
						//look for numberplate in the next node
						if(temp->next->numberPlate == numPlate)
						{
							if(remove)
							{
								node *toDelete = temp->next;
								if(temp->next == tail)
								{
									tail = temp;
								}
								temp->next = toDelete->next;
								delete toDelete;
								cout << "Car Removed Successfully\n";
								numberOfCars--;
							}
							return true;
						}
						temp = temp->next;
						if(temp == head)
						{
							cout << "Car not found\n";
							return false;
						}
					}
				}
			}
			return false;
		}

		// f) You need to keep a count of the number of cars parked in the parking lot at any time.

		int getNumberOfCars() {return numberOfCars;}

		// g) Write a method to insert a new car in the list at the end of the parking lot.

		void insertAtEnd(string numPlate)
		{
			node *newNode = new node;
			newNode->numberPlate = numPlate;
			if(head == NULL)
			{
				head = newNode;
			}
			else
			{
				tail->next = newNode;
			}
			newNode->next = head;
			tail = newNode;
			numberOfCars++;
		}

		// h) Write a method to delete the first car from the list.

		void deleteFromBegining()
		{
			if(isEmpty())
			{
				return;
			}
			else if(numberOfCars == 1)
			{
				delete head;
				head = tail = NULL;
			}
			else 
			{
				node* temp = head;
				head = head->next;
				delete temp;
				tail->next = head;
			}
			numberOfCars--;
			
		}

		void displayFromHeadToTail()
		{
			node * temp=head;
			cout << "[";
			for(int i = 0; i < numberOfCars; i++)
			{
				cout << temp->numberPlate <<  ", ";
				temp = temp->next;
			}
			cout << "\b\b]\n";
		}

		~circularParkingLot()
		{
			node* temp = head;
			node* curr = head;
			for(int i = 0; i < numberOfCars-1; i++)
			{
				temp= temp->next;
				delete curr;
				curr = temp;
			}
			if(numberOfCars != 0)
			{
				delete temp;
			}
		}


		
};


int main()
{
	circularParkingLot test;
	test.createList();
	test.insertAtEnd("ABC1234");
	test.insertAtPosition(2, "CDVB16G");
	test.insertAtPosition(2, "AKJ9786");
	test.displayFromHeadToTail();
	test.deleteFromBegining();
	test.displayFromHeadToTail();
	test.deleteFromBegining();
	test.displayFromHeadToTail();
	cout << "Search for ABC1234: " << endl;
	if(test.isCarInside("ABC1234"))
	{
		cout << "Yes, ABC1234 is inside the parking lot\n";
	}
	else
	{
		cout << "No, ABC1234 is not inside the Parking Lot\n";
	}
	test.deleteSpecificCar("ABC1234");
	test.displayFromHeadToTail();

}
