//DESCRIPTION: for loops
//RETURN: 3628800

const factorial = q => {
    let p = 1;
    for (let i = 1; i <= q; i++) {
        p = p * i;
    }
    return p;
}

function main() {
    let k;
    for (let i = 0; i < 20; i++) {
        if (i >= 10) {
            k = i;
            break;
        }
    }
	return factorial(k);
}