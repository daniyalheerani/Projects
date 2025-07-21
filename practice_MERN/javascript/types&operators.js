//Data types
//number
let num = 10;
let num2 = 20.5;
console.log(num + num2); //30.5
//string
let str = "Hello";
let str2 = 'World';
console.log(str + " " + str2); //Hello World
//boolean
let isLoggedIn = true;
console.log(isLoggedIn); //true
//Null
let emptyValue = null;
console.log(emptyValue); //null
//Undefined
let notAssigned= undefined;
console.log(notAssigned); //undefined  
//object
const person = {
    name: "Daniyal",
    age: 22,
    isEngineer: true, 
    isLoggedIn: false,
    emptyValue: null,
    undefined,
};
console.log(person.name); //Daniyal
console.log(person.age); //22
console.log(person.isEngineer); //true
console.log(person.isLoggedIn); //false
console.log(person.emptyValue); //null
console.log(typeof person.emptyValue); //object
console.log(person.undefined); //undefined
console.log(typeof person.undefined); //undefined


//operators
let a = 10;
let b = 20;
console.log(a + b); //30
console.log(a - b); //-10   
console.log(a * b); //200
console.log(a / b); //0.5
console.log(a % b); //10
console.log(a ** 2); //100

//1->true
//0->false

//string
console.log("12"+"34"); //1234//string
console.log("12"+34); //1234 //string
console.log("12"-34); //-22 //number
console.log("12"-"34"); //-22 //number
console.log("12"*2); //24 //number
console.log("12"*"2"); //24 //number

//typeof operator
console.log(typeof a); //number
console.log(typeof str); //string
console.log(typeof isLoggedIn); //boolean
console.log(typeof emptyValue); //object (this is a known JavaScript quirk)
