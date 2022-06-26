//OPIS: two while loops, one with break
//RETURN: 5

const main = () => {
    let i; let j;
    i = 0;
    j = 0;
    while (i < 10) {
        i = i + 1;
    }
    while (j < 10) {
        if (j >= 5) {
            break;
        }
        j = j + 1;
    }
    return j;
}