//functions
function HelloWorld() {
    console.log("Hello, World!");
}
HelloWorld(); //calls the function

//passing arguments
function add(num1, num2) {
    return num1 + num2; //returns the sum of num1 and num2
}
add(10, 20); //calls the function with parameters 10 and 20

function multiply(num1, num2) {
    return num1 * num2; //returns the product of num1 and num2
}
let a=multiply(10, 20); //calls the function with parameters 10 and 20
console.log("Multiplication result: ",a); //prints the result of multiplication

//function can accept unlimited arguments
function addition() {
    console.log(arguments); //prints all arguments passed to the function
    return arguments; //returns the sum of num1 and num2
}
addition(10, 20, 30, 40); //calls the function with multiple parameters

function addAll() {
    let sum=0;
    for(let i=0; i<arguments.length; i++){
        console.log(arguments[i]); //prints each argument passed to the function
        sum += arguments[i]; //sums all arguments
    }
    return sum; //returns the total sum of all arguments
}
let total = addAll(10, 20, 30, 40); //calls the function with multiple parameters
console.log("Total sum: ", total); //prints the total sum of all arguments

//spread operator
function addAll2(...numb) {
    let ans=0;
    for(let i=0; i<numb.length; i++){
        ans += numb[i]; //sums all arguments
        console.log(numb[i]); //prints each argument passed to the function
    }
    return ans; //returns the total sum of all arguments
}
let total2 = addAll2(10, 20, 30, 40); //calls the function with multiple parameters
console.log("Total sum with spread operator: ", total2); //prints the total sum of all arguments
