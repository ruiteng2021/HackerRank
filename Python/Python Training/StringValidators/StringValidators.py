if __name__ == '__main__':
    s = input()
    num = False
    alpha = False
    digit = False
    lower = False
    upper = False
    for i in range(len(s)):
        if s[i].isalnum():
            num = True
        if s[i].isalpha():
            alpha = True
        if s[i].isdigit():
            digit = True
        if s[i].islower():
            lower = True
        if s[i].isupper():
            upper = True

    if num == True:
        print ("True")
    else:
        print ("False")
    if alpha == True:
        print ("True")
    else:
        print ("False")
    if digit == True:
        print ("True")
    else:
        print ("False")
    if lower == True:
        print ("True")
    else:
        print ("False")
    if upper == True:
        print ("True")
    else:
        print ("False")
