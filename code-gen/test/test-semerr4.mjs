//DESCRIPTION: redefinition of function

const a = (b, c) => {
    return b + c;
}

const a = function(n, k) {
    return n - k;
}

function main() {
    return a(5, 3);
}
