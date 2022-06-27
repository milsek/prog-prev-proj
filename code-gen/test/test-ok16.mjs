//DESCRIPTION: combining while and for loops
//RETURN: 180

function main() {
    let k = 0;
    let l = 0;
    while (k < 6) {
        for (let i = 0; i < 6; i++) 
            l = k + l + i;
        k++;
    }
	return l;
}