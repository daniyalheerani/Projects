#include<string.h>
#include<iostream>
using namespace std;
char postfix[50];
char infix[50];
char opstack[50]; /* operator stack */
int i=0, j=0, top = -1;
int lesspriority(char op, char op_at_stack)
{
    int k;
    int pv1; /* priority value of op */
    int pv2; /* priority value of op_at_stack */
    char operators[] = {'+', '-', '*', '/', '%', '^', '(' };
    int priority_value[] = {0,0,1,1,2,3,4};
    if(op_at_stack == '(' )
        return 0;
        for(k = 0; k < 6; k ++)
        {
            if(op == operators[k])
                pv1 = priority_value[k];
        }
        for(k = 0; k < 6; k ++)
        {
            if(op_at_stack == operators[k]) 
                pv2 = priority_value[k];
        }
        if(pv1 < pv2)
            return 1;
        else
            return 0;
}
void push(char op) /* op - operator */
{
    if(top == -1)
    {
        top++;
        opstack[top] = op;
        
    }
else
{
    if(op != '(' )
    {
        while(lesspriority(op, opstack[top]) == 1 && top >-1)
        {
            postfix[j] = opstack[top];
            j++;
            top--;
        }
    }
    top++;
    opstack[top] = op; /* pushing onto stack */
    
}
}
pop()
{
    while(opstack[top--] != '(' ) /* pop until '(' comes */
    {
        postfix[j] = opstack[top];
        j++;
    }
}
int main()
{
    char ch;
    printf("\n Enter Infix Expression : ");
    cin>>infix;
    while( (ch=infix[i++]) != '\0')
    {
        switch(ch)
        {
            case ' ' : break;
            case '(' :
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' :
            case '%' :
            push(ch); /* check priority and push */
            break;
            case ')' :
            pop();
            break;
            default :
            postfix[j] = ch;
            //cout<<postfix;
            j++;
}
}
    while(top >= -1)
    {
        postfix[j] = opstack[top--];
        cout<<postfix;
        //printf("now in while");
        j++;
    }
    postfix[j] = '\0';
    cout<<"\n Infix Expression : "<< infix;
    cout<<"\n Postfix Expression :  "<<postfix;
    return 0;
}
