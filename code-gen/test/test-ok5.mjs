//OPIS: while loop
//RETURN: 10

const main = () => {
    let i;
    let k;
    k = 0;
    i = 5;
    while (i < 11) {
        i = i + 5;
        i = i - 2;
        while (k < 10) {
            k = k + 1;
        }
    }
    return 10;
}