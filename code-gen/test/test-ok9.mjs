//DESCRIPTION: while with continue
//RETURN: 45

const main = () => {
    let i; let k;
    i = 0;
    k = 0;
    while (i < 10) {
        i = i + 1;
        if (i < 5) {
            continue; 
        }
        k = k + i;
    }
    return k;
}