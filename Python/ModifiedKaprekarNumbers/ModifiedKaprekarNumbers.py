#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the kaprekarNumbers function below.
def kaprekarNumbers(p, q):
    count = 0
    for i in range(p,q+1):
        temp = str(i*i)
        sum1 = temp[len(temp)//2:]
        sum2 = temp[0:len(temp)//2]
        if sum1 == '': 
            sum1 = '0'
        if sum2 == '':
            sum2 = '0'
   
        s1 = int(sum1)
        s2 = int(sum2)

        total = s1 + s2
        if total == i:
            print (str(i), end = ' ')
            count += 1
    if count == 0:
        print("INVALID RANGE")
            
if __name__ == '__main__':
    p = int(input())

    q = int(input())

    kaprekarNumbers(p, q)
    

    """
    count = 0
    for i in range(p,q+1):
        s = str(i**2)
        x = s[len(s)//2:]
        y = s[0:len(s)//2]
        if x=='':x=0
        if y=='':y=0
        if int(x)+int(y)==i:print(i,end=' ');count+=1
    if count==0:print("INVALID RANGE")
    """