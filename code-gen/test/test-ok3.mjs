//OPIS: function expression
//RETURN: 5

const increment = function(a) {
    return a + 1;
}

const add = function(a, b) {
    return a + b;
}

function main() {
    let m;
    let n;
    m = increment(1);
    n = add(1, 2);
    return m + n;
}
