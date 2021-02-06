def merge_the_tools(string, k):
    # your code goes here

    result = []
    s = list(string)
    for i in range(len(s)):
        if i % k == 0:
            temp = []
            for j in range(k):
                temp.append(s[i+j])  
            temp = list(dict.fromkeys(temp))
            temp = ''.join(map(str, temp))
            print(temp)

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)

"""
abcdefghiabcdefghiabcdefghi
9
"""