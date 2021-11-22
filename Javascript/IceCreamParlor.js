'use strict';

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
 * Complete the 'whatFlavors' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER money
 */

function whatFlavors(cost, money) {
    // Write your code here

    const binarySearch = (arr, x , start=0, end=arr.length) => {
        // If the item does not exist, return -1
        if(end < start) return -1;
        
        // Calculate middle index of the array
        let mid = Math.floor((start + end) / 2);
        
        // Is the middle a match?
        if(arr[mid] === x) return mid;
        // Is the middle less than x
        if(arr[mid] < x) return binarySearch(arr, x, mid+1, end);
        // Else the middle is more than x
        else return binarySearch(arr, x , start, mid-1);
    }
   
    console.log("Money: " + money);
    for (var i=1; i<cost.length; i++){
        console.log(cost.slice(i, cost.length));
        var cost_sort = cost.slice(i, cost.length).sort((a,b) => a-b);
        console.log(cost_sort);
        var flavor1_index = i-1;
        var flavor2_index = binarySearch(cost_sort, money-cost[flavor1_index]);
        if(cost[flavor1_index] + cost_sort[flavor2_index] == money)
            break;
    }
    console.log((flavor1_index + 1) + " " + ((cost.indexOf(cost_sort[flavor2_index], flavor1_index + 1)) + 1));
}

function main() {
    const t = parseInt(readLine().trim(), 10);

    for (let tItr = 0; tItr < t; tItr++) {
        const money = parseInt(readLine().trim(), 10);

        const n = parseInt(readLine().trim(), 10);

        const cost = readLine().replace(/\s+$/g, '').split(' ').map(costTemp => parseInt(costTemp, 10));

        whatFlavors(cost, money);
    }
}