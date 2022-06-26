//DESCRIPTION: ternary operator without the mandatory parentheses

const f = (a,b,c) => {
	return a < b ? a : c;
}

function main() {
	return f(1,2,3);
}
