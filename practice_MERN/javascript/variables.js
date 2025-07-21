//Var
var age=22;
var num1=10;
var num2=20;

console.log(age);

age="twenty-two";
console.log(age);

//var can change the behaviour at runtime

//Naming conventions
//firstName  (prefer camelCase)
//first_name (snake_case)
//firstname
//FirstName (ClassName)

let number1=10;
let number2=20;
if (true){
    let number1=30; //block scope
    console.log(number1); //30
}
console.log(number1); //10


//var->global scope
//re-assignable
//global access to the variable

//let ->local scope
//re-assignable
//block access to the variable

//const->local scope
//const ->constant value, cannot be reassigned
//block access to the variable