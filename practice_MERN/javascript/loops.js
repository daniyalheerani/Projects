//loops
//for->if you know the number of iterations
for(let i=1;i<=10;i++){
    console.log('Daniyal'+i); //1 to 10
}

//while->if you don't know the number of iterations but know the condition/task to do
let ip=1;
let house=100;
while(ip!=house){
    ip++;
    console.log('steps taken '+ip); //1 to 100
}
//do while->executes the block at least once, then checks the condition
let you=0;
do{
    you++;
    console.log('steps taken '+you); 
}
while(you<=house);

//game->guess the input
let number=50;
let guess=0;

do{
    guess= parseInt(prompt("guess a number"));
    if(guess==number){
        alert("You guessed it right!");
        break;
    }
}
while(guess!=number);
