#!/bin/python3

import math
import os
import random
import re
import sys
import itertools
# Complete the minimumDistances function below.
def minimumDistances(a):
    diff_list = [] 
    result = []
    for j in a:
        multiple  = [i for i,val in enumerate(a) if val==j]
        if len(multiple) > 1:
            for n1, n2 in list(itertools.combinations(multiple, 2)):  
                #Find the absolute difference 
                diff_list.append(abs(n1-n2))  
            result.append(min(diff_list))   
    if len(result) > 0:
        return min(result) 
    else:
        return -1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    a = list(map(int, input().rstrip().split()))

    result = minimumDistances(a)

    fptr.write(str(result) + '\n')

    fptr.close()
