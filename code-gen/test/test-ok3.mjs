//OPIS: function expression
//RETURN: 5

const increment = function(a) {
    const b;
    b = 0;
    return a + 1;
}

const add = function(a, b) {
    return a + b;
}

function main() {
    var m;
    var n;
    m = increment(1);
    n = add(1, 2);
    return m + n;
}
