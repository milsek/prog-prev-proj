//OPIS: while loop with break
//RETURN: 5

const main = () => {
    let i;
    i = 0;
    while (i < 10) {
        i = i + 1;
        if (i >= 5) {
            break;
        }
    }
    return i;
}