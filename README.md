# Mini JavaScript compiler

 - Technologies used: **Bison** + **Flex** + **Hipsim**
 - Translates simplified JS into a mock Assembly language

## Features
This mini-compiler was built on top of an existing miniC compiler used for teaching purposes. It is incredibly simple and limiting, so my
goal was to try and liberate the syntax a little bit, all while adding useful features. 
### Simple JS functions
JavaScript has many ways of defining and using functions. This solution offers a few simple ways of doing this.
```js
// function syntax
function func1() {
  // body
}

// arrow syntax (const/let)
const func2 = () => {
  // body
}
const func21 = a => {
  // body
}
const func22 = (a, b) => {
  // body
}

// function expression syntax
const func31 = function(a, b) {
  // body
}
```
### JavaScript declarations
This mini-compiler uses **_let_** and **_const_** keywords in order to provide control over variables.
Obviously, _const_ variables have to be initialized upon declaration and they cannot be reassigned later, while the variables declared using the _let_ keyword can be changed at will. It expands upon the aforementioned miniC compiler by allowing the user to also initialize variables upon declaration, as well as declare global variables (only using _let_ though, without initialization).
```js
let b;
function main() {
  const c = 5;
  b = 10;
}
```
### Multiplication
The compiler supports the multiplication operation. It allows both positive and negative operands.
```js
const a = -5;
return 7 * a;  // -35
```
### Post-increment and post-decrement **statements**
The post-increment (++) and post-decrement (--) statements are allowed but just as that - statements. 
```js
let a = 0; 
a++;  // 1
a--;  // 0
```

### While loops
The **_while_** loops are implemented alongside the **_break_** and **_continue_** features, which allow the user to control the flow of the loop. These keywords work with multiple nested loops.
```js
let i = 0;
let j = 0;
let k = 0;
  while (i < 10) {
    while (j < 10) {
      if (i >= 5) {
        break;
      }
      k = k + j;
      j = j + 1;
    }
    i = i + 1;
  }
return k;
```

### Ternary operator
Ternary operator just makes me feel happy whenever I can fit a few lines of if-else syntax into one line. Here, the ternary operator only differs from JavaScript  a little bit because it requires the user to use parentheses around the relational expression.
```js
let a = (x > y) ? x : y;
```

## Limitations
Since this mini-compiler is very simple, it contains certain limitations. Having been inspired by the mentioned miniC compiler, it has taken on a few of its limitations and introduced some new ones:
 - global variables have to be declared at the start of the script, before the functions
 - variables have to be declared/initialized at the start of the function
 - all bits of code happen inside functions
 - functions are made in the simplest possible way, they don't have fancy JS function features, they cannot be passed as arguments or returned from other functions
 - the only supported type is number (signed int)
