
import math
import os
import random
import re
import sys

# Complete the equalizeArray function below.
def equalizeArray(arr):
    temp = []
    counts = []

    for i in range(len(arr)):
        found = 0
        for j in range(len(temp)):
            if temp[j] == arr[i]:
                counts[j] = counts[j] + 1
                found = 1
        if found == 0:
            temp.append(arr[i])
            counts.append(1)

    #print(temp)
    #print(counts)
    print (len(arr)-max(counts))
    #return (len(arr)-max(counts))
    print (len(arr)-max([arr.count(i) for i in arr]))
    return len(arr)-max([arr.count(i) for i in arr])
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = equalizeArray(arr)

    fptr.write(str(result) + '\n')

    fptr.close()