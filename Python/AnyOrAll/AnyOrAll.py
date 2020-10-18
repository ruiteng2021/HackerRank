
x, N = int(input()), list(map(int, input().strip().split()))
print(all(n > 0 for n in N) and any(n < 10 or n % 11 == 0 for n in N))


n=int(input())
x = list(map(int, input().split()))
temp=n
rev=0
isP = 0
allnum = 0
while(n>0):
    dig=n%10
    rev=rev*10+dig
    n=n//10
if(temp==rev):
    isP = 1

if all(i > 0 for i in x):
    allnum = 1

if(isP == 1 and allnum ==1):
    print(True)
else:
    print(False)

"""
Compiler Message
Wrong Answer
Input (stdin)
Download
10
1 2 3 4 5 6 7 8 9 10
Expected Output
Download
True


Wrong Answer
Input (stdin)
Download
1
81
Expected Output
Download
False

"""