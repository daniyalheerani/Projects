//arrow function
//arrow function are global functions

function add(num1, num2) {
    return num1 + num2; //returns the sum of num1 and num2  
}
add(10, 20); //calls the function with parameters 10 and 20

// Arrow function
const addArrow = (num1, num2) => num1 + num2; //One liner Arrow function to add two numbers
console.log("Arrow function result: ", addArrow(10, 20)); // prints the

const dispalayMessage = (message) => {
    console.log(message); // Arrow function to display a message
}
dispalayMessage("Hello from arrow function!"); // calls the arrow function with a message

const addTwoNumbers = (num1, num2) => {
    return num1 + num2; // Arrow function to add two numbers
}
console.log("Add two numbers result: ", addTwoNumbers(5, 15)); // prints the result of adding two numbers

//argument keyword can not be used in arrow functions, but we use spread operator
const addAllNumbers = (...numbers) => {
    let sum = 0;
    for (let number=0; number < numbers.length; number++) {
        sum += number; // Add each number to the sum
    }
    return sum; // Return the total sum
}

//hoisting function
//you can call the function before it is defined in normal functions but not in arrow functions

//this keyword 
const object = {
    value:60,
    myFunction:() => {
        console.log(this); // Arrow function does not bind its own 'this'
    }
}
object.myFunction();// prints the global object

