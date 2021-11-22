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
    const cache = {};

    // fill cache with {[cost] : [index, ...]} pairs
    // in case if there are repeating values
    for (let i = 0; i < cost.length; i++) {
        const value = cache[cost[i]] || [];
        value.push(i);
        cache[cost[i]] = value;
    }

    // console.log(cache);
    
    const result = [];

    // loop over the costs stored in keys of the cache
    for (const key in cache) {
        // calc missing value
        const diff = money - (+key);
        if (diff in cache) {
            let i = 0;
            let j = 0;
            // if it's a repeating value
            // it's stored in the seconds position
            if (diff == key) j = 1;
            result.push(cache[key][i] + 1);
            result.push(cache[diff][j] + 1);
            break;
        }
    }

    const [min, max] = [Math.min(...result), Math.max(...result)];
    return console.log(min, max);
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