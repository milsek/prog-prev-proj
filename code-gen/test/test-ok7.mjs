//OPIS: while loop within while loop with break
//RETURN: 45

const main = () => {
    let i; let j; let k;
    i = 0;
    j = 0;
    k = 0;
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
}