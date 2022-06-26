//DESCRIPTION: postdecrement statement
//RETURN: 25

const main = () => {
    let i; let j;
    i = 51;
    j = 0;
    while (i > j) {
        i--;
        j++;
    }
    return i;
}