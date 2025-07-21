//high order functions -> which takes function as an argument or returns a function
function add(num1, num2) {
    return num1 + num2; //returns the sum of num1 and num2
}
add(10, 20); //calls the function with parameters 10 and 20

function multiply(num1, num2, cb) {
    let result = num1* num2; //calls the callback function with num1 and num2
    return cb(result) //returns the result of the callback function
}
multiply(10, 20, (result) => {
    console.log("Multiplication result: ", result); //prints the result of multiplication
}); //calls the function with parameters 10 and 20

multiply(5, 15, (result) => {console.log(result);}); //calls the function with parameters 5 and 15

function addAll(a,b, cb) {
    let sum = a + b; //sums a and b
    cb(sum); //calls the callback function with the sum
    return ()=>{console.log(sum);}; //returns a function that prints the sum
}
let result= addAll(10, 20, () => {}); //calls the function with parameters 10 and 20
result(); //calls the returned function to print the sum

