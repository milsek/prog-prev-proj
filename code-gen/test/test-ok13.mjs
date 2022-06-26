//OPIS: fibonacci
//RETURN: 75025

let fibonacci = num => {
    let a = 0;
    let b = 1;
   
    let c = 0;

    let i = 2;
    while(i <= num) {
       c = a + b; 
       a = b; 
       b = c;
       i++;
    }
    
    return ( num == 0 ) ? b : a;
}

const main = () => {
    return fibonacci(25);
}