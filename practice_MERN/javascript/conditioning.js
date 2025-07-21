//If/Else Condition Example
const age=22;

if (age => 18) {
    console.log("You are an adult; you can vote.");
}
else if (age < 18 && age > 0) {
    console.log("You are a minor; you cannot vote yet.");
}
else {
    console.log("Invalid age provided. Please enter a valid age.");
}

//ternary operator example
age >= 18 ? console.log("yes you can vote"):console.log("no you cannot vote");
let result = age >= 18 ?"yes you can vote":"no you cannot vote";
console.log(result);

//switch case example
const option = 2;
switch (option) {
    case 1:
        console.log("Hello");
        break;
    case 2:
        console.log("Namaste");
        break;
    case 3:
        console.log("Aslamwalekum");
        break;
    default:
        console.log("Invalid option selected.");
}
let a=30;
let b=20;
let opt="*";
switch (opt) {
    case "+":
        console.log(a + b);
        break;
    case "-":
        console.log(a - b);
        break;
    case "*":
        console.log(a * b);
        break;
    case "/":
        console.log(a / b);
        break;
    default:
        console.log("Invalid operator selected.");
}
