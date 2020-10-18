def print_formatted(number):
    # your code goes here
    dec = "{:d}"
    oct = "{:o}"
    hex = "{:x}"
    bin = "{:b}"

    lenght = len(bin.format(number))
    for i in range(1,number+1):
        print(
        dec.format(i).rjust(lenght), 
        oct.format(i).rjust(lenght), 
        hex.format(i).upper().rjust(lenght), 
        bin.format(i).rjust(lenght))
    #print(bin(number),oct(number),hex(number))
    #print(bin(number)[2:len(bin(number))])

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)