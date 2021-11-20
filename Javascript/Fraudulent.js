'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
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

function getMedianNumber(arr) {
    arr.sort((a, b) => a - b);
    console.log(arr);
    let medianNumber = 0;
    const middle = Math.floor(arr.length / 2);
    console.log(middle);
    if (arr.length % 2 === 0) {
      // Is even we get the median number
      medianNumber = (arr[middle] + arr[middle - 1]) / 2;
    } else {
      const index = Math.floor(middle);
      medianNumber = arr[index];
    }
    console.log(medianNumber);
    return medianNumber;
  }

function activityNotifications(expenditure, d) {
    // Write your code here
    var count = 0;
    // const average = arr => arr.reduce((a,b) => a + b, 0) / arr.length;
    const median = arr => {
        const mid = Math.floor(arr.length / 2),
          nums = [...arr].sort((a, b) => a - b);
        return arr.length % 2 !== 0 ? nums[mid] : (nums[mid - 1] + nums[mid]) / 2;
      };
    //   console.log(median([5, 6, 50, 1, -5]));
    //   console.log(median([1, 2, 3, 4, 5]));

    // console.log(expenditure.length);
    var loops = expenditure.length - d; 
    for(var i=0; i<loops; i++){
        // let newArr = expenditure.filter((element, index) => index >= i && index <= i+d-1);
        let newArr = expenditure.slice(i, i+d);
        console.log(newArr);
        // console.log(2*getMedianNumber(newArr));
        console.log("expenditure[i+d] = " + expenditure[i+d]);
        // if(2*getMedianNumber(newArr) <= expenditure[i+d]){
        if(2*median(newArr) <= expenditure[i+d]){
            count++;
        }
    }
    console.log(count);
    return count;
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