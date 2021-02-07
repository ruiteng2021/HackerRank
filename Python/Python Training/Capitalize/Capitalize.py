#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(s):
    result = ""
    s = list(s)
    count = 0;
    for i in range(len(s)):        
        if s[i] != " " and count ==0:
            result += s[i].upper()
            count = 1
            continue
        if count == 1 or s[i] == " ":
            result += s[i]
            if s[i] == " ":
                count = 0
    print(result) 
    return result


"""    
    result = []
    s = re.sub('\s{2,}', ' ', s)
    s = s.split(" ")
    for i in range(len(s)):
        name =  list(s[i])
        name[0] = name[0].upper()
        name = ''.join(name)
        result.append(name)
    print (' '.join(result))
    return ' '.join(result)
"""

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)

    fptr.write(result + '\n')

    fptr.close()

"""
Compiler Message
Wrong Answer
Input (stdin)
Download
hello   world  lol
Expected Output
Download
Hello   World  Lol


Compiler Message
Wrong Answer
Input (stdin)
Download
q w e r t y u i o p a s d f g h j  k l z x c v b n m Q W E R T Y U I O P A S D F G H J  K L Z X C V B N M
Expected Output
Download
Q W E R T Y U I O P A S D F G H J  K L Z X C V B N M Q W E R T Y U I O P A S D F G H J  K L Z X C V B N M


"""