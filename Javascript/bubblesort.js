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
 * Complete the 'countSwaps' function below.
 *
 * The function accepts INTEGER_ARRAY a as parameter.
 */

function countSwaps(a) {
    // console.log(a);
    // Write your code her
    var n = a.length;
    var swaps = 0;
    // console.log("n=" + n);
    for (var i = 0; i < n; i++) {    
        for (var j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                // swap(a[j], a[j + 1]);
                [a[j], a[j + 1]] = [a[j + 1], a[j]];
                swaps++;
            }
        }   
        console.log(a);     
    }

    // console.log(a);
    console.log("Array is sorted in "+ swaps +" swaps.");   
    console.log("First Element: "+ a[0]); 
    console.log("Last Element: "+ a[n-1]); 

}

function main() {
    var x  = readLine();
    const n = parseInt(x.trim(), 10);

    const a = readLine().replace(/\s+$/g, '').split(' ').map(aTemp => parseInt(aTemp, 10));

    countSwaps(a);
}
