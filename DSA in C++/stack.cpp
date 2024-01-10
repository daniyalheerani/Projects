#include <iostream>
using namespace std;
#define MAX 5
class stack{
int stk[MAX];
int top;
public:
stack(){
top=-1;
}
void push(int x){
if(top==MAX-1){
cout<<"Stack is full.";
return;
}
else{
top=top+1;
stk[top]=x;
}
}
int pop(){
int x;
if(top==-1){
cout<<"Stack is Empty."<<endl;
}
else{
x=stk[top];
top--;
return x;
}
}
void peek(){
cout<<"Peek: "<<stk[top]<<endl<<endl;
}
void display(){
if(top==-1){
cout<<"Stack is Empty."<<endl;
}
else{
cout<<"Stack values: "<<endl;
int temp=top;
for(int i=temp;i>-1;i--){
cout<<stk[i]<<endl;
}
}
}
};

int main(int argc, char** argv) {

stack st;
st.push(7);
st.push(4);
st.push(10);
st.push(9);

st.push(5);
st.peek();
st.display();

int a=st.pop();
cout<<"a: "<<a<<endl;

st.display();
return 0;
}
