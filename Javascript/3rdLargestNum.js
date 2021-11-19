'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.on('SIGINT', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

function activityNotifications(expenditure, d) {
    // Write your code here
    console.log(d);
    console.log(expenditure);
    let newArr = expenditure.filter((element, index) => index >= 3 && index <= 5);
    // let unique = [...new Set(expenditure)];
    console.log(newArr);
    // console.log(unique);

    // Find the third largest number in Array
    let unique = [...new Set(expenditure)];     // remove duplications
    let num3= unique.sort((a, b) => b-a);       // order Decendening
    console.log("num3[2] = " + num3[2]);        // find third biggest number
    var index = expenditure.indexOf(num3[2])    // find index of the 3rd biggest number
    console.log("index = " + index);
    // var indexes = find(num3[2],expenditure);
    const indexOfAll = (arr, val) => arr.reduce((acc, el, i) => (el === val ? [...acc, i] : acc), []);
    var indexes = indexOfAll(expenditure,  num3[2]);  // find all indexes of the 3rd biggest number
    console.log(indexes);
    // return d;

}

function main() {
    const ws = fs.createWriteStream('./output');

    const firstMultipleInput = readLine().replace(/\s+$/g, '').split(' ');

    const n = parseInt(firstMultipleInput[0], 10);

    const d = parseInt(firstMultipleInput[1], 10);

    const expenditure = readLine().replace(/\s+$/g, '').split(' ').map(expenditureTemp => parseInt(expenditureTemp, 10));

    const result = activityNotifications(expenditure, d);

    ws.write(result + '\n');

    ws.end();
}