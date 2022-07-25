process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";

process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});

process.stdin.on("end", function () {
   main(stdin_input);
});

const MODULO = 1000000007;

const times = (a, b) => parseInt((BigInt(a) * BigInt(b)) % BigInt(MODULO));
const sum = (a, b) => (a + b) % MODULO;
const pow = (n, k) => {
    let res = 1, p = n;
    while (k) {
        res = k % 2 ? times(res, p) : res;
        k = Math.floor(k / 2);
        p = times(p, p);
    }
    return res;
}
const calcC = (n, k) => {
    let res = 1;
    for (let i = 1, j = n; i <= k; i ++, j --) {
        res = times(res, j);
        res = times(res, pow(i, MODULO - 2));
    }
    return res;
}

const calcSum = num => {
    let res = 0, cur = 0;
    let leftCase = 1;
    const numbers = num.split('').map(char => parseInt(char));
    numbers.forEach((number, idx) => {
        res = times(res, 11);
        res = sum(res, leftCase * number);
        cur = times(cur, 10);
        cur = sum(cur, number);
        leftCase = times(leftCase, 2);
    })
    return sum(res + MODULO, -1 * cur);
}

function main(input) {
//    process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
    const lines = input.split('\n');
    for (const line of lines.slice(1)) {
        // process.stdout.write(calcSum(line));
        console.log(calcSum(line))
    }
}
