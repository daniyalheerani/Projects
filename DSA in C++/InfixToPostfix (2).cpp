#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

string infixToPostfix(string infix);
int getPrecedence(char op);

struct node
{
	char data;
	node *next;
};


class stack
{
	private:
		node* top;
		int size;
		
	public:
		
		stack()
		{
			top = NULL;
			size = 0;
		}
		
		void push(char val)
		{
			node* newNode = (node*)malloc(sizeof(node));
			newNode->data = val;
			newNode->next = top;
			top = newNode;
			size++;
		}
		
		char pop()
		{
			if(size == 0)
			{
				cout << "Stack is empty\n";
			}
			else
			{
				node* toDelete = top;
				top = top->next;
                char temp = toDelete->data;
				free(toDelete);
                size--;
                return temp;
			}
			return '\0';
		}
		
        char peek()
        {
            if(top != NULL)
            {
                return top->data;
            }
            return '\0';
        }

        bool isEmpty()
        {
            if(top == NULL)
            {
                return true;
            }
            return false;
        }

		void display()
		{
			if(size != 0)
			{
				cout << "[";
				node* temp = top;
				for(int i = 0; i < size; i++)
				{
					cout << temp->data << ", ";
					temp = temp->next;
				}
				cout << "\b\b]\n";
			}
			
		}
		
		
};

int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "\nPOSTFIX: " << postfix << endl;

}








int getPrecedence(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }
    else if(op == '/' || op == '*')
    {
        return 2;
    }
    else
    {
        //if op is not an operator
        return -1;
    }
}

string infixToPostfix(string infix)
{

    //STEP 1 : SCAN THE REVERSED INFIX EXPRESSION FROM LEFT TO RIGHT
    ostringstream output;
    stack opStack;
    for(int i = 0; i < infix.length(); i++)
    {
        if(isdigit(infix[i]))
        {
            output << infix[i];
        }
        else if(opStack.isEmpty() || infix[i] == '(' || opStack.peek() == '(' 
        || getPrecedence(infix[i]) > getPrecedence(opStack.peek()))
        {
            opStack.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            for(char op = opStack.pop(); op != '('; op = opStack.pop())
            {
                output << op;
            }
        }
        else if (getPrecedence(opStack.peek()) > getPrecedence(infix[i]))
        {
            for(char op = opStack.peek(); getPrecedence(op) >= getPrecedence(infix[i]); op = opStack.peek())
            {
                output << op;
                opStack.pop();
            }
            opStack.push(infix[i]);

        }
        
    }

    //STEP 3 : Pop and output from the stack until empty
    while(!opStack.isEmpty())
    {
        output << opStack.pop();
    }
    
    string postfix = output.str();
    return postfix;

}