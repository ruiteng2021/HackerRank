if __name__ == '__main__':
    count = int(input().strip())
    english = list(map(int, input().rstrip().split()))
    count2 = int(input().strip())
    french = list(map(int, input().rstrip().split()))

    set_difference_eng = set(english) - set(french)
    list_difference_eng = list(set_difference_eng)
    set_difference_fren = set(french) - set(english)
    list_difference_fren = list(set_difference_fren)

    print (len(set_difference_eng)+len(set_difference_fren))